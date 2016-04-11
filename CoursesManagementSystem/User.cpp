#include"DBManager.h"
#include"User.h"
#include"Course.h"

#include<string>
#include<iostream>
#include<sstream>
#include<list>
using namespace std;

User::User()
{
	this->id = -1;
	this->courses = new list<int>();
}

User::User(string username, string password)
{
	this->id = -1;
	this->username = username;
	this->password = password;
	this->courses = new list<int>();
}

void User::set_username(string username)
{
	this->username = username;
}

void User::set_password(string password)
{
	this->password = password;
}

string User::get_username()
{
	return username;
}

string User::get_password()
{
	return password;
}

list<Course*>* User::get_courses()
{
	list<Course*>* c = new list<Course*>();
	for(list<int>::iterator it = courses->begin(); it != courses->end(); it++)
	{
		int course_id = *it;
		Course* course = Course::load(*it);
		c->push_back(course);
	}
	return c;
}

void User::add_course(Course* course)
{
	if( find(courses->begin(), courses->end(), course->get_id()) == courses->end() )
	{
		courses->push_back(course->get_id());
	}
}

void User::remove_course(int id)
{
	courses->remove(id);
}

void User::remove_course(Course* course)
{
	remove_course(course->get_id());
}

int User::get_id()
{
	return id;
}

User* User::load(int id)
{
	DBManager* db = DBManager::get_singleton();

	int data_len = 3;
	string *data = new string[data_len];

	User *user = new User();
	user->id = id;
	data = db->load("user", id, data_len);

	user->set_username(data[0]);
	user->set_password(data[1]);
	stringstream ss;
	ss << data[2];
	int len; ss >> len;
	for (int i = 0; i < len; i++)
	{
		int id; ss >> id;
		user->courses->push_back(id);
	}

	return user;
}

User** User::loadAll()
{
	DBManager* db = DBManager::get_singleton();
	int data_len = 3;

	string** users_data = db->loadAll("user", data_len);

	int count = db->get_last_id("user") + 1;
	string s;

	User** users = new User*[count];
	for(int i = 0; i < count; i++)
	{
		string *data = users_data[i];

		User *user = NULL;
		if(data != NULL)
		{
			user = new User();
			user->id = i;
			user->set_username(data[0]);
			user->set_password(data[1]);
			stringstream ss;
			ss << data[2];
			int len; ss >> len;
			for (int i = 0; i < len; i++)
			{
				int id; ss >> id;
				user->courses->push_back(id);
			}
		}
		users[i] = user;
	}

	return users;
}

int User::save()
{
	DBManager* db = DBManager::get_singleton();

	int data_len = 3;
	string *data = new string[data_len];

	data[0] = username;
	data[1] = password;
	stringstream ss;
	ss << courses->size();
	for (auto it = courses->begin(); it != courses->end(); it++)
	{
		ss << " " << *it;
	}
	data[2] = ss.str();

	id = db->store("user", id, data_len, data);
	return id;
}

bool User::trash()
{
	DBManager* db = DBManager::get_singleton();
	return db->trash("user", id);
}
