#include "Product.h"

using namespace std;

Product::Product() : name("Default"), produceDate("00/00/0000"), weight(0), price(0) {}
Product::Product(string& Name, string ProduceDate, int weight, int price) : name(name), produceDate(produceDate), weight(weight), price(price) {}

string Product::Info() const {
    string out;

    out = "Name " + getName() +
          "Produce Date" + getProduceDate() +
          "Weight " + to_string(weight) +
          "Price " + to_string(price);

    return out;
}