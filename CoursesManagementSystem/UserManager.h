#ifndef _USER_MANAGER_H_
#define _USER_MANAGER_H_

#include<string>
using namespace std;

class UserManager
{
public:
	static void list_users();
	static int create_new_user(string username, string password);
	static void view_user(int id);
	static void edit_user(int id, string username, string password);
	static void delete_user(int id);
	static void add_user_course(int user_id, int course_id);
	static void remove_user_course(int user_id, int course_id);
};

#endif
