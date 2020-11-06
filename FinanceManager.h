#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H
#include <iostream>

#include "ShowMenu.h"
#include "UserManager.h"

using namespace std;

class FinanceManager
{
    ShowMenu showMenu;
    UserManager userManager;

public:
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void userRegistration();
    void displayAllUsers();
    void userSignIn();
    int getSignedUserId();
};
#endif
