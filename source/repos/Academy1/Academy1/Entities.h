#pragma once
#pragma once
#pragma once
#include<iostream>
using namespace std;
struct Teacher {
	char* fullname;
	char* speciality;
	int age;
	int id;
};

struct Director {
	char* fullname;
	char* speciality;
	int age;
	int id;
};
struct Student {
	char* fullname;
	int age;
	int id;
};
struct Group {
	char* title;
	char* occupation;
	Student** students;
	Teacher* teacher;
	int student_count;
};
struct Academy {
	Director** directors;
	Group** groups;
	Teacher** teachers;
	int teacher_count = 4;
	int group_count = 1;
	int overall_student_count = 4;
};


