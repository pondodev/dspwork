#include <iostream>
#include "Polynomial.h"

int main()
{
    Polynomial A;
    std::cout << "specify first polynomial (degree followed by coefficients): " << std::endl;
    std::cin >> A;
    std::cout << "A = " << A << std::endl;

    Polynomial B;
    std::cout << "specify first polynomial (degree followed by coefficients): " << std::endl;
    std::cin >> B;
    std::cout << "B = " << B << std::endl;

    Polynomial C = A * B;
    std::cout << "C = A * B = " << C << std::endl;

    return 0;
}
