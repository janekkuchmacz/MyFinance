#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include <vector>
#include<fstream>
#include <cstdlib>
#include "Markup.h"

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UsersFile
{
    const string USERS_FILE_NAME;
public:
    UsersFile():USERS_FILE_NAME("users.xml")
    {

    }
    void addUserToFile(User user);
    void addAllUsersToFile(vector <User> users);
    vector <User> loadUsersFromFile();
};
#endif
