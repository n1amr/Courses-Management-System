#ifndef _COURSE_MANAGER_H_
#define _COURSE_MANAGER_H_

#include<string>
using namespace std;

class CourseManager
{
public:
	static void list_courses();
	static int create_new_course(string course_name);
	static void view_course(int id);
	static void edit_course(int id, string course_name);
	static void delete_course(int id);
	static void add_course_prerequisites(int course_id, int prerequisite_course_id);
	static void remove_course_prerequisites(int course_id, int prerequisite_course_id);


};

#endif
