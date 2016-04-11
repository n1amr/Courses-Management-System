#ifndef _USER_H_
#define _USER_H_

#include<string>
#include"DBManager.h"
#include<vector>
using namespace std;

class User
{
public:
	User();
	User(string user, string pass);
	static User* load(int id);
	static User** loadAll();
	int save();
	bool trash();

	int get_id();
	void set_username(string username);
	void set_password(string password);
	string get_username();
	string get_password();

private:
	int id;
	string username;
	string password;
	vector<int> *courses;

};

#endif
