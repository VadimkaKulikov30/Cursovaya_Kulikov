#include "Sweet.h"

#include <string>

using namespace std;

Sweet::Sweet() :
             sweetType("default"),
             packageType("default") {}
Sweet::Sweet(const string &nameSweet,
             int day, int month, int year,
             int weight,
             int price,
             int dayShelfLifeSweet, int monthShelfLifeSweet, int yearShelfLifeSweet,
             int amountCalories,
             string sweetType,
             string packageType) :
             ProductFood(nameSweet, day, month, year, weight, price, dayShelfLifeSweet, monthShelfLifeSweet, yearShelfLifeSweet, amountCalories),
             sweetType(sweetType),
             packageType(packageType) {}

string Sweet::Info() const {
    string out;

    out = ProductFood::Info() +
          "Sweet type: " + getSweetType() +
          "Package type: " + getPackageType();

    return out;
}