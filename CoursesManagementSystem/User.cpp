#include"DBManager.h"
#include"User.h"

#include<string>
#include<iostream>
using namespace std;

User::User()
{
	id = -1;
}

User* User::load(int id)
{
	DBManager* db = DBManager::get_singleton();
	
	int data_len = 2;
	string *data = new string[data_len];
	
	User *user = new User();
  data = db->load("user", id, data_len);

	// MY_USERNAME = uaer[0];
	// MY_PASSWORD = uaer[1];
	
	return user;
}

void User::save()
{
	DBManager* db = DBManager::get_singleton();
	
	int data_len = 2;
	string *data = new string[data_len];
	
	data[0] = "MY_USERNAME"; // TODO
	data[1] = "MY_PASSWORD"; // TODO
	
	db->store("User", id, data_len, data);
}
