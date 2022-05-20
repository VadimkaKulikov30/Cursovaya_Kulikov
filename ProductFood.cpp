#include "ProductFood.h"
#include <string>

using namespace std;

ProductFood::ProductFood() : shelfLife("00/00/0000"), amountCalories(0) {}
ProductFood::ProductFood(string& name, string& produceDate, int weight, int price, string& shelfLife, int amountCalories) : Product(name, produceDate, weight, price), shelfLife(shelfLife), amountCalories(amountCalories) {}

string ProductFood::Info() const {
    string out;

    out = Product::Info() +
          "Shelf Life " + shelfLife +
          "Amount calories " + to_string(amountCalories);

    return out;
}