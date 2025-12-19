//Neccessary imports
#include <iostream>
#include "node.h"
#include "Student.h"
using namespace std;

//Functions prototypes
void add(Student* &newStudent, Node* &head);
void printNode(Node* next, Node* head);
void Delete(Node* &current, int IndexesAway, Node* previous);

int main(){
	//Create student objects and set head object to null
	char inputName[1000];
	strcpy(inputName, "Random 1");
	Student* a = new Student(inputName,16);
	strcpy(inputName, "Random 2");
	Student* b = new Student(inputName, 17);
	strcpy(inputName, "Random 3");
	Student* c = new Student(inputName, 18);
	Node* head = NULL;
	
	//Add function demonstration
	cout << "Add function adds student objects to Linked List using getNext() setNext(), and Node() constructor" << endl;
	add(a,head);
	add(b,head);
	add(c,head);
	cout << "\n...added new nodes..." << endl;
	
	//Print function demonstration
	cout << "\nprintNode function uses getStudent()";
	printNode(head,head);
	
	//Delete function demonstration
	cout << "Deleting student using node destructor" << a->getName() << endl;
	Delete(head,0,NULL);
	printNode(head,head);

	return 0;
}
//Add function
void add(Student* &newStudent, Node* &head){
	Node* current = head;
	if (current == NULL){
		head = new Node(newStudent);
	}
	else{
		while (current->getNext() !=  NULL) {
			current = current->getNext();
		}
		current->setNext(new Node(newStudent));
	}
}

//Print function
void printNode(Node* next, Node* head){
	if (next == head) {
		cout << "list: ";
	}
	if (next != NULL) {
		next->getStudent()->print();
		cout << endl;
		printNode(next->getNext(), head);
	}
	else{
		cout << endl;
	}
}

//delete function
void Delete(Node* &current, int IndexesAway, Node* previous){
	Node* temp = current->getNext();
	if (IndexesAway == 0){
		if (previous == NULL){
			delete current;
			current = temp;
		}
		else if (current->getNext() == NULL){
			previous->setNext(NULL);
			delete current;

		}
		else{
			previous->setNext(current->getNext());
			delete current;
		}
	}
	else{
		Delete(temp, IndexesAway-1, current);
	}
}
