#include <cmath>
#include "Polynomial.h"

double Polynomial::operator() ( double aX ) const
{
    double output = 0;
    // iterate through every term and calculate it
    for (int i = 0; i <= fDegree; i++)
    {
        auto x = pow(aX, i);
        output += fCoeffs[i] * x;
    }

    return output;
}

Polynomial Polynomial::computeIndefiniteIntegral() const
{
    Polynomial output;

    output.fDegree = fDegree + 1;
    output.fCoeffs[0] = 0.0; // first term is always 0x^0
    // calculate each new term
    for (int i = 0; i <= fDegree; i++)
    {
        output.fCoeffs[i + 1] = fCoeffs[i] / (i + 1);
    }

    return output;
}

double Polynomial::calculateDefiniteIntegral( double aXLow, double aXHigh) const
{
    Polynomial integ = computeIndefiniteIntegral();
    double low = integ(aXLow);
    double high = integ(aXHigh);

    return high - low;
}
