#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "passwords.h"
/*This function was harder than expected, mainly because the steps for the algorith confused me.
I had to spend some time looking for the algorithm before getting it to work. The mistake I was
Then after that it was easy. I used four seperate for loops to count if each type of char occured
once in the string. This could have been better handled in one loop, but I was on a time crunch. Update
I stopped being lazy and was forced by TA to clean to clean up my code.
*/
int entropy(char* k){
	double a = 0;
	int c = 0;
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;
	for(size_t i = 0; i < strlen(k); i++){
		char ch = k[i];
		if (ch >= 'a' && ch <= 'z'){
			c+=1;
		}
		else if (ch >= 'A' && ch <= 'Z'){
			c2+=1;
		}
		else if (isdigit(ch) != 0){
			c3+=1;
		}
		else{
			if(isprint(ch) != 0){
					c4+=1;
			}
		}
		
	}

	if(c > 0){
		a+=26;
	}
	if(c2 > 0){
		a+=26;
	}
	if(c3 > 0){
		a+=10;
	}
	if(c4 > 0){
		a+=32;
	}	
	double v = strlen(k);
	double b = v * (log(a)/ log(2));
	return b;
}
/*
This was the easiest function to make to test. I had a problem with the for loop earlier though.
I used sizeof(passwords) tp get the end of the for loop, but that didn't output the right size.
I used a literal 10000 stopper for the for loop since I know the size caps at 10000. After that
it was simple using strcmp then breaking out of the loop after.
*/
const char* tenk(char *d){
	char *t = ": no match";
	for(size_t i = 0; i < 10000; i++){
				if(strcmp(d, passwords[i]) == 0){
					t = ": match";
					break;	
				}
	}
	return t;	
} 
/*This is my function for the 133t test. This works simple by using switch cases to change
the strings special char to normal char.
*/
void onet(char *f){
	for(size_t i = 0; i < strlen(f); i++){
		switch(f[i]){
			case '0':
				f[i] = 'o';
				break;
			case '3':
				f[i] = 'e';
				break;
			case '!':
				f[i] = 'i';
				break;
			case '@':
				f[i] = 'a';
				break;
			case '#':
				f[i] = 'h';
				break;
			case '$':
				f[i] = 's';
				break;
			case '+':
				f[i] = 't';
				break;
		}
	}
}
int main(int argc, char*argv[]){
	char *s = argv[1];
	char *c = argv[2];
	//Tests 10k. utilizes tenk() function
	if(strcmp(s, "10k") == 0){
		printf("%s", s);
		printf("%s\n", tenk(c));
	}
	//Uses two functions to run. First l33t function (onet()), then 10k function(tenk)
	if(strcmp(s, "l33t") == 0){
		onet(c);
		printf("%s", s);
		printf("%s\n", tenk(c));				
	}
	/*This was way simpler than I expected. I just changed the ending of the string by
	setting the second to last string to null and after that plugged it into the 10k function
	*/
	if(strcmp(s, "plus1") == 0){
	    c[strlen(c)-1] = '\0';
		printf("%s", s);
		printf("%s\n", tenk(c));			
	}
	//Entropy function was used
	if(strcmp(s, "entropy") == 0){
		printf("%s", "bits of entropy:");
		printf(" %d\n", entropy(c));
	}	
}
