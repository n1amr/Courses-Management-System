#include"AdminForm.h"
#include"UserManager.h"
#include"Course.h"
#include"User.h"
#include"iostream"
#include "UserForm.h"
using namespace std;

void clear_screen();
void signup();
void signin();

int main()
{
	clear_screen();

	int choice;
	while (true)
	{
		cout << "1- Admin\n2- Signup\n3- Signin\n4- Exit\nYour choice: ";
		cin >> choice;
		clear_screen();

		if (choice == 1)
			AdminForm::run_form();
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
	User *user = User::authenticate(username, password);
	if (user == nullptr)
		cout << "Your username and password are not correct" << endl;
	else
	{
		cout << "You are successfully logged in" << endl;
		UserForm userForm(user);
		userForm.run_form();
	}
}

void signup()
{
	clear_screen();

	string username, password, password2;
	clear_screen();
	cout << "Select your username: ";
	cin >> username;
	cout << "Select your password : ";
	cin >> password;
	cout << "Confirm your password : ";
	cin >> password2;
	User *u = User::is_registered(username);
	if (u != nullptr)
		cout << "Sorry,you already registered before" << endl;
	else if(password != password2)
		cout << "Passwords don't match" << endl;
	else
	{
		User *user = new User(username, password);
		user->save();
		cout << "You have successfully registered!" << endl;
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