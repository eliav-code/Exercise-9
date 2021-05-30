#pragma once
#include"Student.h"

class PHD : public Student {
	int HourOfResearch;
public:
	PHD(int tz, char* name, char* fname, int courses, int hourofre) : Student(tz, name, fname, courses) {
		HourOfResearch = hourofre;
	};
	int GetHourOfResearch() const { return HourOfResearch; };
	void SetHourOfResearch(int hourofre) { HourOfResearch = hourofre; };
	virtual bool milga() const override;
	virtual void print() const override;
	virtual string studType() const override { string str = "PHD"; return str; };
};