#include "ProductFood.h"
#include <string>
#include <stdexcept>

using namespace std;

ProductFood::ProductFood() :
                         shelfLife("00/00/0000"),
                         amountCalories(0) {}
ProductFood::ProductFood(const string& name,
                         const string& produceDate,
                         int weight,
                         int price,
                         const string& shelfLife,
                         int amountCalories) :
                         Product(name, produceDate, weight, price),
                         shelfLife(shelfLife),
                         amountCalories(amountCalories) {}


string ProductFood::Info() const {
    string out;

    out = Product::Info() +
          " Shelf Life: " + getShelfLife() + "." +
          " Amount calories: " + to_string(getAmountCalories()) + ".";

    return out;
}