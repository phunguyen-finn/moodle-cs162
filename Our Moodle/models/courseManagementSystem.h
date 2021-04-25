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
using namespace std;

void gotoxy(int x, int y);
void delay(unsigned int mseconds);

void set_console_size();
void Loading();

bool adminLogin(std::string username, std::string password);
bool studentLogin(std::string username, std::string password);
void Heading();

void LoginWindow();
    void studentMenu();
        void studentMenu_addCourse();
        // year\semester\courses\course\students.txt
        // year\semester\classes\class\student\courses.txt
        void studentMenu_removeCourse(); 
        // year\semester\classes\class\student\courses.txt
        // year\semester\courses\course\students.txt
        void studentMenu_viewCourse(); 
        void studentMenu_viewScoreboard();
    void staffMenu();
        void staffMenu_createSchoolYear();
        // year
        void staffMenu_createSemester();
        // year\semester
        void staffMenu_courseManagement();
            void staffMenu_courseManagement_createRegistration();
            // year\semester\courseRegistration.txt
            void staffMenu_courseManagement_addCourse();
            // year\semseter\courses\courseList.txt
            // year\semester\courses\course\info.txt
            void staffMenu_courseManagement_updateCourse();
            // year\semester\courses\course\info.txt
            void staffMenu_courseManagement_deleteCourse();
            // year\semester\classes\class\student\courses.txt
            // year\semester\courses\course
            // year\semseter\courses\courseList.txt
            void staffMenu_courseManagement_viewCourse();
                void staffMenu_courseManagement_viewCourse_viewStudent();
                void staffMenu_courseManagement_viewCourse_exportScoreboard();
                // year\semester\courses\course\[courseCode].csv
                void staffMenu_courseManagement_viewCourse_importScoreboard();
                // year\semester\courses\course\mark.txt
                // year\semester\classes\class\student\mark.txt
                void staffMenu_courseManagement_viewCourse_viewScoreboard();
        void staffMenu_classManagement();
            void staffMenu_classManagement_createClass();
            // year\semester\classes\classList.txt
            void staffMenu_classManagement_viewClass();
                void staffMenu_classManagement_viewClass_addStudent();
                // year\semester\classes\class\studentList.txt
                // year\semester\classes\class\student\info.txt
                void staffMenu_classManagement_viewClass_viewStudent();
                void staffMenu_classManagement_viewClass_viewScoreboard();
        void staffMenu_studentManagement();
            void staffMenu_studentManagement_updateStudentResult();
            // year\semester\classes\class\student\mark.txt
            // year\semester\courses\course\mark.txt

/*
currentYear.txt
year
    currentSemester.txt
    semester
        info.txt
        registration.txt
        classes
            classList.txt
            class1
                studentList.txt
                student1
                    info.txt
                    courses.txt
                    marks.txt
                student2
                ...
            class2
            ...
        courses
            courseList.txt
            course1
                students.txt
                marks.txt
            course2
            ...
*/
#endif 
