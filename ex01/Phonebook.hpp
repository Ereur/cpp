#ifndef __PHONEBOOK_H__
#define	__PHONEBOOK_H__
#include <iostream>  

// using namespace std;

class Contact{
	private :
		std::string	First_Name;
		std::string	Last_Name;
		std::string	Nick_Name;
		std::string	Phone_Number;
		std::string	Darkest_Secret;
		void	gad_saf(int i)
		{
			for (int j = 0; j < i; j++)
			{
				std::cout<< " ";
			}
			std::cout<< "|";
		}
		void display_columns()
		{
			std::cout<< "index";
			gad_saf(10 - 5);
			std::cout<< "first name";
			gad_saf(0);
			std::cout<< "last name";
			gad_saf(1);
			std::cout<< "nickname";
			gad_saf(2);
			std::cout<<std::endl;
		}
		
	public :
		Contact()
			: First_Name(""), Last_Name(""), Nick_Name(""), Phone_Number(""), Darkest_Secret("")
		{

		} 
		Contact(std::string& First_Name, std::string& Last_Name, std::string& Nick_Name,
				std::string& Phone_Number, std::string& Darkest_Secret)
			: First_Name(First_Name), Last_Name(Last_Name), Nick_Name(Nick_Name), Phone_Number(Phone_Number), Darkest_Secret(Darkest_Secret)    
		{
		}
		void print_contact(int i)
		{
			if (!i)
				display_columns();
			std::cout<< i ;
			gad_saf(10 - 1);
			this->First_Name.size() >= 10? std::cout<< this->First_Name.substr(0,10) : std::cout<< this->First_Name;
			this->First_Name.size() < 10? gad_saf(10 - this->First_Name.size()):gad_saf(0);
			this->Last_Name.size() >= 10? std::cout<< this->Last_Name.substr(0,10) : std::cout<< this->Last_Name;
			this->Last_Name.size() < 10? gad_saf(10 - this->Last_Name.size()):gad_saf(0);
			this->Nick_Name.size() >= 10? std::cout<< this->Nick_Name.substr(0,10) : std::cout<< this->Nick_Name;
			this->Nick_Name.size() < 10? gad_saf(10 - this->Nick_Name.size()):gad_saf(0);
			std::cout<<std::endl;
		}
};


class Phonebook {
	private :
		Contact contact[9];
		std::string	fields[5];
		int			number_of_contact;
	public :
		Phonebook(std::string init)
			: number_of_contact(0)
		{
			this->fields[0] = "First_Name";
			this->fields[1] = "Last_Name";
			this->fields[2] = "Nick_Name";
			this->fields[3] = "Phone_Number";
			this->fields[4] = "Darkest_Secret";
		}

		void add_contact()
		{
			std::string		command[5];
			for (int i = 0; i < 5; i++)
			{
				std::cout << this->fields[i] << ": " ;
				std::cin >> command[i];
				if (command[i].size() >= 10)
					command[i][9] = '.';
			}
			Contact	s(command[0], command[1], command[2],command[3], command[4]);
			if (number_of_contact == 9)
			{
				this->contact[8] = s;
				return ;	
			}
			this->contact[this->number_of_contact] = s;
			this->number_of_contact++;
		}

		void Search()
		{	
			if (!this->number_of_contact)
				std::cout<< "Phonebook is empty" << std::endl;
			for (int i = 0; i < this->number_of_contact; i++)
			{
				this->contact[i].print_contact(i);
			}
		}
	
};

#endif

