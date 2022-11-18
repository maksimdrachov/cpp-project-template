#include "division.h"
#include <iostream>

const std::string HEADER = "\n=== Divider program ===\n\n";
const std::string USAGE = "Usage:\n\tdivider <numerator> <denominator>\n\nDescription:\n\tComputes "
                          "the result of a fractional division,\n\tand reports both the result and "
                          "the remainder.\n";

int main(int argc, const char *argv[]) {
    Fraction f;

    std::cout << HEADER;

    // ensure the correct number of parameters are used.

    if (argc < 3) {
        std::cout << USAGE;
        return EXIT_FAILURE;
    }

    f.numerator = atoll(argv[1]);
    f.denominator = atoll(argv[2]);

    Division d = Division(f);
    try {
        DivisionResult r = d.divide();

        std::cout << "Division: " << f.numerator << "/" << f.denominator << " = " << r.division << "\n";
        std::cout << "Remainder: " << f.numerator << "%" << f.denominator << " = " << r.remainder << "\n";
    } catch (DivisionByZero excp) {
        std::cout << "Caught exception:\n";
        std::cout << excp.what();
    }

    return EXIT_SUCCESS;
}