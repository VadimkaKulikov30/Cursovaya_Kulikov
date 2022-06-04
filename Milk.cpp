#include "Milk.h"
#include <stdexcept>
#include <string>
#include <utility>

using namespace std;

Milk::Milk() :
           fat(0),
           packageType("default") {}
Milk::Milk(const string& nameMilk,
           const string& produceDateMilk,
           int weight,
           int price,
           const string& shelfLifeMilk,
           int amountCalories,
           int fat,
           string packageType) :
           ProductFood(nameMilk, produceDateMilk, weight, price, shelfLifeMilk, amountCalories),
           fat(fat),
           packageType(std::move(packageType)) {
    if(weight < 0){throw invalid_argument("You entered a milk weight less than 0");}
    if(price < 0){throw invalid_argument("You have entered a price for milk less than 0");}
    if(amountCalories < 0){throw invalid_argument("You entered the number of calories in milk is less than 0");}

    if(fat < 0){throw invalid_argument("You entered milk fat content less than 0%");}
    if(fat > 14){throw invalid_argument("You indicated the fat content of milk is more than 14%");}

}

string Milk::Info() const {
    string out;

    out = ProductFood::Info() +
          " Fat: " + to_string(getFat()) + "%" +
          " Package " + getPackageType();

    return out;
}

