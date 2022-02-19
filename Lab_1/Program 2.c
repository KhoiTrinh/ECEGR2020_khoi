#include<stdio.h>

 int IsLeapYear(int aYear ){
	if (aYear < 1752) {
		return 0;
	}
	else if (aYear % 400 == 0){
		return 1;
	}
	else if (aYear % 100 == 0){
		return 0;
	}
	else if (aYear % 4 == 0){
		return 1;
	}
	else return 0;
}
