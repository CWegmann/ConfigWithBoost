#include "ConfigParser.hpp"
#include <iostream>
#include <fstream>

namespace po = boost::program_options;

ConfigParser::ConfigParser()
    : options_{"Valid options are"}{

    /* In this specific case, there are three possible options for the
     * program: "param01", "param02" and "param03".
     * - Each parameter has a key (e.g. "param01") with which it is
     *   accessed in the map
     * - Each parameter has a description (e.g. "The first parameter")
     * - Parameters can have default values
     * - Options can have more properties:
     *     - E.g. one can create lists that can be populated from both
     *       the command line and a config file
     *       (so that the options "compose" and don't overwrite each other)
     *     - One can have notifications/function calls once a parameter is
     *       populated.
     *     - ...
     */
    options_.add_options()
            ("param01",
             po::value<int>()->default_value(42),
             "The first parameter")
            ("param02",
             po::value<double>()->default_value(3.1415),
             "The second parameter")
            ("param03",
             po::value<std::string>()->default_value("Hello, World!"),
             "The third parameter");
}

void
ConfigParser::parse(
        int argc,
        const char* argv[]){
    // parse the command line options; store result in map_
    try{
        po::store(po::parse_command_line(argc, argv, options_), map_);
    }catch(const po::error& ex){
        std::cout << ex.what() << "\n";
    }
}

void
ConfigParser::parse(
        const std::string& pathToConfigFile){
    std::ifstream file{pathToConfigFile};

    if(!file.is_open())
        std::cout << "could not open configuration file" << "\n";

    // parse parameters from config file; store result in map_
    try{
        po::store(po::parse_config_file(file, options_), map_);
    }catch(const po::error& ex){
        std::cout << ex.what() << "\n";
    }
}

const typename ConfigParser::map_type&
ConfigParser::map() const{
    return map_;
}

const typename ConfigParser::options_type&
ConfigParser::options() const{
    return options_;
}
