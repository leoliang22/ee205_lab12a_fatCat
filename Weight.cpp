///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Leo Liang <leoliang@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Weight.h"

//define the conversions
const float Weight::KILOS_IN_A_POUND = 0.453592;
const float Weight::SLUGS_IN_A_POUND = 0.031081;
const float Weight::UNKNOWN_WEIGHT = -1;
//define the character labels for each weight type
const std::string Weight::KILO_LABEL = "KILO";
const std::string Weight::POUND_LABEL = "POUND";
const std::string Weight::SLUG_LABEL = "SLUG";


float Weight::fromKilogramToPound( const float kilogram ) noexcept {
    return kilogram / KILOS_IN_A_POUND ;
}

float Weight::fromSlugToPound(float slug) noexcept {
    return slug / SLUGS_IN_A_POUND;
}

float Weight::fromPoundToSlug( float pound ) noexcept{
    return pound * SLUGS_IN_A_POUND;
}

float Weight::fromPoundToKilogram(float pound) noexcept {
    return pound * KILOS_IN_A_POUND;
}

float commonUnit;
float endUnit;
float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
   switch( fromUnit ){
       case POUND : commonUnit = fromWeight;
       break;
       case KILO : commonUnit = fromKilogramToPound( fromWeight );
       break;
       case SLUG: commonUnit = fromSlugToPound( fromWeight );
       break;
       default: std::cout << "Unknown fromUnit ";
       return false;
   }

   switch( toUnit ){
       case POUND: endUnit = commonUnit;
       break;
       case KILO: endUnit = fromPoundToKilogram( commonUnit );
       break;
       case SLUG: endUnit = fromSlugToPound(commonUnit );
       break;
       default: std::cout << "Unknown toUnit ";
       return false;
   }


}

Weight::Weight( const Weight::UnitOfWeight newUnitOfWeight, const float newMaxWeight ) : Weight( newUnitOfWeight ){
    setMaxWeight( newMaxWeight );
    setBHasMax();
}

void Weight::setWeight(float weight) {
    setBIsKnown();
    weight = weight;
}

void Weight::setMaxWeight(float maxWeight) {
    Weight::maxWeight = maxWeight;
    setBHasMax();
}

Weight::Weight(float weight) : weight(weight) {
    setBIsKnown();
    setWeight( weight );
}

Weight::Weight(UnitOfWeight newUnitofWeight ) noexcept {
    convertWeight(getWeight(), getUnitOfWeight(), newUnitofWeight );
    setUnitOfWeight( newUnitofWeight );
}

float Weight::getWeight() const {
    return weight;
}

Weight::Weight() noexcept{
}

Weight::UnitOfWeight Weight::getUnitOfWeight() const {
    return unitOfWeight;
}

Weight::Weight(float weight, Weight::UnitOfWeight unitOfWeight) : weight(weight), unitOfWeight(unitOfWeight) {
    convertWeight(weight, getUnitOfWeight(), unitOfWeight);
    setUnitOfWeight( unitOfWeight );
    setBIsKnown();
}

Weight::Weight(float weight, float maxWeight) : weight(weight), maxWeight(maxWeight) {
    setWeight( weight );
    setBIsKnown();
    setMaxWeight( maxWeight);
    setBHasMax();
}

float Weight::getWeight(Weight::UnitOfWeight weightUnits) const {
    convertWeight(getWeight(), getUnitOfWeight(), weightUnits);
    return getWeight();
}

void Weight::setUnitOfWeight(Weight::UnitOfWeight unitOfWeight) {
    Weight::unitOfWeight = unitOfWeight;
}

Weight::Weight(float weight, Weight::UnitOfWeight unitOfWeight, float maxWeight) : weight(weight), maxWeight(maxWeight),
                                                                                   unitOfWeight(unitOfWeight) {
    setMaxWeight(maxWeight);
    setUnitOfWeight( unitOfWeight );
    convertWeight( weight, getUnitOfWeight(), unitOfWeight);
    setBIsKnown();
    setBHasMax();
}


std::ostream& operator<<( std::ostream& lhs_stream
        ,const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO: return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG: return lhs_stream << Weight::SLUG_LABEL ;
        default:
            throw std::out_of_range( "The unit can’t be mapped to a string" );
    }
}

bool Weight::operator==(const Weight& rhs_Weight ) const {
/// Remember to convert the two weight's units into a common unit!
/// Treat unknown weights as 0 (so we can sort them without dealing
/// with exceptions)
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight == rhs_weight;
}

bool Weight::operator<( const Weight& rhs_Weight ) const {
/// Treat unknown weights as 0 (so we can sort them without dealing
/// with exceptions)
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight < rhs_weight;
}


bool Weight::operator+=( float rhs_addToWeight ) const {
/// Treat unknown weights as 0 (so we can sort them without dealing
/// with exceptions)
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_addToWeight);
    return lhs_weight + rhs_weight;
}

bool Weight::isWeightKnown() const {
    return bIsKnown;
}

bool Weight::setBIsKnown() {
    Weight::bIsKnown = true;
}

bool Weight::isBHasMax() const {
    return bHasMax;
}

void Weight::setBHasMax() {
    Weight::bHasMax = true;
}

void Weight::setWeight(float newWeight, UnitOfWeight unitOfWeight){
    convertWeight(newWeight, getUnitOfWeight(), unitOfWeight);
}

float Weight::getMaxWeight() const {
    return maxWeight;
}

bool Weight::isWeightValid(){
    if(getWeight() < 0){
        return false;
    }
    if (isBHasMax() == true){
        if(getWeight()> getMaxWeight()){
            return false;
        }
    }
    return true;
}

bool Weight::Validate(){
    isWeightValid();
    return true;
}

void Weight::dump(){
    std::cout << "==============================================" << std::endl;
    std::cout << "Weight  this                " << &weight << std::endl;
    std::cout << "Weight  isKnown             " << isWeightKnown() << std::endl;
    std::cout << "Weight  weight              " << getWeight() << std::endl;
    std::cout << "Weight  unitOfWeight        " << getUnitOfWeight() << std::endl;
    std::cout << "Weight  hasMax              " << isBHasMax() << std::endl;
    std::cout << "Weight  maxWeight           " << getMaxWeight() << std::endl;
}