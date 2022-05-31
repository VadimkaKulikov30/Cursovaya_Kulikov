#include "Yogurt.h"
#include <string>

using namespace std;

Yogurt::Yogurt() :
               fat(0),
               inside("default") {}
Yogurt::Yogurt(const string& nameYogurt,
               int day, int month, int year,
               int weight,
               int price,
               int dayShelfLifeYogurt, int monthShelfLifeYogurt, int yearShelfLifeYogurt,
               int amountCalories,
               int fat,
               string inside) :
               ProductFood(nameYogurt, day, month, year, weight, price, dayShelfLifeYogurt, monthShelfLifeYogurt, yearShelfLifeYogurt, amountCalories),
               fat(fat),
               inside(inside) {}

string Yogurt::Info() const {
    string out;

    out = ProductFood::Info() +
          "Fat: " + to_string(getFat()) +
          "Inside: " + getInside();

    return out;
}
