#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <typeinfo>
#include <stdlib.h> 

using namespace std;

enum Department {Engineering, English, Math, Nursing, Law, Music, Unknown};

//Top-level class of the class hierarchy
class Person
{
private:
	int ID;
    string firstName;
    string lastName;
	Person* next;
	
public:
	Person();
	Person(int id_in, string first_in, string last_in);
	Person(Person &init);
	virtual ~Person();
	Person& operator=(Person const &p)
	{
		this->ID = p.ID;
		setFirstName(p.firstName);
		setLastName(p.lastName);
		this->next = p.next;
		return *this;
	}
	
	// top level get Functions
	int getID()
	{
		return ID;
	}
	string getFirstName()
	{
		return firstName;
	}
	string getLastName()
	{
		return lastName;
	}
	Person* getNext()
	{
		return next;
	}
	
	// top level set Functions
	void setID(int id_in)
	{
		ID = id_in;
	}
	void setFirstName(string first_in)
	{
		this->firstName = first_in;
	}
	void setLastName(string last_in)
	{
		this->lastName = last_in;
	}
	void setNext(Person* next_in)
	{
		next = next_in;
	}
};

Person* firstPerson = NULL;

Person :: Person()
{
	this->ID = 0000;
	this->firstName = "(null)";
	this->lastName = "(null)";
	this->next = NULL;
}

Person :: Person(int id_in, string first_in, string last_in)
{
	this->ID = id_in;
	this->firstName = first_in;
	this->lastName = last_in;
	this->next = NULL;
}

Person :: Person(Person &init)
{
	this->ID = init.ID;
	this->firstName = "";
	this->lastName = "";
	setFirstName(init.firstName);
	setLastName(init.lastName);
	this->next = init.next;
}

Person :: ~Person()
{

}

//Student class
class Student: public Person
{
private:
	float GPA;
	
public:
	Student();
	Student(int id_in, string first_in, string last_in, float gpa_in);
	Student(Student &init);
	~Student();
	float getGPA()
	{
		return GPA;
	}
	
	void setGPA(float gpa_in)
	{
		GPA = gpa_in;
	}
};

Student :: Student()
{
	this->setID(0000);
	this->setFirstName("(null)");
	this->setLastName("(null)");
	this->GPA = 0.0;
	this->setNext(NULL);
}

Student :: Student(int id_in, string first_in, string last_in, float gpa_in)
{
	setID(id_in);
	setFirstName(first_in);
	setLastName(last_in);
	this->GPA = gpa_in;
	this->setNext(NULL);
}

Student :: Student(Student &init)
{
	this->setID(init.getID());
	this->setGPA(init.GPA);
	this->setFirstName(init.getFirstName());
	this->setLastName(init.getLastName());
	this->setNext(init.getNext());
}

Student :: ~Student()
{

}

//Employee class
class Employee: public Person
{
private:
	float salary;
	
public:
	Employee();
	Employee(int id_in, string first_in, string last_in, float salary_in);
	Employee(Employee &init);
	~Employee();
	float getSalary()
	{
		return salary;
	}
	
	void setSalary(float salary_in)
	{
		salary = salary_in;
	}
};

Employee :: Employee()
{
	this->setID(0000);
	this->setFirstName("(null)");
	this->setLastName("(null)");
	this->salary = 0.0;
	this->setNext(NULL);
}

Employee :: Employee(int id_in, string first_in, string last_in, float salary_in)
{
	setID(id_in);
	setFirstName(first_in);
	setLastName(last_in);
	this->salary = salary_in;
	this->setNext(NULL);
}

Employee :: Employee(Employee &init)
{
	this->setID(init.getID());
	this->setSalary(init.salary);
	this->setFirstName(init.getFirstName());
	this->setLastName(init.getLastName());
	this->setNext(init.getNext());
}

Employee :: ~Employee()
{

}


