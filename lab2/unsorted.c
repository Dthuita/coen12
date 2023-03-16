//LAB 2 COEN12
/*
 *File:        Unsorted.c
 *
 *Copyright:   2022, David C. Thuita
 *
 *Description: This file acts as a definer for the set.h header 
 *             It defines the functions for set.h and its struct
 *             so that unique.c and parity.c can use the functions
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct set{
  char **data; //pointer pointing to pointers
  int length; //length of data array
  int count; //

}SET;


SET *createSet(int maxElts){
  SET *sp;
  sp = malloc(sizeof(SET));
  assert(sp != NULL); 

  sp->data = (char**)malloc(maxElts * sizeof(char*));
  assert(sp->data != NULL);

  sp->length = maxElts;
  sp->count = 0;
  return sp;

}
static int search(SET *sp, char *elt){
  for(int i=0; i < sp->count; i++){
    if( strcmp( sp->data[i], elt) == 0 ){
      return i;
    }
  }
  return -1;//word wasn't found

}

bool addElement(SET *sp, char *elt){
  //first allocate memory
  sp->data[sp->count] = malloc( (strlen(elt) + 1)*sizeof(char) );
  assert( sp->data[sp->count] != NULL );

  //array too long
  if(sp->count == sp->length){
    //printf("Too many Elements!");
    return false;
  }

  //repeatition
  if( search(sp, elt) != -1 ){ 
      //printf("Element already exists!");
      return false;
  }

  //add new element
  strcpy(sp->data[sp->count], elt);
  sp->count += 1;
  return true;
}
int numElements(SET *sp){
  return sp->count;
}
void removeElement(SET *sp, char *elt){
  assert(sp != NULL);

  //find Element in array if exists
  if( search(sp, elt) == -1){
    return;
    //printf("Element does not exist!");
  }else{
    //remove element from array
    int index = search(sp, elt);
    free( sp->data[index] );

    //check memory
    assert( sp->data[index] != NULL );

    //fill space with last element in array
    sp->data[index] = sp->data[--sp->count]; //why --sp->count

  }

}
char *findElement(SET *sp, char *elt){
  for(int i=0; i < sp->count; i++){
    if( strcmp( sp->data[i], elt) == 0 ){
      return elt;
    }
  }
  return NULL;
}
char **getElements(SET *sp){
  char **words = malloc(sp->count*(sizeof(char*)));
  assert(words != NULL);

  return memcpy(words, sp->data, sp->count*(sizeof(char*))  );
}
void destroySet(SET *sp){
  assert( sp != NULL);
  //free alloacated memories
  for(int i=0; i < sp->count; i++){
    free(sp->data[i]);
  }
  free(sp->data);
  free(sp);

}
