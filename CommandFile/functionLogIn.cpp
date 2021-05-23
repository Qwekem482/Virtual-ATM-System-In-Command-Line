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

void insertLock(User* currentClient) {
    fstream lockList;
    lockList.open("Database/lockAccount.txt", fstream::out | fstream::app);
    checkDatabase(&lockList);
    lockList << endl << currentClient->ID;
    lockList.close();
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
        cout << endl << "The ID is incorrect, please try again." << endl;
    }
    loginList.close();
}

void checkLockList(User* databaseClient, User* currentClient, bool* controlLoop) {
    fstream lockList;
    lockList.open("Database/lockAccount.txt", fstream::in);
    checkDatabase(&lockList);
    while (!lockList.eof()) {
        lockList >> databaseClient->ID;
        if(checkID(databaseClient, currentClient)) {
            cout << endl << "This Account is locked, please try again." << endl;
            *controlLoop = false;
            break;
        }
    }
    lockList.close();
}

void checkMatchIDPass(User* databaseClient, User* currentClient, bool* controlLoop) {
    fstream loginList;
    loginList.open("Database/Account.txt", fstream::in);
    checkDatabase(&loginList);
    for (int i = 0; i < 5; i++) {
        while(!loginList.eof()) {
            loginList >> databaseClient->ID >> databaseClient->pass;
            if(checkPass(databaseClient, currentClient)) {
                *controlLoop = true;
                break;
            }
            else {
                *controlLoop = false;
            }
        }
        if (*controlLoop == true) break;
        if (i < 4) {
            cout << endl << "The Password is incorrect, please try again." << endl;
            cout << endl << "Welcome" << endl << "Please log in to continue." << endl;
            input(currentClient);
        } else {
            cout << endl << "Your Account will be locked because you tried too many times." << endl;
            insertLock(currentClient);
            *controlLoop = false;
        }
    }
    loginList.close();
}
