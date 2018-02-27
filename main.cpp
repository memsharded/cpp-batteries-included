#include "CLI/CLI.hpp"
#include <fplus/fplus.hpp>
#include "rang.hpp"
extern "C" {
#include "src/test_expat.h"
}

#include <string>
#include <sstream>
#include <array>
#include "fmt/format.h"
#include "Poco/MD5Engine.h"
#include <boost/regex.hpp>
#include <cereal/archives/json.hpp>
#ifdef _WIN32
#ifndef __MINGW32__
#define GOOGLE_GLOG_DLL_DECL 

#endif
#endif
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <glog/logging.h>


int main(int argc, char **argv){
    std::cout << "App can parse command line arguments with CLI11\n\n";
    CLI::App app("C++ Batteries Included with Conan");
    CLI11_PARSE(app, argc, argv);

    google::InitGoogleLogging(argv[0]);
    LOG(ERROR) << "Google logging works!!\n\n";

    std::list<std::string> things = {"same old", "same old"};
    if (fplus::all_the_same(things))
        std::cout << "Functional is fun in C++ with FunctionalPlus: All things being equal.\n\n";


    std::cout << rang::style::reset << rang::bg::green << rang::fg::gray << rang::style::bold
              << "Using Rang for colors!! " << rang::bg::reset << rang::fg::reset << rang::style::reset << '\n' << std::endl;
    
    test_expat();

    std::string thing("World");
    fmt::print("FMT Formatting library rocks! Hello {}!\n\n", thing);

    Poco::MD5Engine md5;
    md5.update("Hello World");
    std::string md5string = Poco::DigestEngine::digestToHex(md5.digest());
    std::cout<< "Poco is computing an MD5 wrapping OpenSSL = " << md5string << "\n\n";

    std::cout << "Boost regex checks validity of some emails: ";
    std::string s = "correct@email.com", s2="bademail";
    boost::regex expr{"\\b[a-zA-Z0-9._%-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,4}\\b"};
    std::cout << std::boolalpha << boost::regex_match(s, expr) << ", ";
    std::cout << std::boolalpha << boost::regex_match(s2, expr) << "\n\n";

 
    std::stringstream ss; // any stream can be used
    {
        bool arr[] = {true, false};
        cereal::JSONOutputArchive  archive(ss);
        archive(arr);
    }
    std::cout << "Some serialization to JSON courtesy of Cereal: " << ss.str() << "\n\n";
    
}
