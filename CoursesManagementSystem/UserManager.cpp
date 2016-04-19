#include"AdminForm.h"

#include"DBManager.h"
#include"User.h"
#include"UserManager.h"
#include"Course.h"
#include"CourseManager.h"
#include<iostream>
#include<string>
#include"LinkedList.h"
#include"Node.h"
using namespace std;

void UserManager::list_users()
{
	User** users = User::loadAll();

	int count = DBManager::get_singleton()->get_last_id("user") + 1;

	for(int i = 0; i < count; i++)
	{
		User *user = users[i];
		if(user != NULL)
		{
			cout << "User #" << i << endl;
			cout << "Username: " << user->get_username() << endl;
			cout << "Password: " << user->get_password() << endl;
			cout << endl;
		}
	}
}

int UserManager::create_new_user(string username, string password)
{
	User* user = new User();

	if(username.length() > 0)
		user->set_username(username);

	if(password.length() > 0)
		user->set_password(password);

	int id = user->save();
	delete user;
	return id;
}

void UserManager::view_user(int id)
{
	User* user = User::load(id);

	cout << "Username: " << user->get_username() << endl;
	cout << "Password: " << user->get_password() << endl;
	cout << "Courses: ";
	List<Course*>* courses = user->get_courses();
	for(Node<Course*>* it = courses->begin(); it != nullptr; it = it->GetNext())
	{
		Course* c = *(*it);
		cout << " " << c->get_name() << ", ";
	}
	cout << endl;

	delete user;
	delete courses;
}

void UserManager::edit_user(int id, string username, string password)
{
	User* user = User::load(id);

	if(username.length() > 0)
		user->set_username(username);

	if(password.length() > 0)
		user->set_password(password);

	id = user->save();
	delete user;
}

void UserManager::delete_user(int id)
{
	User* user = User::load(id);
	user->trash();

	delete user;
}

void UserManager::add_user_course(int user_id, int course_id)
{
	User* user = User::load(user_id);
	Course* course = Course::load(course_id);

	user->add_course(course);
	user->save();

	delete user;
	delete course;
}

void UserManager::remove_user_course(int user_id, int course_id)
{
	User* user = User::load(user_id);
	Course* course = Course::load(course_id);

	user->remove_course(course);
	user->save();

	delete user;
	delete course;
}
