#include "Product.h"

Product::Product() :
                 name("Default"),
                 produceDate("DD/MM/YYYY"),
                 weight(0),
                 price(0) {}

Product::Product(string name,
                 string produceDate,
                 int weight,
                 int price) :
                 name(move(name)),
                 produceDate(move(produceDate)),
                 weight(weight),
                 price(price) {}

string Product::Info() const {
    string out;

    out = "Name: " + getName() + "." +
          " Produced " + getProduceDate() +
          " Weight: " + to_string(getWeight()) + "(g)" +
          " Price " + to_string(getPrice()) + "$";

    return out;
}