//Professor Class
class Professor: public Employee
{
private:
	bool tenured;
	Department department;
	
public:
	Professor();
	Professor(int id_in, string first_in, string last_in, float salary_in, bool ten_in, Department dep_in);
	Professor(Professor &init);
	~Professor();
	bool getTenured()
	{
		return tenured;
	}
	Department getDepartment()
	{
		return department;
	}
	
	void setTenured(bool ten_in)
	{
		tenured = ten_in;
	}
	void setDepartment(Department dep_in)
	{
		department = dep_in;
	}
};

Professor :: Professor()
{
	this->setID(0000);
	this->setFirstName("(null)");
	this->setLastName("(null)");
	this->setSalary(0.0);
	this->tenured = false;
	this->department = Unknown;
	this->setNext(NULL);
}

Professor :: Professor(int id_in, string first_in, string last_in, float salary_in, bool ten_in, Department dep_in)
{
	setID(id_in);
	setFirstName(first_in);
	setLastName(last_in);
	setSalary(salary_in);
	this->tenured = ten_in;
	this->department = dep_in;
	this->setNext(NULL);
}

Professor :: Professor(Professor &init)
{
	this->setID(init.getID());
	this->setSalary(init.getSalary());
	this->setFirstName(init.getFirstName());
	this->setLastName(init.getLastName());
	this->setTenured(init.tenured);
	this->setDepartment(init.department);
	this->setNext(init.getNext());
}

Professor :: ~Professor()
{

}

template <class DstType, class SrcType>
bool instanceof(const SrcType* src)
{
  return dynamic_cast<const DstType*>(src) != nullptr;
}

//Functions list
void insertNode(Person* person_in);
void deleteNode(Person* person_in);
void removeFromList(int id_in);
void updateList(int id_in);
void menuDisplay(void);
void addMenuDisplay(void);
void updateStudentMenu(string first, string last);
void updateProfessorMenu(string first, string last);
void updateEmployeeMenu(string first, string last);


void readUni_Info(void)
{
	ifstream readRecords;
	int totalPeople = 0;
	readRecords.open("Uni_Info.txt.");
	if(!readRecords.is_open())
	{
		cerr << "Could not open file: Uni_Info.txt" << endl;
	}
	else
	{
		string temp = "";
		readRecords >> temp;
		readRecords >> temp;
		readRecords >> temp;
		readRecords >> totalPeople;
		cout << "\nNumber of People: " << totalPeople << "\n";
		for(int i = 0; i < totalPeople; i++)
		{
			readRecords >> temp;
			if(temp == "Student")
			{
				int read_id = 0;
				string read_first = "";
				string read_last= "";
				float read_gpa = 0.0;
				readRecords >> temp;
				readRecords >> read_id;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_first;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_last;
				readRecords >> temp;
				readRecords >> read_gpa;
				
				Person* newStudent = new Student(read_id, read_first, read_last, read_gpa);
				insertNode(newStudent);
			}
			else if(temp == "Professor")
			{
				int read_id = 0;
				string read_first = "";
				string read_last= "";
				float read_salary = 0.0;
				bool read_ten = false;
				Department read_dep = Unknown;
				readRecords >> temp;
				readRecords >> read_id;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_first;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_last;
				readRecords >> temp;
				readRecords >> read_salary;
				readRecords >> temp;
				readRecords >> read_ten;
				readRecords >> temp;
				readRecords >> temp;
				if(temp == "Engineering")
				{
					read_dep = Engineering;
				}
				else if(temp == "English")
				{
					read_dep = English;
				}
				else if(temp == "Math")
				{
					read_dep = Math;
				}
				else if(temp == "Nursing")
				{
					read_dep = Nursing;
				}
				else if(temp == "Law")
				{
					read_dep = Law;
				}
				else if(temp == "Music")
				{
					read_dep = Music;
				}
				else
				{
					read_dep = Unknown;
				}
				
				Person* newProfesor = new Professor(read_id, read_first, read_last, read_salary, read_ten, read_dep);
				insertNode(newProfesor);
			}
			else if(temp == "Employee")
			{
				int read_id = 0;
				string read_first = "";
				string read_last= "";
				float read_salary = 0.0;
				readRecords >> temp;
				readRecords >> read_id;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_first;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_last;
				readRecords >> temp;
				readRecords >> read_salary;
				
				Person* newEmployee = new Employee(read_id, read_first, read_last, read_salary);
				insertNode(newEmployee);
			}
			else
			{
				
			}
		}
		readRecords.close();
	}
}

