#include <stdexcept>
#include <iostream>
#include <cstring>   // for strlen, strcpy

using std::cout, std::cin, std::cerr, std::endl, std::string;

// TODO: function prototypes
void addStudent(const char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double* gpaPtr, double newGpa);
void printStudent(const char* name, const double& gpa);
double averageGPA(const double gpas[], int size);

// TODO: implement addStudent
void addStudent(const char* name, double gpa, char* names[], double gpas[], int& size, int capacity)
{
	if(size >= capacity)
		throw "List full";

	names[size] = new char[std::strlen(name) + 1];

	std::strcpy(names[size], name);

	gpas[size] = gpa;

	size++;	
}

// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa)
{
	if(!gpaPtr){
		throw "Invalid GPA pointer!";
	}
	
	*gpaPtr = newGpa;
}

// TODO: implement printStudent
void printStudent(const char* name, const double& gpa)
{
	cout << name << ": " << gpa << endl;
}

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size)
{
	if(size == 0)
		throw "No students";

	double sum = 0.0;
	for(int i = 0; i < size; i++)
		sum += gpas[i];

	return sum/size;	
}


int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Usage: ./program <capacity>" << std::endl;
		return 1;
	}

	int capacity = std::stoi(argv[1]);
	char** names = new char*[capacity];
	
	for(int i = 0; i < capacity; i++)
		names[i] = nullptr;

	double* gpas = new double[capacity];
	int size = 0;

	int choice;
	do {
		std::cout << "Menu:\n";
		std::cout << "1. Add student\n";
		std::cout << "2. Update GPA\n";
		std::cout << "3. Print all students\n";
		std::cout << "4. Compute average GPA\n";
		std::cout << "5. Quit\n";
		std::cout << "Enter choice: ";
		std::cin >> choice;

		switch (choice) {
			case 1: {
					// TODO: implement menu logic
					string name;
					double gpa;

					cout << "Please enter the student's name: ";
					cin >> name;	

					cout << "Please enter student's GPA: ";
					cin >> gpa;

					try {
						addStudent(name.c_str(), gpa, names, gpas, size, capacity);	
					} catch(const char* msg)
					{
						cout << msg << endl;
					}	

					break;
				}
			case 2: {
					// TODO: implement menu logic
					if(size == 0)
					{
						cout << "No students to update!" << endl;
						break;
					}
					int index; 
					cout << "Enter student index to update" << endl;
					cin >> index;

					double newGPA; 
					cout << "Enter your GPA: ";
					cin >> newGPA;
					
					double* gpaPtr = nullptr;
					
					if(index >= 0 && index < size)
					{
						gpaPtr = &gpas[index];
					}

					try {
					updateGPA(gpaPtr, newGPA);
					std::cout << "GPA updated! " << endl;
					} catch (const char* error)
					{
						cout << error << endl;
					}	
					
					break;
				}
			case 3: {
					// TODO: implement menu logic
					if(size == 0)
					{
						cout << "List is empty" << endl;
						break;
					}
					else {
					for(int i = 0; i < size; i++)
					{
						cout << i << ": ";
						printStudent(names[i], gpas[i]);
					}
					}
					break;
				}
			case 4: {
					// TODO: implement menu logic
					try{
					cout << "Average GPA: " << averageGPA(gpas, size) << endl;
					cout << "Rounded average GPA: " << static_cast<int>(averageGPA(gpas, size)) << endl;
					} catch (const char* msg)
					{
						std::cout << msg << std::endl;
					}
					break;
				}
			case 5: {
					std::cout << "Goodbye!" << std::endl;
					break;
				}
			default: {
					 std::cout << "Invalid choice" << std::endl;
				 }
		}
	} while (choice != 5);

	// TODO: free memory
	for(int i = 0; i < size; i++)
		delete[] names[i];

	delete[] names;
	delete[] gpas;
	return 0;
}
