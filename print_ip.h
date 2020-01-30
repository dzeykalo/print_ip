#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <tuple>
#include <type_traits>

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