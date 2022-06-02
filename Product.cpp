#include "Product.h"
#include <stdexcept>
using namespace std;

Product::Product() :
                 name("Default"),
                 produceDate("00/00/0000"),
                 weight(0),
                 price(0) {}
Product::Product(const string& name,
                 const string& produceDate,
                 int weight,
                 int price) :
                 name(name),
                 produceDate(produceDate),
                 weight(weight),
                 price(price) {

}

string Product::Info() const {
    string out;

    out = "Name: " + getName() + "." +
          " Produce date: " + getProduceDate() + "." +
          " Weight: " + to_string(getWeight()) + "." +
          " Price: " + to_string(getPrice()) + ".";

    return out;
}