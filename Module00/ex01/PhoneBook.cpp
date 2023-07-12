#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdio>

/* Constructor */
PhoneBook::PhoneBook()
{
}

/* Destructor */
PhoneBook::~PhoneBook()
{
}

void PhoneBook::rotateContacts()
{
	for (int i = 0; i < 7; i++)
		PhoneList[i] = PhoneList[i + 1];
}

int PhoneBook::lastContact()
{
	int max;

	max = 0;
	while (PhoneList[i])
	{
		if (PhoneList[i].getIndex() > max)
			max = PhoneList[i].getIndex();
		i++;
	}
	return (max);	
}

std::string ft_readline(std::string prompt)
{
	std::string line;
	std::cout << prompt;
	std::getline(std::cin, line);
	return (line);
}

void PhoneBook::AddContact()
{
	id = lastContact();
	std::string first = ft_readline("Enter first name: ");
	std::string last = ft_readline("Enter last name: ");
	std::string nick = ft_readline("Enter nickname: ");
	std::string number = ft_readline("Enter phone number: ");
	std::string secret = ft_readline("Enter darkest secret: ");
	std::cout << id << std::endl;
	if (id == 7)
	{
		printf("lala\n");
		rotateContacts();
		PhoneList[0].CreateContact(0, first, last, nick, number, secret);
	}
	else
		PhoneList[id].CreateContact(id, first, last, nick, number, secret);
}

//setw minimum number of character positions a variable will consume
void PhoneBook::ShowContacts()
{
	int i = 0;
	int last = lastContact();
	printf("%d\n", last);
	while (i < last)
	{
		std::cout << std::setw(10) << PhoneList[i].getIndex() << "|";
		std::cout << std::setw(10) << PhoneList[i].getFirstName() << "|";
		std::cout << std::setw(10) << PhoneList[i].getLastName() << "|";
		std::cout << std::setw(10) << PhoneList[i].getNickname() << std::endl;
		i++;
	}
}
// Copia do other para o this, assegurando alocacoes de memoria independentes
PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
	if (this != &other) // Verifica se a atribuicao e a dele mesmo
	{
		// Faz uma 'deep copy' dos membros
		for (int i = 0; i < 8; i++)
			PhoneList[i] = other.PhoneList[i];
	}
	return *this;
}