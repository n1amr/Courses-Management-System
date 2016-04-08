#include"DBManager.h"
#include"User.h"

#include<string>
#include<iostream>
using namespace std;

User::User()
{
  id = -1;
}

User::User(string username, string password)
{
  this->username = username;
  this->password = password;
  this->id = -1;
}

void User::set_username(string username)
{
  this->username = username;
}

void User::set_password(string password)
{
  this->password = password;
}

string User::get_username()
{
  return username;
}

string User::get_password()
{
  return password;
}

User* User::load(int id)
{
  DBManager* db = DBManager::get_singleton();
  
  int data_len = 2;
  string *data = new string[data_len];
  
  User *user = new User();
  data = db->load("user", id, data_len);

  user->set_username(data[0]);
  user->set_password(data[1]);

  return user;
}

void User::save()
{
  DBManager* db = DBManager::get_singleton();
  
  int data_len = 2;
  string *data = new string[data_len];
  
  data[0] = username;
  data[1] = password;
  
  id = db->store("User", id, data_len, data); 
}
