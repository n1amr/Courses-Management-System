#include"DBManager.h"
#include"Course.h"

#include<string>
#include<iostream>
#include<algorithm>
#include<sstream>
using namespace std;

Course::Course()
{
	this->id = -1;
	this->prerequisites = new list<int>();
}

Course::Course(string name)
{
	this->id = -1;
	this->name = name;
	this->prerequisites = new list<int>();
}

void Course::set_name(string name)
{
	this->name = name;
}

string Course::get_name()
{
	return name;
}

list<Course*>* Course::get_prerequisites()
{
	list<Course*>* l = new list<Course*>();
	for(list<int>::iterator it = prerequisites->begin(); it != prerequisites->end(); it++)
	{
		int course_id = *it;
		Course* course = Course::load(*it);
		l->push_back(course);
	}
	return l;
}

void Course::add_prerequisite(Course* course)
{
	if( find(prerequisites->begin(), prerequisites->end(), course->get_id()) == prerequisites->end() )
	{
		prerequisites->push_back(course->get_id());
	}
}

void Course::remove_prerequisite(int id)
{
	prerequisites->remove(id);
}

void Course::remove_prerequisite(Course* course)
{
	remove_prerequisite(course->get_id());
}

int Course::get_id()
{
	return id;
}

Course* Course::load(int id)
{
	DBManager* db = DBManager::get_singleton();

	int data_len = 2;
	string *data = new string[data_len];

	Course *course = new Course();
	course->id = id;
	data = db->load("course", id, data_len);

	stringstream ss;

	course->set_name(data[0]);
	ss << data[1];
	int len; ss >> len;
	for (int i = 0; i < len; i++)
	{
		int id;
		ss >> id;
		course->prerequisites->push_back(id);
	}

	return course;
}

Course** Course::loadAll()
{
	DBManager* db = DBManager::get_singleton();
	int data_len = 2;

	string** courses_data = db->loadAll("course", data_len);

	int count = db->get_last_id("course") + 1;
	string s;

	Course** courses = new Course*[count];
	for(int i = 0; i < count; i++)
	{
		string *data = courses_data[i];

		Course *course = NULL;
		if(data != NULL)
		{
			course = new Course();
			course->id = i;

			course->set_name(data[0]);
			stringstream ss;
			ss << data[1];
			int len; ss >> len;
			for (int i = 0; i < len; i++)
			{
				int id;
				ss >> id;
				course->prerequisites->push_back(id);
			}
		}
		courses[i] = course;
	}

	return courses;
}

int Course::save()
{
	DBManager* db = DBManager::get_singleton();

	int data_len = 2;
	string *data = new string[data_len];

	data[0] = name;
	stringstream ss;
	ss << prerequisites->size();
	for (auto it = prerequisites->begin(); it != prerequisites->end(); it++)
	{
		ss << " " << *it;
	}
	ss << endl;
	data[1] = ss.str();

	id = db->store("course", id, data_len, data);
	return id;
}

bool Course::trash()
{
	DBManager* db = DBManager::get_singleton();
	return db->trash("course", id);
}
