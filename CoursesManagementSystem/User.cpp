#include"DBManager.h"
#include"User.h"

#include<string>
#include<iostream>
using namespace std;

//User::User()
//{
//	User* user = new User();
//
//}
User* User::load(int id)
{
	User *u = new User();
		u->user = db->load("user", id, data_len);
	
	return u;
}

void User::save()
{
	data_len = 2;
	cout << "Username : ";
	cin >> user[0];
	cout << "Password :";
	cin >> user[1];
	db->store("user", id, data_len, user);
	id++;
}