#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
	int ID;
	char firstName[30];
	char lastName[30];
	float GPA;
	struct student* next;
} Student;

Student* headNode = NULL;

//Function to create new student
Student* createStudent(int id, char first[30],char last[30],float grade){
	Student* newNode = NULL;
	newNode = (Student *)malloc(sizeof(Student));
	if( newNode != NULL){

		newNode -> ID = id;
		strcpy(newNode -> firstName,first ); 
		strcpy(newNode -> lastName, last); 
		newNode -> GPA = grade; 
		newNode->next = NULL;
	}
	return newNode;
}

//Function to add new student
void addNode(Student* newNode){
	Student* currentNode = headNode; 
	if (headNode == NULL){
		headNode = newNode;
		return;
	}
	while(currentNode-> next != NULL){
		currentNode = currentNode->next;
	}
	currentNode->next = newNode;
	newNode->next = NULL;
}


//Function to insert a new student
void insertNode(Student* newNode){
	Student* list = headNode;
	while(list->next != NULL){
		Student* nextNode = list->next;
		if((list -> GPA > newNode -> GPA) && (newNode -> GPA >= nextNode -> GPA)){
			newNode->next = list -> next;
			list->next = newNode;
			return;
		}
		else if(list -> GPA <= newNode -> GPA){
			newNode->next = list;
			headNode = newNode;
			return;
		}
		list = list->next;
	}
	list->next = newNode;
	newNode->next = NULL;
	return;
}


