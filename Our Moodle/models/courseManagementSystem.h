#ifndef COURSEMANAGEMENTSYSTEM_H
#define COURSEMANAGEMENTSYSTEM_H

#include <Windows.h>
#include <string>
#include <conio.h>
#include <iostream>
#include "commandReader.h"
#include "schoolYear.h"
#include "semester.h"
#include "class.h"
#include "student.h"
#include "course.h"
#include "user.h"
using namespace std;

void gotoxy(int x, int y);
void delay(unsigned int mseconds);
void set_console_size();
void Loading();
void Heading();

void LoginWindow(); 
    void studentMenu();
        void studentMenu_addCourse();
        void studentMenu_removeCourse(); 
        void studentMenu_viewCourse(); 
        void studentMenu_viewScoreboard();
    void staffMenu();
        void staffMenu_createSchoolYear();
        void staffMenu_createSemester();
        void staffMenu_courseManagement();
            void staffMenu_courseManagement_createRegistration();
            void staffMenu_courseManagement_addCourse();
            void staffMenu_courseManagement_updateCourse();
            void staffMenu_courseManagement_deleteCourse();
            void staffMenu_courseManagement_viewCourse();
            void staffMenu_courseManagement_viewCourse_menu();
                void staffMenu_courseManagement_viewCourse_viewStudent();
                void staffMenu_courseManagement_viewCourse_exportScoreboard();
                void staffMenu_courseManagement_viewCourse_importScoreboard();
                void staffMenu_courseManagement_viewCourse_viewScoreboard();
        void staffMenu_classManagement();
            void staffMenu_classManagement_createClass();
            void staffMenu_classManagement_viewClass();
            void staffMenu_classManagement_viewClass_menu();
                void staffMenu_classManagement_viewClass_addStudent();
                void staffMenu_classManagement_viewClass_viewStudent();
                void staffMenu_classManagement_viewClass_viewScoreboard();
        void staffMenu_studentManagement();
            void staffMenu_studentManagement_updateStudentResult();

/* folder data
currentYear.txt
currentSemester.txt
currentClass.txt
currentCourse.txt
classes
    classList.txt
    class1
        studentList.txt
        student1.txt
        student2.txt
        ...
    class2
    ...
year
    semester1
        info.txt
        registration.txt
        students
            student1
                courses.txt
                marks.txt
            student2
            ...
        courses
            courseList.txt
            course1
                info.txt
                students.txt
                marks.txt
            course2
            ...
*/

/* folder csvFile
year
    semester
        classes
            class.csv
        courses
            course.csv
*/
#endif 
