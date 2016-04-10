#ifndef _USER_FORM_HPP_
#define _USER_FORM_HPP_

#include"DBManager.h"
#include"User.h"
#include<iostream>
#include<string>
using namespace std;

void run_user_form()
{
	string s;

	while(true)
 	{
		cout << "Select opeation:" << endl;
		cout << "	1- List users." << endl;
		cout << "	2- Create user." << endl;
		cout << "	3- Retrieve user." << endl;
		cout << "	4- Edit user." << endl;
		cout << "	5- Delete user." << endl;
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

			delete user;
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
	}
}

// void run_user_form()
// {
// 	string s;

// 	while(true)
// 	{
// 		cout << "Select opeation:" << endl;
// 		cout << "	1- List users." << endl;
// 		cout << "	2- Create user." << endl;
// 		cout << "	3- Retrieve user." << endl;
// 		cout << "	4- Edit user." << endl;
// 		cout << "	5- Delete user." << endl;
// 		int response = -1;
// 		cin >> response; getline(cin, s);
// 		if(response == 1)
// 		{
// 			User** users = User::loadAll();

// 			// int count; cin >> count; getline(cin, s);
// 			int count = DBManager::get_singleton()->get_last_id("user") + 1;

// 			for(int i = 0; i < count; i++)
// 			{
// 				User *user = users[i];
// 				if(user != NULL)
// 				{
// 					cout << "User #" << i << endl;
// 					cout << "Username: " << user->get_username() << endl;
// 					cout << "Password: " << user->get_password() << endl;
// 					cout << endl;
// 				}
// 			}
// 		}
// 		else if(response == 2)
// 		{
// 			User* user = new User();

// 			cout << "Enter username:";
// 			getline(cin, s);
// 			if(s.length() > 0)
// 				user->set_username(s);
// 			cout << "Enter password:";
// 			getline(cin, s);
// 			if(s.length() > 0)
// 				user->set_password(s);

// 			int id = user->save();
// 			delete user;

// 			cout << "User was saved woth id #" << id << endl;
// 		}
// 		else if(response == 3)
// 		{
// 			cout << "Enter id:";
// 			int id; cin >> id; getline(cin, s);

// 			User* user = User::load(id);

// 			cout << "Username: " << user->get_username() << endl;
// 			cout << "Password: " << user->get_password() << endl;

// 			delete user;
// 		}
// 		else if(response == 4)
// 		{
// 			cout << "Enter id:";
// 			int id; cin >> id; getline(cin, s);

// 			User* user = User::load(id);

// 			cout << "Edit username(" << user->get_username() << "):" ;
// 			getline(cin, s);
// 			if(s.length() > 0)
// 				user->set_username(s);
// 			cout << "Edit password(" << user->get_password() << "):" ;
// 			getline(cin, s);
// 			if(s.length() > 0)
// 				user->set_password(s);

// 			id = user->save();
// 			cout << "User was saved woth id #" << id << endl;
// 			delete user;
// 		}
// 		else if(response == 5)
// 		{
// 			cout << "Enter id:";
// 			int id; cin >> id; getline(cin, s);

// 			User* user = User::load(id);
// 			user->trash();

// 			delete user;
// 		}
// 	}
// }

#endif
