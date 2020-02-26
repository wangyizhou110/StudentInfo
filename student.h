#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <vector>
using namespace std;

class student
{
private:
	int s_id, s_grade;
	string s_name;
public:
	student();
	student(int, string, int);
	string heading();
	string showInfo();
	int get_s_grade();
};

void storestudent(int num, ofstream& output);

vector<string> split(const string& s, const string& seperator);

void filterStudents(ifstream& input);




#endif 