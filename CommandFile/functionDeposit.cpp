#include <iostream>
#include <fstream>
#include "../HeaderFile/functionDeposit.hpp"
#include "../HeaderFile/user.hpp"

using namespace std;

void receiveDepositData(int banknote[], DataOfATM atmData[], int i) {
    cin >> banknote[i];
    atmData[i].money = atmData[i].money + banknote[i];
    cout << "You have inserted: ";
}

void deposit(int banknote[], DataOfATM atmData[], int* total) {
    *total = 0;
    cout << "How much do you want to deposit:" << endl;
    for (int i = 0; i <= 5; i++) {
        cout << atmData[i].denomination << "VND:        ";
        receiveDepositData(banknote, atmData, i);
        *total = *total + banknote[i] * atmData[i].denomination;
        cout << *total << " VND" << endl;
    }
    atmData[6].money = atmData[6].money + *total;
}