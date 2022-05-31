#ifndef CURSOVAYA_PRODUCT_H
#define CURSOVAYA_PRODUCT_H

#include <string>

using namespace std;

struct Date{
    int day, month, year;
};

class Product {
private:
    string name;
    int weight, price;
protected:
    Date produceDate;
public:
    Product();
    Product(
            const string& name,
            int dayProduceDate, int monthProduceDate, int yearProduceDate,
            int weight,
            int price
            );

    string getName() const {return name;}
    Date getProduceDate() const {return produceDate;}
    int getWeight() const {return weight;}
    int getPrice() const {return price;}

    virtual string Info() const;

};


#endif //CURSOVAYA_PRODUCT_H
