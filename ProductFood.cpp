#include "ProductFood.h"

ProductFood::ProductFood() :
                         shelfLife("DD/MM/YYYY"),
                         amountCalories(500) {}
ProductFood::ProductFood(const string& name,
                         const string& produceDate,
                         int weight,
                         int price,
                         string shelfLife,
                         int amountCalories) :
                         Product(name, produceDate, weight, price),
                         shelfLife(move(shelfLife)),
                         amountCalories(amountCalories) {}

string ProductFood::Info() const {
    string out;

    out = Product::Info() +
          " Expire " + getShelfLife() +
          " Calories: " + to_string(getAmountCalories()) + " kcal";

    return out;
}