void readList(void){
	Person* node = firstPerson;
	printf("\nUNIVERSITY RECORDS");
	while(node != NULL) 
	{
		
		// Print the attributes of each student in the linked list.
		
		if(instanceof<Student>(node))
		{
			Student* tempStudent = (Student*) node;
			cout << "\n\nStudent";
			cout << "\nID: " << tempStudent->getID();
			cout << "\nFirst Name: " << tempStudent->getFirstName();
			cout << "\nLast Name: " << tempStudent->getLastName();
			cout << "\nGPA: " << tempStudent->getGPA();
		}
		else if(instanceof<Professor>(node))
		{
			Professor* tempProfessor = (Professor*) node;
			cout << "\n\nProfessor";
			cout << "\nID: " << tempProfessor->getID();
			cout << "\nFirst Name: " << tempProfessor->getFirstName();
			cout << "\nLast Name: " << tempProfessor->getLastName();
			cout << "\nSalary: " << tempProfessor->getSalary();
			if(tempProfessor->getTenured())
			{
				cout << "\nTenured: Yes";
			}
			else
			{
				cout << "\nTenured: No";
			}
			 tempProfessor->getTenured();
			if(tempProfessor->getDepartment() == Engineering)
			{
				cout << "\nDepartment: Engineering";
			}
			else if(tempProfessor->getDepartment() == English)
			{
				cout << "\nDepartment: English";
			}
			else if(tempProfessor->getDepartment() == Math)
			{
				cout << "\nDepartment: Math";
			}
			else if(tempProfessor->getDepartment() == Nursing)
			{
				cout << "\nDepartment: Nursing";
			}
			else if(tempProfessor->getDepartment() == Law)
			{
				cout << "\nDepartment: Law";
			}
			else if(tempProfessor->getDepartment() == Music)
			{
				cout << "\nDepartment: Music";
			}
			else
			{
				cout << "\nDepartment: Unknown";
			}
		}
		else if(instanceof<Employee>(node))
		{
			Employee* tempEmployee = (Employee*) node;
			cout << "\n\nEmployee";
			cout << "\nID: " << tempEmployee->getID();
			cout << "\nFirst Name: " << tempEmployee->getFirstName();
			cout << "\nLast Name: " << tempEmployee->getLastName();
			cout << "\nSalary: " << tempEmployee->getSalary();
		}
		node = node->getNext(); 
	}
}

