#include "PHD.h"

bool PHD::milga() const
{
	if (GetNumOfCourses() >= 2 && GetHourOfResearch() > 25)
		return true;
	return false;
}

void PHD::print() const
{
	Student::print();
	cout << "hours: " << HourOfResearch;
}
