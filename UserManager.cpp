# include "UserManager.h"

void UserManager:: userRegistration()
{
    User user = enterNewUserData();

    users.push_back(user);

    //plikzUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Registration complited" << endl << endl;
    system("pause");
}
User UserManager::enterNewUserData()
{
    User user;
    user.setUserId(getNewUserId());

    cout<<"Enter your name:";
    user.setName(enterLine());
    cout<<"Enter your surname:";
    user.setSurname(enterLine());

    do
    {
        cout <<  "Enter login: ";
        user.setLogin(enterLine());
    } while (loginExists(user.getLogin()) == true);

    cout << "Enter password: ";
    user.setPassword(enterLine());

    return user;
}
int UserManager:: getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}
 string UserManager:: enterLine()
 {
    string input = "";
    getline(cin, input);
    return input;
 }
bool UserManager::loginExists (string login)
  {

   for (int i=0; i<users.size(); i++)
   {
       if(users[i].getLogin()==login)
       {
            cout << endl << "Login exists!" << endl;
            return true;
       }
   }
   return false;
  }
void UserManager::displayAllUsers()
{
    for (int i=0; i<users.size(); i++)
   {
       cout<<users[i].getUserId()<<endl;
       cout<<users[i].getName()<<endl;
       cout<<users[i].getSurname()<<endl;
       cout<<users[i].getLogin()<<endl;
       cout<<users[i].getPassword()<<endl;
    }
    system ("pause");
}
int UserManager::userSignIn()
{
    User user;
    string login = "", password = "";
    int numberOfAttempts=3;
    cout << endl << "Enter login: ";
    login = enterLine();

    for (int i=0; i<users.size(); i++)
    {
      if (users[i].getLogin() == login)
        {
            for (numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Enter password. Attempts left: " << numberOfAttempts << ": ";
                password = enterLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "You have successfully logged in" << endl << endl;
                    system("pause");
                    signedUserId = users[i].getUserId();
                    break;
                }
            }
            if (numberOfAttempts==0)
            {
                cout << "You entered wrong password 3 times " << endl;
                system("pause");
            }
        }

    }
    if  (signedUserId ==0 && numberOfAttempts==3)
    {
        cout << "You entered wrong login" << endl << endl;
        system("pause");
    }
}
int UserManager::getSignedUserId()
{
    return signedUserId;
}
