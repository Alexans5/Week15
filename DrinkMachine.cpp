/*  Author: Alex Stewart
    Date: 5/2/24
    Purpose: Create a class that simulates and manages a soft drink machine
*/  

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Drink {
    string name;
    double price;
    int quantity;
};

class DrinkMachine {
private:
    Drink drinks[5] = {
        {"Cola", 1.00, 2},
        {"Root Beer", 1.00, 2},
        {"Orange Soda", 1.00, 2},
        {"Grape Soda", 1.00, 2},
        {"Bottled Water", 1.50, 2},
    };

    double moneyCollected = 0.0;

    double inputMoney(int choice);
    void dailyReport();

public:
    void displayChoices();
    void buyDrink(int choice);
    ~DrinkMachine();
};

void DrinkMachine::displayChoices() {
    cout << "**** Machine Beverage Choices *****\n\n";
    for (int i = 0; i < 5; ++i) {
        cout << "\t" << i + 1 << ") " << drinks[i].name << "  $" << fixed << setprecision(2) << drinks[i].price;
        cout << endl;
    }
    cout << "\t" << "6) Exit" << endl;
}

double DrinkMachine::inputMoney(int choice) {
    double money;
    cout << "\n" << "Please insert sufficient money for your beverage chioce" << "\n" 
        << "(or 0 if you no longer wish to purchase drink). " << endl <<"Enter money now: ";
    cin >> money;
    return money;
}

void DrinkMachine::buyDrink(int choice) {
    if (choice < 1 || choice > 5) {
        cout << "Invalid choice." << endl;
        return;
    }

    choice--;

    if (drinks[choice].quantity <= 0) {
        cout << "\nSorry, that selection is sold out.\n" <<
         "Please retrieve your money from the coin return slot." << endl; 
        return;
    }

    double remainingAmount = drinks[choice].price;
    double amountPaid = 0.0;

    while (remainingAmount > 0) {
        amountPaid = inputMoney(choice);
        remainingAmount -= amountPaid;
        if (remainingAmount > 0) {
            cout << "\nInsufficient money was inserted." << endl;
            cout << "Please retrieve your money from the coin slot." << endl;
            cout << "Then insert enough money for your chosen beverage." << endl;
        }
    }

    double change = amountPaid - drinks[choice].price;
    if (change > 0) {
        cout << "\nReturned change: $" << change << endl;
    }
    cout << "\nThump, thump, thump, splat! Enjoy your beverage" << endl << "\n";
    drinks[choice].quantity--;
    moneyCollected += drinks[choice].price;
}

void DrinkMachine::dailyReport() {
    cout << "**** End of day report**** \n\n";
    cout << "Quantities Remaining in the Machine\n" << endl; 
    for (int i = 0; i < 5; ++i) {
        cout << setw(15) << left << drinks[i].name << drinks[i].quantity << endl;
    }
    cout << "\nDaily earnings: $" << fixed << setprecision(2) << moneyCollected << endl;
}

DrinkMachine::~DrinkMachine() {
    dailyReport();
}

int main() {
    DrinkMachine machine;

    int choice;
    do {
        cout << "\n";
        machine.displayChoices();
        cin >> choice;

        if (choice >= 1 && choice <= 5) {
            machine.buyDrink(choice);
        }
        else if (choice != 6) {
            cout << "Valid choices are 1-6. Please re-enter your choice: ";
            cin >> choice;
        }
        else {
            break;
        }

    } while (true);

    return 0;
}
