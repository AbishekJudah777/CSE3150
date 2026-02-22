#include <iostream>
#include "while_count_utils.h"

using namespace std;

namespace while_count_utils
{
	void runWhileCount()
	{
		int integer; 

		cout << "Enter a number to count to:" << endl;
		cin >> integer;

		while(integer > 10)
		{
			cout << "I'm programmed to only count up to 10!" << endl;
			cout << "Enter a number to count to:" << endl;
			cin >> integer;
		}

		
		int count = 1;

		while(count <= integer)
		{
			if(count == 5)
			{
				count++;
				continue;
			}

			cout << count << endl;
			count++;

		}
	}
}