void saveFile() 
{
	ofstream openRecords;
	openRecords.open("Uni_Info.txt");
	Person* node = firstPerson; 
	int personCount = 0; 
	while(node != NULL) 
	{
		personCount++; 
		node = node->getNext(); 
	}
	if (!openRecords.is_open())
	{
		cout << "Unable to write file\n";
	}
	else
	{
		openRecords << "Number of people: " << personCount;
		node = firstPerson; 
		while(node != NULL)
		{
			// Printing the ID, first and last name, and GPA of each student.
			if(instanceof<Student>(node))
			{
				Student* tempStudent = (Student*) node;
				openRecords << "\n\nStudent";
				openRecords << "\nID: " << tempStudent->getID();
				openRecords << "\nFirst Name: " << tempStudent->getFirstName();
				openRecords << "\nLast Name: " << tempStudent->getLastName();
				openRecords << "\nGPA: " << tempStudent->getGPA();
				//delete tempStudent;
			}
			else if(instanceof<Professor>(node))
			{
				Professor* tempProfessor = (Professor*) node;
				openRecords << "\n\nProfessor";
				openRecords << "\nID: " << tempProfessor->getID();
				openRecords << "\nFirst Name: " << tempProfessor->getFirstName();
				openRecords << "\nLast Name: " << tempProfessor->getLastName();
				openRecords << "\nSalary: " << tempProfessor->getSalary();
				openRecords << "\nTenured: " << tempProfessor->getTenured();
				if(tempProfessor->getDepartment() == Engineering)
				{
					openRecords << "\nDepartment: Engineering";
				}
				else if(tempProfessor->getDepartment() == English)
				{
					openRecords << "\nDepartment: English";
				}
				else if(tempProfessor->getDepartment() == Math)
				{
					openRecords << "\nDepartment: Math";
				}
				else if(tempProfessor->getDepartment() == Nursing)
				{
					openRecords << "\nDepartment: Nursing";
				}
				else if(tempProfessor->getDepartment() == Law)
				{
					openRecords << "\nDepartment: Law";
				}
				else if(tempProfessor->getDepartment() ==  Music)
				{
					openRecords << "\nDepartment:  Music";
				}
				else
				{
					openRecords << "\nDepartment: Unknown";
				}
				
				//delete tempProfessor;
			}
			else if(instanceof<Employee>(node))
			{
				Employee* tempEmployee = (Employee*) node;
				openRecords << "\n\nEmployee";
				openRecords << "\nID: " << tempEmployee->getID();
				openRecords << "\nFirst Name: " << tempEmployee->getFirstName();
				openRecords << "\nLast Name: " << tempEmployee->getLastName();
				openRecords << "\nSalary: " << tempEmployee->getSalary();
				//delete tempEmployee;
			}
			
			node = node->getNext(); // Iterate.
		}
		openRecords.close(); // Close the file.
	}
}

void insertNode(Person* person_in)
{
	if(firstPerson == NULL)
	{
		firstPerson = person_in;
		return;
	}
	else if(firstPerson->getNext() == NULL)
	{
		if(firstPerson->getID() >= person_in->getID())
		{
			firstPerson->setNext(person_in);
			return;
		}
		else
		{
			Person* temp = firstPerson;
			firstPerson = person_in;
			firstPerson->setNext(temp);
			return;
		}
	}
	
	Person* node = firstPerson;
	
	while(node->getNext() != NULL)
	{
		Person* nextNode = node->getNext();
		
		if((node->getID() > person_in->getID()) && (person_in->getID() >= nextNode->getID()))
		{
			person_in->setNext(node->getNext());
			node->setNext(person_in);
			return;
		}
		else if(node->getID() <= person_in->getID())
		{
			person_in->setNext(node);
			firstPerson = person_in;
			return;
		}
		node = node->getNext();
	}
	node->setNext(person_in);
	person_in->setNext(NULL);
	return;
}

void deleteNode(Person* person_in)
{
	Person* currentPerson = firstPerson;
	Person* prevPerson = NULL;
	
	if(firstPerson == person_in)
	{
		firstPerson = firstPerson->getNext();
		delete person_in;
		return;
	}
	
	while(currentPerson != NULL && currentPerson != person_in) 
	{
		prevPerson = currentPerson; 
		currentPerson = currentPerson->getNext(); 
	}
	
	if(currentPerson != NULL)
	{
		prevPerson->setNext(currentPerson->getNext());
	}
	
	delete person_in;
}

