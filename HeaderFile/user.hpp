#ifndef user_hpp
#define user_hpp

#include <string>

struct User {
    std::string ID;
    std::string pass;
    int money;
};

struct DataOfATM {
    int money;
    int denomination;
};

void confirm(bool* controlLoop);
std::string convertTime(int time);
std::string getTime();
void checkDatabase(std::fstream* list);
void readATMData (DataOfATM atmData[]);
void openAccount (User* currentClient);
void currentBalance (User* currentClient, int* total);
void writeATMData(DataOfATM atmData[]);
void reopenMenu(bool* controlLoop);

#endif