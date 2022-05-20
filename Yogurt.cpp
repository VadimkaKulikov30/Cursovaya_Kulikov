#include "Yogurt.h"

#include <string>

using namespace std;

Yogurt::Yogurt() : fat(0), inside("default") {}
Yogurt::Yogurt(string& name, string produceDate, int weight, int price, string shelfLife, int amountCalories, int fat, string inside) : ProductFood(name, produceDate, weight, price, shelfLife, amountCalories), fat(fat), inside(inside) {}

string Yogurt::Info() const {
    string out;

    out = ProductFood::Info() +
          "Fat: " + to_string(getFat()) +
          "Inside: " + getInside();

    return out;
}