void addToList()
{
	int user_input = 0;
	do
	{
		int id_input;
		string first_input, last_input;
		float gpa_input, salary_input;
		bool ten_input;
		Department dep_input;
		string temp;
		Person* idCheck = firstPerson;
		
		addMenuDisplay();
		cout << "\nWho would you like to add? ";
		cin >> user_input;
		
		switch(user_input)
		{
			case 1 :
			{
				printf("\nEnter the ID of the student: "); 
				cin >> id_input; 
				while(idCheck != NULL) 
				{
					if(id_input == idCheck->getID()) 
					{
						printf("\nEntered ID is currently used by and existing person."); 
						idCheck = firstPerson; 
						printf("\nEnter the ID of the student: "); 
						cin >> id_input; 
					}
					idCheck = idCheck->getNext(); 
				}
				
				printf("\nEnter the first name of the student: "); 
				
				printf("\nEnter the last name of the student: "); 
				cin >> last_input;
				
				printf("\nEnter the GPA of the student: "); 
				cin >> gpa_input; 
				while((gpa_input > 4.0) || (gpa_input < 1.0)) 
				{
					printf("\nPlease enter a GPA in the range of 4.0 and 1.0."); 
					printf("\nEnter the GPA of the student: "); 
					cin >> gpa_input; 
				}
				
				Person* peterPtr = new Student(id_input, first_input, last_input, gpa_input);
				insertNode(peterPtr);
				break;
			}
			case 2 :
			{
				printf("\nEnter the ID of the professor: "); 
				cin >> id_input; 
				while(idCheck != NULL) 
				{
					if(id_input == idCheck->getID()) 
					{
						printf("\nEntered ID is currently used by an existing person."); 
						idCheck = firstPerson; 
						printf("\nEnter the ID of the professor: "); 
						cin >> id_input; 
					}
					idCheck = idCheck->getNext(); 
				}
				
				printf("\nEnter the first name of the professor: "); 
				cin >> first_input;
				
				printf("\nEnter the last name of the professor: "); 
				cin >> last_input;
				
				printf("\nEnter the salary of the professor: "); 
				cin >> salary_input;
				
				cout << "\nAre they tenured? (yes/no) ";
				cin >> temp;
				string yes = "yes";
				string no = "no";
				if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
					ten_input = true;
				else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
					ten_input = false;
				else
				{
					bool check = true;
					while(check)
					{
						cout << "\nPlease indicate yes or no: ";
						cin >> temp;
						if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
						{
							ten_input = true;
							check = false;
						}
							
						else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
						{
							ten_input = false;
							check = false;
						}
					}
				}
				
				cout << "\nEnter the department of the professor: ";
				cin >> temp;
				
				if(temp == "Engineering"){dep_input = Engineering;}
				else if(temp == "English"){dep_input = English;}
				else if(temp == "Math"){dep_input = Math;}
				else if(temp == "Nursing"){dep_input = Nursing;}
				else if(temp == "Law"){dep_input = Law;}
				else if(temp == "Music"){dep_input = Music;}
				else{dep_input = Unknown;}
				
				Person* peterPtr = new Professor(id_input, first_input, last_input, salary_input, ten_input, dep_input);
				insertNode(peterPtr);
				break;
			}
			case 3 :
			{
				printf("\nEnter the ID of the employee: "); 
				cin >> id_input; 
				while(idCheck != NULL) 
				{
					if(id_input == idCheck->getID()) 
					{
						printf("\nEntered ID is currently used by an existing person."); 
						idCheck = firstPerson; 
						printf("\nEnter the ID of the employee: "); 
						cin >> id_input; 
					}
					idCheck = idCheck->getNext(); 
				}
				
				printf("\nEnter the first name of the employee: "); 
				cin >> first_input;
				
				printf("\nEnter the last name of the employee: "); 
				cin >> last_input;
				
				printf("\nEnter the salary of the employee: "); 
				cin >> salary_input;
				
				Person* peterPtr = new Employee(id_input, first_input, last_input, salary_input);
				insertNode(peterPtr);
				break;
			}
			
			case 4 : 
				break; 
				
			default : 
				printf("\nInvalid input\n"); 
		}
	}while(user_input != 4);
}

void removeFromList(int id_in)
{
	Person* node = firstPerson;
	while(node != NULL) 
	{
		if(id_in == node->getID()) 
		{
			string first = node->getFirstName();
			string last =  node->getLastName();
			deleteNode(node); 
			cout << "\n" << first << " " << last << " was successfully deleted."; 
			return; 
		}
		node = node->getNext(); 
	}
	cout << "\nThere is no person associated with the given ID.";
}

