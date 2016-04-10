#ifndef User_H
#define User_H

#include<string>
#include"DBManager.h"
using namespace std;

class User
{
public:
	User();
	User(int id);
	User(string user, string pass);
	static User* load(int id);
	static User** loadAll();
	void set_username(string username);
	void set_password(string password);
	string get_username();
	string get_password();
	int save();
	bool trash();

private:
	int id;
	string username;
	string password;

};

#endif
