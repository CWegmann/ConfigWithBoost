#include <iostream>
#include "ConfigParser.hpp"
#include "Consumer.hpp"

int main(int argc, const char* argv[]){

    ConfigParser parser;

    // just for demonstration purposes:
    // one can print all possible configuration options/parameters on the console
    std::cout << parser.options() << "\n";

    // parse command line parameters of the form "--paramXY value"
    // command line arguments have precedence over config file parameters
    // (because they come first)
    parser.parse(argc, argv);

    // parse parameters from config file of the form "paramXY = value"
    // possibly you have to adjust the path
    parser.parse("config.ini");

    Consumer consumer;
    // just for demonstration purposes:
    // pass the map of key value pairs which resulted from the command line arguments
    // plus from the config file to a consumer (which simply prints the pairs)
    consumer.consume(parser.map());
    
    return 0;
}
