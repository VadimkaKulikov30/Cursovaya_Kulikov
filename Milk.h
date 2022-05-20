#ifndef CURSOVAYA_MILK_H
#define CURSOVAYA_MILK_H

#include "Product.h"
#include "ProductFood.h"
#include <string>

using namespace std;

class Milk : ProductFood {
private:
    int fat;
    string packageType;
public:
    Milk();
    Milk(
            string& name,
            string produceDate,
            int weight,
            int price,
            string shelfLife,
            int amountCalories,
            int fat,
            string packageType
            );

    int getFat() const {return fat;}
    string getPackageType() const {return packageType;}

    string Info() const override;
};


#endif //CURSOVAYA_MILK_H
