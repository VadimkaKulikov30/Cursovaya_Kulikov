#include "Product.h"
#include <stdexcept>
#include <utility>
using namespace std;

Product::Product() :
                 name("Default"),
                 produceDate("00/00/0000"),
                 weight(0),
                 price(0) {}
Product::Product(string name,
                 string produceDate,
                 int weight,
                 int price) :
                 name(std::move(name)),
                 produceDate(std::move(produceDate)),
                 weight(weight),
                 price(price) {

}

string Product::Info() const {
    string out;

    out = "Name: " + getName() + "." +
          " Produce date: " + getProduceDate() + "." +
          " Weight: " + to_string(getWeight()) + " grams." +
          " Price: " + to_string(getPrice()) + "$.";

    return out;
}