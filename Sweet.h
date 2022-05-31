#ifndef CURSOVAYA_SWEET_H
#define CURSOVAYA_SWEET_H

#include "Product.h"
#include "ProductFood.h"
#include <string>

using namespace std;

class Sweet : public ProductFood {
private:
    string sweetType;
    string packageType;
public:
    Sweet();
    Sweet(
           const string& nameSweet,
           int day, int month, int year,
           int weight,
           int price,
           int dayShelfLifeSweet, int monthShelfLifeSweet, int yearShelfLifeSweet,
           int amountCalories,
           string sweetType,
           string packageType
           );

    string getSweetType() const {return sweetType;}
    string getPackageType() const {return packageType;}

    string Info() const override;
    string Type() const override{return "Sweet";}
};


#endif //CURSOVAYA_SWEET_H
