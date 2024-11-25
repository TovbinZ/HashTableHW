#include "College.h"
void College::addCourse()
{
	string name;
	int num;
	cout << "enter course name" << endl;
	cin >> name;
	cout << "enter course id" << endl;
	cin >> num;
	// TODO: Add the course to the courses table
}
void College::removeCourse()
{
	int num;
	cout << "enter course id" << endl;
	cin >> num;
	// TODO: Remove the course from the course table
}
void College::addStudent()
{
	string name;
	cout << "enter students name" << endl;
	cin >> name;
	list<int> lst;
	// TODO: Insert the student to the students table
}
void College::removeStudent()
{
	string name;
	cout << "enter students name" << endl;
	cin >> name;
	// TODO: Remove the student from the student table
}
void College::registration()
{
	string name;
	cout << "enter students name" << endl;
	cin >> name;
	int num;
	cout << "enter course id" << endl;
	cin >> num;
	try {
		// TODO: add the course id (if it exists) to the end of the student's course-list
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}
void College::removeReg()
{
	string name;
	cout << "enter students name" << endl;
	cin >> name;
	int num;
	cout << "enter course id" << endl;
	cin >> num;
	try {
		// TODO: remove the course id (if it exists) from the student's list
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}
void College::print()
{
	string name;
	cout << "enter students name" << endl;
	cin >> name;
	try {
		list<int> lst; // TODO: fix, so this would be the student's courses lis
		for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		{
			int k = *it;
			Course c; // TODO: fix
			cout << c.getName() << ' ';
		}
		cout << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

}
void College::printStudentsTable() {
	students.print();
}
void College::printCoursesTable() {
	courses.print();
}