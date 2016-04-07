#include"DBManager.h"
#include"User.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
  cout << "main\n";
  DBManager* db = DBManager::get_singleton();

  string * data;
  int data_len = 2;

  cout << "Storing from main\n";
  data = new string[data_len];
  data[0] = "Student 1";
  data[1] = "Password 1";
  db->store("User", 5, data_len, data);

  cout << "Loading from main\n";
  delete[] data;
  data = NULL;
  data = db->load("User", 3, data_len);
  cout << "Username = " << data[0] << ", Password = " << data[1] << endl;
  

  User* user1=new User();
  
     user1->save();
	 user1->save();
	 user1->load(3);
	 return 0;
}
