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
};
