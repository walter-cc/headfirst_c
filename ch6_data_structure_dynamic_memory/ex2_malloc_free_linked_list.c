/*
	p291:
	This is the sample code shows how to use malloc() & free in linked list
*/

#include <stdio.h>
#include <stdlib.h>	// for using malloc() & free()
#include <string.h> // for strdup(char *name);

typedef struct island{
	
	char *name;
	char *opens;
	char *closes;
	struct island *next;	// pointer to direct to next struct. This pointer need to use "struct island" declare
} island;					// the struct island called "recursive structure"

void display(island *start){

	island *i = start;
		
	for(; i != NULL ; i = i->next){
		printf("Name: %sopen: %s-%s\n",i->name,i->opens,i->closes);
	}	
}

// create the heap memory
island* create(char *name){

	island *i = malloc(sizeof(island));
	i->name = strdup(name);	// copy the string to the heap
	//"open" and "close" items are constant value, is stored in constants area of memory, read-only. unneccessary to use strdup.
	i->opens = "09:00";
	i->closes = "17:00";
	i->next = NULL;

	return i;
}

// release the heap memory
void release(island *start){

	island *i = start;
	island *next = NULL;
	for(; i != NULL; i = next ){
		next = i->next;	// let pointer instruct to next island
		free(i->name);	// free strdup() first 
		free(i);		// free island struct
	}
}

int main(void){

	island *start = NULL;
	island *i = NULL;
	island *next = NULL;
	char name[80];

	/*
		stdin : read the words form standard intput keyboard
		i = next : let the next island be the next one
		fgets(name, 80, stdin) != NULL : if error or over, then break out the loop
	*/
	for(; fgets(name, 80, stdin) != NULL ; i = next){
		
		next = create(name);	// create island
		
		if(start == NULL){
			start = next;
		}
		
		if(i != NULL){
			i->next = next;
		}
		
		display(start);
	}
	
	return(0);
}

