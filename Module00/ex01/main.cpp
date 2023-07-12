#include "PhoneBook.hpp"
#include <cstdio>

// Função para ler um input em C++
std::string readInput() {
    std::string input;
    std::cout << ">";
    std::getline(std::cin, input);
    return input;
}

/* Compara dois elementos ate um deles acabar */
int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int main(int ac, char **av)
{
	PhoneBook myBook;
	char *input;

	(void)ac;
	(void)av;
	while (1)
	{
		input = const_cast<char*>(readInput().c_str());
		if ((ft_strcmp(input, "ADD") == 0))
			myBook.AddContact();
		else if (ft_strcmp(input, "SEARCH") == 0)
		{
			std::cout << lastContact() << std::endl;
			std::cout << "SEARCH" << std::endl;
			myBook.ShowContacts();
		}
		else if ((ft_strcmp(input, "EXIT") == 0))
			break;
	}
}