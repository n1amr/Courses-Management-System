#ifndef User_H
#define User_H

#include<string>
#include<map>
#include"DBManager.h"
using namespace std;

class User
{
public:
  User();
	User(string user, string pass); // TODO
	static User* load(int id);
	void set_username(string user);
	void set_password(string pass);
	string get_username();
	string get_password();
	void save();
private:
	  int id;
	  string user_name;
	  string pass_word;
};

#endif
