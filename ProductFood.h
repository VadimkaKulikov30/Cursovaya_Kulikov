#ifndef CURSOVAYA_PRODUCTFOOD_H
#define CURSOVAYA_PRODUCTFOOD_H

#include "Product.h"

class ProductFood : public Product {
private:
    string shelfLife;
    int amountCalories;
public:
    ProductFood();
    ProductFood(const string& name,
                const string& produceDate,
                int weight,
                int price,
                string shelfLife,
                int amountCalories);

    int convertDate(const string& date);
    void dateComparison(const string& ProduceDate, const string& ShelfLife);
    void checkDate(const string& date);
    string getShelfLife() const {return shelfLife;}
    int getAmountCalories() const {return amountCalories;}

    string Info() const override;


};


#endif //CURSOVAYA_PRODUCTFOOD_H
