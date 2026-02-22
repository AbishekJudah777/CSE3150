#include <iostream>
#include "add_mode.h"
#include <string>

using namespace std; 

namespace add_mode
{
	int add(int a, int b)
	{
		return a+b;
	}

	double add(double a, double b)
	{
		return a+b;
	}
	std::string add(std::string a, std::string b)
	{
		return a+b;
	}

	void run(int argc, char* argv[])
	{
		if(argc < 4) 
		{
			cout << "Usage: ./analyzer add <arg3> <arg4>" << endl;
			return;
		}

		int digit1_count = 0, digit2_count = 0;
		bool is_integer_arg1 = false, is_integer_arg2 = false, is_double_arg1 = false, is_double_arg2 = false;

		std::string arg1 = argv[2];
		std::string arg2 = argv[3];

		for(char c: arg1)
		{
			if(std::isdigit(c))
				digit1_count++;
		}	
		

		for(char c: arg2)
		{
			if(std::isdigit(c))
				digit2_count++;
		}

		if(digit1_count == arg1.size())
			is_integer_arg1 = true;
		if(digit2_count == arg2.size())
			is_integer_arg2 = true;

		if(arg1.find('.') != std::string::npos)
			is_double_arg1 = true;
		if(arg2.find('.') != std::string::npos)
			is_double_arg2 = true;


		if(is_integer_arg1 && is_integer_arg2)
		{
			int digit1 = std::stoi(arg1), digit2 = std::stoi(arg2);
			cout << "Result: " << std::to_string(add(digit1, digit2)) << endl;
		}
		else if(is_double_arg1 || is_double_arg2)
		{	
			double digit1 = std::stod(arg1), digit2 = std::stod(arg2);
			cout << "Result: " << std::to_string(add(digit1, digit2)) << endl;
		}
		else
		{
			cout << "Result: " << add(arg1, arg2) <<endl;
		}

	}
}
