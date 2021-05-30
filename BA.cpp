#include "BA.h"
BA::~BA()
{
	if (Grades)
		delete Grades;
	Grades = nullptr;
}

float BA::av(const int* const grades, const int size) const
{
	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += grades[i];
	}
	sum /= size;
	return sum;
}

void BA::SetGrades(int* grades)
{
	for (int i = 0; i < GetSize(); i++) {
		Grades[i] = grades[i];
	}
}

bool BA::milga() const
{
	float average = av(GetGrades(), GetSize());
	if (Size >= 10 && average > 95)
		return true;
	return false;
}

void BA::print() const
{
	Student::print();
	cout << "grades: ";
	for (int i = 0; i < GetSize(); i++) {
		cout << Grades[i] << ' ';
	}
	cout << endl;
}