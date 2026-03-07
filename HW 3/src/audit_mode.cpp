#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "audit_mode.h"
#include "validation.h"

using std::cout, std::endl, std::string, std::cin;

namespace audit_mode 
{
	void process_file(string input, string output)
	{
		//Reading from file
		std::ifstream input_file(input);
		if(!input_file)
		{
			cout << "Error opening file" << endl;
			return;
  		}

		//Checking if the file is indeed TSV/CSV
		if(input.size() <= 3)
		{
			cout << "Invalid file" << endl;
			return;
		}

		string username;
		string email;
		string password;

		char input_delimeter = ' ';
		char output_delimeter = ' ';

		//Checking file extension
		input_delimeter = (input.size() > 3 && input.substr(input.size()-3) == "csv") ? ',': '\t' ;
		output_delimeter = (output.size() > 3 && output.substr(output.size()-3) == "csv") ? ',': '\t';		

		//Reading file lines
		while(std::getline(input_file, username, input_delimeter) &&
		std::getline(input_file, email, input_delimeter) &&
		std::getline(input_file, password)) 
		{
			//Checking password validity
			if(!validation::is_valid_password(password))
			{
				//writing in output file
				std::ofstream output_file(output, std::ios::app);
				output_file << username << output_delimeter
					       << email << output_delimeter
					       << password << endl;
			}

		}
		//Exit
	}
	void run_menu()
	{

		int choice = 0;
		do
		{		       
			cout << "1. Check a single password\n"
			     << "2. Process a TSV/CSV file\n"
			     << "3. Quit" << endl;
			std::cin >> choice;	
			cin.ignore();

		if(choice == 3)
			break;

		switch(choice)
		{
			case 1:
				{
					string password;

					cout << "Please enter your password: " << endl;
					std::getline(cin, password);

			                if(validation::is_valid_password(password))
						cout << "Valid" << endl;
					else
						cout << "Invalid" << endl;

					break;
				}
			case 2:
				{
					string input_file = " ";
					string output_file = " ";

					cout << "Please enter the input file: ";
					cin >> input_file;

					cout << "Please enter the output file: ";
					cin >> output_file;
					

					process_file(input_file, output_file);
						
					break;
				}
			default:
				{
					cout << "Invalid choice" << endl;
					break;
				}
			}
		}while(choice != 3);
	}
}
