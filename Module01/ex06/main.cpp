#include "Harl.hpp"

int main(void)
{
	Harl a;
	std::string messages[7];
	messages[0] = "DEBUG";
	messages[1] = "OLA";
	messages[2] = "INFO";
	messages[3] = "WARNING";
	messages[4] = "ERROR";
	messages[5] = "OI";
	messages[6] = "";

	for (int i = 0; i < 7; i++)
	{
		a.complain(messages[i]);
		std::cout << "---" << std::endl;
	}
}