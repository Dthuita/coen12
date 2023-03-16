

//LAB 2 COEN12
/*
 *File:        sorted.c
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
#include "set.h"

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


static int search(SET *sp, char *elt, bool *found){ //use binary search & add bool found

  int low, mid, hig;

  low = 0;
  hig = sp->count-1;

  while(low <= hig){

    mid = (low+hig)/2;

    //if mid value less than given str
    if( strcmp(sp->data[mid], elt) < 0 ){
      low = mid + 1;
    }
    //if mid value greater than given str
    if( strcmp(sp->data[mid], elt) > 0 ){
      hig = mid - 1;
    }
    //if mid value equal than given str i.e. value is found
    if( strcmp(sp->data[mid], elt) == 0 ){
      *found = true;
      return mid;
    }
  }
  *found = false;
  return low; //index where elt should be
}

void addElement(SET *sp, char *elt){

  bool found;

  //first allocate memory
  //sp->data[sp->count] = malloc( (strlen(elt) + 1)*sizeof(char) );
  //assert( sp->data[sp->count] != NULL );

  //array too long
  if(sp->count == sp->length){
    return;
  }

  //repeatition
  int index = search(sp, elt, &found);
  if( found == true){
      return;
  }
  //---------------add new element-----------------//
  
  //first: shift array from right side
  int k;
  for(k=sp->count; k > index; k--){
    sp->data[k] = sp->data[k-1];
  }
  //second: add new element
  elt = strdup(elt);
  sp->data[index] = elt;


  //return true and increament count
  sp->count += 1;
  return;
}
int numElements(SET *sp){
  return sp->count;
}
void removeElement(SET *sp, char *elt){
  bool found; 

  assert(sp != NULL);

  //find Element in array if exists
  search(sp, elt, &found);
  if( found != true){
    return;
  }else{
    //remove element from array
    int index = search(sp, elt, &found);

    free( sp->data[index] );
    assert( sp->data[index] != NULL );

    int k;
    for(k=index; k < sp->count-1; k++){
      sp->data[k] = sp->data[k+1];
    }
    
    //free space and check memory
    //free( sp->data[sp->count-1] );
    //assert( sp->data[sp->count-1] != NULL );

  }


  sp->count--; //update count
}
char *findElement(SET *sp, char *elt){
  bool found;
  int i= search(sp, elt, &found);
  
  return found?sp->data[i]:NULL;
}
char **getElements(SET *sp){
  char **words = malloc(sp->count*(sizeof(char*)));
  assert(words != NULL);

  return memcpy(words, sp->data, sp->count*(sizeof(char*))  );
}
void destroySet(SET *sp){
  assert( sp != NULL);
  //free alloacated memories
  int i;
  for(i=0; i < sp->count; i++){
    free(sp->data[i]);
  }
  free(sp->data);
  free(sp);

}
