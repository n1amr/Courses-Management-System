#include"AdminForm.h"

#include"DBManager.h"
#include"User.h"
#include"UserManager.h"
#include"Course.h"
#include"CourseManager.h"
#include<iostream>
#include<string>
#include"LinkedList.h"
#include"Node.h"
using namespace std;


#include"CourseManager.h"

#include"DBManager.h"
#include"User.h"
#include"Course.h"
#include<iostream>
#include<string>
using namespace std;

void CourseManager::list_courses()
{
	List<Course*>* courses = Course::loadAll();

	for(Node<Course*>* it = courses->begin(); it != nullptr; it = it->GetNext())
	{
		Course *course = *(*it);
		if(course != NULL)
		{
			cout << "Course #" << course->get_id() << endl;
			cout << "Name: " << course->get_name() << endl;
			cout << endl;
		}
	}
}

int CourseManager::create_new_course(string course_name)
{
	Course* course = new Course();

	if(course_name.length() > 0)
		course->set_name(course_name);

	int id = course->save();
	delete course;
	return id;
}

void CourseManager::view_course(int id)
{
	Course* course = Course::load(id);
	if(course == nullptr)
	{
		cout << "Course doesn't exist" << endl;
		return;
	}


	cout << "Course name: " << course->get_name() << endl;
	cout << "Prerequisite: " << endl;
	List<Course*>* prerequisites = course->get_prerequisites();
	for(Node<Course*>* it = prerequisites->begin(); it != nullptr; it = it->GetNext())
	{
		Course* course = *(*it);
		cout << "#" << course->get_id() << ": " << course->get_name() << endl;
	}
	delete course;
}

void CourseManager::edit_course(int id, string course_name)
{
	Course* course = Course::load(id);
	if(course == nullptr)
	{
		cout << "Course doesn't exist" << endl;
		return;
	}

	cout << "Edit course name(" << course->get_name() << "):" ;
	if(course_name.length() > 0)
		course->set_name(course_name);

	id = course->save();
	delete course;
}

void CourseManager::delete_course(int id)
{
	Course* course = Course::load(id);
	if(course == nullptr)
	{
		cout << "Course doesn't exist" << endl;
		return;
	}

	course->trash();

	delete course;
}

void CourseManager::add_course_prerequisites(int course_id, int prerequisite_course_id)
{
	Course* course = Course::load(course_id);
	if(course == nullptr) {
		cout << "Course doesn't exist" << endl;
		return;
	}
	Course* course2 = Course::load(prerequisite_course_id);
	if(course2 == nullptr) {
		cout << "Course doesn't exist" << endl;
		return;
	}

	course->add_prerequisite(course2);
	course->save();

	delete course;
	delete course2;
}

void CourseManager::remove_course_prerequisites(int course_id, int prerequisite_course_id)
{
	Course* course = Course::load(course_id);
	if(course == nullptr) {
		cout << "Course doesn't exist" << endl;
		return;
	}
	Course* course2 = Course::load(prerequisite_course_id);
	if(course2 == nullptr) {
		cout << "Course doesn't exist" << endl;
		return;
	}

	course->remove_prerequisite(course2);
	course->save();

	delete course;
	delete course2;
}
