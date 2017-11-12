/*
	p275:
	This is the sample code shows "Linked list"
*/

#include<stdio.h>

typedef struct island{
	
	char *name;
	char *opens;
	char *closes;
	struct island *next;	// pointer to direct to next struct. This pointer need to use "struct island" declare
} island;					// the struct island called "recursive structure"

void display(island *start){

	island *i = start;
		
	for(; i != NULL ; i = i->next){
		printf("Name: %s open: %s-%s\n",i->name,i->opens,i->closes);
	}	
}

int main(void){

	island amity = {"Amity","09:00","17:00",NULL};
	island craggy = {"Craggy","09:00","17:00",NULL};
	island isla_nublar = {"Isla Nublar","09:00","17:00",NULL};
	island shutter = {"Shutter","09:00","17:00",NULL};

	amity.next = &craggy;
	craggy.next = &isla_nublar;
	isla_nublar.next = &shutter;
	/*
		amity -> craggy -> isla_nublar -> shutter
	*/		
	display(&amity);

	island skull = {"Skull","09:00","17:00",NULL};
	isla_nublar.next = &skull;
	skull.next = &shutter;
	/*
		amity -> craggy -> isla_nublar -> skull -> shutter
	*/
	display(&amity);

	return(0);
}










