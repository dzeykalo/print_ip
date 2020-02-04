cmake_minimum_required(VERSION 3.5)

set( PRO_PATCH $ENV{TRAVIS_BUILD_NUMBER})
if (NOT "${PRO_PATCH}")
    set(PRO_PATCH "1")
endif (NOT "${PRO_PATCH}")

project(print_ip VERSION 0.0.${PRO_PATCH})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(print_ip main.cpp print_ip.h)
add_executable(print_ip_test testing.cpp)

set_target_properties(
        print_ip PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
)
set_target_properties(
        print_ip_test PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(print_ip_test ${Boost_LIBRARIES})

enable_testing()
add_test(test_print_ip print_ip_test)

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME print_ip)
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_PACKAGE_CONTACT mr.alligator@yandex.ru)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
include(CPack)