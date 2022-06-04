#include "ProductFood.h"
#include <string>
#include <utility>

using namespace std;

ProductFood::ProductFood() :
                         shelfLife("00/00/0000"),
                         amountCalories(0) {}
ProductFood::ProductFood(const string& name,
                         const string& produceDate,
                         int weight,
                         int price,
                         string shelfLife,
                         int amountCalories) :
                         Product(name, produceDate, weight, price),
                         shelfLife(std::move(shelfLife)),
                         amountCalories(amountCalories) {}


string ProductFood::Info() const {
    string out;

    out = Product::Info() +
          " Expire " + getShelfLife() +
          " Calories: " + to_string(getAmountCalories()) + " kcal";

    return out;
}