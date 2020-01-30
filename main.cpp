#include "print_ip.h"

int main() {
    char _char = -1;
    short  _short = 0;
    int _int = 2130706433;
    long long _LL = 8875824491850138409LL;
    std::string str = "172.22.12.129";
    print_ip(str);

    return 0;
}