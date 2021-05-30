#include "MA.h"

bool MA::milga() const
{
	float average = av(GetGrades(), GetSize());
	if (GetNumOfCourses() >= 7 && average > 90 && GetResearch())
		return true;
	return false;
}

void MA::print() const
{
	BA::print();
	Research ? cout << "research: yes" << endl : cout << "research: no" << endl;
}