#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <sstream>
#include <string>
#include "../HeaderFile/user.hpp"

using namespace std;

string convertTime(int time) {
    string timeString;
    stringstream ss;                                        //convert from int to string
    ss << time;
    if (time < 10) {
        timeString = "0" + ss.str();
    } else {
        timeString = ss.str();
    }
    return timeString;
}

string getTime() {
    string historyTime;
    time_t now = time(0);
    tm* localTime = localtime(&now);
    historyTime = convertTime(localTime->tm_hour) + ":" + convertTime(1 + localTime->tm_min) + ":" + convertTime(1 + localTime->tm_sec) + " ";
    historyTime = historyTime + convertTime(localTime->tm_mday) + "/" + convertTime(1 + localTime->tm_mon) + "/" + convertTime(1900 + localTime->tm_year) + "        ";
    return historyTime;
}

void checkDatabase(fstream* list) {
    if (list->is_open() == false) {
        char pause;
        cout << endl << "Critical Error: Database badly damaged." << endl;
        system("pause");
        exit(EXIT_FAILURE);
    }
}

void readATMData (DataOfATM atmData[]) {
    fstream atmMoney;
    atmMoney.open("Database/atmMoney.txt", fstream::in);
    checkDatabase(&atmMoney);
    for (int i = 0; i <= 6; i++) {
        atmMoney >> atmData[i].denomination >> atmData[i].money;
    }
    atmMoney.close();
}

void openAccount (User* currentClient) {
    string path = "Database/" + currentClient->ID + ".txt";
    fstream account;
    account.open(path, fstream::in);
    account >> currentClient->money;
    cout << endl << "Your account balance: " << currentClient->money << endl;
    account.close();
}

void currentBalance (User* currentClient, int* total) {
    string pathHistory = "Database/" + currentClient->ID + "_History.txt";
    string pathInfo = "Database/" + currentClient->ID + ".txt";
    currentClient->money = currentClient->money + *total;
    cout << endl << "Your account balance: " << currentClient->money << endl;
    fstream history, accountInfo;
    history.open(pathHistory, fstream::out | fstream::app);
    checkDatabase(&history);
    if (*total > 0) {
        history << getTime() << "+" << *total << " VND" << endl;
    } else {
        history << getTime() << *total << " VND" << endl;
    }
    history.close();
    accountInfo.open(pathInfo, fstream::out | fstream::trunc);
    checkDatabase(&accountInfo);
    accountInfo << currentClient->money << endl;
    accountInfo.close();
}

void writeATMData(DataOfATM atmData[]) {
    fstream atmMoney;
    atmMoney.open("Database/atmMoney.txt", fstream::trunc | fstream::out);
    checkDatabase(&atmMoney);
    for (int i = 0; i <= 6; i++) atmMoney << atmData[i].denomination << " " << atmData[i].money << endl;
    atmMoney.close();
}

void reopenMenu(bool* controlLoop) {
    string c;
    cout << endl << "Thanks for using our service. If you really want to..." << endl;
    cout << "End this session           press 1" << endl;
    cout << "Continue this session      press 2" << endl;
    while (true) {
        cout << "Your choice: ";
        cin >> c;
        if (c == "1") {
            *controlLoop = false;
            break;
        }
        else if (c == "2") {
            *controlLoop = true;
            system("cls");
            break;
        }
        else {
            cout << "Can't recognize your input, please try again." << endl;
        }
    }

}