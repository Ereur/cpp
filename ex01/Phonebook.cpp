// # include <string.h>
# include "Phonebook.hpp"

int main()
{
	Contact			test[5];
	Phonebook		one("init");
	std::string		command;

	while (1)
	{
		std::cout << "enter command : ";
		std::cin >> command;
		if (!command.compare("ADD"))
		{
			one.add_contact();
		}
		else if (!command.compare("SEARCH"))
		{
			one.Search();
		}
		else if (!command.compare("EXIT"))
		{
			exit(1);
		}
		else
			std::cout<< std::endl;
	}
}
