
// COS30008, Tutorial 3, 2019

#include "PassiveResistor.h"

#include <stdexcept>

using namespace std;

void PassiveResistor::normalize( double& aNormalizedValue, string& aUnit ) const
{
    aNormalizedValue = getBaseValue();
    string lPrefixes = getMinorUnits();
    
    for ( int i = 0; i < lPrefixes.size(); i++ )
    {
        if ( mustScale( aNormalizedValue ) )
        {
            aNormalizedValue *= getMultiplier();
        }
        else
        {
            if ( i > 0 )
            {
                aUnit += lPrefixes[i];
            }
            aUnit += getMajorUnit();
            break;
        }
    }
}

void PassiveResistor::flatten( const double& aRawValue, const string& aRawUnit )
{
    string lMajorUnit = getMajorUnit();
    string lMinorUnits = getMinorUnits();

    // error handling
    // test basic features (raw unit too long and not containing major unit)
    if ( (aRawUnit.size() > lMajorUnit.size() + 1) ||
         (aRawUnit.find( getMajorUnit() ) == string::npos) )
    {
        throw invalid_argument( "Invalid unit specification" );
    }

    // test scale features, aRawUnit[0] must be contained in minor units
    if ( (aRawUnit.size() == lMajorUnit.size() + 1) &&
         lMinorUnits.find( aRawUnit[0] ) == string::npos )
    {
        throw invalid_argument( "Invalid unit scale specification" );
    }

    // adjust base value
    double lMultiplier = 1.0;
    
    for ( size_t i = lMinorUnits.find( aRawUnit[0] ); i > 0; i-- )
    {
        lMultiplier *= 1.0/getMultiplier();
    }

    setBaseValue( aRawValue * lMultiplier );
}

bool PassiveResistor::mustScale( double aValue ) const
{
    return aValue >= 1000.0;
}

const double PassiveResistor::getMultiplier() const
{
    return 1.0 / 1000.0;
}

const std::string PassiveResistor::getMajorUnit() const
{
    return "Ohm";
}

const std::string PassiveResistor::getMinorUnits() const
{
    return "Okm";
}

void PassiveResistor::setBaseValue( double aBaseValue )
{
    fBaseValue = aBaseValue;
}

double PassiveResistor::getBaseValue() const
{
    return fBaseValue;
}

double PassiveResistor::getValue( double aFrequency ) const
{
    return getBaseValue();
}

double PassiveResistor::getPotential ( double aCurrent, double aFrequency ) const
{
    return aCurrent * this->getValue(aFrequency);
}

double PassiveResistor::getCurrent( double aVoltage, double aFrequency ) const
{
    return aVoltage / this->getValue(aFrequency);
}

std::istream& operator>>( std::istream& aIStream, PassiveResistor& aObject )
{
    double lValue;
    string lUnit;
    aIStream >> lValue >> lUnit;
    aObject.flatten(lValue, lUnit);
    return aIStream;
}

std::ostream& operator<<( std::ostream& aOStream, const PassiveResistor& aObject )
{
    double lValue;
    string lUnit;
    aObject.normalize(lValue, lUnit);
    aOStream << lValue << lUnit;
    return aOStream;
}

PassiveResistor::PassiveResistor( double aBaseValue )
{
    fBaseValue = aBaseValue;
}
