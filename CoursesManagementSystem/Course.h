#ifndef _COURSE_H_
#define _COURSE_H_

#include<string>
#include"DBManager.h"
using namespace std;

class Course
{
public:
	Course();
	Course(string user, string pass);
	static Course* load(int id);
	static Course** loadAll();
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
