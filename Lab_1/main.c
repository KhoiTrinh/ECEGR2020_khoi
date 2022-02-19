#include<stdio.h>


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

int main(int argc, char** argv)
{
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