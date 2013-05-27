#include <iostream>

#include <cstdlib>

#include <cstdio>

#include <cstring> 

#include <fstream>

#include "contactbook.h"

using namespace std;


void ContactBook::Edit()

{

    cin.get();

    cout << endl << "FirstName: ";

    cin.getline (contact.first,20);

 

    cout << endl << "LastName: ";

    cin.getline (contact.last,30);

 

    cout << endl << "Area Code: ";

    cin.getline (contact.areacode,6);

 

    cout << endl << "Phone Number: ";

    cin.getline (contact.number,10);

 

    cout << endl << "e-mail: ";

    cin.getline (contact.email,60);

 

    cout << endl << "WebAddress: ";

    cin.getline (contact.webaddr,60);



    cout << endl << "HomeAddress: ";

    cin.getline (contact.address,60);

    cout << "OK." << endl;

}

 

void ContactBook::Print(bool showall)

{

    cout << endl << "FirstName: " << contact.first

        << endl << "LastName: " << contact.last;

    if(showall){

        cout << endl << "Area Code: " << contact.areacode

            << endl << "Phone Number: " << contact.number

            << endl << "e-mail: " << contact.email

            << endl << "WebAddress: " << contact.webaddr

            << endl << "HomeAddress: " << contact.address

            << endl << "---" << endl <<  "OK." << endl;

    }

}

 

bool ContactBook::SearchContact(char searchThis[60])

{

    if(!strcmp(contact.first, searchThis)){ return true; }

       else if(!strcmp(contact.last, searchThis)){ return true; }

       else if(!strcmp(contact.areacode, searchThis)){ return true; }

       else if(!strcmp(contact.number, searchThis)){ return true; }

       else if(!strcmp(contact.email, searchThis)){ return true; }

       else if(!strcmp(contact.webaddr, searchThis)){ return true; }

       else if(!strcmp(contact.address, searchThis)){ return true; }

    else {return false;};

}



/*  CLEAR THE SCREEN AND PUT THE HEADER  */

void clearscreen()

{

    system("CLS"); /* Clear the screen */

    cout << "CONTACT_BOOK by Seymur and Hashem" << endl

         << "--------------------------------" << endl << endl;

}

 

ContactBook book[MAX_CONTACTS];

void Save()

{

    ofstream data;

    int i;

    data.open ("data.txt");

    if (data.is_open())

        for (i=0; i < MAX_CONTACTS; i++)

            if (book[i].contact.first[0]!='\\') {

                data << "[USER]\n";

                data<< "FIRST= " << book[i].contact.first<<endl;

                data<< "LAST= " << book[i].contact.last<<endl;

                data<< "AREACODE= " << book[i].contact.areacode<<endl;

                data<< "PHONE NUMBER= " << book[i].contact.number<<endl;

                data<< "EMAIL= " << book[i].contact.email<<endl;

                data<< "WEBADDR= " << book[i].contact.webaddr<<endl;

                data<< "ADDRESS= " << book[i].contact.address<<endl;

                data<< "[ENDUSER]\n\n";

            }

    data.close();

}

 

void Load ()

{

    ifstream data;

    char word[60];

    int i=-1;

    data.open ("data.txt");

 

    if (data.is_open()) {

        data >> word;

 

        while (!data.eof()) {

            if (!strcmp(word,"[USER]")) {

                i++;

                data >> word;

                if (!strcmp(word,"FIRST=")) {

                    book[i].contact.first[0]='\0';

                    data >> word;

                    while (strcmp(word,"LAST=")) {

                        if (book[i].contact.first[0]!='\0')

                            strcat(book[i].contact.first," ");

                        strcat(book[i].contact.first,word);

                        data >> word;

                    }

                    data >> word;

                    while (strcmp(word,"AREACODE=")) {

                        if (book[i].contact.last[0]!='\0')

                            strcat(book[i].contact.last," ");

                        strcat(book[i].contact.last,word);

                        data >> word;

                    }

                    data >> word;

                    while (strcmp(word,"NUMBER=")) {

                        if (book[i].contact.areacode[0]!='\0')

                            strcat(book[i].contact.areacode," ");

                        strcat(book[i].contact.areacode,word);

                        data >> word;

                    }

                    data >> word;

                    while (strcmp(word,"EMAIL=")) {

                        if (book[i].contact.number[0]!='\0')

                            strcat(book[i].contact.number," ");

                        strcat(book[i].contact.number,word);

                        data >> word;

                    }

                    data >> word;

                    while (strcmp(word,"WEBADDR=")) {

                        if (book[i].contact.email[0]!='\0')

                            strcat(book[i].contact.email," ");

                        strcat(book[i].contact.email,word);

                        data >> word;

                    }

                    data >> word;

                    while (strcmp(word,"ADDRESS=")) {

                        if (book[i].contact.webaddr[0]!='\0')

                            strcat(book[i].contact.webaddr," ");

                        strcat(book[i].contact.webaddr,word);

                        data >> word;

                    }

                    data >> word;

                    while (strcmp(word,"[ENDUSER]")) {

                        if (book[i].contact.address[0]!='\0')

                            strcat(book[i].contact.address," ");

                        strcat(book[i].contact.address,word);

                        data >> word;

                    }

                }

            }

            data >> word;

        }

        data.close ();

    }

}
