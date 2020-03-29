#pragma once

#define MAX_DEGREE 20+1

class Polynomial
{
    private:
        int degree;
        double coeffs[MAX_DEGREE];

    public:
        Polynomial();

        Polynomial operator*(const Polynomial &_right) const;
        
        friend std::istream &operator>>(std::istream &_is, Polynomial &_obj);
        friend std::ostream &operator<<(std::ostream &_os, const Polynomial &_obj);
};
