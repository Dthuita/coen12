/*
 * David Thuita
 *
 * Lab 4
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "list.h"
#include "set.h"


typedef struct set{
	int count;
	int length;
	LIST **lists;
	int (*compare)();//function pointer
	unsigned (*hash)();
}SET;

int search(SET *sp, void *elt){
	int index = (*sp->hash)(elt);

	if( findItem(sp->lists[index], elt) != NULL){
		return index; //item found
	}else{
		return -1; //item not found
	}
}
SET *createSet(int maxElts, int (*compare)(), unsigned (*hash)() ){
	//init SET
	SET *sp = malloc(sizeof(SET));
	
	//init simple SET components
	int average = 20;
	sp->length= maxElts/average; //double check ??
	sp->count = 0;
	sp->compare = compare;
	sp->hash = hash;

	//init complex SET components
	sp->lists = malloc(sp->length*sizeof(LIST*));
	int i= 0;
	for(; i< sp->length; i++){
		sp->lists[i] = createList(sp->compare);
	}
	
}
void destroySet(SET *sp){
	//check if empty
	assert(sp != NULL);

	//free lists 
	int i=0;
	for(; i< sp->length; i++){
		destroyList(sp->lists[i]);
	}

	//free set
	free(sp);
}
int numElements(SET *sp){
	return sp->count;
}
void addElement(SET *sp, void *elt){
	//check item exisitence
	int index = search(sp, elt);
	if( index != -1){
		return; //item already exists
	}
	
	//add element
	addFirst(sp->lists[index],elt);
	sp->count++;
}
void removeElement(SET *sp, void *elt){
	//check item exisitence
	int index = search(sp, elt);
	if( index == -1){
		return; //item doesn't exists
	}

	//remove element
	removeItem(sp->lists[index],elt);
	sp->count--;
}
void *findElement(SET *sp, void *elt){
	int index = (*sp->hash)(elt);

	void *el = findItem(sp->lists[index], elt);

	if(el != NULL){
		return el; //item found
	}else{
		return NULL; //item not found
	}

}
void *getElements(SET *sp){
	assert(sp != NULL);
	
	void **allEl = malloc(sp->count*sizeof(void*));	
	void **item;

	int i;
	int j;
	for(j=0, i=0; i < sp->length; i++){
		item = getItems(sp->lists[i]);
                memcpy(allEl+j, item, sizeof(void *)*numItems(sp->lists[i]) );
		j+= numItems(sp->lists[i]);
		free(item);
	}
	
	return allEl;
}




