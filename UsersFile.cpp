#include "UsersFile.h"


void UsersFile:: addUserToFile(User user)
{
    CMarkup xml;
    bool fileExists = xml.Load( USERS_FILE_NAME );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");

    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname",user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password",user.getPassword());

    xml.Save(USERS_FILE_NAME);
}
 void UsersFile::addAllUsersToFile(vector <User> users)
 {
        CMarkup xml;
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
        xml.FindElem();
        xml.IntoElem();
        for (int i=0; i<users.size(); i++)
        {
            xml.AddElem("User");
            xml.IntoElem();
            xml.AddElem("UserId", users[i].getUserId());
            xml.AddElem("Name", users[i].getName());
            xml.AddElem("Surname",users[i].getSurname());
            xml.AddElem("Login", users[i].getLogin());
            xml.AddElem("Password",users[i].getPassword());
            xml.OutOfElem();
        }
       xml.Save(USERS_FILE_NAME);
}
vector <User> UsersFile::loadUsersFromFile()
{
        vector <User> users;
        User user;
        CMarkup xml;
        bool fileExists = xml.Load( "users.xml" );

        if (fileExists==1)
        {
            xml.ResetPos(); // top of document
            xml.FindElem(); // ORDER element is USERS
            xml.IntoElem(); // inside USERS

            while ( xml.FindElem("User") )
            {
                xml.FindChildElem( "UserId" );
                user.setUserId(AuxiliaryMethods::stringToIntConversion(xml.GetChildData()));
                xml.FindChildElem( "Name");
                user.setName(xml.GetChildData());
                xml.FindChildElem( "Surname");
                user.setSurname(xml.GetChildData());
                xml.FindChildElem( "Login");
                user.setLogin(xml.GetChildData());
                xml.FindChildElem( "Password");
                user.setPassword(xml.GetChildData());
                users.push_back(user);
            }
            return users;
        }
}



