#pragma once
#include<iostream>
#include "Entities.h"
using namespace std;

Student** students = new Student * [] {new Student{ new char[] {"Ali Ahmadov"},20,1 },
	{ new Student{new char[] {"Elgun Memmedov"},12,2} },
	{ new Student{new char[] {"Ugur Memmedov"},9,3} },
	{ new Student{new char[] {"Rufat Sadigov"},21,4} }
};

Teacher** teachers = new Teacher * [] {new Teacher{ new char[] {"Eltun Memmedli"},new char[] {"Programmer"},42,1 },
	{ new Teacher{new char[] {"Mobil Ahmadov"},new char[] {"IT Specialist"},24,2} },
	{ new Teacher{new char[] {"Javad Sadigov"},new char[] {"SQL Professional"},34,3} },
	{ new Teacher{new char[] {"Jack Jackson"},new char[] {"HTML Assistant"},37,4} }
};

Director** directors = new Director * [] {new Director{ new char[] {"Ruslan Memmedli"},new char[] {"Mathematician"},42,1 },
	{ new Director{new char[] {"Adil Adigozalov"},new char[] {"Physics"},45,2} },
	{ new Director{new char[] {"Mixaylo Medvedev"},new char[] {"Chemistry"},60,3} },
	{ new Director{new char[] {"Bob Billy"},new char[] {"Biology"},25,1} }
};

Group** groups = new Group * [] {new Group{ new char[] {"Programmers"},new char[] {"Programming"},
new Student * [] {new Student{ new char[] {"Ali Ahmadov"},20,1 },new Student{new char[] {"Elgun Memmedov"},12,2}},
new Teacher{new char[] {"Eltun Memmedli"},new char[] {"Programmer"},42,1},2 }};



Academy* academy = new Academy{ directors,groups };

int global_student_id = 1;



void ShowMenu() {

	cout << "Show All Teachers 1\n";
	cout << "Create Group      2\n";
	cout << "Show All Groups   3\n";

}


Student* getNewStudent() {

	cin.ignore();
	cin.clear();
	char* fullname = new char[100]{};
	cout << "Enter the fullname: ";
	cin.getline(fullname, 100);

	int age = 0;
	cout << "Enter the age: ";
	cin >> age;

	Student* student = new Student{ fullname,age,global_student_id };
	global_student_id++;

	return student;

}

int global_teacher_id = 1;
Teacher* getNewTeacher() {
	cin.ignore();
	cin.clear();

	char* fullname = new char[100]{};
	cout << "Enter the fullname: ";
	cin.getline(fullname, 100);

	char* speciality = new char[100]{};
	cout << "Enter the speciality: ";
	cin.getline(speciality, 100);

	int age = 0;
	cout << "Enter the age: ";
	cin >> age;

	Teacher* teacher = new Teacher{ fullname,speciality,age,global_teacher_id };
	global_teacher_id++;

	return teacher;

}

Teacher* getTeacherByid(Teacher** teachers, int id) {

	for (size_t i = 0; i < academy->teacher_count; i++)
	{
		if (teachers[i]->id == id) {
			return teachers[i];
		}
	}
	return nullptr;
}

Student** getStudentsById(Student** students, int*& arr_ids, int count) {
	int index = 0;
	Student** student_group = new Student * [count] {};
	for (size_t i = 0; i < academy->overall_student_count; i++)
	{
		for (size_t k = 0; k < count; k++)
		{
			if (students[i]->id == arr_ids[k]) {
				student_group[index] = students[i];
				index++;
			}
		}
	}
	return student_group;
}

void ShowStudent(Student* student) {

	cout << "ID: " << student->id << endl;
	cout << "Fullname: " << student->fullname << endl;
	cout << "Age: " << student->age << endl;
	cout << "======================================" << endl;
}

void ShowAllStudents(Student** students) {
	for (size_t i = 0; i < academy->overall_student_count; i++)
	{
		ShowStudent(students[i]);
	}
}
void ShowGroupStudents(Group* group) {


	for (size_t k = 0; k < group->student_count; k++)
	{

		ShowStudent(group->students[k]);
	}


}

void ShowAllTeachers(Teacher** teachers) {

	cout << "\n************************************\n";
	cout << "***********  Teachers  *************\n";
	cout << "************************************\n";
	for (size_t i = 0; i < academy->teacher_count; i++)
	{
		cout << "\n============================" << endl;
		cout << "ID: " << teachers[i]->id << endl;
		cout << "Fullname: " << teachers[i]->fullname << endl;
		cout << "Speciality: " << teachers[i]->speciality << endl;
		cout << "Age: " << teachers[i]->age << endl;
		cout << "\============================" << endl;

	}cout << endl;

}

int global_group_count = 0;
Group* getGroup() {
	cin.ignore();
	cin.clear();

	char* title = new char[100]{};
	cout << "Enter the title: ";
	cin.getline(title, 100);

	char* occupation = new char[100]{};
	cout << "Enter the occupation of the group: ";
	cin.getline(occupation, 100);

	ShowAllTeachers(teachers);
	int teacher_id = 0;
	cout << "Enter the teacher id: ";
	cin >> teacher_id;

	auto teacher = getTeacherByid(teachers, teacher_id);

	cout << endl;

	ShowAllStudents(students);
	int count_student = 0;
	cout << "Enter the number of students: ";
	cin >> count_student;

	int* arr = new int[count_student] {};
	for (size_t i = 0; i < count_student; i++)
	{
		int id_student = 0;
		cout << "Enter th student id: ";
		cin >> id_student;
		arr[i] = id_student;
	}

	auto student_group = getStudentsById(students, arr, count_student);

	Group* group = new Group{ title,occupation, student_group,teacher,count_student };
	global_group_count++;

	return group;
}

int number = 0;
void ShowGroup(Group* group) {
	cout << "GROUP NUMBER " << number + 1 << endl;
	cout << "\n============================" << endl;
	cout << "Title: " << group->title << endl;
	cout << "Occupation: " << group->occupation << endl;
	cout << "Teacher: " << group->teacher->fullname << endl;
	cout << "Student Count: " << group->student_count << endl;
	cout << "\n============================" << endl;
	number++;
	cout << "STUDENTS: " << endl;
	ShowGroupStudents(group);
}
void ShowAllGroups(Group** groups) {
	cout << "\n************************************\n";
	cout << "***********   GROUPS  ****************\n";
	cout << "**************************************\n";
	for (size_t i = 0; i < academy->group_count; i++)
	{
		ShowGroup(groups[i]);
	}
}

void AddnewGroups(Group* group) {
	auto newarray = new Group * [academy->group_count + 1]{};

	for (size_t i = 0; i < academy->group_count; i++)
	{
		newarray[i] = groups[i];
	}
	newarray[academy->group_count] = group;

	groups = newarray;
	newarray = nullptr;
	academy->group_count++;
}

#pragma once
