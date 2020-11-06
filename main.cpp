#include <iostream>
#include "FinanceManager.h"

using namespace std;

int main()
{
    FinanceManager financeManager;
    char choice;
    while (true)
    {
        if (financeManager.getSignedUserId() == 0)
        {
            choice = financeManager.chooseOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                financeManager. userRegistration();
                //financeManager. displayAllUsers();
                break;
            case '2':
                  financeManager. userSignIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Choose correct option, please" << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {

       choice = financeManager.chooseOptionFromUserMenu();


            switch (choice)
            {
            case '1':
                //ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                //ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                //ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
               // ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
               // ksiazkaAdresowa.usunAdresata();
                //idUsunietegoAdresata = usunAdresata(adresaci);
                //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                //ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                //ksiazkaAdresowa.edytujAdresata();
                break;
            }
        }
    }

    return 0;
}

