#include "Contact.hpp"

/* Constructor */
Contact::Contact() {
    this->index = 0;
}

/* Destructor */
Contact::~Contact(){
}

/* Copy Constructor.
Copia do other para o this, assegurando alocacoes de memoria independentes */
Contact& Contact::operator=(const Contact& other)
{
   if (this != &other) // Verifica se a atribuicao e a dele mesmo
   {
      // Faz uma 'deep copy' dos membros
      firstName = other.firstName;
      lastName = other.lastName;
      nickname = other.nickname;
	  phoneNumber = other.phoneNumber;
      darkestSecret = other.darkestSecret;
   }
   return *this;
}

void Contact::setIndex(int i) {
    this->index = i;
}

int Contact::getIndex() {
    return (this->index);
}

std::string Contact::getFirstName() {
    return (this->firstName);
}

std::string Contact::getLastName() {
	return (this->lastName);
}

std::string Contact::getNickname() {
	return (this->nickname);
}

void Contact::CreateContact (int id, std::string first, std::string last, std::string nick, std::string number, std::string secret) {
    this->index = id;
    this->firstName = first;
    this->lastName = last;
    this->nickname = nick;
    this->phoneNumber = number;
    this->darkestSecret = secret;
}

void Contact::DisplayContact() {
    std::cout << this->firstName << std::endl;
    std::cout << this->lastName << std::endl;
    std::cout << this->nickname << std::endl;
    std::cout << this->phoneNumber << std::endl;
    std::cout << this->darkestSecret << std::endl;
}