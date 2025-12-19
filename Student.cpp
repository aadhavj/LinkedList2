//imports
#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

//Student constructor
Student::Student(char* inputName, int inputID, float inputGPA) {
	name = new char[1000];
	strcpy(name, inputName);
	ID = inputID;
	GPA = inputGPA;
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
int Student::getID(){
	return ID;
}
//set students age
void Student::setID(int newID){
	ID = newID;
}
float Student::getGPA(){
	return GPA;
}
void Student::setGPA(float newGPA){
	GPA = newGPA;
}
//print student's info
void Student::print(){
	cout << "\nName: " << name << "\tID: " << ID << "\tGPA: " << GPA << endl;
}
