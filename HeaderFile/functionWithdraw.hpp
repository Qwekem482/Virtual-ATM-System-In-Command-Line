#ifndef functionWithdraw_hpp
#define functionWithdraw_hpp

#include "../HeaderFile/user.hpp"

void minMoneyCanWithdraw(int* atmData, int* mustMultiple);
void checkMoneyWithdraw(int* tempMoney, int* mustMultiple, bool* controlLoop, User* currentClient);
void greedyWithdraw(int*tempMoney, int* total, int atmData[], int valueATMData[], bool* controlLoop);


#endif