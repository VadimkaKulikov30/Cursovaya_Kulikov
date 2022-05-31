#include "Milk.h"
#include <stdexcept>
#include <string>

using namespace std;

Milk::Milk() :
           fat(0),
           packageType("default") {}
Milk::Milk(const string& nameMilk,
           int day, int month, int year,
           int weight,
           int price,
           int dayShelfLifeMilk, int monthShelfLifeMilk, int yearShelfLifeMilk,
           int amountCalories,
           int fat,
           string packageType) :
           ProductFood(nameMilk, day, month, year, weight, price, dayShelfLifeMilk, monthShelfLifeMilk, yearShelfLifeMilk, amountCalories),
           fat(fat),
           packageType(packageType) {if(fat < 0 || fat > 100){throw length_error("Wrong fat Milk");}}

string Milk::Info() const {
    string out;

    out = ProductFood::Info() +
          "Fat: " + to_string(getFat()) + "%" +
          "Package Type: " + getPackageType();

    return out;
}

