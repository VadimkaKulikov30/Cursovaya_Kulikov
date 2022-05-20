#ifndef CURSOVAYA_SWEET_H
#define CURSOVAYA_SWEET_H

#include "Product.h"
#include "ProductFood.h"
#include <string>

using namespace std;

class Sweet : ProductFood {
private:
    string sweetType;
    string packageType;
public:
    Sweet();
    Sweet(
            string& name,
            string produceDate,
            int weight,
            int price,
            string shelfLife,
            int amountCalories,
            string sweetType,
            string packageType
            );

    string getSweetType() const {return sweetType;}
    string getPackageType() const {return packageType;}

    string Info() const override;
};


#endif //CURSOVAYA_SWEET_H
