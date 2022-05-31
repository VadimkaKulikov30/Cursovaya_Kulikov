#ifndef CURSOVAYA_YOGURT_H
#define CURSOVAYA_YOGURT_H

#include "Product.h"
#include "ProductFood.h"

class Yogurt : public ProductFood{
private:
    int fat;
    string inside;
public:
    Yogurt();
    Yogurt(
            const string& nameYogurt,
            int day, int month, int year,
            int weight,
            int price,
            int dayShelfLifeYogurt, int monthShelfLifeYogurt, int yearShelfLifeYogurt,
            int amountCalories,
            int fat,
            string inside
            );

    int getFat() const {return fat;}
    string getInside() const {return inside;}

    string Info() const override;
    string Type() const override{return "Yogurt";}

};


#endif //CURSOVAYA_YOGURT_H
