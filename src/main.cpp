#include <iostream>
#include <sstream>

constexpr double c { 299792458.0 };
constexpr double zero { 0.0 };

int main(int argc, char *argv[])
try
{
    if (argc != 3)
    {
        throw std::invalid_argument("Usage: frequency epsilon");
    }

    auto frequency { zero };
    {
        std::stringstream ss { argv[1] };
        ss >> frequency;
    }

    auto epsilon { zero };
    {
        std::stringstream ss { argv[2] };
        ss >> epsilon;
    }

    std::cout << "Frequency: " << frequency << std::endl;
    std::cout << "Epsilon: " << epsilon << std::endl;

    auto const lambda = c / (frequency * std::sqrt(epsilon));

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
