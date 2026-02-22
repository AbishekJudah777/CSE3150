#include <iostream>
#include "stats_mode.h"
#include <string>
#include <set>

using namespace std;

namespace stats_mode
{
 	void run(int argc, char* argv[])
	{
		if(argc < 3)
		{
			cout << "Usage: ./analyzer stat <arg3>" << endl;
			return;
		}

		std::string text = argv[2];

		if(text.empty())
		{
			cout << "Length: 0" << endl;
			cout << "Unique 0" << endl;
			cout << "Alphanumeric: yes" << endl;
			cout << "Reversed: " << endl;
			cout << "Without spaces: " << endl;
			cout << "Lowercase: " << endl;
			cout << "Palindrome: yes" << endl;
			return;

		}

		cout << "Length " << text.size() << endl;

		//Counting Unique Characters
		int unique_count = 0;
		bool uniqueness = false;
		for(size_t i = 0; i < text.size(); i++)
		{
			uniqueness = true;
			for(size_t j = 0; j < i; j++)
			{
				if(text[i] ==text[j])
					uniqueness = false;
			}
			
			if(uniqueness)
				unique_count++;

		}
		
		cout << "unique " << unique_count << endl;


		//Determining is string is alpha numeric only
		int alphanum_count = 0;
		for(char c: text)
		{
			if(isalnum(c))
				alphanum_count++;
		}
		if(alphanum_count == text.size())
			cout << "Alphanumeric: yes" << endl;
		else
			cout << "Alphanumeric: no" << endl;

		//Reversing a string 
		std::string reverse_text = "";
		for(size_t i = 0; i < text.size(); i++)
			reverse_text += text[text.size()-1-i];
		cout << "Reversed: " << reverse_text << endl;

		//Removing white spaces
		std::string non_white_space_string = "";
		for(char c: text)
		{
			if(!std::isspace(c))
				non_white_space_string += c;
		}
		cout << "withoutspaces" << non_white_space_string << endl;

		//Converting string to lower case
		std::string lower_string = "";
		for(char c: non_white_space_string)
		{
			c = std::tolower(c);
			lower_string += c;
		}
		cout << "Lowercase: " << lower_string << endl;

		//Checking palindrome
		bool is_palindrome = true;
		int left = 0, right = lower_string.size()-1;
		while(left < right)
		{
			if(lower_string[left] != lower_string[right])
			{
				is_palindrome = false;
				break;
			}
			left++;
			right--;
		}
		if(is_palindrome)
			cout << "Palindrome: yes" << endl;
		else
			cout << "Palindrome: no" << endl;


	}
 
}
