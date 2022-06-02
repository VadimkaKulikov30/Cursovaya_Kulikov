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
            const string& name,
            const string& produceDate,
            int weight,
            int price,
            const string& shelfLife,
            int amountCalories
            );

    string getShelfLife() const {return shelfLife;}
    int getAmountCalories() const {return amountCalories;}

    virtual string Type() const = 0;

    string Info() const override;


};


#endif //CURSOVAYA_PRODUCTFOOD_H
