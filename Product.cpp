#include "Product.h"

using namespace std;

Product::Product() :
                 name("Default"),
                 produceDate({00,00,0000}),
                 weight(0),
                 price(0) {}
Product::Product(const string& name,
                 int day, int month, int year,
                 int weight,
                 int price) :
                 name(name),
                 produceDate({day, month, year}),
                 weight(weight),
                 price(price) {}

string Product::Info() const {
    string out;

    out = "Name " + getName() +
          "Produce Date" + to_string(getProduceDate().day) + "/" + to_string(getProduceDate().month) + "/" + to_string(getProduceDate().year) +
          "Weight " + to_string(getWeight()) +
          "Price " + to_string(getPrice());

    return out;
}