#include <iostream>
#include <fstream>
#include "../HeaderFile/functionWithdraw.hpp"
#include "../HeaderFile/user.hpp"

using namespace std;

void minMoneyCanWithdraw(DataOfATM atmData[], int* mustMultiple) {
    if(atmData[0].money != 0) {
        cout << "The amount withdrawn must be a multiple of 10000 VND" << endl;
        *mustMultiple = 10000;
    } else if(atmData[1].money != 0) {
        cout << "The amount withdrawn must be a multiple of 20000 VND" << endl;
        *mustMultiple = 20000;
    } else if(atmData[2].money != 0) {
        cout << "The amount withdrawn must be a multiple of 50000 VND" << endl;
        *mustMultiple = 50000;
    } else if(atmData[3].money != 0) {
        cout << "The amount withdrawn must be a multiple of 100000 VND" << endl;
        *mustMultiple = 100000;
    } else if(atmData[4].money != 0) {
        cout << "The amount withdrawn must be a multiple of 200000 VND" << endl;
        *mustMultiple = 200000;
    } else if(atmData[5].money != 0) {
        cout << "The amount withdrawn must be a multiple of 500000 VND" << endl;
        *mustMultiple = 500000;
    }
}

void checkMoneyWithdraw(int* tempMoney, int* mustMultiple, bool* controlLoop, User* currentClient) {
    while (*controlLoop == true) {
        cout << "Please enter the amount you want to withdraw: ";
        cin >> *tempMoney;
        if (*tempMoney % *mustMultiple == 0) {
            break;
        } else {
            cout << "The amount must be a multiple of " << *mustMultiple << endl;
            reopenMenu(controlLoop);
            continue;
        }
        if (currentClient->money < *tempMoney) {
            cout << "Insufficient account balance";
            reopenMenu(controlLoop);
            continue;
        }
    }
}

void greedyWithdraw(int*tempMoney, int* total, DataOfATM atmData[], bool* controlLoop) {
    int banknoteWithdraw[6], mustWithdraw = *tempMoney;
    *total = 0;
    if (*tempMoney <= atmData[6].money) {
        for (int i = 5; i >= 0; i--) {
            banknoteWithdraw[i] = mustWithdraw / atmData[i].denomination;
            if (banknoteWithdraw[i] > atmData[i].money) banknoteWithdraw[i] = atmData[i].money;
            *total = *total + banknoteWithdraw[i] * atmData[i].denomination;
            mustWithdraw =  mustWithdraw - banknoteWithdraw[i] * atmData[i].denomination;
            atmData[i].money = atmData[i].money - banknoteWithdraw[i];
        }
    }
    
    if (*total < *tempMoney) {
        cout << "#890996 can't offer this amount. Sorry for the inconvenience, please try again" << endl;
        *total = 0;
    } else {
        cout << "You receive: " << endl;
        for (int i = 0; i < 6; i++) {
            if (i < 3) cout << atmData[i].denomination << "  VND          x" << banknoteWithdraw[i] << endl;
            else cout << atmData[i].denomination << " VND          x" << banknoteWithdraw[i] << endl;
        }
        *total = 0 - *total;
        atmData[6].money = atmData[6].money + *total;
    }
    
}
 
