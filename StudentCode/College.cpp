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
	this->courses.insert(num, name);
}
void College::removeCourse()
{
	int num;
	cout << "enter course id" << endl;
	cin >> num;
	// TODO: Remove the course from the course table
	this->courses.remove(num);
}
void College::addStudent()
{
	string name;
	cout << "enter students name" << endl;
	cin >> name;
	list<int> lst;
	// TODO: Insert the student to the students table
	this->students.insert(name, lst);
	
}
void College::removeStudent()
{
	string name;
	cout << "enter students name" << endl;
	cin >> name;
	// TODO: Remove the student from the student table
	students.remove(name);
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
		this->courses.search(num);
		this->students.search(name).push_back(num);
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
		courses.search(num);
		students.search(name).remove(num);

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
		list<int> lst = students.search(name);// TODO: fix, so this would be the student's courses lis 
		//if (lst.size() == 1)
		//	cout << courses.search(*lst.begin());
		for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		{
			int k = *it;
			Course c = courses.search(k); // TODO: fix
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
