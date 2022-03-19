#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream> 

using namespace std;


//Student Class
class Student{
	private:
		int ID = NULL;
		char* firstName = NULL;
		char* lastName = NULL;
		float GPA = NULL;
		Student* next;
	
	public:
		Student();
		Student(int id, char *first_name, char *last_name, float grade);
		Student(Student &init);
		~Student();
		
		Student& operator=(Student const &stu)
	{
		this->ID = stu.ID;
		setfirstName(stu.firstName);
		setlastName(stu.lastName);
		this->GPA = stu.GPA;
		cout << "Student Assignment Operator \n";
		return *this;
	}
	
	//Student get Functions
	int getID(){
		return ID;
	} 
	float getGPA(){
		return GPA;
	}
	char* getfirstName(){
		return firstName;
	}
	char* getlastName(){
		return lastName;
	}
	Student* getNext(){
		return next;;
	}
	
	//Student set Functions
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// Since the length of the string are no longer cap at 30 chars, we have to change the size of malloc
	// to fit with the string by using strlen() + 1//////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	void setID(int id){
		ID = id;
	}
	void setGPA(float grade){
		GPA = grade;
	}
	void setfirstName(char *first_name){
		free(firstName);
		firstName = (char*)malloc(sizeof(strlen(first_name)+1));
		strcpy(firstName,first_name);
	}
	void setlastName(char *last_name){
		free(lastName);
		lastName = (char*)malloc(sizeof(strlen(last_name)+1));
		strcpy(lastName,last_name);
	}
	void setNext(Student* adj){
		next = adj;
	}
};

Student* headNode = NULL;

Student :: Student(){
	this->ID = 0000;
	this->firstName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this -> firstName, (char*)"<unknown>");
	this->lastName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this-> lastName, (char*) "<unknown>");
	this->GPA = 0.0;
	this->next = NULL; 
	cout << "Default constructor \n";
}

Student :: Student(int id, char* first_name, char* last_name, float grade)
{
	this->ID = id;
	this->firstName = (char*) malloc(sizeof(strlen(first_name)+1));
	strcpy(this->firstName, first_name);
	this->lastName = (char*) malloc(sizeof(strlen(last_name)+1));
	strcpy(this->lastName, last_name);
	this->GPA = grade;
	this->next = NULL;
}

Student :: Student(Student &init)
{
	ID = init.ID;
	GPA = init.GPA;
	if(init.firstName != NULL)
	{
		setfirstName(init.firstName);
	}
	if(init.lastName != NULL)
	{
		setlastName(init.lastName);
	}
	cout << "Student Copy Constructor \n";
}

Student :: ~Student()
{
	
	if(firstName)
	{
		free(firstName);
	}
	if(lastName)
	{
		free(lastName);
	}
	cout << "Student Deconstructor " << firstName << " " <<lastName << endl;
}

//Function to add a new Student
void addNode(Student* newNode){
	Student* currentNode = headNode; 
	if (headNode == NULL){
		headNode = newNode;
		return;
	}
	while(currentNode-> getNext() != NULL){
		currentNode = currentNode->getNext();
	}
	currentNode->setNext(newNode);
	newNode->setNext(NULL);
}

//Function to insert a new student
void insertNode(Student* newNode){
	Student* list = headNode;
	while(list->getNext() != NULL){
		Student* nextNode = list->getNext();
		if((list -> getGPA() > newNode -> getGPA()) && (newNode -> getGPA() >= nextNode -> getGPA())){
			newNode->setNext(list->getNext());
			list->setNext(newNode);
			return;
		}
		else if(list -> getGPA() <= newNode -> getGPA()){
			newNode->setNext(list);
			headNode = newNode;
			return;
		}
		list = list->getNext();
	}
	list->setNext(newNode);
	newNode->setNext(NULL);
	return;
}

