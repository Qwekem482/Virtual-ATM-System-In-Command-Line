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
    string path, servicestr;
    int total = 0, banknote[6], mustMultiple, tempMoney = 0;
    DataOfATM atmData[7];
    //Begin of Login
    while (controlLoop == false) {
        cout << "Welcome" << endl << "Please log in to continue." << endl;
        input(&currentClient);
        checkAvailable(&databaseClient, &currentClient, &controlLoop);
        if (controlLoop == false) {
            cout << endl;
            continue;
        }
        checkLockList(&databaseClient, &currentClient, &controlLoop);
        if (controlLoop == false) {
            cout << endl;
            continue;
        }
        checkMatchIDPass(&databaseClient, &currentClient, &controlLoop);
        if (controlLoop == false) {
            cout << endl;
            continue;
        }
    }
    //End of Login
    //Begin of Menu
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Welcome, " << currentClient.ID << ". Thanks for using our Virtual ATM System" << endl;
    cout << "This is the #890996 ATM. ";
    while (controlLoop == true) {
        cout << "What service do you want to use?" << endl;
        cout << "To deposit your money          press 1" << endl;
        cout << "To withdraw your money         press 2" << endl;
        cout << "To see your account history    press 3" << endl;
        cout << "To see your current balance    press 4" << endl;
        cout << "To end this session            press 5" << endl;
        cout << "Your choice: ";
        cin >> servicestr;
        if ((servicestr != "1" && servicestr != "2") && (servicestr != "3" && servicestr != "4") && servicestr != "5") {
            cout << "Can't recognize your input, please try again." << endl << endl;
        }
        if (servicestr == "1") {
            readATMData(atmData);
            openAccount(&currentClient);
            deposit(banknote, atmData, &total);
            currentBalance(&currentClient, &total);
            writeATMData(atmData);
            reopenMenu(&controlLoop);
            cout << endl;
        }
        if (servicestr == "2") {
            readATMData(atmData);
            openAccount(&currentClient);
            minMoneyCanWithdraw(atmData, &mustMultiple);
            checkMoneyWithdraw(&tempMoney, &mustMultiple, &controlLoop, &currentClient);
            if (controlLoop == false) continue;
            greedyWithdraw(&tempMoney, &total, atmData, &controlLoop);
            currentBalance(&currentClient, &total);
            writeATMData(atmData);
            reopenMenu(&controlLoop);
            cout << endl;
        }
        if (servicestr == "3") {
            openAccount(&currentClient);
            getHistory(&currentClient);
            reopenMenu(&controlLoop);
            cout << endl;
        }
        if (servicestr == "4") {
            openAccount(&currentClient);
            reopenMenu(&controlLoop);
            cout << endl;
        }
        if (servicestr == "5") {
            reopenMenu(&controlLoop);
            cout << endl;
        }
//End of fixs
    }
    //End of Menu
    //Begin of Credit
    return 0;
    //End of Credit
}