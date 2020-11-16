#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include<fstream>
#include<sstream>

#include "User.h"
#include "UsersFile.h"


using namespace std;

class UserManager
{
        int signedUserId;
        vector <User> users;

        User enterNewUserData();
        int getNewUserId();
        string enterLine();
        bool loginExists (string login);

        UsersFile usersFile;

    public:
        UserManager ()
        {
           signedUserId=0;
           users=usersFile.loadUsersFromFile();
        }
        void userRegistration();
        void displayAllUsers();
        int userSignIn();
        int getSignedUserId();
        void setSignedUserId(int newUserId);
        void passwordChange();
        bool userSignedIn();


};

#endif
