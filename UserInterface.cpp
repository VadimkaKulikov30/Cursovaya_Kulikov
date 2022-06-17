#include "UserInterface.h"

void UserInterface::SystemMenu() {
    int weight, fat, price, amountCalories, amount, gain, selection;
    string name, inside, packageType, produceDate, todayDate, shelfLife, sweetType;
    string CurrentDate = "16/06/2022";
    Yogurt *yogurt;
    Milk *milk;
    Sweet *sweet;
    ProductFood productFood;
    Shelf shelf;


        cout << "|=========================================|\n"
                "|       WELCOME TO THE PRODUCT SHOP       |\n";
    do {
        cout << "|=========================================|\n"
                "| Choose product:                         |\n"
                "|=========================================|\n"
                "| 1. Yogurt.                              |\n"
                "| 2. Milk.                                |\n"
                "| 3. Sweet.                               |\n"
                "|=========================================|\n"
                "| Choose method:                          |\n"
                "|=========================================|\n"
                "| 4. Checking the product for shelf life. |\n"
                "| 5. Sorting products on the shelf.       |\n"
                "| 6. Buying products.                     |\n"
                "| 7. Revenue of products sold.            |\n"
                "| 8. Checking product for integrity.      |\n"
                "| 9. Printing products on the shelf.      |\n"
                "|=========================================|\n"
                "| 10. Info Shelf.                         |\n"
                "| 11. Exit the program.                   |\n"
                "| Today date: "; cout << CurrentDate; cout << "                  |\n";
        cout << "|=========================================|\n"
                "| You can choose any of the 11 sub-items  |\n"
                "|   and follow the prompts. Good luck!    |\n"
                "|=========================================|\n";

        cout << "\nEnter your selection:\n"; cin >> selection;
        switch (selection) {
            case 1:
                try {
                    cout << "You chose yogurt, let's add it to the shelf.\n";
                    cout << "Enter the name of the yogurt:\n"; cin.ignore(); getline(cin, name);
                    cout << "Production date input format example: DD/MM/YYYY.\n";
                    cout << "Enter production date:\n"; cin.ignore(); getline(cin, produceDate);
                    cout << "Weight is calculated in grams and cannot be less than 0.\n";
                    cout << "Enter weight:\n"; cin >> weight;
                    cout << "The price is calculated in dollars and cannot be less than 0.\n";
                    cout << "Enter price:\n"; cin >> price;
                    cout << "Shelf life input format example: DD/MM/YYYY.\n";
                    cout << "Enter shelf life:\n"; cin.ignore(); getline(cin, shelfLife);
                    cout << "Calories are counted in kcal and cannot be less than 0.\n";
                    cout << "Enter amount calories:\n"; cin >> amountCalories;
                    cout << "The fat content of yogurt is not less than 0% and not more than 10%.\n";
                    cout << "Enter fat:\n"; cin >> fat;
                    cout << "The inside of yogurt can be for example pineapple, mango, apple and other fruits.\n";
                    cout << "Enter the inside of the yogurt:\n"; cin.ignore(); getline(cin, inside);
                    cout << "Seats on the shelf now: " << shelf.getCapacity() << ".\n";
                    cout << "Enter amount of product:\n"; cin >> amount;

                    yogurt = new Yogurt(name, produceDate, weight, price, shelfLife, amountCalories, fat, inside);
                    shelf.addProductFood(yogurt, amount);
                    if(amount > 1){
                        cout << " " << amount << " yogurts have been added to the shelf.\n";
                    } else {
                        cout << " " << amount << " yogurt have been added to the shelf.\n";
                    }
                } catch (exception &ex) {
                    cout << ex.what() << endl;
                }
                break;
            case 2:
                try {
                    cout << "You chose milk, let's add it to the shelf.\n";
                    cout << "Enter the name of the milk:\n"; cin.ignore(); getline(cin, name);
                    cout << "Production date input format example: DD/MM/YYYY.\n";
                    cout << "Enter production date:\n"; cin.ignore(); getline(cin, produceDate);
                    cout << "Weight is calculated in grams and cannot be less than 0.\n";
                    cout << "Enter weight:\n"; cin >> weight;
                    cout << "The price is calculated in dollars and cannot be less than 0.\n";
                    cout << "Enter price:\n"; cin >> price;
                    cout << "Shelf life input format example: DD/MM/YYYY.\n";
                    cout << "Enter shelf life:\n"; cin.ignore(); getline(cin, shelfLife);
                    cout << "Calories are counted in kcal and cannot be less than 0.\n";
                    cout << "Enter amount calories:\n"; cin >> amountCalories;
                    cout << "The fat content of yogurt is not less than 0% and not more than 14%.\n";
                    cout << "Enter fat:\n"; cin >> fat;
                    cout << "Milk is stored in a package.\n"
                            "For example cardboard, bottle, glass and others.\n";
                    cout << "Enter package type:\n"; cin.ignore(); getline(cin, packageType);
                    cout << "Seats on the shelf now: " << shelf.getCapacity() << ".\n";
                    cout << "Enter amount of product:\n"; cin >> amount;

                    milk = new Milk(name, produceDate, weight, price, shelfLife, amountCalories, fat, packageType);
                    shelf.addProductFood(milk, amount);
                    cout << " " << amount << " milk " << packageType << " have been added to the shelf.\n";
                } catch (exception &ex) {
                    cout << ex.what() << endl;
                }
                break;
            case 3:
                try {
                    cout << "You chose sweet, let's add it to the shelf.\n";
                    cout << "Enter the name of the sweet:\n"; cin.ignore(); getline(cin, name);
                    cout << "Production date input format example: DD/MM/YYYY.\n";
                    cout << "Enter production date:\n"; cin.ignore(); getline(cin, produceDate);
                    cout << "Weight is calculated in grams and cannot be less than 0.\n";
                    cout << "Enter weight:\n"; cin >> weight;
                    cout << "The price is calculated in dollars and cannot be less than 0.\n";
                    cout << "Enter price:\n"; cin >> price;
                    cout << "Shelf life input format example: DD/MM/YYYY.\n";
                    cout << "Enter shelf life:\n"; cin.ignore(); getline(cin, shelfLife);
                    cout << "Calories are counted in kcal and cannot be less than 0.\n";
                    cout << "Enter amount calories:\n"; cin >> amountCalories;
                    cout << "You can choose different type of sweets.\n"
                            "For example chocolate, candy, marshmallows, waffles and others.\n";
                    cout << "Enter sweet type:\n"; cin.ignore(); getline(cin, sweetType);
                    cout << "Sweet is stored in a package.\n"
                            "For example cardboard, foil, box and others.\n";
                    cout << "Enter package type:\n"; cin.ignore(); getline(cin, packageType);
                    cout << "Seats on the shelf now: " << shelf.getCapacity() << ".\n";
                    cout << "Enter amount of product:\n"; cin >> amount;

                    sweet = new Sweet(name, produceDate, weight, price, shelfLife, amountCalories, sweetType, packageType);
                    shelf.addProductFood(sweet, amount);
                    cout << " " << amount << " " << sweetType << " in a " << packageType << " added to the shelf.\n";
                } catch (exception& ex){
                    cout << ex.what() << endl;
                }
                break;
            case 4:
                cout << "Check the shelf life of the products added to the shelf.\n";
                shelf.loseShelfLifeProductFood(CurrentDate);
                break;
            case 5:
                cout << "This sub-item sorts the products on the shelf.\n"
                        "You can sort products by price."; cout << endl;
                do {
                    cout << "\nYou can sort products in ascending order by pressing - 1.\n"
                            "You can sort products in descending order by pressing - 2.\n"
                            "You can exit by pressing - 3.\n"
                            "\nEnter your choice:\n"; cin >> selection;
                    switch(selection) {
                        case 1:
                            shelf.sortProductPriceAscending();
                            break;
                        case 2:
                            shelf.sortProductPriceDescending();
                            break;
                        case 3:
                            cout << " You left case 5.\n";
                            break;
                        default:
                            cout << "\n";
                    }
                } while(selection != 3);
                break;
            case 6:
                cout << "In this subsection, you can buy a product that is on the shelf.\n";
                do {
                    cout << "\nYou can buy a product by name by pressing - 1.\n"
                            "You can buy all products at once by pressing - 2.\n"
                            "You can exit by pressing - 3.\n"
                            "\nEnter your choice:\n"; cin >> selection;
                    switch(selection){
                        case 1:
                            cout << "Enter product name:\n"; cin.ignore(); getline(cin, name);
                            shelf.buyProduct(name);
                            break;
                        case 2:
                            shelf.buyAllProduct();
                            break;
                        case 3:
                            cout << " You left case 6.\n";
                            break;
                        default:
                            cout << "\n";
                    }
                } while(selection != 3);
                break;
            case 7:
                if(shelf.getAmountMoney() == 0){
                    cout << " You haven't sold a single product." << "\n";
                } else {
                    cout << " You have sold products worth " << shelf.getAmountMoney() << " $\n";
                }
                break;
            case 8:
                cout << "In this subsection you can check the products for integrity.\n";
                do {
                    cout << "\nYou can check product for integrity by name by pressing - 1.\n"
                            "You can check all products for integrity at once by pressing - 2.\n"
                            "You can exit by pressing - 3.\n"
                            "\nEnter your choice:\n"; cin >> selection;
                    switch(selection){
                        case 1:
                            cout << "Enter product name:\n"; cin.ignore(); getline(cin, name);
                            shelf.checkIntegrity(name);
                            break;
                        case 2:
                            shelf.checkAllIntegrity();
                            break;
                        case 3:
                            cout << " You left case 8.\n";
                            break;
                        default:
                            cout << "\n";
                    }
                } while(selection != 3);
                break;
            case 9:
                cout << " Products on the shelf:\n";
                shelf.printProductFood();
                break;
            case 10:
                do{
                    cout << "\nYou can increase the number of shelf spaces by pressing - 1.\n"
                            "You can decrease the number of shelf spaces by pressing - 2.\n"
                            "You can view the default number of shelf slots by pressing - 3.\n"
                            "You can exit by pressing - 4.\n"
                            "\nEnter your choice:\n"; cin >> selection;
                    switch (selection) {
                        case 1:
                            cout << "Enter gain: " << "\n"; cin >> gain;
                            shelf.setCapacityIncrease(gain);
                            break;
                        case 2:
                            cout << "Enter gain: " << "\n"; cin >> gain;
                            if(gain > shelf.getCapacity()){
                                cout << "You can't make the shelf capacity less than zero." << "\n";
                            } else {
                                shelf.setCapacityReduce(gain);
                            }
                            break;
                        case 3:
                            cout << "Seats on the shelf now: " << shelf.getCapacity() << ".\n";
                            break;
                        case 4:
                            cout << " You left case 10.\n";
                            break;
                        default:
                            cout << "\n";
                    }
                } while(selection != 4);
                break;
            case 11:
                cout << "\nThank you for using the program. Goodbye!\n";
                exit(0);
            default:
                cout << "\nYou made the wrong choice.\n";
        }
    } while(selection != 0);
}