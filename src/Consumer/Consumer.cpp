#include "Consumer.hpp"

#include <iostream>

void
Consumer::consume(
        const map_type& map) const{

    std::cout << "The following parameters were passed:" << "\n";

    try{
        if(map.count("param01"))
            std::cout << "Parameter 01: " << map["param01"].as<int>() << "\n";

        if(map.count("param02"))
            std::cout << "Parameter 02: " << map["param02"].as<double>() << "\n";

        if(map.count("param03"))
            std::cout << "Parameter 03: " << map["param03"].as<std::string>() << "\n";

    }catch(const boost::bad_any_cast& ex){
        std::cout << ex.what() << "\n";
    }
}
