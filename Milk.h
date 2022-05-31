#ifndef CURSOVAYA_MILK_H
#define CURSOVAYA_MILK_H

#include "Product.h"
#include "ProductFood.h"
#include <string>

using namespace std;

class Milk : public ProductFood {
private:
    int fat;
    string packageType;
public:
    Milk();
    Milk(
          const string& nameMilk,
          int day, int month, int year,
          int weight,
          int price,
          int dayShelfLifeMilk, int monthShelfLifeMilk, int yearShelfLifeMilk,
          int amountCalories,
          int fat,
          string packageType
          );

    int getFat() const {return fat;}
    string getPackageType() const {return packageType;}

    string Info() const override;
    string Type() const override{return "Milk";}
};


#endif //CURSOVAYA_MILK_H
