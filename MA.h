#pragma once
#include"BA.h"

class MA : public BA {
	bool Research;
public:
	MA(int tz, char* name, char* fname, int courses, int* grades, bool re) : BA(tz, name, fname, courses, grades) {
		Research = re;
	};
	bool GetResearch() const { return Research; };
	void SetResearch(bool re) { Research = re; };
	virtual bool milga() const override;
	virtual void print() const override;
	virtual string studType() const override { string str = "MA"; return str; };
};

