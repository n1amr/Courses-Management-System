#include"DBManager.h"

#include<string>
#include<iostream>
using namespace std;

DBManager* DBManager::singleton = NULL;

DBManager* DBManager::get_singleton()
{
  if(singleton == NULL)
    singleton = new DBManager();
  return singleton;
}

int DBManager::store(string table_name, int id, int data_len, string* data)
{
  cout << "Storing to \"" << table_name << "\" table, id #" << id << ": ";
  for(int i = 0; i < data_len; i++)
  {
    cout << data[i] << "\t";
  }
  cout << endl;
  return -1;
}

string* DBManager::load(string table_name, int id, int data_len)
{
  string* data = new string[data_len];
  string s;

  for(int i = 0; i < data_len; i++)
  {
    cout << ">";
    cin >> data[i];
  }
  return data;
}
