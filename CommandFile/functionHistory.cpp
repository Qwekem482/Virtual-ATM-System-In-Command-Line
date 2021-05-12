#include <iostream>
#include <fstream>
#include <string>
#include "../HeaderFile/functionHistory.hpp"
#include "../HeaderFile/user.hpp"

using namespace std;

void getHistory(User* currentClient) {
    string path = "Database/" + currentClient->ID + "_History.txt";
    string content;
    fstream historyFile;
    historyFile.open(path, fstream::in);
    checkDatabase(&historyFile);
    while (!historyFile.eof()) {
        getline(historyFile, content);
        cout << content << endl;
    }
    historyFile.close();
}