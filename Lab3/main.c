#include <stdio.h>
#include <stdlib.h>

int theArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//Function for Program A
void ReverseArray(void){
	int reverse[10];
	printf("TheArray values after reversed are:\n");
	for (int n = 0; n < 10; n++){
		reverse[9-n] = theArray[n];
	}
	for (int n = 0; n < 10; n++){
		theArray[n] = reverse[n];
	}
	for (int n = 0; n < 10; n++){
		printf("%d ", theArray[n]);
	}
	printf("\n\n");
}

//Functions for Program B
	struct Student
{
	int  ID;
	char firstName[30];
	char lastName[30];
	float GPA;
} Student;


struct Student *createStudent(void)
{
    struct Student *newStudent;
   
    newStudent = (struct Student *) malloc(sizeof(struct Student));
	if(newStudent == NULL)
		return -1;
	printf("Enter Student's ID: \n");
	scanf("%d", &newStudent->ID);
	printf("Enter Student's first name: \n");
	scanf("%s", &newStudent->firstName);
   	printf("Enter Student's last name: \n");
	scanf("%s", &newStudent->lastName);
	printf("Enter Student's GPA: \n");
	scanf("%f", &newStudent->GPA);
    return newStudent;
}

//SORT GPA Function
void sort_GPA(struct Student **studentList, int count){
	int j, k;
	struct Student* temp;
	for (j = 0; j < count; ++j){
		for (k = j + 1; k < count; ++k){
			if (studentList[j]->GPA < studentList[k]->GPA){
				temp = studentList[j];
				studentList[j] = studentList[k];
				studentList[k] = temp;
			}
		}
	}
}


//Functions for Program D and E
void printMenu(){
	printf("Menu:\n\
	A) Count the number of vowels in the string\n\
	B) Count the number of consonants in the string\n\
	C) Convert the string to uppercase\n\
	D) Convert the string to lowercase\n\
	E) Display the current string\n\
	F) Enter another string\n\
	M) Display this menu\n\
	R) Reverse words in string.\n\
	X) Exit the program\n");
}

int checkVowel(char c)
{
	char vowel[10] = {'a','e','i','o','u','A','E','I','O','U'};
	for(int i=0;i<10;i++){
		if(c==vowel[i])
			return 1;
	}
	return 0;
}

//A
int countVowel(char s[],int n){
    
	int vowel = 0;
	for(int i=0;i<n;i++){
		if(checkVowel(s[i]))
			vowel++;
	}
	return vowel;
}

//B
int countConstant(char s[],int n){
	int consonants = 0;
	for (int i = 0; i < n; ++i)
	{ 
		if(('A'<= s[i] <= 'Z') || ('a'<= s[i] <= 'z')){
			if(!checkVowel(s[i]))
				consonants++;
        }
    }
	return consonants;
}


//C
void toupper(char s[],int n){
    
	for (int i = 0; i < n; ++i)
	{   
		if('a'<= s[i] && s[i]<= 'z'){
			s[i] = s[i]-32;
		}
	}
}

//D
void tolower(char s[],int n){
    
	for (int i = 0; i < n; ++i)
	{ 
		if('A'<= s[i] && s[i] <= 'Z'){
			s[i] = s[i]+32;
		}
	}
}

//R
void reverseUtil(char s[],int i,int j){
	int size = j-i+1;
	for(int k=0;k < size/2;k++){
		char temp = s[i+k];
		s[i+k] = s[j-k];
		s[j-k] = temp;
	}
}

void reverse(char s[],int n){
	int i=0;
	while(s[i]==' ')i++;
	for(int j=i;j<n;j++){
		if(s[j]==' '){
			reverseUtil(s,i,j);
			i = j + 1;
		}
	}
}

int Input(char s[]){
	printf("Enter a string: ");
	scanf("%[^\n]s",s);
	getchar();
	int n=0;
	while(s[n]!='\0')n++;
	return n;

}


//Main function
int main() {
	//Test for Program A
	ReverseArray();





// Program B
	int StuNum;
	printf("Enter the number of students: \n");
	scanf("%d", &StuNum);
	struct Student **studentList;

	studentList = (struct Student **) malloc(StuNum*sizeof(struct Student*));
	if (studentList == NULL)
		return -1;
	
    for( int i = 0; i < StuNum; i++ ) {
        studentList[i] = createStudent();
    }
	
	sort_GPA(studentList, StuNum);
	
	FILE *fp;
	fp = fopen ("students.txt", "w+");
	for(int i=0;i<StuNum;i++){
		fprintf(fp, "Student's ID: %d\n",studentList[i]->ID);
		fprintf(fp, "Student's first name: %s\n",studentList[i]->firstName );
		fprintf(fp, "Student's last name: %s\n",studentList[i]->lastName );
		fprintf(fp, "Student's GPA: %.1f\n\n\n\n",studentList[i]->GPA );
	}
	
	//Compute Average GPA. Program C
	float grade, sum;
	for (int i = 0; i < StuNum; ++i){
		grade = studentList[i]->GPA;
		sum = sum + grade;
	}
	float ave_GPA = sum/StuNum;
	fprintf(fp, "Average GPA: %.2f\n\n",ave_GPA);
	fclose(fp);
	for(int i=0;i<StuNum;i++){
		free(studentList[i]);
	}
	free(studentList);
	
	// PRINT ALL CONTENTS FROM FILE. PROGRAM C
	printf("\n\nProgram C. Print out students.txt\n\n");
	FILE *fpt;
	char c;
	fpt = fopen ("students.txt", "r");
	c = fgetc(fpt);
	while (c != EOF){
		printf ("%c", c);
		c = fgetc(fpt);
	}
	fclose(fpt);




	//Test for Program D and E
	char str[100]="Hello";
	int n = 5;
	n = Input(str);
	printMenu();
	char choice;
	while(1){
		printf("Enter which option you want to execute: ");
		scanf("%c",&choice);
		getchar();
		if(choice=='A'){
			printf("The total vowels: %d\n",countVowel(str,n));
        }
		else if(choice=='B'){
			printf("The total consonants: %d\n",countConstant(str,n));
        }
		else if(choice=='C'){
			toupper(str,n);
        }
		else if(choice=='D'){
			tolower(str,n);
        }
		else if(choice=='E'){
			printf("The current string is: %s\n",str);
        }
		else if(choice=='F'){
			n = Input(str);
        }
		else if(choice=='M'){
			printMenu();
        }
		else if(choice=='R'){
			reverse(str,n);
		}
		else if(choice=='X'){
			break;
		}
	}
	return 0;
}
