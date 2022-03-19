#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

enum Department{Engineering, English, Math, Nursing, Law, Music, Unknown};

//Student Class
class Student{
	private:
		int ID = NULL;
		char* firstName = NULL;
		char* lastName = NULL;
		float GPA = NULL;
	
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
	
	
	//Student Set Functions
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
};

Student :: Student(){
	this->ID = 0000;
	this->firstName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this -> firstName, (char*)"<unknown>");
	this->lastName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this-> lastName, (char*) "<unknown>");
	this->GPA = 0.0;
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
	cout << "Student constructor for " << firstName << lastName <<"\n";
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
	cout << "Student Deconstructor " << firstName << lastName << endl;
	if(firstName)
	{
		free(firstName);
	}
	if(lastName)
	{
		free(lastName);
	}
}


//Professor Class
class Professor{
	private:
		int ID;
		char* firstName;
		char* lastName;
		float salary;
		bool tenured;
		Department department;
	
	public:
		Professor();
		Professor(int id, char *first_name, char *last_name, float sal, bool ten, Department major);
		Professor(Professor &init);
		~Professor();
		
		Professor& operator=(Professor const &pro){
		this->ID = pro.ID;
		setfirstName(pro.firstName);
		setlastName(pro.lastName);
		this->salary = pro.salary;
		this->tenured = pro.tenured;
		this->department = pro.department;
		cout << "Professor Assignment Operator \n";
		return *this;
		}

//Get Functions for Professor
int getID(){
		return ID;
	} 
	float getsalary(){
		return salary;
	}
	char* getfirstName(){
		return firstName;
	}
	char* getlastName(){
		return lastName;
	}
	bool getTenured(){
		return tenured;
	}
	Department getDepartment(){
		return department;
	}

//Set Functions for Professor
	void setID(int id){
		ID = id;
	}
	void setGPA(float sal){
		salary = sal;
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
	void setTenured(bool ten){
		tenured = ten;
	}
	void setDepartment(Department major){
		department = major;
	}
	
};

Professor :: Professor(){
	this->ID = 0000;
	this->firstName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this -> firstName, (char*)"<unknown>");
	this->lastName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this-> lastName, (char*) "<unknown>");
	this->salary = 0.0;
	tenured = false;
	department = Unknown;
	cout << "Professor Default constructor \n";
}

Professor :: Professor(int id, char* first_name, char* last_name, float sal, bool ten, Department major )
{
	this->ID = id;
	this->firstName = (char*) malloc(sizeof(strlen(first_name)+1));
	strcpy(this->firstName, first_name);
	this->lastName = (char*) malloc(sizeof(strlen(last_name)+1));
	strcpy(this->lastName, last_name);
	this->salary = sal;
	this->tenured = ten;
	this->department = major;
	cout << "Professor constructor for " << firstName << lastName <<"\n";
}

Professor :: Professor(Professor &init){
	ID = init.ID;
	salary = init.salary;
	if(init.firstName)
	{
		setfirstName(init.firstName);
	}
	if(init.lastName)
	{
		setlastName(init.lastName);
	}
	tenured = init.tenured;
	department = init.department;
	cout << "Professor Copy Constructor \n";
}

Professor :: ~Professor(){
	cout << "Professor Deconstructor " << firstName << lastName << endl;
	if(firstName)
	{
		free(firstName);
	}
	if(lastName)
	{
		free(lastName);
	}
}

//Employee Class

class Employee{
	private:
		int ID;
		char* firstName;
		char* lastName;
		float salary;
	
	public:
		Employee();
		Employee(int id, char *first_name, char *last_name, float sal);
		Employee(Employee &init);
		~Employee();
		
		Employee& operator=(Employee const &emp)
	{
		this->ID = emp.ID;
		setfirstName(emp.firstName);
		setlastName(emp.lastName);
		this->salary = emp.salary;
		cout << "Employee Assignment Operator \n";
		return *this;
	}
	
	//Employee get Funtions
	int getID(){
		return ID;
	} 
	float getsalary(){
		return salary;
	}
	char* getfirstName(){
		return firstName;
	}
	char* getlastName(){
		return lastName;
	}
	
	//Employee set Functions
	void setID(int id){
		ID = id;
	}
	void setGPA(float sal){
		salary = sal;
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
	
};

Employee :: Employee(){
	this->ID = 0000;
	this->firstName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this -> firstName, (char*)"<unknown>");
	this->lastName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this-> lastName, (char*) "<unknown>");
	this->salary = 0.0;
	cout << "Employee Default constructor \n";
}

Employee :: Employee(int id, char* first_name, char* last_name, float sal)
{
	this->ID = id;
	this->firstName = (char*) malloc(sizeof(strlen(first_name)+1));
	strcpy(this->firstName, first_name);
	this->lastName = (char*) malloc(sizeof(strlen(last_name)+1));
	strcpy(this->lastName, last_name);
	this->salary = sal;
	cout << "Employee constructor for " << firstName << lastName <<"\n";
}

Employee :: Employee(Employee &init)
{
	ID = init.ID;
	salary = init.salary;
	if(init.firstName)
	{
		setfirstName(init.firstName);
	}
	if(init.lastName)
	{
		setlastName(init.lastName);
	}
	cout << "Employee Copy Constructor \n";
}

Employee :: ~Employee()
{
	cout << "Employee Deconstructor " << firstName << lastName << endl;
	if(firstName)
	{
		free(firstName);
	}
	if(lastName)
	{
		free(lastName);
	}
}

int main()
{
	Student student1(1234, (char*) "Jacky", (char*) "Chan", 3.4);
	//Print out the deconstructor to see if the memory is leaked or not. 
	cout << endl << student1.getID()<< endl <<student1.getfirstName() << endl << student1.getlastName() << endl <<student1.getGPA() << endl;
	Student student2 = student1;
	cout << endl << student2.getID()<< endl <<student2.getfirstName() << endl << student2.getlastName() << endl <<student2.getGPA() << endl;
	if(student2.getID() == student1.getID()){
		cout << "It is the same" << endl;
	}
	student2.setID(1444);
	student2.setfirstName((char*) "King");
	student2.setlastName((char*) "Kong");
	student2.setGPA(2.2);
	cout << endl << student2.getID()<< endl <<student2.getfirstName() << endl << student2.getlastName() << endl <<student2.getGPA() << endl;
}

	//If the deconstructor are printed at the end, then the program is not leaked