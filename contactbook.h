#ifndef MAX_CONTACTS
#define MAX_CONTACTS 3000



struct Contact

{

    char first[20]; /*First Name*/

    char last[30]; /*Last Name*/

    char areacode[6]; /*Area Code*/

    char number[10]; /*Telephone Number*/

    char email[60]; /*E-Mail*/

    char webaddr[60]; /*Web address of a website -you never know-*/

    char address[60]; /*Home Address*/

};



class ContactBook

{

public:

    Contact contact;

    bool CreateMe(){if(contact.first[0]=='\\') return true; else return false;};

    void Edit();

    void Delete(){contact.first[0]='\\';};

    void Print(bool showall);

    bool SearchContact(char SearchThis[60]);

};

void clearscreen();

void Save();

void Load ();

extern ContactBook book[];



#endif