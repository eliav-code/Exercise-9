#include"BA.h"
#include"MA.h"
#include"PHD.h"
#include<vector>
#include <list>
#include <vector>
#include <algorithm>

typedef vector<Student*>::iterator It;

enum option {
	stop, 
	addNewStudent,
	milgaList,
	mostResearch,
	countMilgaBA,
	noResearchMA,
	overheadStudent,
	removePHDFailers
};

void add(vector<Student*> &vec){	// Add a new student to vector.
	int op;
	It start = vec.end(); Student* p;
	cout << "enter 1 to add a BA student\n";
	cout << "enter 2 to add a MA student\n";
	cout << "enter 3 to add a PHD student\n";
	cin >> op;
	cout << "enter id, first name, last name and number Of Courses\n"; int id, numOfCourses; char* name = new char[20]; char* fname = new char[20];
	cin >> id >> name >> fname >> numOfCourses;
	switch (op)
	{
	case 1:{	//BA
		int* array_grades = new int[numOfCourses];
		cout << "enter " << numOfCourses << " grades\n";
		for (int i = 0; i < numOfCourses; i++){
			cin >> array_grades[i];
		}
		p = new BA(id, name, fname, numOfCourses, array_grades);
		vec.insert(start, p);
		break;
	}
	case 2:{	// MA
		int* array_grades = new int[numOfCourses];
		cout << "enter " << numOfCourses << " grades\n";
		for (int i = 0; i < numOfCourses; i++) {
			cin >> array_grades[i];
		}
		cout << "enter 1 if the student does research and 0 if not\n"; bool research; cin >> research;
		p = new MA(id, name, fname, numOfCourses, array_grades, research);
		vec.insert(start, p);
		break;
	}
	case 3:	//PHD
		cout << "enter number of research hours\n"; int rehour; cin >> rehour;
		p = new PHD(id, name, fname, numOfCourses, rehour);
		vec.insert(start, p);
		break;
	default:
		break;
	}
	return;
}

void milga(vector<Student*> vec) {	// Print the students that have milga.
	It start = vec.begin(), finish = vec.end();
	for_each(start, finish, [](Student* p) {if (p->milga()) p->print(); }); cout << endl;
	return;
}

Student* mostResearchHours(vector<Student*> vec){	// Return pointer to student PHD do the most research hours, if no return NULL.
	int max = 0, i = 0;
	for (; unsigned(i) < vec.size(); i++) {
		if (vec[i]->studType() == "PHD") {
			if (((PHD*)vec[i])->GetHourOfResearch() > max)
				max = ((PHD*)vec[i])->GetHourOfResearch();
		}
	}
	if (i == vec.size()+1)
		return nullptr;
	auto found = find_if(vec.begin(), vec.end(), [=](Student* p) { return (p->studType() == "PHD" && ((PHD*)p)->GetHourOfResearch() == max); });
	return (*found);
}

int main() {
	vector<Student*> vec; It start = vec.begin(); It finish = vec.end();
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != stop)
	{
		switch (op)
		{
		case addNewStudent:
			add(vec);
			break;
		case milgaList:
			milga(vec);
			break;
		case mostResearch: {
			Student* s = mostResearchHours(vec);
			cout << "PHD studnet with most research hours: ";
			s ? cout << s->GetName() << ' ' << s->GetFname() << endl : cout << endl;
		}
		break;
		case countMilgaBA:
			cout << "#BA studnets for milga: ";
			cout << count_if(vec.begin(), vec.end(), [](Student* p) { return (p->studType() == "BA" && ((BA*)p)->milga()); });
			cout << endl;
			break;
		case noResearchMA:	// no research
			cout << "list of no research MA students : ";
			for_each(vec.begin(), vec.end(), [](Student* p) {if (p->studType() == "MA" && !((MA*)p)->GetResearch()) cout << p->GetName() << ' ' << p->GetFname(); });
			cout << endl;
			break;
		case overheadStudent:	// more than 15 courses.
			if (count_if(vec.begin(), vec.end(), [](Student* p) {return (p->GetNumOfCourses()>15);}))
				cout << "there is a student that takes more than 15 courses\n";
			else
				cout << "no student takes more than 15 courses\n";
			break;
		case removePHDFailers:	// remove who have no courses.
			start = vec.begin(); finish = vec.end();
			finish = remove_if(start, finish, [](Student* p) {return (p->studType() == "PHD" && p->GetNumOfCourses() == 0); });
			for_each(start, finish, [](Student* p) { cout << p->GetTz() << ' ' << p->GetName() << ' ' << p->GetFname() << ' ' << p->GetNumOfCourses() << ' '; });
			break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}