#include <iostream>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <map>

constexpr double c { 299792458.0 };
constexpr double zero { 0.0 };

int main(int argc, char *argv[])
try
{
    if (argc != 4)
    {
        throw std::invalid_argument("Usage: frequency prefix epsilon");
    }

    auto frequency { zero };
    {
        std::stringstream ss { argv[1] };
        ss >> frequency;
    }

    std::string prefix;
    {
        std::stringstream ss { argv[2] };
        ss >> prefix;
    }

    auto epsilon { zero };
    {
        std::stringstream ss { argv[3] };
        ss >> epsilon;
    }

    std::map<std::string, double> supported_prefix
    {
        { "Hz", 1.0 },
        { "kHz", 1.0E3 },
        { "MHz", 1.0E6 },
        { "GHz", 1.0E9 },
        { "THz", 1.0E12 }
    };

    auto it { supported_prefix.find(prefix) };

    if (it == supported_prefix.end())
    {
        throw std::runtime_error("Unsupported prefix: " + prefix);
    }

    auto const mult_value { it->second };

    std::cout << "Frequency: " << frequency << " " << prefix << std::endl;
    std::cout << "Epsilon: " << epsilon << std::endl;

    auto const lambda = c / (frequency * mult_value * std::sqrt(epsilon));

    std::cout << "Wavelength: " << lambda << " m" << std::endl;

    return EXIT_SUCCESS;
}
catch (std::exception &exc)
{
    std::cerr << "Exception: " << exc.what() << std::endl;
    return EXIT_FAILURE;
}
catch (...)
{
    std::cerr << "Error: exception" << std::endl;
    return EXIT_FAILURE;
}
