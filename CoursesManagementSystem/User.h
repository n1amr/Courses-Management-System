#ifndef _USER_H_
#define _USER_H_

#include<string>
#include"DBManager.h"
#include"Course.h"
#include"iostream"
#include"LinkedList.h"
using namespace std;

class User
{
public:
	User();
	User(string user, string pass);
	static User* load(string* data);
	static User* load(int id);
	static List<User*>* loadAll();
	int save();
	bool trash();

	static User* is_registered(string username);
	static User* authenticate(string username, string password);

	int get_id();
	void set_username(string username);
	void set_password(string password);
	string get_username() const;
	string get_password() const;

	List<Course*>* get_courses();
	void add_course(Course* course);
	void remove_course(int id);
	void remove_course(Course* course);
	bool operator==(User const& u) const;
	bool operator<(User const& u) const;

private:
	int id;
	string username;
	string password;
	List<int> *courses;
	friend ostream& operator<<(ostream& os, const User& u);

};


#endif
