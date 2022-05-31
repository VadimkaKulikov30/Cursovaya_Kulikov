#ifndef CURSOVAYA_PRODUCTFOOD_H
#define CURSOVAYA_PRODUCTFOOD_H

#include "Product.h"

using namespace std;

class ProductFood : public Product {
protected:
    Date shelfLife;
    int amountCalories;
public:
    ProductFood();
    ProductFood(
            const string& name,
            int day, int month, int year,
            int weight,
            int price,
            int dayShelfLife, int monthShelfLife, int yearShelfLife,
            int amountCalories
            );

    Date getShelfLife() const {return shelfLife;}
    int getAmountCalories() const {return amountCalories;}

    virtual string Type() const = 0;

    string Info() const override;


};


#endif //CURSOVAYA_PRODUCTFOOD_H
