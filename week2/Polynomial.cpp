#include <iostream>
#include "Polynomial.h"

Polynomial::Polynomial()
{
    degree = 0;
    for (double d : coeffs) d == 0.0;
}

std::istream &operator>>(std::istream &_is, Polynomial &_obj)
{
    _is >> _obj.degree;

    for (int i = 0; i <= _obj.degree; i++) _is >> _obj.coeffs[i];

    return _is;
}

std::ostream &operator<<(std::ostream &_os, const Polynomial &_obj)
{
    _os << _obj.coeffs[0] << "x^0 ";
    for (int i = 1; i <= _obj.degree; i++)
        _os << "+ " << _obj.coeffs[i] << "x^" << i;
    _os << std::endl;

    return _os;
}

Polynomial Polynomial::operator*(const Polynomial &_right) const
{
    Polynomial output;
    output.degree = degree + _right.degree;

    for (int i = 0; i <= degree; i++)
    {
        for (int j = 0; j <= _right.degree; j++)
        {
            output.coeffs[i + j] += coeffs[i] * _right.coeffs[j];
        }
    }

    return output;
}
