#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <tuple>
#include <type_traits>
#include <tuple>

using vector_uchar = std::vector<unsigned char>;

void print(vector_uchar &ip)
{
    std::copy(ip.begin(), ip.end()-1, std::ostream_iterator<int>(std::cout,"."));
    std::copy(ip.end()-1, ip.end(), std::ostream_iterator<int>(std::cout, "\n"));
}

template<typename T>
typename std::enable_if<std::is_integral<T>::value>::type
print_ip (T &number)
{
    vector_uchar ack;
    for (int i=(sizeof(number)-1)*8; 0 <= i; i-=8)
    {
        unsigned char bytes = (number >> i) & 0xFF;
        ack.push_back(bytes);
    }
    print(ack);
}

void print_ip (std::string &number)
{
    std::cout << number << std::endl;
}

template<typename T> struct is_container : public std::false_type {};

template<typename T>
struct is_container<std::vector<T>> : public std::true_type {};

template<typename T>
struct is_container<std::list<T>> : public std::true_type {};

template<typename T>
typename std::enable_if<is_container<T>::value>::type
print_ip (T &number)
{
    vector_uchar ack;
    for (auto i: number)
    {
        ack.push_back(i);
    }
    print(ack);
}

/*
template<typename T> struct is_tuple : public std::false_type {};

template<typename ...Arg>
struct is_tuple<std::tuple<Arg...>> : public std::true_type {};

template<typename T>
typename std::enable_if<is_tuple<T>::value>::type
print_ip (T &number)
{
  std::cout <<  " is typle" << std::endl;
}
*/

template<std::size_t I = 0, typename... Arg>
typename std::enable_if<I == sizeof...(Arg), void>::type
print_ip(std::tuple<Arg...> &number)
{
  std::cout << std::endl;
}

template<std::size_t I = 0, typename... Arg>
typename std::enable_if<I < sizeof...(Arg), void>::type
print_ip(std::tuple<Arg...>& t)
{
  std::cout << std::get<I>(t);

  if (I+1 != sizeof...(Arg))
    std::cout << ".";
  print_ip<I + 1, Arg...>(t);
}
