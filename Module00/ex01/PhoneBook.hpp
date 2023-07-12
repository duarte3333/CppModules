#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
    private:
        Contact PhoneList[8];
        void rotateContacts(void);
		int lastContact(void);

    public:
		//PhoneBook() = default; //Implementacao implicita do compilador
        ~PhoneBook(void); //Destructor - libertar recursos
        PhoneBook(void); //Copy Constructor - criar instancia com base noutra
		PhoneBook& operator=(const PhoneBook& other); // Copy Assignment Operator
        void AddContact(void);
        void ShowContacts(void);
        void SearchContact(void);
};


#endif