void updateList(int id_in)
{
	Person* node = firstPerson;
	int user_input = 0;
	while(node != NULL)
	{
		if(id_in == node->getID())
		{
			if(instanceof<Student>(node))
			{
				do
				{
					updateStudentMenu(node->getFirstName(), node->getLastName()); 
					cin >> user_input; 
					// Declarations for placeholder variables.
					int new_id, old_id = 0;
					string new_first = "";
					string old_first = "";
					string new_last = "";
					string old_last = "";
					string temp = "";
					float new_gpa, old_gpa = 0.0;
					Person* idCheck = firstPerson;
					Student* tempStudent = (Student*) node;
					
					switch(user_input) 
					{
						case 1 :
							cout << "\nEnter the new ID: "; 
							cin >> new_id; 
							while(idCheck != NULL) 
							{
								if(new_id == idCheck->getID()) 
								{
									printf("\nEntered ID is currently used by and existing student."); 
									idCheck = firstPerson; 
									printf("\nEnter the ID of the student: "); 
									scanf("%d", &new_id); 
								}
								idCheck = idCheck->getNext(); 
							}
							old_id = tempStudent->getID(); 
							tempStudent->setID(new_id); 
							node = tempStudent;
							printf("\n%d was sucessfully updated to %d", old_id, new_id); 
							break; 
						case 2 : 
							printf("\nEnter the new first name: "); 
							cin >> new_first;
							old_first = tempStudent->getFirstName(); 
							tempStudent->setFirstName(new_first); 
							cout << "\n" << old_first << " was sucessfully updated to " << new_first;
							node = tempStudent;
							break; 
						case 3 : 
							printf("\nEnter the new last name: "); 
							cin >> new_last;
							old_last = tempStudent->getLastName(); 
							tempStudent->setLastName(new_last); 
							cout << "\n" << old_last<< " was sucessfully updated to " << new_last;
							node = tempStudent;
							break; 
						case 4 : 
							printf("\nEnter the new GPA: "); 
							scanf("%f", &new_gpa); 
							while((new_gpa > 4.0) || (new_gpa < 1.0)) // 
							{
								printf("\nPlease enter a GPA in the range of 4.0 and 1.0."); 
								printf("\nEnter the GPA of the student: "); 
								scanf("%f", &new_gpa); 
							}
							old_gpa = tempStudent->getGPA(); 
							tempStudent->setGPA(new_gpa);
							node = tempStudent;
							printf("\n%f was sucessfully updated to %f", old_gpa, new_gpa); 
							break; 
						
						case 5 :
							break; 
						
						default :
							printf("\nInvalid input\n");
					}
				}while(user_input != 5);
				return;
			}
			else if(instanceof<Professor>(node))
			{
				do
				{
					updateProfessorMenu(node->getFirstName(), node->getLastName()); 
					cin >> user_input;
					// Declarations for placeholder variables.
					int new_id, old_id = 0;
					string new_first = "";
					string old_first = "";
					string new_last = "";
					string old_last = "";
					string temp, temp2 = "";
					float new_salary, old_salary = 0.0;
					bool new_ten, old_ten = false;
					Department new_dep;
					Person* idCheck = firstPerson;
					Professor* tempProfessor = (Professor*) node;
					
					switch(user_input) 
					{
						case 1 : 
						{
							cout << "\nEnter the new ID: "; 
							cin >> new_id;
							while(idCheck != NULL) 
							{
								if(new_id == idCheck->getID()) 
								{
									printf("\nEntered ID is currently used by and existing student."); 
									idCheck = firstPerson; 
									printf("\nEnter the ID of the student: "); 
									scanf("%d", &new_id); 
								}
								idCheck = idCheck->getNext(); 
							}
							old_id = tempProfessor->getID(); 
							tempProfessor->setID(new_id); 
							node = tempProfessor;
							printf("\n%d was sucessfully updated to %d", old_id, new_id); 
							break; 
						}

						case 2 : 
						{
							printf("\nEnter the new first name: "); 
							cin >> new_first;
							old_first = tempProfessor->getFirstName();
							tempProfessor->setFirstName(new_first);
							cout << "\n" << old_first << " was sucessfully updated to " << new_first;
							node = tempProfessor;
							break; 
						}

						case 3 : 
						{
							printf("\nEnter the new last name: "); 
							cin >> new_last;
							old_last = tempProfessor->getLastName(); 
							tempProfessor->setLastName(new_last); 
							cout << "\n" << old_last<< " was sucessfully updated to " << new_last;
							node = tempProfessor;
							break; 
						}
						case 4 : 
						{
							printf("\nEnter the new Salary: "); 
							scanf("%f", &new_salary);
							old_salary = tempProfessor->getSalary(); 
							tempProfessor->setSalary(new_salary); 
							node = tempProfessor;
							printf("\n%f was sucessfully updated to %f", old_salary, new_salary); 
							break; 
						}
						
						case 5 : 
						{
							cout << "\nAre they tenured? (yes/no) ";
							cin >> temp;
							string yes = "yes";
							string no = "no";
							if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
								new_ten = true;
							else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
								new_ten = false;
							else
							{
								bool check = true;
								while(check)
								{
									cout << "\nPlease indicate yes or no: ";
									cin >> temp;
									if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
									{
										new_ten = true;
										check = false;
									}
										
									else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
									{
										new_ten = false;
										check = false;
									}
								}
							}
							old_ten = tempProfessor->getTenured();
							tempProfessor->setTenured(new_ten);
							node = tempProfessor;
							if(new_ten == old_ten)
								cout << "\nNo change was made (value entered was the same as the current value)";
							else
								cout << "\nTenured was updated";
							break;
						}
						
						case 6 :
						{
							cout << "\nEnter the department of the professor: ";
							cin >> temp;
							
							if(temp == "Engineering"){new_dep = Engineering;}
							else if(temp == "English"){new_dep = English;}
							else if(temp == "Math"){new_dep = Math;}
							else if(temp == "Nursing"){new_dep = Nursing;}
							else if(temp == "Law"){new_dep = Law;}
							else if(temp == "Music"){new_dep = Music;}
							else{new_dep = Unknown;}
							
							if(tempProfessor->getDepartment() == Engineering)
							{
								temp2 = "Engineering";
							}
							else if(tempProfessor->getDepartment() == English)
							{
								temp2 = "English";
							}
							else if(tempProfessor->getDepartment() == Math)
							{
								temp2 = "Math";
							}
							else if(tempProfessor->getDepartment() == Nursing)
							{
								temp2 = "Nursing";
							}
							else if(tempProfessor->getDepartment() == Law)
							{
								temp2 = "Law";
							}
							else if(tempProfessor->getDepartment() == Music)
							{
								temp2 = "Music";
							}
							else
							{
								temp2 = "Unknown";
							}
							tempProfessor->setDepartment(new_dep);
							node = tempProfessor;
							cout << "\n" << temp2 << " was successfully updated to " << temp;
							break;
						}
						
						case 7 :
						{
							break;
						}
						
						default : 
							printf("\nInvalid input\n");
					}
				}while(user_input != 7);
				return;
			}
			else if(instanceof<Employee>(node))
			{
				do
				{
					updateEmployeeMenu(node->getFirstName(), node->getLastName()); 
					cin >> user_input; 
					// Declarations for placeholder variables.//
					int new_id, old_id = 0;
					string new_first = "";
					string old_first = "";
					string new_last = "";
					string old_last = "";
					string temp = "";
					float new_salary, old_salary = 0.0;
					Person* idCheck = firstPerson;
					Employee* tempStudent = (Employee*) node;
					
					switch(user_input) 
					{
						case 1 : 
							cout << "\nEnter the new ID: "; 
							cin >> new_id; 
							while(idCheck != NULL)
							{
								if(new_id == idCheck->getID())
								{
									printf("\nEntered ID is currently used by and existing student.");
									idCheck = firstPerson; 
									printf("\nEnter the ID of the student: "); 
									scanf("%d", &new_id); 
								}
								idCheck = idCheck->getNext();
							}
							old_id = tempStudent->getID();
							tempStudent->setID(new_id);
							node = tempStudent;
							printf("\n%d was sucessfully updated to %d", old_id, new_id); 
							break; 
						case 2 : 
							printf("\nEnter the new first name: "); 
							cin >> new_first;
							old_first = tempStudent->getFirstName(); 
							tempStudent->setFirstName(new_first); 
							cout << "\n" << old_first << " was sucessfully updated to " << new_first;
							node = tempStudent;
							break; // Leave the switch-case.
						case 3 : // 3) Update Last Name
							printf("\nEnter the new last name: "); 
							cin >> new_last;
							old_last = tempStudent->getLastName(); 
							tempStudent->setLastName(new_last); 
							cout << "\n" << old_last<< " was sucessfully updated to " << new_last; 
							node = tempStudent;
							break; 
						case 4 : 
							printf("\nEnter the new Salary: "); 
							scanf("%f", &new_salary); 
							
							old_salary = tempStudent->getSalary(); 
							tempStudent->setSalary(new_salary); 
							node = tempStudent;
							printf("\n%f was sucessfully updated to %f", old_salary, new_salary); 
							break; 
						
						case 5 : 
							break; 
						
						default : 
							printf("\nInvalid input\n");
					}
				}while(user_input != 5);
				return;
			}
		}
		node = node->getNext();
	}
	cout << "\nThere is no person associated with the given ID.";
}

