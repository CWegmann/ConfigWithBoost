#ifndef CONSUMER_HPP
#define CONSUMER_HPP

#include <boost/program_options.hpp>

class Consumer{

public:
    using map_type = boost::program_options::variables_map;

    void consume(const map_type& map) const;

};

#endif
