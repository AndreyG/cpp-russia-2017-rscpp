#include "navigation/abrahams_dimov.h"
#include "navigation/usings.h"
#include "navigation/adl.h"

int main()
{
    abrahams_dimov::run();
    std::cout << "---------------------------------------------------------------------------------------------\n";
    a::x::y::z::run();
    std::cout << "---------------------------------------------------------------------------------------------\n";
    app::run();
}
