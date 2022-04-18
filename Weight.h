///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Leo Liang <leoliang@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_LAB12A_FATCAT_WEIGHT_H
#define EE205_LAB12A_FATCAT_WEIGHT_H

#include <string>

class Weight {
public: ////////////// Enumerations //////////////
/// A unit of measure for weight
    enum UnitOfWeight {
        POUND, KILO, SLUG
    };
    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND;

    static const std::string POUND_LABEL ;
    static const std::string KILO_LABEL ;
    static const std::string SLUG_LABEL ;

    static float fromKilogramToPound( float kilogram ) noexcept;
    static float fromSlugToPound( float slug ) noexcept;
    static float fromPoundToSlug( float pound ) noexcept;
    static float fromPoundToKilogram( float pound ) noexcept;

    static float convertWeight( float fromWeight
            ,UnitOfWeight fromUnit
            ,UnitOfWeight toUnit ) noexcept;
};
#endif //EE205_LAB12A_FATCAT_WEIGHT_H
