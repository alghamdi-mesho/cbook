#include <iostream>

#include <cstdlib>

#include "contactbook.h"

using namespace std;
 



int main()

{


    char Mnuoption='0';

    int i;

    char buff[60];

    bool found;

 

    for(int j=0; j<MAX_CONTACTS; j++)

        book[j].Delete();

 

    clearscreen();

     

    Load();

     

    while(Mnuoption != '6')

    {

            found=false;

            i=0;

 

            cout << "1. Create New Contact" << endl;

            cout << "2. Edit Contact's data" << endl;

            cout << "3. Delete a Contact" << endl;

            cout << "4. Search a Contact" << endl;

            cout << "5. Save All Data" << endl;

            cout << "6. Terminate program" << endl;

 

        cout << endl << "Selection: ";

        cin >> Mnuoption;

 

        switch(Mnuoption)

        {

            case '1':

 

                do

                {

                    if(book[i].CreateMe()){

                         book[i].Edit();

                         found = true;

                    }

                    i++;

                }while(i < MAX_CONTACTS && !found);

                break;

 

            case '2':

                cout << "Please, give me a name or sth..." << endl;

                cin >> buff;

                if(book[i].SearchContact(buff) && !book[i].CreateMe())

                {

                    cout << endl << "EDITING: ";

                    book[i].Print(false);

                    book[i].Edit();

                }

                else

                {

                    i++;

                }

                break;

 

            case '3':

                cout << "Please, give me a name or sth..." << endl;

                cin >> buff;

                if(book[i].SearchContact(buff) && !book[i].CreateMe())

                {

                    cout << endl << "DELETING: ";

                    book[i].Print(true);

                    cout << endl << "Are you sure? (y/n)";

                    cin >> buff[0];

                    if(buff[0]=='y') book[i].Delete();

                }

                else

                {

                    i++;

                }

                break;

 

            case '4':

                cout << endl << "Search: " << endl;

                cin >> buff;

 

                if(book[i].SearchContact(buff) && !book[i].CreateMe())

                {

                    book[i].Print(true);

                    cout << endl;

                }

                else

                {

                    i++;

                }

                break;

                cout << endl << "Type a number to continue ";

                cin >> i;

 

            case '5':

                Save();

                break;

        }

    }

    cout << endl << endl << "END. " << endl;

    system("PAUSE");

    return 0;

}
