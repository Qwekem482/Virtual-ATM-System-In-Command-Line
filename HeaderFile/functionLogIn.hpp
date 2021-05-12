#ifndef functionLogIn_hpp
#define functionLogIn_hpp

#include "../HeaderFile/user.hpp"


bool checkID (User* databaseClient, User* currentClient);
bool checkPass (User* databaseClient, User* currentClient);
void input(User* currentClient);
void insertLock(User* currentClient);
void checkAvailable(User* databaseClient, User* currentClient, bool* controlLoop);
void checkLockList(User* databaseClient, User* currentClient, bool* controlLoop);
void checkMatchIDPass(User* databaseClient, User* currentClient, bool* controlLoop);

#endif