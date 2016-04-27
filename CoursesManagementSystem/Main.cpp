#include"AdminForm.h"
#include"UserManager.h"
#include"Course.h"
#include"User.h"
#include"iostream"
#include "UserForm.h"

using namespace std;

void clear_screen();
User* is_registered(string username, string password);
void signup();
void signin();

int main()
{
	clear_screen();

	int choice;
	while (true)
	{
		cout << "1- Admin\n2- Signup\n3- Signin\n4- Exit\n Your choice: ";
		cin >> choice;
		if (choice == 1)
		{
			clear_screen();
			AdminForm::run_form();
			clear_screen();
			main();
		}
		else if (choice == 2)
			signup();
		else if (choice == 3)
			signin();
		else
			return 0;
	}
}

void signin()
{
	clear_screen();
	string username, password;
	cout << "Enter your username: ";
	cin >> username;
	cout << "Enter your password: ";
	cin >> password;
	User *user = is_registered(username, password);
	if (user == nullptr)
		cout << "your username and password are not correct\n ";
	else
	{
		cout << "you are successfully logged in \n";
		UserForm userForm(user);
		userForm.run_form();
	}
}

void signup()
{
	clear_screen();

	string username, password;
	clear_screen();
	cout << "Select your username: ";
	cin >> username;
	cout << "Select your password : ";
	cin >> password;
	User **users = User::loadAll();
	User *u = new User();
	int count = DBManager::get_singleton()->get_last_id("user") + 1;
	bool found = false;
	for (int i = 0; i < count; i++)
	{
		User *user = users[i];
		if (user != nullptr && username == user->get_username())
		{
			found = true;
			break;
		}
	}
	if (found)
		cout << "Sorry,you already registered before\n";
	else
	{
		u->set_username(username);
		u->set_password(password);
		u->save();
		cout << "you have successfully registered !\n";
	}
}

void clear_screen()
{
#ifdef _WIN32
	system("cls");
#endif
#ifdef __linux__
	system("clear");
#endif
}

User *is_registered(string username, string password)
{
	User **users = User::loadAll();
	int count = DBManager::get_singleton()->get_last_id("user") + 1;
	for (int i = 0; i < count; i++)
	{
		User *user = users[i];
		if (user != nullptr && username == user->get_username() && password == user->get_password())
				return user;
	}

	return nullptr;
}
