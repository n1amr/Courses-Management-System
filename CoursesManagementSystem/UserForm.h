//
// Created by n1amr on 4/26/16.
//

#ifndef COURSESMANAGEMENTSYSTEM_USERFORM_H
#define COURSESMANAGEMENTSYSTEM_USERFORM_H


#include "User.h"

class UserForm {
private:
    User* user;
public:
    void view_user();
    void edit_user();
    void delete_user();
    void add_user_course();
    void remove_user_course();
    void list_courses();
    void view_course();

    UserForm(User *pUser);

    void run_form();
};


#endif //COURSESMANAGEMENTSYSTEM_USERFORM_H
