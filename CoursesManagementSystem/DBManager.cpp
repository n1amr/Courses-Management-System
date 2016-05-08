#include"DBManager.h"
#include<iostream>
#include<fstream>
#include <cstring>

using namespace std;

/* Helper functions */
string get_database_path() { return "database"; }
string get_table_path(string table_name) { return get_database_path() + "/" + table_name; }
string get_table_info_filename(string table_name) { return get_table_path(table_name) + "/info"; }
string get_entry_filename(string table_name, int id) { return get_table_path(table_name) + "/" + to_string(id) + ".dat"; }
bool file_exists(string filename) {
	ifstream f(filename.c_str());
	bool exists = f.good();
	f.close();
	return exists;
}

DBManager::DBManager()
{
}

DBManager* DBManager::singleton = NULL;

DBManager* DBManager::get_singleton()
{
	if(singleton == NULL)
		singleton = new DBManager();
		return singleton;
}

int DBManager::store(string table_name, int id, int data_len, string* data)
{
	bool new_entry = (id == -1);
	if(new_entry)
		id = get_last_id(table_name) + 1;

	// Write entry data into file
	ofstream fout(get_entry_filename(table_name, id));
	fout << id << endl;
	for(int i = 1; i < data_len; i++)
		fout << data[i] << endl;
	fout.close();

	// Update last id
	fout.open(get_table_info_filename(table_name));
	fout << id;
	fout.close();

	return id;
}

string* DBManager::load(string table_name, int id, int data_len)
{
	string s;
	string* data = new string[data_len];

	// Read entry file lines
	ifstream fin(get_entry_filename(table_name, id));
	for(int i = 0; i < data_len; i++)
		getline(fin, data[i]);
	fin.close();

	return data;
}

List<string*>* DBManager::loadAll(string table_name, int data_len)
{
	int last_id = get_last_id(table_name);

	List<string*>* rows = new List<string*>();

	for(int id = 0; id <= last_id; id++)
		if(file_exists(get_entry_filename(table_name, id)))
			rows->push_back(load(table_name, id, data_len));

	return rows;
}

bool DBManager::trash(string table_name, int id)
{
	bool successful = (remove(get_entry_filename(table_name, id).c_str()) == 0);
	return successful;
}

int DBManager::get_last_id(string table_name)
{
	int last_id = -1;

	ifstream fin(get_table_info_filename(table_name));
	fin >> last_id;
	fin.close();

	return last_id;
}