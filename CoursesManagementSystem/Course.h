#ifndef _COURSE_H_
#define _COURSE_H_

#include<string>
#include"DBManager.h"
#include<list>
using namespace std;

class Course
{
public:
	Course();
	Course(string name);
	static Course* load(int id);
	static Course** loadAll();
	int save();
	bool trash();

	int get_id();
	void set_name(string name);
	string get_name();

	list<Course*>* get_prerequisites();
	void add_prerequisite(Course* course);
	void remove_prerequisite(int id);
	void remove_prerequisite(Course* course);

private:
	int id;
	string name;
	list<int> *prerequisites;

};

#endif
