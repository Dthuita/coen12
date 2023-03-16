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
//#include "set.h"


typedef struct set{
	int count;
	int length;
	LIST **lists;
	int (*compare)();//function pointer
	unsigned (*hash)();
}SET;



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
		sp->lists[i] = createList(compare);
	}
    assert(sp != NULL);
    return sp;
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
    free(sp->lists);
	free(sp);
}
int numElements(SET *sp){
	return sp->count;
}
void addElement(SET *sp, void *elt){
    assert(sp != NULL && elt != NULL && sp->lists != NULL);

	//check item exisitence
	int index = (*sp->hash)(elt) % sp->length;

	//if( findItem(sp->lists[index], elt) == NULL){
		addFirst(sp->lists[index],elt);
        sp->count++;
	//}
    return;
}
void removeElement(SET *sp, void *elt){
    assert(sp != NULL && elt != NULL);
	//check item exisitence
	int index = (*sp->hash)(elt) % sp->length;

    if( findItem(sp->lists[index], elt)  != NULL){
		removeItem(sp->lists[index],elt);
        sp->count--;
	}
}
void *findElement(SET *sp, void *elt){
    assert(sp != NULL);
	int index = (*sp->hash)(elt) % sp->length;

	return findItem(sp->lists[index], elt);
}
void *getElements(SET *sp){
    assert(sp!=NULL||sp->count!=0);
    void  **elts = malloc(sizeof(void*) * sp->count);
    assert(elts!=NULL);
    int index=0;
    int i=0;
    for(;i<sp->length;i++)
        if(sp->lists[i]!=NULL){
            void **items=getItems(sp->lists[i]);
            int j=0;
            for(;j<numItems(sp->lists[i]);j++){
                elts[index]=items[j];
                index++;
            }
    }
    return elts;
}




