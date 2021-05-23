#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <sstream>
#include <string>
#include "HeaderFile/user.hpp"
#include "HeaderFile/functionLogIn.hpp"
#include "HeaderFile/functionDeposit.hpp"
#include "HeaderFile/functionHistory.hpp"
#include "HeaderFile/functionWithdraw.hpp"

using namespace std;

int main() {
    //Variable
    bool controlLoop = false;
    User currentClient, databaseClient;
    short service = 0, num;
    string path;
    int total = 0, banknote[6], mustMultiple, tempMoney = 0, pause;
    DataOfATM atmData[7];
    //Begin of Login
    while (controlLoop == false) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Welcome" << endl << "Please log in to continue." << endl;
        input(&currentClient);
        checkAvailable(&databaseClient, &currentClient, &controlLoop);
        if (controlLoop == false) continue;
        checkLockList(&databaseClient, &currentClient, &controlLoop);
        if (controlLoop == false) continue;
        checkMatchIDPass(&databaseClient, &currentClient, &controlLoop);
        if (controlLoop == false) continue;
    }
    //End of Login
    //Begin of Menu
    while (controlLoop == true) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Welcome, " << currentClient.ID << ". Thanks for using our Virtual ATM System" << endl;
        cout << "This is the #890996 ATM, what service do you want to use?" << endl;
        cout << "To deposit your money          press 1" << endl;
        cout << "To withdraw your money         press 2" << endl;
        cout << "To see your account history    press 3" << endl;
        cout << "To end this session            press 4" << endl;
        cout << "Your choice: ";
        cin >> service;
        switch (service) {
            //Begin of Deposit
        case 1:
            readATMData(atmData);
            openAccount(&currentClient);
            deposit(banknote, atmData, &total);
            currentBalance(&currentClient, &total);
            writeATMData(atmData);
            reopenMenu(&controlLoop);
            if (controlLoop == false) continue;
            break;
            //End of Deposit
            //Begin of Withdraw
        case 2:
            readATMData(atmData);
            openAccount(&currentClient);
            minMoneyCanWithdraw(atmData, &mustMultiple);
            checkMoneyWithdraw(&tempMoney, &mustMultiple, &controlLoop, &currentClient);
            if (controlLoop == false) continue;
            greedyWithdraw(&tempMoney, &total, atmData, &controlLoop);
            currentBalance(&currentClient, &total);
            writeATMData(atmData);
            reopenMenu(&controlLoop);
            if (controlLoop == false) continue;
            break;
            //End of Withdraw
            //Begin of History
        case 3:
            openAccount(&currentClient);
            getHistory(&currentClient);
            if (controlLoop == false) continue;
            reopenMenu(&controlLoop);
            break;
            //End of History
            //Begin of End
        case 4:
            reopenMenu(&controlLoop);
            break;
            //End of End
        default:
            cout << "Can't recognize your input, please try again." << endl;
            break;
        }
    }
    //End of Menu
    //Begin of Credit
    return 0;
    //End of Credit
}