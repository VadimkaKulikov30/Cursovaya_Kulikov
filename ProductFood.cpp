#include "ProductFood.h"
#include <string>

using namespace std;

ProductFood::ProductFood() :
                         shelfLife({00, 00, 0000}),
                         amountCalories(0) {}
ProductFood::ProductFood(const string& name,
                         int day, int month, int year,
                         int weight,
                         int price,
                         int dayShelfLife, int monthShelfLife, int yearShelfLife,
                         int amountCalories) :
                         Product(name,day,month,year, weight, price),
                         shelfLife({dayShelfLife, monthShelfLife, yearShelfLife}),
                         amountCalories(amountCalories) {}

string ProductFood::Info() const {
    string out;

    out = Product::Info() +
          "Shelf Life " + to_string(getShelfLife().day) + "/" + to_string(getShelfLife().month) + "/" + to_string(getShelfLife().year) +
          "Amount calories " + to_string(getAmountCalories());

    return out;
}