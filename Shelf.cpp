#include "Shelf.h"

Shelf::Shelf() : capacity(5) {}

int Shelf::convertDate(const string& date){
    int day, month, year;
    sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);
    int convertDate = day + month * 100 + year * 10000;
    return convertDate;
}

void Shelf::dateComparison(const string &ProduceDate, const string &ShelfLife) {
    int produceDate = convertDate(ProduceDate);
    int shelfLife = convertDate(ShelfLife);
    if(produceDate > shelfLife) {
        throw invalid_argument(" You entered a production date less than the shelf life. This can't be");
    }
}

void Shelf::addProductFood(const ProductFood* product, int count) {
    if(count < 0) {
        throw invalid_argument(" You have entered a amount of products less than 0. This cannot be.");
    } else if (count > getCapacity()){
        throw invalid_argument(" Initially, there is less space on the shelf than you wanted to add.");
    } else {
        while (count > 0) {
            vecAmountProduct.push_back(product); count--; capacity--;
        }
    }
}

//Checking the product for shelf life.
void Shelf::loseShelfLifeProductFood(const string& date) {
    if(vecAmountProduct.empty()){
        cout << " There are no products on the shelf." << endl;
    } else {
        int todayDate = convertDate(date);
        for (auto product = vecAmountProduct.begin(); product != vecAmountProduct.end();) {
            const ProductFood *productFood = *product;
            int shelfDate = convertDate(productFood->getShelfLife());
            if (todayDate > shelfDate) {
                product = vecAmountProduct.erase(product);
                capacity++;
            } else {
                product++;
            }
        }
    }
}

//Sorting products by price.
bool sortComparatorPriceAscending(const ProductFood * productFirst, const ProductFood * productSecond){return (productFirst->getPrice() < productSecond->getPrice());}
bool sortComparatorPriceDescending(const ProductFood * productFirst, const ProductFood * productSecond) {return (productFirst->getPrice() > productSecond->getPrice());}

void Shelf::sortProductPriceAscending() {
    if(vecAmountProduct.empty()){
        cout << " There are no products on the shelf.\n"
                " You can't sort the product." << endl;
    } else {
        sort(vecAmountProduct.begin(), vecAmountProduct.end(), sortComparatorPriceAscending);
    }
}

void Shelf::sortProductPriceDescending() {
    if(vecAmountProduct.empty()){
        cout << " There are no products on the shelf.\n"
                " You can't sort the product." << endl;
    } else {
        sort(vecAmountProduct.begin(), vecAmountProduct.end(), sortComparatorPriceDescending);
    }
}

//Buying a product by name.
const ProductFood* Shelf::buyProduct(const string &name) {
    if(vecAmountProduct.empty()){
        cout << " There are no products on the shelf." << endl;
    } else {
        for (auto product = vecAmountProduct.begin(); product != vecAmountProduct.end();) {
            const ProductFood *productFood = *product;
            if (productFood->getName() == name) {
                vecAmountProduct.erase(product);
                sumPrice(productFood->getPrice());
                capacity++;
                break;
                //return productFood;
            } else {
                product++;
            }
        }
    }
    return nullptr;
}

//Buying of all products.
const ProductFood* Shelf::buyAllProduct() {
    if(vecAmountProduct.empty()){
        cout << " There are no products on the shelf." << endl;
    } else {
        for (auto product = vecAmountProduct.begin(); product != vecAmountProduct.end();) {
            const ProductFood *productFood = *product;
            vecAmountProduct.erase(product);
            sumPrice(productFood->getPrice());
            capacity++;
        }
    }
    return nullptr;
}

//Checking product for integrity.
const ProductFood* Shelf::checkIntegrity(const string &name) {
    if(vecAmountProduct.empty()) {
        cout << " There are no products on the shelf." << endl;
    } else {
    random_device rd;
    default_random_engine generator(rd());
    for(auto product = vecAmountProduct.begin(); product != vecAmountProduct.end();){
        const ProductFood * productFood = *product;
            if(productFood->getName() == name){
                bernoulli_distribution distribution(0.8);
                if(distribution(generator)){
                    product++;
                } else {
                    vecAmountProduct.erase(product); capacity++;
                }
            } else {
                product++;
            }
        }
        cout << " You checked " << name <<  " for integrity.\n";
    }
    return nullptr;
}

//Printing products on the shelf.
void Shelf::printProductFood() {
    if(vecAmountProduct.empty()){
        cout << " There are no products on the shelf." << endl;
    } else {
        for(auto product : vecAmountProduct){
            cout << product->Info() << endl;
        }
    }
}





