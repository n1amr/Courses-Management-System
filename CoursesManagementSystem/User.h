#ifndef User_H
#define User_H

#include<string>
#include"DBManager.h"
using namespace std;

class User
{
public:
  User();
	// User(string username_, string password_); // TODO
	static User* load(int id);
	void save();
private:
	int id;
};

#endif
