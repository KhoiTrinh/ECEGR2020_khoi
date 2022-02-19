#include <stdio.h>
#include <stdlib.h>

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
void sort_GPA(struct Student **studentList, int count)
{
	int i, j, k;
	float temp;
	for (j = 0; j < count; ++j)
	{
		for (k = j + 1; k < count; ++k)
		{
			if (studentList[j]->GPA < studentList[k]->GPA)
		{
			temp = studentList[j]->GPA;
			studentList[j]->GPA = studentList[k]->GPA;
			studentList[k]->GPA = temp;
		}
	}
}
	printf("GPA in descending order:\n");
	for (i = 0; i < count; ++i)
	printf("%d\n", studentList[i]->GPA);
}


int main(){
// Program B
	int StuNum;
	printf("Enter the number of students: \n");
	scanf("%d", &StuNum);
    struct Student **studentList;
    struct Student *aStudent;
	//FILE
	FILE *fp;
	fp = fopen ("students.txt", "w+");
   
    studentList = (struct Student **) malloc(StuNum*sizeof(struct Student));
   
	sort_GPA(studentList, StuNum);
	
    for( int i = 0; i < StuNum; i++ ) {
        studentList[i] = createStudent();
		fprintf(fp, "Student's ID: \n",studentList[i]->ID);
		fprintf(fp, "Student's first name: \n",studentList[i]->firstName );
		fprintf(fp, "Student's last name: \n",studentList[i]->lastName );
		fprintf(fp, "Student's GPA: \n",studentList[i]->GPA );
    }

return 0;
}