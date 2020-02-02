#include "print_ip.h"

int main() {
    char _char = -1;
    short  _short = 0;
    int _int = 2130706433;
    long long _ll = 8875824491850138409LL;
    std::string str = "45.67.89.101.112.131.41";
    std::vector<int> v = {67,89,101,112,131,41};
    std::list<int> l = {89,101,112,131,41};
    std::tuple<int,int> t = {66,67};

    /*print_ip(_char);
    print_ip(_short);
    print_ip(_int);
    print_ip(_ll);
    print_ip(str);
    print_ip(v);
    print_ip(l);*/
    print_ip(t);


    return 0;
}