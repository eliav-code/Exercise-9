#pragma once
#include"Student.h"

class BA : public Student {
	int* Grades;
	int Size;
public:
	BA(int tz, char* name, char* fname, int courses, int* grades) : Student(tz, name, fname, courses) {
		Size = courses;
		Grades = new int[Size];
		for (int i = 0; i < Size; i++) {
			Grades[i] = grades[i];
		}
	};
	virtual ~BA();
	int* GetGrades() const { return Grades; };
	int GetSize() const { return Size; };
	float av(const int* const grades, const int size) const;
	void SetGrades(int* grades);
	//void SetSize(int size) { Size = size; };
	virtual bool milga() const override;
	virtual void print() const override;
	virtual string studType() const override { string str = "BA"; return str; };
};

