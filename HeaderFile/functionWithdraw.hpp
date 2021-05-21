#ifndef functionWithdraw_hpp
#define functionWithdraw_hpp

#include "../HeaderFile/user.hpp"

void minMoneyCanWithdraw(DataOfATM atmData[], int* mustMultiple);
void checkMoneyWithdraw(int* tempMoney, int* mustMultiple, bool* controlLoop, User* currentClient);
void greedyWithdraw(int*tempMoney, int* total, DataOfATM atmData[], bool* controlLoop);


#endif