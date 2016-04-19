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
	Course** courses = Course::loadAll();

	int count = DBManager::get_singleton()->get_last_id("course") + 1;

	for(int i = 0; i < count; i++)
	{
		Course *course = courses[i];
		if(course != NULL)
		{
			cout << "Course #" << i << endl;
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

	cout << "Edit course name(" << course->get_name() << "):" ;
	if(course_name.length() > 0)
		course->set_name(course_name);

	id = course->save();
	delete course;
}

void CourseManager::delete_course(int id)
{
	Course* course = Course::load(id);
	course->trash();

	delete course;
}

void CourseManager::add_course_prerequisites(int course_id, int prerequisite_course_id)
{
	Course* course = Course::load(course_id);
	Course* course2 = Course::load(prerequisite_course_id);

	course->add_prerequisite(course2);
	course->save();

	delete course;
	delete course2;
}

void CourseManager::remove_course_prerequisites(int course_id, int prerequisite_course_id)
{
	Course* course = Course::load(course_id);
	Course* course2 = Course::load(prerequisite_course_id);

	course->remove_prerequisite(course2);
	course->save();

	delete course;
	delete course2;
}
