#include <iostream>
#include"student.h"

using namespace std;

//Menu
int main()
{
	char choose;
	int num;
	cout << "Please select an action:\n"<<endl<<"Add informations of students(a)\n"<<"Search students informations based on grades(s)\n"<<"Quit(q)\n";
	cin >> choose;
	ofstream output;
	ifstream input;
	if (choose != 'q')
	{
		switch (choose)
		{
			//Add informations of student
			case 'a':
			{
				cout << "Please enter the number of student.\n";
				cin >> num;
				cout << endl;
				output.open("studentInfo.txt");
				if (output.is_open())
				{
					storestudent(num, output);
				}
				else
				{
					cout << "Fail to open the file.\n" << endl;
				}
				output.close();
				break;
			}
			//Search students informations based on grades
			case 's':
			{
				cout << endl;
				input.open("studentInfo.txt");
				if (input.is_open())
				{
					filterStudents(input);
				}
				else
				{
					cout << "Fail to open the file.\n"<<endl;
				}
				break;
			}
			default:
				break;
		}
		main();
	}
	//quit
	if (choose == 'q')
	{
		cout <<endl<< "Finish the programe." ;
	}
	output.close();
	input.close();
	return 0;
}
