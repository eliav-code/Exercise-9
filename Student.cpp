#include "Student.h"

Student::Student(int tz, char* name, char* fname, int courses)
{
	Name = new char[20]; Fname = new char[20];
	Tz = tz;
	strcpy(Name, name);
	strcpy(Fname, fname);
	NumOfCourses = courses;
}

Student::~Student()
{
	if (Name)
		delete[] Name;
	Name = nullptr;
	if (Fname)
		delete[] Fname;
	Fname = nullptr;
}

void Student::print() const
{
	cout << "ID: " << GetTz() << endl;
	cout << "first name: " << GetName() << endl;
	cout << "last name: " << GetFname() << endl;
	cout << "num courses: " << GetNumOfCourses() << endl;
}