#include"DBManager.h"
#include"User.h"
#include"Course.h"

#include<string>
#include<iostream>
#include<sstream>
#include"LinkedList.h"
#include"Node.h"
using namespace std;

User::User()
{
	this->id = -1;
	this->courses = new List<int>();
}

User::User(string username, string password)
{
	this->id = -1;
	this->username = username;
	this->password = password;
	this->courses = new List<int>();
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

List<Course*>* User::get_courses()
{
	List<Course*>* c = new List<Course*>();
	for(Node<int>* it = courses->begin(); it != nullptr; it = it->GetNext())
	{
		int course_id = *(*it);
		Course* course = Course::load(course_id);
		c->push_back(course);
	}
	return c;
}

void User::add_course(Course* course)
{
	if( courses->find(course->get_id()) != -1 )
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

User *User::load(string *data)
{
	User *user = new User();

	int data_len = 4;

	user->id = atoi(data[0].c_str());
	user->set_username(data[1]);
	user->set_password(data[2]);
	stringstream ss;
	ss << data[3];
	int len; ss >> len;
	for (int i = 0; i < len; i++)
	{
		int id; ss >> id;
		user->courses->push_back(id);
	}

	return user;
}


User* User::load(int id)
{
	DBManager* db = DBManager::get_singleton();

	int data_len = 4;
	string *data = db->load("user", id, data_len);
	return load(data);
}

List<User*>* User::loadAll()
{
	DBManager* db = DBManager::get_singleton();
	int data_len = 4;

	List<string*>* users_data = db->loadAll("user", data_len);

	List<User*>* users = new List<User*>();
	for(Node<string*>* it = users_data->begin(); it != nullptr; it = it->GetNext())
	{
		string *data = *(*it);
		User *user = load(data);
		users->push_back(user);
	}

	return users;
}

int User::save()
{
	DBManager* db = DBManager::get_singleton();

	int data_len = 4;
	string *data = new string[data_len];

	//data[0] = to_string(id); // Skip
	data[1] = username;
	data[2] = password;
	stringstream ss;
	ss << courses->size();
	for (auto it = courses->begin(); it != courses->end(); it++)
	{
		ss << " " << *(*it);
	}
	data[3] = ss.str();

	id = db->store("user", id, data_len, data);
	return id;
}

bool User::trash()
{
	DBManager* db = DBManager::get_singleton();
	return db->trash("user", id);
}
