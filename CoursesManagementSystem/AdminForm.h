#ifndef _FORM_H_
#define _FORM_H_

class AdminForm
{
private:
	static void run_user_form();
	static void run_course_form();
	static void list_users();
	static void create_new_user();
	static void view_user();
	static void edit_user();
	static void delete_user();
	static void add_user_course();
	static void remove_user_course();
	static void list_courses();
	static void create_new_course();
	static void view_course();
	static void edit_course();
	static void delete_course();
	static void add_course_prerequisites();
	static void remove_course_prerequisites();

public:
	static void run_form();
};

#endif
