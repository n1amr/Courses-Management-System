#ifndef _DB_MANAGER_H_
#define _DB_MANAGER_H_

#include<string>
using namespace std;

class DBManager
{
private:
	DBManager(){}
	static DBManager* singleton;

public:
	static DBManager* get_singleton();
	void store(string table_name, int id, int data_len, string* data);
	string* load(string table_name, int id, int data_len);
};

#endif
