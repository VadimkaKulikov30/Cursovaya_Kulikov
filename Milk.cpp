#include "Milk.h"

#include <string>

using namespace std;

Milk::Milk() : fat(0), packageType("default") {}
Milk::Milk(string& name, string produceDate, int weight, int price, string shelfLife, int amountCalories, int fat, string packageType) : ProductFood(name, produceDate, weight, price, shelfLife, amountCalories), fat(fat), packageType(packageType) {}

string Milk::Info() const {
    string out;

    out = ProductFood::Info() +
          "Fat: " + to_string(getFat()) +
          "Package Type: " + getPackageType();

    return out;
}