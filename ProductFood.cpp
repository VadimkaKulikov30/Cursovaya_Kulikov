#include "ProductFood.h"

ProductFood::ProductFood() :
                         shelfLife("DD/MM/YYYY"),
                         amountCalories(500) {}
ProductFood::ProductFood(const string& name,
                         const string& produceDate,
                         int weight,
                         int price,
                         const string& shelfLife,
                         int amountCalories) :
                         Product(name, produceDate, weight, price),
                         shelfLife(shelfLife),
                         amountCalories(amountCalories){
    ProductFood::dateComparison(produceDate, shelfLife);
}

int ProductFood::convertDate(const string& date){
    int day, month, year;
    sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);
    int convertDate = day + month * 100 + year * 10000;
    return convertDate;
}

void ProductFood::dateComparison(const string &ProduceDate, const string &ShelfLife) {
    int produceDate = convertDate(ProduceDate);
    int shelflife = convertDate(ShelfLife);
    if(produceDate > shelflife) {
        throw invalid_argument(" You entered a production date less than the shelf life. This can't be.");
    }
}

bool ProductFood::isShelfLifeGood(const string &currentDate) const {
    int ShelfLife = convertDate(shelfLife);
    int CurrentDate = convertDate(currentDate);
    return ShelfLife >= CurrentDate;
        //if(true){} else throw invalid_argument("dis");
    //else throw invalid_argument("dis");
    //return ShelfLife >= CurrentDate;
}
/*void ProductFood::checkDateShelfLife(const string &date) {
    time_t dateToday;
    char arrayTodayDate[12];
    time(&dateToday);
    strftime(arrayTodayDate, 12, "%d/%m/%Y", localtime(&dateToday));
    if (convertDate(date) < convertDate(arrayTodayDate)){
        throw invalid_argument(" Expiry date less than today date.");
    }
}*/

string ProductFood::Info() const {
    string out;

    out = Product::Info() +
          " Expire " + getShelfLife() +
          " Calories: " + to_string(getAmountCalories()) + " kcal";

    return out;
}

