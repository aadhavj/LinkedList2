//Neccessary imports
#include <iostream>
#include "node.h"
#include <iomanip>
#include "Student.h"
using namespace std;

//Functions prototypes
void add(Student* &newStudent, Node* &head);
void printNode(Node* next, Node* head, int index);
void Delete(Node* &current, int IndexesAway, Node* previous);

int main(){
	//Basic var instantiation
	char command[1000];
	char inputName[1000];
	int inputID;
	float GPA;
	bool runProgram = true;
	Node* head = NULL;

	//Valid Command prompts
	char del[] = "DELETE";;
	char print[] = "PRINT";
	char addC[] = "ADD";
	char quit[] = "QUIT";
	char avg[] = "AVERAGE";

	while (runProgram){
                //Command parsing and prompting
		cout << "\nEnter Command (DELETE, PRINT, ADD, QUIT, AVERAGE): ";
                cin >> command;
		cin.ignore();
                command[7] = '\0';

                //Command recognition
		//Needs to identify by id num
                if (strcmp(command, del) == 0){
                        	cout << "Delete command initiated" << endl;
			if (head != NULL){
				int inputIndex;

				printNode(head,head, 0);

                        	//Gets student ID to delete
                        	cout << "Enter Student Index (Delete): ";
                        	cin >> inputIndex;
				cin.ignore();

                        	//Deletes at that index
                        	Delete(head, inputIndex, NULL);
			}
			else{
				cout << "\nNo objects to delete." << endl;
			}
                }
                else if (strcmp(command, print) == 0) {
			//Prints all objects in LinkedList
                        cout << "Print command initiated" << endl;
			if (head == NULL){
				cout << "\nNo students have been added." << endl;
			}
			else{
				printNode(head,head, 0);
			}
                }
                else if (strcmp(command, addC) == 0){

                        cout << "Add command initiated" << endl;

                        //Get input data
                        cout << "Full name: ";
                        cin.get(inputName, 999);

                        cout << "\nStudent ID: ";
                        cin >> inputID;
			cin.ignore();
                        cout << "\nStudent GPA: ";
                        cin >> GPA;
			cin.ignore();

                        //Assgin to object
			Student *createdStudent = new Student(inputName, inputID, GPA);

                        //Add to studentList array
			add(createdStudent, head);

                        cout << "Student Created!" << endl;
                }
                else if (strcmp(command, quit) == 0){

                        cout << "Quit command initiated. Program off." << endl;
                        //End Program functionality
                        runProgram = false;
                }
		else if (strcmp(command, avg) == 0){
			if (head == NULL){
				cout << "No student objects. Cannot find average." << endl;
			}
			else{
				Node* current = head;
				float sum = 0;
				int numOfGPA = 0;
				while (current != NULL){
					sum += current->getStudent()->getGPA();
					numOfGPA += 1;
					current = current->getNext();
				}
				cout << "Average score: " << fixed << setprecision(2) << sum / numOfGPA << endl;
				
			}
		}
                else {
                        //Invalid comands, print message
                        cout << "Command prompt unrecognized." << endl;
                }
        }

        //Farewell program end text
        cout << "Thank you for interacting with our student database. Please do so again!";

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
void printNode(Node* next, Node* head, int index){
	if (next == head) {
		cout << "list: ";
	}
	if (next != NULL) {
		cout << "Student " << index << endl;
		next->getStudent()->print();
		cout << endl;
		printNode(next->getNext(), head, index+1);
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
