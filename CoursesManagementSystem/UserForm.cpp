#include <iostream>
#include "UserForm.h"
#include "UserManager.h"
#include "CourseManager.h"
#include "Helper.h"

void UserForm::view_user() {
    UserManager::view_user(user->get_id());
}

void UserForm::edit_user() {
    string username, password;

    cout << "Edit username(" << user->get_username() << "):" ;
    getline(cin,username);

    cout << "Edit password(" << user->get_password() << "):" ;
    getline(cin, password);

    UserManager::edit_user(user->get_id(),username,password);
		user = User::load(user->get_id()); // Reload
}

void UserForm::delete_user() {
    UserManager::delete_user(user->get_id());
}

void UserForm::add_user_course() {
    int course_id;
    cout << "Enter course id" << endl;
    cin >> course_id;
    string s;
    getline(cin, s);

    UserManager::add_user_course(user->get_id(),course_id);
}

void UserForm::remove_user_course() {
    int course_id;
    cout << "Enter course id" << endl;
    cin >> course_id;
    string s;
    getline(cin, s);

    UserManager::remove_user_course(user->get_id(),course_id);
}

void UserForm::list_all_courses() {
    List<Course*> *courses = Course::loadAll();
    for(Node<Course*> *it = courses->begin(); it != nullptr; it = it->GetNext())
    {
        Course *course = *(*it);
        cout << "ID: " << course->get_id() << endl;
        cout << "Name: " << course->get_name() << endl;
				cout << "Prerequisites: ";
				for(Node<Course*> *it2 = course->get_prerequisites()->begin(); it2 != nullptr; it2 = it2->GetNext()) {
					Course *preq= *(*it2);
					cout << preq->get_name() << ", ";
				}
        cout << endl << "------------------------"<< endl << endl;
    }
}

void UserForm::list_user_courses()
{
    List<Course*> *courses = user->get_courses();
    for(Node<Course*> *it = courses->begin(); it != nullptr; it = it->GetNext())
    {
        Course *course = *(*it);
        cout << "ID: " << course->get_id() << endl;
        cout << "Name: " << course->get_name() << endl;
        cout << "------------------------"<< endl << endl;
    }
}

void UserForm::view_course() {
    int course_id;
    cout << "Enter course id" << endl;
    cin >> course_id;
    string s;
    getline(cin, s);

    CourseManager::view_course(course_id);
}

UserForm::UserForm(User* user) {
    this->user = user;
}

void UserForm::run_form() {
    string s;

    while(true) {
        Helper::clear_screen();

        cout << "Select operation:" << endl;
        cout << "	1- View profile." << endl;
        cout << "	2- Edit profile." << endl;
        cout << "	3- Delete profile." << endl;
        cout << "	4- Add course." << endl;
        cout << "	5- Remove course." << endl;
        cout << "	6- List my courses." << endl;
        cout << "	7- List all courses." << endl;
        cout << "	8- View course." << endl;
        cout << "	9- Sign out." << endl;
        int response = -1;
        cin >> response;
        getline(cin, s);
        if (response == 1)
            view_user();
        else if (response == 2)
            edit_user();
        else if (response == 3)
            delete_user();
        else if (response == 4)
            add_user_course();
        else if (response == 5)
            remove_user_course();
        else if (response == 6)
            list_user_courses();
        else if (response == 7)
            list_all_courses();
        else if (response == 8)
            view_course();
        else if (response == 9)
            return;

        cout << "Press [ENTER] to continue";
        getline(cin, s);
    }
}
