#include "Sweet.h"

#include <string>

using namespace std;

Sweet::Sweet() : sweetType("default"), packageType("default") {}
Sweet::Sweet(string &name, string produceDate, int weight, int price, string shelfLife, int amountCalories, string sweetType, string packageType) : ProductFood(name, produceDate, weight, price, shelfLife, amountCalories), sweetType(sweetType), packageType(packageType) {}

string Sweet::Info() const {
    string out;

    out = ProductFood::Info() +
          "Sweet type: " + getSweetType() +
          "Package type: " + getPackageType();

    return out;
}