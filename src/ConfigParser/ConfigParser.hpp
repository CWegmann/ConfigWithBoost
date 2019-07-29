#ifndef CONFIGPARSER_HPP
#define CONFIGPARSER_HPP

#include <string>
#include <boost/program_options.hpp>

class ConfigParser{

public:
    ConfigParser();

    void parse(int argc, const char* argv[]);
    void parse(const std::string& pathToConfigFile);

    using map_type = boost::program_options::variables_map;
    using options_type = boost::program_options::options_description;

    const map_type& map() const;
    const options_type& options() const;

private:
    map_type map_;
    boost::program_options::options_description options_;

};

#endif