void menuDisplay() // Displays the default menu.
{
	printf("\nUNIVERSITY MENU");
	
	printf("\n\n1) List");
	printf("\n2) Add");
	printf("\n3) Remove");
	printf("\n4) Update");
	printf("\n5) Quit");
	printf("\n\n");
}

void addMenuDisplay() // Displays the default add menu.
{
	printf("\nADD MENU");
	printf("\n\n1) Student");
	printf("\n2) Professor");
	printf("\n3) Employee");
	printf("\n4) Quit");
	printf("\n\n");
}

void updateStudentMenu(string first, string last) // Displays the specific menu for student
{
	printf("\nUPDATE STUDENT MENU");
	cout << "\nWhat do you want to update about " << first << " " << last << "?";
	printf("\n\n1) ID");
	printf("\n2) First Name");
	printf("\n3) Last Name");
	printf("\n4) GPA");
	printf("\n5) Quit");
	printf("\n\n");
}

void updateProfessorMenu(string first, string last) // Displays the specific menu for professor
{
	printf("\nUPDATE PROFESSOR MENU");
	cout << "\nWhat do you want to update about " << first << " " << last << "?";
	printf("\n\n1) ID");
	printf("\n2) First Name");
	printf("\n3) Last Name");
	printf("\n4) Salary");
	printf("\n5) Tenured");
	printf("\n6) Department");
	printf("\n6) Quit");
	printf("\n\n");
}

void updateEmployeeMenu(string first, string last) // Displays the specific menu for employee
{
	printf("\nUPDATE EMPLOYEE MENU");
	cout << "\nWhat do you want to update about " << first << " " << last << "?";
	printf("\n\n1) ID");
	printf("\n2) First Name");
	printf("\n3) Last Name");
	printf("\n4) Salary");
	printf("\n5) Quit");
	printf("\n\n");
}

//Main Function
int main()
{
	int options = 0;
	readUni_Info();
	do
	{
		int userID_in;
		
		menuDisplay();
		cout << "\nWhat do you want to do? ";
		cin >> options;
		
		switch(options)
		{
			case 1 :
			{
				readList();
				break;
			}
			case 2 :
			{
				addToList();
				break;
			}
			case 3 : 
			{
				printf("\nEnter the ID of the person you want to delete: "); 
				cin >> userID_in; 
				removeFromList(userID_in);
				break; 
			}
			case 4 :
			{
				printf("\nEnter the ID of the person you want to update: "); 
				cin >> userID_in; 
				updateList(userID_in); 
				break; 
			}
			case 5 :
			{
				printf("\nExiting University Program..."); 
				break; 
			}
		}
		
	}while(options != 5);
	saveFile();
}
