#include "Capacitor.h"

using namespace std;

bool Capacitor::mustScale( double aValue ) const
{
    return aValue < 1.0;
}

const double Capacitor::getMultiplier() const
{
    return 1000.0;
}

const string Capacitor::getMajorUnit() const
{
    return "F";
}

const string Capacitor::getMinorUnits() const
{
    return "Fmunp";
}

double Capacitor::getValue( double aFrequency ) const
{
    return getBaseValue();
}

Capacitor::Capacitor( double aBaseValue )
{
    setBaseValue(aBaseValue);
}
