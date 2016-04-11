#include"DBManager.h"
#include"User.h"

#include<string>
#include<iostream>
using namespace std;

User::User()
{
	id = -1;
}

User::User(string username, string password)
{
	this->username = username;
	this->password = password;
	this->id = -1;
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

int User::get_id()
{
	return id;
}

User* User::load(int id)
{
	DBManager* db = DBManager::get_singleton();

	int data_len = 2;
	string *data = new string[data_len];

	User *user = new User();
	user->id = id;
	data = db->load("user", id, data_len);

	user->set_username(data[0]);
	user->set_password(data[1]);

	return user;
}

User** User::loadAll()
{
	DBManager* db = DBManager::get_singleton();
	int data_len = 2;

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
		}
		users[i] = user;
	}

	return users;
}

int User::save()
{
	DBManager* db = DBManager::get_singleton();

	int data_len = 2;
	string *data = new string[data_len];

	data[0] = username;
	data[1] = password;

	id = db->store("user", id, data_len, data);
	return id;
}

bool User::trash()
{
	DBManager* db = DBManager::get_singleton();
	return db->trash("user", id);
}
