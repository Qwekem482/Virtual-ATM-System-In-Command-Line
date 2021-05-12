#ifndef user_hpp
#define user_hpp

#include <string>

struct User {
    std::string ID;
    std::string pass;
    int money;
};

void confirm(bool* controlLoop);
std::string convertTime(int time);
std::string getTime();
void checkDatabase(std::fstream* list);
void readATMData (int atmData[]);
void openAccount (User* currentClient);
void currentBalance (User* currentClient, int* total);
void writeATMData(int atmData[]);
void reopenMenu(bool* controlLoop);

#endif