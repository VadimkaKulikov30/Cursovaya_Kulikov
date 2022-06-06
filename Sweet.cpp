#include "Sweet.h"

Sweet::Sweet() :
             sweetType("chocolate"),
             packageType("cardboard") {}
Sweet::Sweet(const string &nameSweet,
             const string& produceDateSweet,
             int weight,
             int price,
             const string& shelfLifeSweet,
             int amountCalories,
             string sweetType,
             string packageType) :
             ProductFood(nameSweet, produceDateSweet, weight, price, shelfLifeSweet, amountCalories),
             sweetType(move(sweetType)),
             packageType(move(packageType)) {
    if(weight < 0){throw invalid_argument(" You entered a sweet weight less than 0");}
    if(price < 0){throw invalid_argument(" You have entered a price for sweet less than 0");}
    if(amountCalories < 0){throw invalid_argument(" You entered the number of calories in sweet is less than 0");}
}

string Sweet::Info() const {
    string out;

    out = ProductFood::Info() +
          " Type " + getSweetType() +
          " Package " + getPackageType();

    return out;
}