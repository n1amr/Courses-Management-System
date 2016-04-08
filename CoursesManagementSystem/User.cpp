#include"DBManager.h"
#include"User.h"

#include<string>
#include<iostream>
using namespace std;

User::User()
{
	id = -1;

}
User::User(string user , string pass)
{
	user_name = user;
	pass_word = pass;
}

void User::set_username(string name)
{
	user_name = name;
}

void User::set_password(string pass)
{
	pass_word = pass;
}

string User::get_username()
{
	return user_name;
}

string User::get_password()
{
	return pass_word;
}
User* User::load(int id)
{
	DBManager* db = DBManager::get_singleton();
	
	int data_len = 2;
	string *data = new string[data_len];
	
	User *user = new User();
    data = db->load("user", id, data_len);

	user->set_username(data[0]);
	user->set_password(data[1]);

	return user;
}

void User::save()
{
	DBManager* db = DBManager::get_singleton();
	
	int data_len = 2;
	string *data = new string[data_len];
	
	data[0] = user_name; // TODO
	data[1] = pass_word; // TODO
	id++;
	db->store("User", id, data_len, data);
	
}
