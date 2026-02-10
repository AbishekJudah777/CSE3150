#include <iostream>
#include <string>
#include "string_utils.h"

using namespace std;

namespace string_utils
{
	/*
	 * This function takes in the string lenght as an input. 
	 * Ensure the limit of string lenght, if the string length exceeds the limit, then it outputs an error.
	 * Takes in the string as an input
	 * A character array is  created and copies the characters from the string.
	 * A Null terminator is added in the end of the character array, to signify the end.
	 * The final character array is printed out as a string
	 */

	int runStringOption()
	{
		int string_length = 0;

		cout << "Enter string length: " << endl;
		cin >> string_length;

		if(string_length >= 20)
		{
			cout << "Error: String length greater than 20" << endl;
			return 1;
		}

		cin.ignore();

		cout << "Enter string: " << endl;
		string input; 
	        getline(cin, input);

			
		char array[20];

		for(int i = 0; i < string_length; i++)
		{
			    array[i] = input[i];
		}

		array[string_length] = '\0';

		cout << "C-style string: " << array << endl; 

		return 0;

	}
}
