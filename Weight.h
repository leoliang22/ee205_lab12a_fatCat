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

private:
    float weight{};
    float maxWeight{};
    bool bIsKnown = false;
    bool bHasMax = false;
    enum UnitOfWeight unitOfWeight = POUND ;

public:


    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND;
    static const float UNKNOWN_WEIGHT;

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


    Weight(UnitOfWeight newUnitOfWeight, const float newMaxWeight );
    Weight() noexcept;
    Weight(float weight);
    Weight(UnitOfWeight newUnitofWeight ) noexcept;
    Weight(float weight, UnitOfWeight unitOfWeight);
    Weight(float weight, float maxWeight);
    Weight(float weight, UnitOfWeight unitOfWeight, float maxWeight);

    bool isWeightKnown() const;
    bool setBIsKnown();

    bool isBHasMax() const;
    void setBHasMax();

    void setWeight(float weight);
    void setMaxWeight(float maxWeight);
    float getWeight() const;
    UnitOfWeight getUnitOfWeight() const;
    void setUnitOfWeight(UnitOfWeight unitOfWeight);
    float getWeight(UnitOfWeight weightUnits) const;
    void setWeight(float newWeight, UnitOfWeight unitOfWeight);
    bool isWeightValid();
    bool Validate();
    float getMaxWeight() const;
    void dump();

    bool operator==( const Weight& rhs_Weight ) const;
    bool operator<( const Weight& rhs_Weight ) const;
    bool operator+=( float rhs_addToWeight ) const;
};



#endif //EE205_LAB12A_FATCAT_WEIGHT_H