//Function to delete a student
void deleteNode(Student* newNode){
	Student* currentNode = headNode;
	Student* prevNode = NULL;
	
	if(headNode == newNode){
		headNode = headNode->next;
		free(newNode);
		return;
	}
	
	while(currentNode != NULL && currentNode != newNode){
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	
	if(currentNode != NULL){
		prevNode->next = currentNode->next;
	}
	
	free(newNode);
}


/////////MAIN FUNCTION//////////////////
int main()
{
	int options;
	readFile();
	do{
		int yourID;
		char firName[30] = "";	
		char lasName[30] = "";
		float megrades;
		
		Student* id = headNode;
		menu();
		printf("What do you want to do?:\n");
		scanf("%d",&options);
		switch(options){
			case 1:
				listStudent();
				break;
			case 2: 
				printf("Student ID:\n"); 
				scanf("%d", &yourID);
				while(id != NULL){
					if(yourID == id->ID){
						printf("ID is in use, use another one. \n");
						id = headNode;
						printf("Enter a new id \n");
						scanf("%d", &yourID);
					}
					id = id->next;
				}
				
				printf("Student first name:\n");
				scanf("%s", firName);
				printf("Student last name:\n");
				scanf("%s", lasName);
				printf("Student GPA:\n");
				scanf("%f",&megrades);
				
				Student* ptr = createStudent(yourID, firName, lasName, megrades);
				insertNode(ptr);
				break;
			case 3: 
				printf("Enter ID of student to remove:");
				scanf("%d", &yourID);
				removeStudent(yourID);
				break;
			case 4:
				printf("Enter id of student to update:");
				scanf("%d", &yourID);
				updateStudent(yourID);
				break;
			case 5:
				break;
		}
	}
	while(options != 5);
	saveFile();
	freeNode();
}

//Function to detele all students info and free the memory
void freeNode(){
	Student* list = headNode;
	Student* nodenode = headNode->next;
	while(list != NULL){
		deleteNode(list);
		list = nodenode;
		nodenode = nodenode -> next;
	}
}


void saveFile(){
	FILE *fp;
	fp = fopen("students.txt", "w+");
	Student* list = headNode;
	int studentNum = 0;
	while(list != NULL){
		studentNum++;
		list = list->next;
	}
	fprintf(fp, "Number of Students: %d\n", &studentNum);
	list = headNode;
	while( list != NULL){
		fprintf(fp, "Number of Students: %d\n", list->ID);
		fprintf(fp, "Student first name: %s\n", list->firstName);
		fprintf(fp, "Student last name: %s\n", list->lastName);
		fprintf(fp, "Student GPA: %f\n", list->GPA);
		list = list->next;
	}
	fclose(fp);
}

void readFile(){
	int findID = 0;
	char fName[30] = "";
	char lName[30] = "";
	float x_gpa;
	int studentNum = 0;
	float averageGPA = 0.0;
	char c;
	Student* pointer = (Student*)malloc(sizeof(Student)); //sets up a pointer to student memory allocation


	FILE *fp;
	fp = fopen("students.txt", "r"); //reads the text file
	
	if(fp == NULL){
		printf("File does not exist\n"); //checking if the file exists
		return NULL;
	}
	
	fscanf(fp, "Number of Student: %d", &studentNum); //looks at the first line to take the number of students
	printf("Number of Student: %d\n", studentNum);
	
	for(int i = 0; i < studentNum; i++){
		fscanf(fp, "\nStudent ID: %d", &findID ); //looks at the next line and sets variable as id
		fscanf(fp, "\nStudent first name: %s", fName);//looks at the next line and sets variable as firstname
		fscanf(fp, "\nStudent last name: %s", lName);//looks at the next line and sets variable as lastname
		fscanf(fp, "\nStudent GPA: %f", &x_gpa);//looks at the next line and sets variable as gpa
		
		Student* fileNode = createStudent(findID, fName, lName, x_gpa);
		addNode(fileNode);
	}
}

void updateStudent(int id){
	Student* list = headNode;
	Student* prevList = list;
	//int c = 0;
	int options = 0;
	while(list != NULL){
		if(id == list->ID){
			do{
				updateMenu(list->firstName, list-> lastName);
				printf("Choose your option:");
				scanf("%d", &options);
				
				int nextID, prevID;
				char nextFirstName[30], prevFirstName[30];
				char nextLastName[30], prevLastName[30];
				float nextGPA, prevGPA;
				Student* updateList = headNode;
				
				switch(options){
					case 1: 
						printf("Enter new ID:");
						scanf("%d",&nextID);
						while(updateList != NULL){
							if(nextID == updateList -> ID){
								printf("Enter a different id\n");
								updateList = headNode;
								printf("Enter updated ID of student: ");
								scanf("%d", &nextID);
								
							}
							updateList = updateList ->next;
						}
						prevID = list->ID;
						list->ID = nextID;
					case 2:
						printf("\nEnter updated first name:");
						scanf("%s", nextFirstName);
						strcpy(prevFirstName, list->firstName);
						strcpy(list -> firstName, nextFirstName);
						break;
					case 3:
						printf("\nEnter updated last name:");
						scanf("%s", nextLastName);
						strcpy(prevLastName, list->lastName);
						strcpy(list -> lastName, nextLastName);
						break;
					case 4: 
						printf("\nEnter updated GPA: ");
						scanf("%f", &nextGPA);
						prevGPA = list -> GPA;
						list -> GPA = nextGPA;
						if(prevList == list){
							list -> next = NULL;
							insertNode(list);
						}
						else{
							prevList-> next = list->next;
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
		list = list-> next;
	}
	
	
}

void removeStudent(int id){
	Student* list = headNode;
	while(list != NULL){
		if(id == list->ID){
			char fname[30];
			char lname[30];
			strcpy(fname, list->firstName);
			strcpy(lname, list->lastName);
			deleteNode(list);
			printf("Student deleted");
			return;
		}
		list = list-> next;
	}
	return; 
}

void listStudent(){
	Student* list = headNode;
	while(list != NULL){
		printf("\nStudent ID: %d", list -> ID);
		printf("\nStudent first name: %s", list -> firstName);
		printf("\nStudent lastn ame: %s", list -> lastName);
		printf("\nStudent GPA: %f\n\n", list -> GPA);
		list = list ->next;
	}
}

void menu(){
	printf("\n[1] List all Students\n");
	printf("[2] Add Student\n");
	printf("[3] Remove Student\n");
	printf("[4] Update Student\n");
	printf("[5] Quit\n\n");

}

void updateMenu(){ // Displays the menu for the specific student to have their attributes updated.
	printf("What would you like to update for this student?\n");
	printf("[1] ID \n");
	printf("[2] First Name \n");
	printf("[3] Last Name \n");
	printf("[4] GPA \n");
	printf("[5] Quit \n\n");
}

