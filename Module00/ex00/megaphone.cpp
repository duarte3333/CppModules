#include <iostream>

void myMegaphone(char *str) 
{

	for (int i = 0; str[i]; i++ )
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

int main(int ac, char **av) 
{
	int	i;	

	(void)ac;
	i = 1;
	while (av[i])
	{
		myMegaphone(av[i]);
		std::cout << av[i] ;
		i++;
	}
	std::cout << std::endl;

    return 0;
}
