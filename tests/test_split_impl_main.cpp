// tests/test_split_impl_main.cpp: test two-file approach.
// Thanks to bladchan for sample code

#include "toml_fwd.hpp"
#include <iostream>
#include <sstream>

int main()
{
    std::istringstream iss("key = value\n", std::ios_base::binary);
    if(!iss.good()) {
        return 1;
    }

    toml::value data;
    try {
        data = toml::parse(iss, "inline");
    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::cout << std::setw(80) << data << std::endl;

    return 0;
}
