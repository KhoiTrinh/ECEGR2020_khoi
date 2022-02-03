#include <stdio.h>

//Function for Program A
long Factorial(long num) {
	int i;
	long facto = 1;
	
	for (i=1; i<=num; ++i) {
		facto *= i;
	}
	printf("Factorial of %d = %llu\n", num, facto);
	return facto;
}

//Function for Program B
int IsPalindrome(long value){
	long reverse = 0;
	long origin = value;
	int remain;
	
	while (value != 0){
		remain = value % 10;
		reverse = reverse * 10 + remain;
		value = value/10;
	}
	if (reverse == origin){
		printf("The number %d is a Palindrome number\n", origin);
		return 1;
	}
	else {
		printf("The number %d is not a Palindrome number\n", origin);
		return 0;
	}
}

//Function for Program C
int HighestBitSet(int value){
	int remain;
	int highest = -1;
	int index = 1;
	int i = 0;
	int origin = value;
	long long binary = 0;

	while (value !=0){
		remain = value % 2;
		if (remain == 1) {
			highest = i;
		}
		binary = binary + remain * index;
		index = index * 10;
		value = value/2;
		i++;
	}
	printf("Value = %d ", origin);
	printf("Binary = %llu ", binary);
	if (highest == -1){
		printf ("No bit is set\n");
	}
	else {
		printf ("Highest bit set = %d\n", highest);
	}
}

//Function for Program D
void ReverseIt (void){
	float value1;
	float value2;
	float value3;
	float value4;
	float value5;
	printf("\nEnter a number.\n");
	scanf(" %f", &value1);
	printf("\nEnter a number.\n");
	scanf(" %f", &value2);
	printf("\nEnter a number.\n");
	scanf(" %f", &value3);
	printf("\nEnter a number.\n");
	scanf(" %f", &value4);
	printf("\nEnter a number.\n");
	scanf(" %f", &value5);
	
	printf("\nreverse order: \n");
	printf("\n%.2f\n", value5);
	printf("\n%.2f\n", value4);
	printf("\n%.2f\n", value3);
	printf("\n%.2f\n", value2);
	printf("\n%.2f\n", value1);
	
	FILE *fp;
	
	fp = fopen ("test.txt", "w+");
	fprintf(fp,"\n%.2f\n", value1);
	fprintf(fp,"\n%.2f\n", value2);
	fprintf(fp,"\n%.2f\n", value3);
	fprintf(fp,"\n%.2f\n", value4);
	fprintf(fp,"\n%.2f\n", value5);
	fprintf(fp,"\n%.2f\n", value5);
	fprintf(fp,"\n%.2f\n", value4);
	fprintf(fp,"\n%.2f\n", value3);
	fprintf(fp,"\n%.2f\n", value2);
	fprintf(fp,"\n%.2f\n", value1);
	fclose(fp);
}

//Function for Program E
void ReverseItAgain (void){
	float num;
	FILE *fp;
	fp = fopen("test.txt", "r");
	fscanf(fp,"%f",&num);
	printf("%f\n\n",num);
	fscanf(fp,"%f",&num);
	printf("%f\n\n",num);
	fscanf(fp,"%f",&num);
	printf("%f\n\n",num);
	fscanf(fp,"%f",&num);
	printf("%f\n\n",num);
	fscanf(fp,"%f",&num);
	printf("%f\n\n",num);
	fscanf(fp,"%f",&num);
	printf("%f\n\n",num);
	fscanf(fp,"%f",&num);
	printf("%f\n\n",num);
	fscanf(fp,"%f",&num);
	printf("%f\n\n",num);
	fscanf(fp,"%f",&num);
	printf("%f\n\n",num);
	fscanf(fp,"%f",&num);
	printf("%f\n\n",num);
	fclose(fp);
}

//Function for Program F
void Pyramid( int lines ){
	int i;
	int k;
	int s;
	int x;
	int y;
	int z;
	
	for (i = 1; i <= lines; ++i, k = 0){  
		for (s = 1; s <= lines - i; ++s){
			printf("  ");
		}
	  
		while (k != 2 * i - 1){
			printf("* ");
			++k;
		}
		printf("\n");
	}
	
	FILE *fp;
	fp = fopen ("programF.txt", "w+");
	for (x = 1; x <= lines; ++x, y = 0){  
		for (z = 1; z <= lines - x; ++z){
			fprintf(fp, "  ");
		}
	  
		while (y != 2 * x - 1){
			fprintf(fp, "* ");
			++y;
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}
//Main function
int main() {
	//Test for Program A
	printf("Program A:\n");
	int n;
	int i;
	for(i=1;i<=5;i++)
	{
	printf("\nEnter a number\n");
	scanf(" %d", &n);
	Factorial(n);
	}

	//Test for Program B
	printf("\n\nProgram B:\n");
	int number;
	int c = 0;
	for(c=1;c<=5;c++)
	{
	printf("\nEnter a number.\n");
	scanf(" %d", &number);
	IsPalindrome(number);
	}

	//Test for Program C
	printf("\n\nProgram C:\n");
	int value;
	int x;
	for(x=1;x<=5;x++)
	{
	printf("\nEnter a number.\n");
	scanf(" %d", &value);
	HighestBitSet(value);
	}

	//Test for Program D
	ReverseIt();

	//Test for Program E
	ReverseItAgain();

	//Test for Program F
	("\n\nProgram F:\n");
	printf("the figure with 8 lines\n");
	Pyramid(8);
	printf("the figure with 2 lines\n");
	Pyramid(2);
	printf("the figure with 9 lines\n");
	Pyramid(9);
	printf("the figure with 12 lines\n");
	Pyramid(12);
	return 0;
}