//Function to delete a student
void deleteNode(Student* newNode){
	Student* currentNode = headNode;
	Student* prevNode = NULL;
	
	if(headNode == newNode){
		headNode = headNode->getNext();
		delete newNode;
		return;
	}
	
	while(currentNode != NULL && currentNode != newNode){
		prevNode = currentNode;
		currentNode = currentNode->getNext();
	}
	
	if(currentNode != NULL){
		prevNode->setNext(currentNode->getNext());
	}
	
	delete newNode;
}

//Function to read students.txt file
void readFile(){
	ifstream FILE;
	int in_ID = NULL;
	char* first_Name = NULL;
	char* last_Name = NULL;
	float in_gpa = NULL;
	int studentNum = 0;

	FILE.open("students.txt"); //reads the text file
	
	if(!FILE.is_open()){
		cout << "File does not exist\n"; //checking if the file exists
	}
	else{
		string fill = "";
		FILE >> fill;
		FILE >> fill;
		FILE >> fill;
		//FILE >> fill;
		FILE >> studentNum;
		cout << "Number of Student: " << studentNum;
		for(int i = 0; i < studentNum; i++){
			FILE >> fill;
			FILE >> fill;
			FILE >> in_ID;
			FILE >> fill;
			FILE >> fill;
			FILE >> fill;
			first_Name = (char*)malloc(strlen((fill.c_str())+1));
			strcpy(first_Name, fill.c_str());
			FILE >> fill;
			FILE >> fill;
			FILE >> fill;
			last_Name = (char*)malloc(strlen((fill.c_str())+1));
			strcpy(last_Name, fill.c_str());
			FILE >> fill;
			FILE >> fill;
			FILE >> in_gpa;
			Student* fileNode = new Student(in_ID, first_Name, last_Name, in_gpa);
			addNode(fileNode);
			free(first_Name);
			free(last_Name);
		}
	}
	FILE.close();
}


void removeStudent(int id){
	Student* list = headNode;
	while(list != NULL){
		if(id == list->getID()){
			char first_name[30];
			char last_name[30];
			strcpy(first_name, list->getfirstName());
			strcpy(last_name, list->getlastName());
			deleteNode(list);
			printf("Student deleted");
			return;
		}
		list = list-> getNext();
	}
	return; 
}

void listStudent(){
	Student* list = headNode;
	while(list != NULL){
		printf("\nStudent ID: %d", list -> getID());
		printf("\nStudent first name: %s", list -> getfirstName());
		printf("\nStudent last name: %s", list -> getlastName());
		printf("\nStudent GPA: %f\n\n", list -> getGPA());
		list = list ->getNext();
	}
}

void menu(){
	printf("\n1) List all Students\n");
	printf("2) Add Student\n");
	printf("3) Remove Student\n");
	printf("4) Update Student\n");
	printf("5) Quit\n");

}

void updateMenu(char fi[30], char la[30])
{
	printf("What would you like to update? %s %s?\n", fi, la);
	printf("1) ID \n");
	printf("2) First Name \n");
	printf("3) Last Name \n");
	printf("4) GPA \n");
	printf("5) Quit \n");
}

