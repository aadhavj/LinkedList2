//Header guards and imports
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;

//Creates class student
class Student{
	//public constructor, destructor, and functions
	public:
		Student(char*, int);
		~Student();
		char* getName();
		void setName(char*);
		int getAge();
		void setAge(int);
		void print();
	//private variables
	private:
		char* name;
		int age;
};
//end of header guard
#endif
