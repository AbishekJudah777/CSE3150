#include <iostream>
#include <string>
#include <cctype>
#include "text_mode.h"

using namespace std;

namespace text_mode
{
	void run(int argc, char *argv[])
	{
		if(argc < 3)
		{
			cout << "Usage: ./analyzer <mode> [arguments]" << endl;
			return;
		}
		else
		{
			std::string text = argv[2];
		       	cout << "Original: " << text << endl;

			std::size_t length = text.size();
			cout << "Length: " << length << endl;


			int alphaCount = 0, digitCount = 0, spaceCount = 0, punctuationCount = 0;

			for(size_t i = 0; i < length; i++)
			{
				if(std::isalpha(text[i]))
					alphaCount++;

				else if(std::isdigit(text[i]))
					digitCount++;

				else if(std::isspace(text[i]))
					spaceCount++;

				else if(std::ispunct(text[i]))
					punctuationCount++;

			}

			cout << "Letters: " << alphaCount << "\ndigits: " << digitCount << "\nSpaces: " << spaceCount 
				<< "\nPunctuation: " << punctuationCount << endl;

			//Converting text to uppercase
			std::string upper_text = "";
			for(char c: text)
			{
				upper_text += toupper(c);
			}
			cout << "Uppercase: " << upper_text << endl; 

			//Converting text to lowercase
			std::string lower_text;
			for(char c: text)
			{
				lower_text += tolower(c);
			}			
			cout << "Lowercase: " << lower_text << endl;

			//Checking if string contains a substring 'test'
			if(lower_text.find("test") != std::string::npos)
				cout << "containstest: yes" << endl;
			else
				cout << "containstest: no" << endl;

			
			size_t space_pos = text.find(' ');
			if(space_pos != std::string::npos)
			{
				cout << "firstword " << text.substr(0, space_pos) << endl;
			}
		}
	}
}
