#include"Form.h"
#include"iostream"
#include"fstream"
#include"User.h"
#include"LinkedList.h"
using namespace std;

void clear_screen();
bool is_registered();

int main()
{
	clear_screen();

	int choice;
	string username, password;
	ofstream reg;
	cout << "1- Admin\n2- Signup\n3- Signin\n4- Exit\n Your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		clear_screen();
		run_form();
		clear_screen();
		main();
	}
	else if (choice == 2)
	{
		clear_screen();
		cout << "Select your username: ";
		cin >> username;
		cout << "Select your password : ";
		cin >> password;
		User** users = User::loadAll();
		User *u = new User();
		int count = DBManager::get_singleton()->get_last_id("user") + 1;
		for (int i = 0; i < count; i++)
		{
			User *user = users[i];
			if (user != nullptr)
			{
				if (username == user->get_username())
				{
					cout << "Sorry,you already registered before\n";
				}
				else
				{
					u->set_username(username);
					u->set_password(password);
					u->save();
					cout << "you have sucessifully registered !\n";
				}
			}
		}

		main();
	}
	else if (choice==3)
	{
		clear_screen();
		if (!is_registered())
		{
			cout << "your username and password are not correct\n ";
			return 0;
		}
		else
		{
			cout << "you are successifully logged in \n";
			return 0;
		}
	}
	else
	{
		return 0;
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

bool is_registered()
{
	string username, password;
	cout << "Enter your username: "; cin >> username;
	cout << "Enter your password: "; cin >> password;
	User** users = User::loadAll();
	User *u = new User();
	int count = DBManager::get_singleton()->get_last_id("user") + 1;
	for (int i = 0; i < count; i++)
	{
		User *user = users[i];
		if (user != nullptr)
		{
			if (username == user->get_username()&&password== user->get_password())
			{
				return true;
			}
		}
	}

	return false;
}
