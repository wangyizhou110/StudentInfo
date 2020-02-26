#include"student.h"




//initialize the information of student.
student::student()
{
	s_id = -1;
	s_name = "unknown";
	s_grade = -1;
}

//set the information.
student::student(int input_s_id, string input_s_name, int input_s_grade)
{
	s_id = input_s_id;
	s_name = input_s_name;
	s_grade = input_s_grade;
}

//print the heading of the list to the screan to distinguish the information.
string student::heading()
{
	//Characters can be inserted into the stream with any operation allowed on output streams.
	std::ostringstream oss;
	oss << "ID,    Name,    Grade" << endl;
	return oss.str();
}

//print the information with the following format, separated by ","
string student::showInfo()
{
	std::ostringstream oss;
	oss << s_id << "," << s_name << "," << s_grade << endl;
	return oss.str();
}

int student::get_s_grade()
{
	return s_grade;
}



//Function of store information of students.
void storestudent(int num, ofstream& output)
{
	//define a string array which is long enough.
	student stu[100];

	//define a temporary variable .
	student temporary;
	int s_id, s_grade;
	string s_name;

	//Enter student information in turn based on the number of students entered in the main function.
	for (int i = 0; i < num; i++)
	{
		cout << "please enter the information of the student\n" << endl<<"ID,    Name,    Grade\n";
		cin >> s_id >> s_name >> s_grade;
		//put all information of one student in one position of the string array.
		stu[i] = student(s_id, s_name, s_grade);
		cout << endl;
	}

	//Sort information based on student grades in the array.
	for (int i = 0; i < num; i++)
	{
		for (int j = 1; j < num - i; j++)
		{
			if (stu[i].get_s_grade() < stu[i + j].get_s_grade())
			{
				temporary = stu[i + j];
				stu[i + j] = stu[i];
				stu[i] = temporary;
			}
		}
	}

	//the information output by showInfo() is stored into specified file in turn.
	for (int i = 0; i < num; i++)
	{
		output << stu[i].showInfo();
	}
	cout << "Success to store the information\n" << endl;
}

//Function of separate the long string. This function will be used when read the information from a file.
vector<string> split(const string& s, const string& seperator)
{
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;
	while (i != s.size())
	{
		//Find the first letter in the string that is not equal to the separator.
		int flag = 0;
		while (i != s.size() && flag == 0)
		{
			flag = 1;
			for (string_size x = 0; x < seperator.size(); x++)
			{
				if (s[i] == seperator[x])
				{
					i++;
					flag = 0;
					break;
				}
			}
		}

		//Finde the next separator and take the string between the two separator.
		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0) {
			for (string_size x = 0; x < seperator.size(); x++)
				if (s[j] == seperator[x])
				{
					flag = 1;
					break;
				}
			if (flag == 0)
				j++;
		}
		if (i != j)
		{
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return result;
}

//Query information and filter if based on grades.
void filterStudents(ifstream& input)
{
	int a, i=0;
	//define the temporary variable.
	string  s, name, id, grade;
	student stu[100];
	cout << stu[0].heading();

	//read each line information of the file and output as a string.
	//the information of each line is: "ID, Name, Grade,"
	while (getline(input, s))
	{
		//separate the long string read from the file, the separator is ",".
		vector<string> v = split(s, ","); 
		for (vector<string>::size_type i = 0; i != v.size(); i++)
		{
			//each separated string is placed into the string array v[]. The first string is v[0]......
			//print a new list. Every string is separate by "," in one line.
			cout << v[i] << ",";
		}

		//we, know that the first string is ID, the second one is name, the last one is grade.
		id = v[0]; name = v[1]; grade = v[2];
		//convert the string(id and grade) into int.
		int s_id = atoi(id.c_str()); string s_name = name; int s_grade = atoi(grade.c_str());
		//put the new list into the stu[i] of class.
		stu[i] = student(s_id, s_name, s_grade);
		//get next line of the file.
		i++;
		cout << endl;
	}	
	cout << endl;

	//print to the screan, search, and filter.
	//this function allow user to filter the student information by the grade. 
	cout << "How much grade of student do you wangt to search？\n" << "please enter the limit:\n";
	cin >> a;
	cout << endl;
	cout << stu[0].heading();
	for (int i = 0; i < 100; i++)
	{
		if (stu[i].get_s_grade() >= a)
		{
			cout << stu[i].showInfo();
		}
	}
	cout << endl;
}
