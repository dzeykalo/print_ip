#define BOOST_TEST_MODULE testing

#include "print_ip.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite)

    BOOST_AUTO_TEST_CASE(test_integer)
    {
        std::string s("255");
        char _char = -1;
        BOOST_CHECK( s == print_ip(_char) );
    }
    BOOST_AUTO_TEST_CASE(test_string)
    {
        std::string s("45.67.89.101.112.131.41");
        std::string ss("45.67.89.101.112.131.41");
        BOOST_CHECK( s == print_ip(ss) );
    }
    BOOST_AUTO_TEST_CASE(test_container)
    {
        std::string s("67.89.101.112.131.41");
        std::vector<int> v = {67,89,101,112,131,41};
        BOOST_CHECK( s == print_ip(v) );
    }
    BOOST_AUTO_TEST_CASE(test_tuple)
    {
        std::string s("255.255.255.0");
        std::tuple<char, char, char, char> t = {-1,-1,-1,0};
        BOOST_CHECK( s == print_ip(t) );
    }
BOOST_AUTO_TEST_SUITE_END()
