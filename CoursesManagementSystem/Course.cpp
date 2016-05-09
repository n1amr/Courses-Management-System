#include"DBManager.h"
#include"Course.h"

#include<string>
#include<iostream>
#include<sstream>
#include"LinkedList.h"
#include"Node.h"

using namespace std;

Course::Course()
{
	this->id = -1;
	this->prerequisites = new List<int>();
}

Course::Course(string name)
{
	this->id = -1;
	this->name = name;
	this->prerequisites = new List<int>();
}

void Course::set_name(string name)
{
	this->name = name;
}

string Course::get_name()
{
	return name;
}

List<Course*>* Course::get_prerequisites()
{
	List<Course*>* l = new List<Course*>();
	for(Node<int>* it = prerequisites->begin(); it != nullptr; it = it->GetNext())
	{
		int course_id = *(*it);
		Course* course = Course::load(course_id);
		if(course != nullptr)
			l->push_back(course);
	}
	return l;
}

void Course::add_prerequisite(Course* course)
{
	if( prerequisites->find(course->get_id()) == -1 )
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

Course* Course::load(string *data)
{
	Course *course = new Course();

	if(data == nullptr)
		return nullptr;

	stringstream ss;

	course->id = atoi(data[0].c_str());
	course->set_name(data[1]);
	ss << data[2];
	int len; ss >> len;
	for (int i = 0; i < len; i++)
	{
		int id;
		ss >> id;
		course->prerequisites->push_back(id);
	}

	return course;
}

Course* Course::load(int id)
{
	DBManager* db = DBManager::get_singleton();

	int data_len = 3;
	string *data = db->load("course", id, data_len);

	Course *course = load(data);
	return course;
}

List<Course*>* Course::loadAll()
{
	DBManager* db = DBManager::get_singleton();
	int data_len = 3;

	List<string*>* courses_data = db->loadAll("course", data_len);

	List<Course*>* courses = new List<Course*>();
	for(Node<string*>* it =courses_data->begin(); it != nullptr; it= it->GetNext())
	{
		string *data = *(*it);
		Course *course = load(data);
		courses->push_back(course);
	}

	return courses;
}

int Course::save()
{
	DBManager* db = DBManager::get_singleton();

	int data_len = 3;
	string *data = new string[data_len];

//	data[0] = to_string(id); // Skip
	data[1] = name;

	stringstream ss;
	ss << prerequisites->size();
	for (Node<int>* it = prerequisites->begin(); it != nullptr; it = it->GetNext())
	{
		ss << " " << *(*it);
	}
	data[2] = ss.str();

	id = db->store("course", id, data_len, data);
	return id;
}

bool Course::trash()
{
	DBManager* db = DBManager::get_singleton();
	return db->trash("course", id);
}

void Course::printPrerequisiteTree(Course* c, string indent)
{
	if(c == nullptr)
		return;

	cout << indent << c->get_name() << endl;
	indent += "|   ";
	for (Node<Course*>* it = c->get_prerequisites()->begin(); it != nullptr; it = it->GetNext()) {
		printPrerequisiteTree(*(*it), indent);
	}
}

void Course::printPrerequisiteTree()
{
	printPrerequisiteTree(this, "");
}
