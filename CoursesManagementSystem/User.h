#ifndef User_H
#define User_H

#include<string>
#include"DBManager.h"
using namespace std;

class User
{
public:
	
	User* load(int id);
	void save();
private:
	int data_len = 2;
	string *user = new string[data_len];
	DBManager* db = DBManager::get_singleton();
	int id = 1;
};

#endif