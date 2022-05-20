#ifndef CURSOVAYA_YOGURT_H
#define CURSOVAYA_YOGURT_H

#include "Product.h"
#include "ProductFood.h"

class Yogurt : ProductFood{
private:
    int fat;
    string inside;
public:
    Yogurt();
    Yogurt(
            string& name,
            string produceDate,
            int weight,
            int price,
            string shelfLife,
            int amountCalories,
            int fat,
            string inside
            );

    int getFat() const {return fat;}
    string getInside() const {return inside;}

    string Info() const override;

};


#endif //CURSOVAYA_YOGURT_H
