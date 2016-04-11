#include"DBManager.h"
#include"Course.h"

#include<string>
#include<iostream>
using namespace std;

Course::Course()
{
	id = -1;
}

// TODO
Course::Course(int id)
{
	this->id = id;
}

Course::Course(string username, string password)
{
	this->username = username;
	this->password = password;
	this->id = -1;
}

void Course::set_username(string username)
{
	this->username = username;
}

void Course::set_password(string password)
{
	this->password = password;
}

string Course::get_username()
{
	return username;
}

string Course::get_password()
{
	return password;
}

Course* Course::load(int id)
{
	DBManager* db = DBManager::get_singleton();

	int data_len = 2;
	string *data = new string[data_len];

	Course *course = new Course(id);
	data = db->load("course", id, data_len);

	course->set_username(data[0]);
	course->set_password(data[1]);

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
			course->set_username(data[0]);
			course->set_password(data[1]);
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

	data[0] = username;
	data[1] = password;

	id = db->store("course", id, data_len, data);
	return id;
}

bool Course::trash()
{
	DBManager* db = DBManager::get_singleton();
	return db->trash("course", id);
}
