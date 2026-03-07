#include <cctype>
#include <string>
#include "validation.h"

using std::string;

namespace validation
{
	bool is_valid_password(string password)
	{
		bool valid_size = false;
		bool contains_uppercase = false;
		bool contains_non_alnum = false;

		// Verifying password size
		if(password.size() >= 8)
			valid_size = true;

		//Verifying if password contains uppser case and alphnumer
		for(char c: password)
		{
			if(std::isupper(c))
				contains_uppercase = true;
			if(!std::isalnum(c))
				contains_non_alnum = true;
		}


		//Checking the requiriments
		return (valid_size && contains_uppercase && contains_non_alnum);
	
	}
}
