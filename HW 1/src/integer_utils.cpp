#include <iostream>
#include "integer_utils.h"

using namespace std;

namespace integer_utils
{
	int runIntegerOption()
	{
		int i1, i2; 

		cout << "Enter first integer:" << endl;
		cin >> i1;

		cout << "Enter second integer:" << endl;
		cin >> i2;

		if(i2 == 0)
		{
			cout<< "Error: division by zero" << endl;
			return 0;
		}

		int result = i1/i2;

		cout << "Result: " << result << endl;  //This prints the quotient value of 1st integer divided by 2nd integer

		cout << "After post-increment: " << i1++ << endl;

		cout << "After pre-increment: " << ++i1 << endl;

		return 1;

	}
}
