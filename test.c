#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// Header file which contains helpful definitions
// Contains externs, structs, and union definitions
#include "support.h"

#define SIZE_MAL 10
#define SET_EXTERN 0

// i variable which can be reset and used for loops throughout the program
int i = 0;

// Extern variable reference. Declared and set in support.h
extern int variable;

void callbackMessage();

void callback(void (*ptr)());

void call_process();


void main(){
	printf("\n\nHello world. And welcome to Kellen's amazing C Review!\n");
	printf("Learn some stuff as I do as well!\n");
	
	printf("\n\nStrings, Pointers, and Memory Allocation.\n");
	char* c = malloc(SIZE_MAL);
	c[0] = 'W';
	c[1] = 'O';
	c[2] = 'W';
	for(i = 3; i < SIZE_MAL; i++){
		c[i] = '\0'; 
	}
	
	printf("%s\n", c);
	
	printf("\n\nExtern\n");
	printf("Originally Set: %d\n", variable);
	variable = 1;
	printf("Reset: %d\n", variable);
	
	
	printf("\n\nStructs & Unions\n");
	struct test_struct ts;
	ts.i = 1;
	ts.f = 2.5;
	sprintf(ts.label, "label");
	printf("Struct: %d, %lf, %s\n", ts.i, ts.f, ts.label);
	union test_union tu;
	tu.i = 1;
	tu.f = 2.5;
	sprintf(tu.label, "label");
	printf("Union: %d, %lf, %s\n", tu.i, tu.f, tu.label);
	
	printf("\n\nCallbacks\n");
	void (*ptr)() = &callbackMessage;
	callback(ptr);
	
	printf("\n\nProcesses & Threads\n");
	call_process();
	
	printf("\n\nFIN.\n");
	
}

void callbackMessage(){
	printf("I'm calling back!!");
}

void callback(void (*ptr)()){
	(*ptr) ();
}


void call_process(){
	int pid = fork();
	
	if(pid == 0){
		printf("Child Process! %d", pid);
	}
	else{
		printf("Parent Process! %d", pid);
	}
}