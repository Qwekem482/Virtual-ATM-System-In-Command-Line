#include <iostream>
#include <fstream>
#include "../HeaderFile/functionDeposit.hpp"
#include "../HeaderFile/user.hpp"

using namespace std;

void receiveDepositData(int banknote[], int atmData[], int i) {
    cin >> banknote[i];
    atmData[i] = atmData[i] + banknote[i];
    cout << "You have ";
}

void deposit(int banknote[], int atmData[], int* total) {
    cout << "How much do you want to deposit (Enter the denominations):" << endl;
    for (int i = 0; i <= 6; i++) {
        switch(i) {
            case 0:
                cout << "10000 VND: ";
                receiveDepositData(banknote, atmData, i);
                *total = *total + banknote[i] * 10000;
                cout << "inserted " << *total << " VND" << endl;
                break;
            case 1:
                cout << "20000 VND: ";
                receiveDepositData(banknote, atmData, i);
                *total = *total + banknote[i] * 20000;
                cout << "inserted " << *total << " VND" << endl;
                break;
            case 2:
                cout << "50000 VND: ";
                receiveDepositData(banknote, atmData, i);
                *total = *total + banknote[i] * 50000;
                cout << "inserted " << *total << " VND" << endl;
                break;
            case 3:
                cout << "100000 VND: ";
                receiveDepositData(banknote, atmData, i);
                *total = *total + banknote[i] * 100000;
                cout << "inserted " << *total << " VND" << endl;
                break;
            case 4:
                cout << "200000 VND: ";
                receiveDepositData(banknote, atmData, i);
                *total = *total + banknote[i] * 200000;
                cout << "inserted " << *total << " VND" << endl;
                break;
            case 5:
                cout << "500000 VND: ";
                receiveDepositData(banknote, atmData, i);
                *total = *total + banknote[i] * 500000;
                cout << "inserted " << *total << " VND" << endl;
                break;
            case 6:
                atmData[i] = atmData[i] + *total;
                break;
            default:
                break;
        }
    }
}