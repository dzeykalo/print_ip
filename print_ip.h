#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <tuple>
#include <type_traits>
#include <tuple>

template<typename T>
typename std::enable_if<std::is_integral<T>::value, std::string>::type
print_ip (T &number)
{
    std::string ack;
    for (int i=(sizeof(number)-1)*8; 0 <= i; i-=8)
    {
        unsigned char bytes = (number >> i) & 0xFF;
        ack += std::to_string(bytes);
        if (i != 0) ack += ".";
    }
    return ack;
}

std::string print_ip (std::string &number){ return number; }


template<typename T> struct is_container : public std::false_type {};

template<typename T>
struct is_container<std::vector<T>> : public std::true_type {};

template<typename T>
struct is_container<std::list<T>> : public std::true_type {};

template<typename T>
typename std::enable_if<is_container<T>::value, std::string>::type
print_ip (T &number)
{
    std::string ack;
    for (auto i: number)
    {
        ack += std::to_string(i);
        if (i != number.back()) ack += ".";
    }
    return ack;
}

template<std::size_t I = 0, typename T, typename U>
typename std::enable_if< std::is_same<T, U>::value, std::string>::type
same_print_ip(T& arg, U u)
{
  return print_ip<I>(arg);
}

template<std::size_t I = 0, typename... Arg>
typename std::enable_if<I == sizeof...(Arg), std::string>::type
print_ip(std::tuple<Arg...> &number)
{
  std::string s("\0");
  return s;
}

template<std::size_t I = 0, typename... Arg>
typename std::enable_if<I < sizeof...(Arg), std::string>::type
print_ip(std::tuple<Arg...>& t)
{
  std::string s(same_print_ip(std::get<I>(t), std::get<I>(t)));

  if (I+1 != sizeof...(Arg))
    s += ".";
  s += same_print_ip(std::get<I+1>(t), std::get<I>(t));
  return s;
}


/// Remember a good solution ///
//template <typename... Args>
//struct is_all_same;
//
//template <typename T>
//struct is_all_same <T> : std::true_type {} ;
//
//template <typename T>
//struct is_all_same <T, T> : std::true_type {} ;
//
//template<typename T, typename U, typename... Args>
//struct is_all_same<T, U, Args...> : std::false_type {};
//
//template <typename T, typename... Args>
//struct is_all_same<T, T, Args...> : is_all_same<T, Args...> {};
//
//template <typename... Args>
//constexpr auto is_all_same_v = is_all_same<Args...>::value;

//template<std::size_t I = 0, typename... Arg>
//typename std::enable_if<I < sizeof...(Arg), std::string>::type
//print_ip(std::tuple<Arg...>& t)
//{
//  static_assert(is_all_same_v<Arg...>);
//  std::string s(print_ip(std::get<I>(t)));
//
//  if (I+1 != sizeof...(Arg))
//    s += ".";
//  s += print_ip<I + 1, Arg...>(t);
//  return s;
//}