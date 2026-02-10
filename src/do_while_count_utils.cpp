#include <iostream>
#include "do_while_count_utils.h"

using namespace std;

namespace do_while_count_utils
{
	void runDoWhileCount()
	{
		int i;
		const int values[] = {1, 2, 3, 4, 5};
		do
		{
			cout << "Enter a number between 1 and 5:" << endl;
			cin >> i;
		}while(i < 1 || i > 5);

		for(int value: values)
		{
			cout << "Value: " << value << endl;

			if(i == value)
				break;
		}
	}
}
