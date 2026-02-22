#include <iostream>
#include "grade_utils.h"

using namespace std;

namespace grade_utils
{
	double calculateGrade()
	{
		char student_type;
		double grade;

		cout << "Enter student type (U for undergrad, G for grad):" << endl;
		cin >> student_type;

		cout << "Enter numeric grade: " << endl;
		cin >> grade;

		if(grade < 0 || grade > 100)
		{
			cout << "Invalid grade" << endl;
			return -1;
		}

		bool pass;

		switch(student_type)
		{
			case 'U':
			case 'u':
				pass = (grade >= 60);
				break;

			case 'G':
			case 'g':
				pass = (grade>=70);
				break;

			default:
				return -1;
		}

		if(pass)
			cout << "Status: Pass" << endl;
		else
			cout << "Status: Fail" << endl;

		return grade;

	}
}
