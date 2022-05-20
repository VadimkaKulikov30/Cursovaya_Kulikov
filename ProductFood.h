#ifndef CURSOVAYA_PRODUCTFOOD_H
#define CURSOVAYA_PRODUCTFOOD_H

#include "Product.h"

using namespace std;

class ProductFood : public Product {
protected:
    string shelfLife;
    int amountCalories;
public:
    ProductFood();
    ProductFood(
            string& name,
            string& produceDate,
            int weight,
            int price,
            string& shelfLife,
            int amountCalories
            );

    string Info() const override;

    string getShelfLife() {return shelfLife;}
    int getAmountCalories() {return amountCalories;}

    virtual bool ExpiredShelfLife();
};


#endif //CURSOVAYA_PRODUCTFOOD_H
