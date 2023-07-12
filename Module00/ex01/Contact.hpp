#ifndef CONTACT_HPP
#define CONTACT_HPP
#include "iostream"
#include "iomanip"
#include "string"

class Contact{
private:
	int         index;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
public:
	//Contact() = default; //Default constructor
	Contact(void); //Copy constructor
	~Contact(void); //Destructor
	Contact& operator=(const Contact & other); //Copy Assignment Operator
	int getIndex(void);
	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	void setIndex(int i);
	void CreateContact (int id, std::string first, std::string last, std::string nick, std::string number, std::string secret);
	void DisplayContact(void);
};

#endif