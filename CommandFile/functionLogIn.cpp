#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "../HeaderFile/functionLogIn.hpp"
#include "../HeaderFile/user.hpp"

using namespace std;

bool checkID (User* databaseClient, User* currentClient) {
    if (databaseClient->ID == currentClient->ID) return true;
        else return false;
}

bool checkPass (User* databaseClient, User* currentClient) {
    if (databaseClient->pass == currentClient->pass && databaseClient->ID == currentClient->ID) return true;
        else return false;
}

void input(User* currentClient) {
    cout << "ID: ";
    cin >> currentClient->ID;
    cout << "Password: ";
    cin >> currentClient->pass;
}


void checkAvailable(User* databaseClient, User* currentClient, bool* controlLoop) {
    fstream loginList;
    loginList.open("Database/Account.txt", fstream::in);
    checkDatabase(&loginList);
    while (!loginList.eof()) {
        loginList >> databaseClient->ID >> databaseClient->pass;
        if(checkID(databaseClient, currentClient)) {
            *controlLoop = true;
            break;
        } else {
            *controlLoop = false;
        }
    }
    if (*controlLoop == false) {
        cout << endl << "The ID is incorrect. ";
        system("pause");
        system("cls");
    }
    loginList.close();
}

void checkLockList(User* databaseClient, User* currentClient, bool* controlLoop) {
    string path = "Database/" + currentClient->ID + "_lockTime.txt";
    fstream loginTime;
    loginTime.open(path, fstream::in);
    checkDatabase(&loginTime);
    loginTime >> currentClient->loginTime;
    loginTime.close();
    if(currentClient->loginTime >= 5) {
        cout << endl << "This Account is locked. ";
        *controlLoop = false;
        system("pause");
        system("cls");
    }
}

void checkMatchIDPass(User* databaseClient, User* currentClient, bool* controlLoop) {
    string path = "Database/" + currentClient->ID + "_lockTime.txt";
    fstream loginList, loginTime;
    loginTime.open(path, fstream::in);
    checkDatabase(&loginTime);
    loginTime >> currentClient->loginTime;
    loginTime.close();
    loginList.open("Database/Account.txt", fstream::in);
    checkDatabase(&loginList);
    while (true) {
        while (!loginList.eof()) {
            loginList >> databaseClient->ID >> databaseClient->pass;
            if (checkPass(databaseClient, currentClient)) {
                *controlLoop = true;
                currentClient->loginTime = 0;
                loginTime.open(path, fstream::trunc | fstream::out);
                checkDatabase(&loginTime);
                loginTime << currentClient->loginTime;
                loginTime.close();
                break;
            }
            else {
                *controlLoop = false;
            }
        }
        if (*controlLoop == true) break;
        else {
            currentClient->loginTime = currentClient->loginTime + 1;
            loginTime.open(path, fstream::trunc | fstream::out);
            checkDatabase(&loginTime);
            loginTime << currentClient->loginTime;
            loginTime.close();
        }
        if (currentClient->loginTime < 5) {
            cout << endl << "The Password is incorrect. ";
            system("pause");
            system("cls");
            cout << "Welcome" << endl << "Please log in to continue." << endl;
            input(currentClient);
        }
        else {
            cout << endl << "This Account will be locked because you tried too many times. ";
            system("pause");
            system("cls");
            *controlLoop = false;
            break;
        }
        loginList.close();
    }
}