void updateStudent(int id){
	Student* list = headNode;
	Student* prevList = list;
	//int c = 0;
	int options = 0;
	while(list != NULL){
		if(id == list->getID()){
			do{
				updateMenu(list->getfirstName(), list-> getlastName());
				cout << "What do you want to do? ";
				cin >> options;
				
				int nextID, prevID = 0;
				char *nextFirstName, *prevFirstName = NULL;
				char *nextLastName, *prevLastName = NULL;
				float nextGPA, prevGPA = 0;
				string fill = "";
				Student* updateList = headNode;
				
				switch(options){
					case 1: 
						cout << "Enter new ID:";
						cin >> nextID;
						while(updateList != NULL){
							if(nextID == updateList -> getID()){
								cout << "Enter a different id\n";
								updateList = headNode;
								cout << "Enter updated ID of student: ";
								cin >> nextID;;
							}
							updateList = updateList ->getNext();
						}
						prevID = list->getID();
						list->setID(nextID);
					case 2:
						cout << "\nEnter updated first name: ";
						cin >> fill;
						nextFirstName = (char*)malloc(strlen((fill.c_str())+1));
						strcpy(nextFirstName, fill.c_str());
						prevFirstName = (char*)malloc(strlen(list->getfirstName()+1));
						strcpy(prevFirstName, list->getfirstName());
						list->setfirstName(nextFirstName);
						free(nextFirstName);
						free(prevFirstName);
						break;
					case 3:
						cout << "\nEnter updated name name: ";
						cin >> fill;
						nextLastName = (char*)malloc(strlen((fill.c_str())+1));
						strcpy(nextLastName, fill.c_str());
						prevLastName = (char*)malloc(strlen(list->getlastName()+1));
						strcpy(prevLastName, list->getlastName());
						list->setlastName(nextLastName);
						free(nextFirstName);
						free(prevFirstName);
						break;
					case 4: 
						cout << "\nEnter updated GPA: ";
						cin >> nextGPA;
						prevGPA = list -> getGPA();
						list -> setGPA(nextGPA);
						if(prevList == list){
							list -> setNext(NULL);
							insertNode(list);
						}
						else{
							prevList-> setNext(list->getNext());
							insertNode(list);
						}
					case 5:
						break;
				}
			}
			while(options != 5);
			return;
		}
		prevList = list;
		list = list-> getNext();
	}
}

void saveFile(){
	ofstream FILE;
	Student* list = headNode;
	int studentNum = 0;

	FILE.open("students.txt"); //reads the text file
	
	while(list != NULL){
		studentNum++;
		list = list->getNext();
	}
	if (!FILE.is_open()){
		cout << "File does not exist\n";
	}
	else{
		FILE << "Number of Student: "<< studentNum;
		while(list != NULL){
			FILE << "\nStudent ID: " << list->getID();
			FILE << "\nStudent first name: " << list->getfirstName();
			FILE << "\nStudent last name: " << list->getlastName();
			FILE << "\nStudent GPA: \n\n" << list->getGPA();
			list = list->getNext();
		}
	}
	FILE.close();
}

int main()
{
	int options = 0;
	readFile();
	do{
		int yourID = 0;
		char *firName = NULL;	
		char *lasName = NULL;
		float megrades = 0;
		string fill = "";
		Student* id = headNode;
		menu();
		cout << "What do you want to do? \n\n";
		cin >> options;
		switch(options){
			case 1:
				listStudent();
				break;
			case 2: {
				cout << "Student ID: \n"; 
				cin >> yourID;
				while(id != NULL){
					if(yourID == id->getID()){
						cout << "ID is in use, use another one. \n";
						id = headNode;
						cout << "Enter a new id \n";
						cin >> yourID;
					}
					id = id->getNext();
				}
				
				cout << "Student first name: \n";
				cin >> fill;
				firName = (char*)malloc(strlen((fill.c_str())+1));
				strcpy(firName, fill.c_str());
				
				cout << "Student last name: \n";
				cin >> fill;
				lasName = (char*)malloc(strlen((fill.c_str())+1));
				strcpy(lasName, fill.c_str());
				
				cout << "Student GPA: \n";
				cin >> megrades;
				
				Student* ptr = new Student(yourID, firName, lasName, megrades);
				insertNode(ptr);
				free(firName);
				free(lasName);
				break;
			}
			case 3: 
				cout << "Enter ID of student to remove: ";
				cin >> yourID;
				removeStudent(yourID);
				break;
			case 4:
				cout << "Enter id of student to update:";
				cin >> yourID;
				updateStudent(yourID);
				break;
			case 5:
				break;
		}
	}
	while(options != 5);
	saveFile();
}