#include"AdminForm.h"
#include"UserManager.h"
#include"User.h"
#include"iostream"
#include "UserForm.h"
#include "Helper.h"
using namespace std;

void signup();
void signin();

int main()
{
	string s;
	int choice;
	while(true)
	{
		Helper::clear_screen();
		cout << "\t1- Admin\n\t2- Signup\n\t3- Signin\n\t4- Exit\nYour choice: ";
		cin >> choice;
		getline(cin, s);

		if (choice == 1)
			AdminForm::run_form();
		else if (choice == 2)
			signup();
		else if (choice == 3)
			signin();
		else
			exit(0);

	}
}

void signin()
{
	Helper::clear_screen();

	string username, password;
	cout << "Enter your username: ";
	getline(cin, username);
	cout << "Enter your password: ";
	getline(cin, password);
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
	Helper::clear_screen();

	string username, password, password2;
	Helper::clear_screen();
	cout << "Select your username: ";
	getline(cin, username);
	cout << "Select your password : ";
	getline(cin, password);
	cout << "Confirm your password : ";
	getline(cin, password2);
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