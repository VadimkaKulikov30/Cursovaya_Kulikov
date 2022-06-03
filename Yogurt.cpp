#include "Yogurt.h"
#include <string>
#include <stdexcept>
#include <utility>

using namespace std;

Yogurt::Yogurt() :
               fat(0),
               inside("default") {}
Yogurt::Yogurt(const string& nameYogurt,
               const string& produceDateYogurt,
               int weight,
               int price,
               const string& shelfLifeYogurt,
               int amountCalories,
               int fat,
               string inside) :
               ProductFood(nameYogurt, produceDateYogurt, weight, price, shelfLifeYogurt, amountCalories),
               fat(fat),
               inside(std::move(inside)) {

    if(weight < 0){throw invalid_argument("You entered a yogurt weight less than 0");}
    if(price < 0){throw invalid_argument("You have entered a price for yogurt less than 0");}
    if(amountCalories < 0){throw invalid_argument("You entered the number of calories in yogurt is less than 0");}

    if(fat < 0){throw invalid_argument("You entered yogurt fat content less than 0%");}
    if(fat > 10){throw invalid_argument("You indicated the fat content of yogurt is more than 10%");}
}

string Yogurt::Info() const {
    string out;

    out = ProductFood::Info() +
          " Fat: " + to_string(getFat()) + "%." +
          " Inside: " + getInside() + ".";

    return out;
}
