#include <iostream>

#include "integer_utils.h"
#include "string_utils.h"
#include "grade_utils.h"
#include "while_count_utils.h"
#include "do_while_count_utils.h"

using namespace std;

int main()
{
	int option;

	int flag = 0;	

	do
	{
	cout << "1. Integer operations" << endl;
	cout << "2. Character arrays and C-style strings" << endl;
	cout << "3. Grade evaluation" << endl;
	cout << "4. While-loop counting" << endl;
	cout << "5. Do-while and range-based for counting" << endl;
	cout << "6. Quit" << endl;

	cin >> option;

	switch(option)
	{
		case 1:
			integer_utils::runIntegerOption();
			break;
		case 2:
			if(string_utils::runStringOption() == 1)
			{
				flag = 1;
				return 1;
			}
			break;
		case 3:
			if(grade_utils::calculateGrade() < 0)
			{
				flag = 1;
				return 1;
			}	
			break;
		case 4:
			while_count_utils::runWhileCount();
			break;
		case 5:
			do_while_count_utils::runDoWhileCount();
			break;
		case 6:
			cout << "Goodbye!" << endl;
			break;
		default: 
			break;
	}

	} while(option!=6);		

	return flag;
}
