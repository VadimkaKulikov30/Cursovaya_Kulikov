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
    Milk(const string& nameMilk,
         const string& produceDate,
         int weight,
         int price,
         const string& shelfLife,
         int amountCalories,
         int fat,
         string packageType);

    int getFat() const {return fat;}
    string getPackageType() const {return packageType;}

    string Info() const override;
};


#endif //CURSOVAYA_MILK_H
