//imports
#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

//Student constructor
Student::Student(char* inputName, int inputAge) {
	name = new char[1000];
	strcpy(name, inputName);
	age = inputAge;
}
//Student destructor
Student::~Student() {
	delete name;
}
//Get students name
char* Student::getName(){
	return name;
}
//set students name
void Student::setName(char* newName){
	strcpy(name, newName);
}
//get students age
int Student::getAge(){
	return age;
}
//set students age
void Student::setAge(int newAge){
	age = newAge;
}
//print student's info
void Student::print(){
	cout << "\nName: " << name << "\nAge: " << age << endl;
}
