#include"Form.h"

#include"DBManager.h"
#include"User.h"
#include"Course.h"
#include<iostream>
#include<string>
#include"LinkedList.h"
#include"Node.h"
using namespace std;

void run_form()
{
	string s;
	while(true)
	{
		cout << "Select model:" << endl;
		cout << "	1- User." << endl;
		cout << "	2- Course." << endl;

		int response = -1;
		cin >> response; getline(cin, s);
		if(response == 1)
		{
			run_user_form();
		}
		else if(response == 2)
		{
			run_course_form();
		}

		cout << "Continue? (y/n) ";
		getline(cin, s);
		if(s == "n")
			break;
	}
}

void run_user_form()
{
	string s;

	cout << "Select opeation:" << endl;
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
	else if(response == 2)
	{
		User* user = new User();

		cout << "Enter username:";
		getline(cin, s);
		if(s.length() > 0)
			user->set_username(s);
		cout << "Enter password:";
		getline(cin, s);
		if(s.length() > 0)
			user->set_password(s);

		int id = user->save();
		delete user;

		cout << "User was saved woth id #" << id << endl;
	}
	else if(response == 3)
	{
		cout << "Enter id:";
		int id; cin >> id; getline(cin, s);

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
	else if(response == 4)
	{
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
		cout << "User was saved woth id #" << id << endl;
		delete user;
	}
	else if(response == 5)
	{
		cout << "Enter id:";
		int id; cin >> id; getline(cin, s);

		User* user = User::load(id);
		user->trash();

		delete user;
	}
	else if(response == 6)
	{
		cout << "Enter user id:";
		int id; cin >> id; getline(cin, s);
		User* user = User::load(id);

		cout << "Enter course id:";
		cin >> id; getline(cin, s);
		Course* course = Course::load(id);

		user->add_course(course);
		user->save();

		delete user;
		delete course;
	}
	else if(response == 7)
	{
		cout << "Enter user id:";
		int id; cin >> id; getline(cin, s);
		User* user = User::load(id);

		cout << "Enter course id:";
		cin >> id; getline(cin, s);
		Course* course = Course::load(id);

		user->remove_course(course);
		user->save();

		delete user;
		delete course;
	}
}

void run_course_form()
{
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
	{
		Course** courses = Course::loadAll();

		int count = DBManager::get_singleton()->get_last_id("course") + 1;

		for(int i = 0; i < count; i++)
		{
			Course *course = courses[i];
			if(course != NULL)
			{
				cout << "Course #" << i << endl;
				cout << "Name: " << course->get_name() << endl;
				cout << endl;
			}
		}
	}
	else if(response == 2)
	{
		Course* course = new Course();

		cout << "Enter course name:";
		getline(cin, s);
		if(s.length() > 0)
			course->set_name(s);

		int id = course->save();
		delete course;

		cout << "Course was saved woth id #" << id << endl;
	}
	else if(response == 3)
	{
		cout << "Enter id:";
		int id; cin >> id; getline(cin, s);

		Course* course = Course::load(id);

		cout << "Course name: " << course->get_name() << endl;
		cout << "Prerequisite: " << endl;
		List<Course*>* prerequisites = course->get_prerequisites();
		for(Node<Course*>* it = prerequisites->begin(); it != nullptr; it = it->GetNext())
		{
			Course* course = *(*it);
			cout << "#" << course->get_id() << ": " << course->get_name() << endl;
		}

		delete course;
	}
	else if(response == 4)
	{
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
	else if(response == 5)
	{
		cout << "Enter id:";
		int id; cin >> id; getline(cin, s);

		Course* course = Course::load(id);
		course->trash();

		delete course;
	}
	else if(response == 6)
	{
		cout << "Enter id:";
		int id; cin >> id; getline(cin, s);
		Course* course = Course::load(id);

		cout << "Enter prerequisite course id:";
		cin >> id; getline(cin, s);
		Course* course2 = Course::load(id);

		course->add_prerequisite(course2);
		course->save();

		delete course;
		delete course2;
	}
	else if(response == 7)
	{
		cout << "Enter id:";
		int id; cin >> id; getline(cin, s);
		Course* course = Course::load(id);

		cout << "Enter prerequisite course id:";
		cin >> id; getline(cin, s);
		Course* course2 = Course::load(id);

		course->remove_prerequisite(course2);
		course->save();

		delete course;
		delete course2;
	}
}
