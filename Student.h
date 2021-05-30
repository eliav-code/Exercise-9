#pragma once
#include<cstring>
#include<string>
#pragma warning (disable:4996)
#include<iostream>
using namespace std;

class Student
{
	int Tz;
	char* Name;
	char* Fname;
	int NumOfCourses;
public:
	//Student* Next;
	Student(int tz, char* name, char* fname, int courses);
	virtual ~Student();
	virtual bool milga() const = 0;
	virtual string studType() const = 0;
	virtual void print() const;
	int GetTz() const { return Tz; };
	char* GetName() const { return Name; };
	char* GetFname() const { return Fname; };
	int GetNumOfCourses() const { return NumOfCourses; };
	//Student* GetNext() const { return Next; };
	void SetTz(int tz) { Tz = tz; };
	void SetName(char* name) { strcpy(Name, name); };
	void SetFname(char* fname) { strcpy(Fname, fname); };;
	void SetNumOfCourses(int num) { NumOfCourses = num; };
};