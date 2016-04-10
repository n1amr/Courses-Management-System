#include"DBManager.h"
#include"User.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	cout << "main\n";
	
	User* user1=new User();
	
	// TODO
	user1->set_username("username1");
	user1->set_password("password1");

	user1->save(); // save
	
	User* user2 = User::load(3);

	cout<< user2->get_username()<<"\n";
	cout << user2->get_password() << "\n";

	// TODO
	user2->set_username("username2_new"); // update values locally
	user2->set_password("password2_new");

	user2->save(); // commit updates to database
	
	cout << user2->get_username() << "\n";
	cout << user2->get_password() << "\n";

	return 0;
}
