#include"AdminForm.h"

#include"DBManager.h"
#include"User.h"
#include"Course.h"
#include"UserManager.h"
#include"CourseManager.h"
#include "Helper.h"
#include<iostream>
#include<string>
using namespace std;

void AdminForm::run_form()
{
	string s;
	do
	{
		Helper::clear_screen();
		cout << "Select model:" << endl;
		cout << "	1- User." << endl;
		cout << "	2- Course." << endl;
		cout << "Or:" << endl;
		cout << "	3- Exit." << endl;

		int response = -1;
		cin >> response; getline(cin, s);
		if(response == 1)
			run_user_form();
		else if(response == 2)
			run_course_form();
		else if(response == 3)
			return;

		cout << "Press [ENTER] to continue";
		getline(cin, s);
	}while(true);
}

void AdminForm::run_user_form()
{
	Helper::clear_screen();

	string s;

	cout << "Select operation:" << endl;
	cout << "	1- List users." << endl;
	cout << "	2- Create user." << endl;
	cout << "	3- Retrieve user." << endl;
	cout << "	4- Edit user." << endl;
	cout << "	5- Delete user." << endl;
	cout << "	6- Add course." << endl;
	cout << "	7- Remove course." << endl;
	int response = -1;
	cin >> response; getline(cin, s);
	if(response == 1)
		list_users();
	else if(response == 2)
		create_new_user();
	else if(response == 3)
		view_user();
	else if(response == 4)
		edit_user();
	else if(response == 5)
		delete_user();
	else if(response == 6)
		add_user_course();
	else if(response == 7)
		remove_user_course();
}

void AdminForm::run_course_form()
{
	Helper::clear_screen();

	string s;

	cout << "Select opeation:" << endl;
	cout << "	1- List courses." << endl;
	cout << "	2- Create course." << endl;
	cout << "	3- Retrieve course." << endl;
	cout << "	4- Edit course." << endl;
	cout << "	5- Delete course." << endl;
	cout << "	6- Add course prerequisites." << endl;
	cout << "	7- Remove course prerequisites." << endl;
	int response = -1;
	cin >> response; getline(cin, s);
	if(response == 1)
		list_courses();
	else if(response == 2)
		create_new_course();
	else if(response == 3)
		view_course();
	else if(response == 4)
		edit_course();
	else if(response == 5)
		delete_course();
	else if(response == 6)
		add_course_prerequisites();
	else if(response == 7)
		remove_course_prerequisites();
}

void AdminForm::list_users()
{
	UserManager::list_users();
}

void AdminForm::create_new_user()
{
	string username, password;

	cout << "Enter username:";
	getline(cin, username);
	cout << "Enter password:";
	getline(cin, password);

	int id = UserManager::create_new_user(username, password);

	cout << "User was saved with id #" << id << endl;
}

void AdminForm::view_user()
{
	string s;
	cout << "Enter id:";
	int id; cin >> id; getline(cin, s);

	UserManager::view_user(id);
}

void AdminForm::edit_user()
{
	string s;
	cout << "Enter id:";
	int id; cin >> id; getline(cin, s);

	User* user = User::load(id);

	cout << "Edit username(" << user->get_username() << "):" ;
	getline(cin, s);
	if(s.length() > 0)
		user->set_username(s);
	cout << "Edit password(" << user->get_password() << "):" ;
	getline(cin, s);
	if(s.length() > 0)
		user->set_password(s);

	id = user->save();
	cout << "User was saved with id #" << id << endl;
	delete user;
}

void AdminForm::delete_user()
{
	string s;
	cout << "Enter id:";
	int id; cin >> id; getline(cin, s);

	UserManager::delete_user(id);
}

void AdminForm::add_user_course()
{
	string s;
	cout << "Enter user id:";
	int user_id; cin >> user_id; getline(cin, s);

	cout << "Enter course id:";
	int course_id; cin >> course_id; getline(cin, s);

	UserManager::add_user_course(user_id, course_id);
}

void AdminForm::remove_user_course()
{
	string s;
	cout << "Enter user id:";
	int user_id; cin >> user_id; getline(cin, s);

	cout << "Enter course id:";
	int course_id; cin >> course_id; getline(cin, s);

	UserManager::remove_user_course(user_id, course_id);
}

void AdminForm::list_courses()
{
	CourseManager::list_courses();
}

void AdminForm::create_new_course()
{
	string course_name;
	cout << "Enter course name:";
	getline(cin, course_name);

	int id = CourseManager::create_new_course(course_name);

	cout << "Course was saved woth id #" << id << endl;
}

void AdminForm::view_course()
{
	string s;
	cout << "Enter id:";
	int id; cin >> id; getline(cin, s);

	CourseManager::view_course(id);
}

void AdminForm::edit_course()
{
	string s;
	cout << "Enter id:";
	int id; cin >> id; getline(cin, s);

	Course* course = Course::load(id);

	cout << "Edit course name(" << course->get_name() << "):" ;
	getline(cin, s);
	if(s.length() > 0)
		course->set_name(s);

	id = course->save();
	cout << "Course was saved woth id #" << id << endl;
	delete course;
}

void AdminForm::delete_course()
{
	string s;
	cout << "Enter id:";
	int id; cin >> id; getline(cin, s);

	CourseManager::delete_course(id);
}

void AdminForm::add_course_prerequisites()
{
	string s;
	cout << "Enter id:";
	int course_id; cin >> course_id; getline(cin, s);

	cout << "Enter prerequisite course id:";
	int prerequisite_course_id; cin >> prerequisite_course_id; getline(cin, s);

	CourseManager::add_course_prerequisites(course_id, prerequisite_course_id);
}

void AdminForm::remove_course_prerequisites()
{
	string s;
	cout << "Enter id:";
	int course_id; cin >> course_id; getline(cin, s);

	cout << "Enter prerequisite course id:";
	int prerequisite_course_id; cin >> prerequisite_course_id; getline(cin, s);

	CourseManager::remove_course_prerequisites(course_id, prerequisite_course_id);
}
