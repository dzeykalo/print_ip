#include "print_ip.h"

int main() {
    char _char = -1;
    short  _short = 0;
    int _int = 2130706433;
    long long _ll = 8875824491850138409LL;
    std::string str = "45.67.89.101.112.131.41";
    std::vector<int> v = {67,89,101,112,131,41};
    std::list<int> l = {89,101,112,131,41};
    std::tuple<int, int, int, int> t = {101,112,131,41};

    std::cout << print_ip(_char) << std::endl;
    std::cout << print_ip(_short) << std::endl;
    std::cout << print_ip(_int) << std::endl;
    std::cout << print_ip(_ll) << std::endl;
    std::cout << print_ip(str) << std::endl;
    std::cout << print_ip(v) << std::endl;
    std::cout << print_ip(l) << std::endl;
    std::cout << print_ip(t) << std::endl;

    return 0;
}