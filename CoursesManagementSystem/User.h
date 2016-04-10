#ifndef User_H
#define User_H

#include<string>
#include"DBManager.h"
using namespace std;

class User
{
public:
	User();
	User(string user, string pass);
	static User* load(int id);
	void set_username(string username);
	void set_password(string password);
	string get_username();
	string get_password();
	void save();

private:
	int id;
	string username;
	string password;

};

#endif
