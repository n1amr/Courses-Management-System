#include"Form.h"
#include"iostream"
#include"fstream"
#include "User.h"
using namespace std;



bool is_registered()
{
	string username, password, user, pass;
	cout << "Enter your username: "; cin >> username;
	cout << "Enter your password: "; cin >> password;
	ifstream read("data\\users\\" + username + ".txt");
	getline(read, user);
	getline(read, pass);
	if (username == user&&password == pass) //replace user & pass -> getusername and getpassword from DbManager 
	{
		return true;
	}
	else
		return false;
}
int main()
{
	cout << "main starts" << endl;

	int choice;
	string username,password;
	ofstream reg;
	//User* u =new User();
	cout << "1- Admin\n2- Signup\n3- Signin\n4- Exit\n Your choice: " ;
	cin >> choice;
	switch (choice)
	{
	
    case 1:
		system("cls");
		run_form();
		system("cls");
		main();

	case 2:
		system("cls");
		cout << "Select your username: ";
		cin >> username;
		cout << "Select your password : ";
		cin >> password;
		reg.open("data\\users\\" + username + ".txt");
		if (!reg)
		{
			cout << "you are registered before";
		}
		else
		{
			//u->set_username(username);
			//u->set_password(password)
			reg << username << endl << password;
			reg.close();
			cout << "you have sucesifully registered !\n";
		}
		main();

	case 3:
		system("cls");
		if (!is_registered())
		{
			cout << "your username and password are not correct\n ";
			return 0;
		}
		else
		{
			cout << "you are successifully logged in \n";
			return 1;
		}

	case 4:
		break;
	default: 
		break;
	}
	return 0;
}

