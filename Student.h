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
		Student(char*, int, float);
		~Student();
		char* getName();
		void setName(char*);
		int getID();
		void setID(int);
		float getGPA();
		void setGPA(float);
		void print();
	//private variables
	private:
		char* name;
		float GPA;
		int ID;
};
//end of header guard
#endif
