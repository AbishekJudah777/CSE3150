#include <iostream>
#include <string>
#include "text_mode.h"
#include "add_mode.h"
#include "stats_mode.h"

using namespace std;
using std::string;

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cout << "Usage: ./analyzer <mode> [arguments]" << endl;
		return 1;
	}

	//Converting arg[1] into string
	string mode = argv[1];
	
	int choice = 0;

	if(mode == "text") choice = 1;
	else if(mode == "add") choice = 2;
	else if(mode == "stats") choice = 3;

	/*
	cout << "Choose your Mode" << endl;
	cout << "1. Text" << endl;
	cout << "2. Add" << endl;
	cout << "3. Stats" << endl;
	*/

	switch(choice)
	{
		case 1:
			{
				text_mode::run(argc, argv);
				break;
			}
		case 2: 
			{
				add_mode::run(argc, argv);
				break;
			}
		case 3:
			{
				stats_mode::run(argc, argv);
				break;
			}
		default:
			{
				cout << "Invalid mode" << endl;
				return 1;
			}
	}

	return 0;
}
