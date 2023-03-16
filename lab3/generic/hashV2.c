//LAB 2 COEN12
/*
*File:        hashV2.c 
*
*Copyright:   2022, David C. Thuita
*
*Description: This file acts as a definer for the set.h header 
*             It defines the functions for set.h and its struct
*             so that unique.c and parity.c can use the functions,
*             this version uses hash tables for data storage
*
*/


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct set{
    char *flags;//flag to id the spots in hash table
    void **data; //pointer pointing to pointers
    int length; //length of data array
    int count; 
    int (*compare)();
    unsigned (*hash)();
}SET;


static int search(SET *sp, void *elt, bool *found){

    assert(sp != NULL && elt != NULL);//make sure array or new elt arent empty
    
    //int check = 0;
    int locn;
    int deleted = -1;

    int i;
    for(i=0; i < sp->length; i++){

     
     locn = ( (*sp->hash)(elt) + i) % sp->length;

      if( sp->flags[locn] == 'F'){
	    if( (*sp->compare)(sp->data[locn],elt) == 0){
            *found = true;//elt has been found
            return locn;
	    }
       }else if( sp->flags[locn] == 'E'){
           *found = false;
           if(deleted == -1){ //no deleted spot
               return locn;
           }else{
               return deleted; //return deleted spot
           }
       }else if( sp->flags[locn] == 'D' && deleted == -1){
           deleted = locn;
       }
      }  
    *found = false;
    return deleted;
}

SET *createSet(int maxElts, int (*compare)(), unsigned (*hash)() ){
    SET *sp;
    sp = malloc(sizeof(SET));
    assert(sp != NULL);

    sp->data = (void**)malloc(maxElts * sizeof(void*));
    assert(sp->data != NULL);

    sp->flags = (char*)malloc(maxElts * sizeof(char));
    int i;
    for(i=0; i < maxElts; i++){  //initialize flags as empty
      sp->flags[i] = 'E';
    }

    sp->compare = compare;
    sp->hash = hash;

    sp->length = maxElts;
    sp->count = 0;
    return sp;

}
int numElements(SET *sp){
      return sp->count;
}
void destroySet(SET *sp){
    assert( sp != NULL);
    

    free(sp->data);
    free(sp->flags);
    free(sp);
}
void *findElement(SET *sp, void *elt){
    bool found;
    int i= search(sp, elt, &found);
      
    return found?sp->data[i]:NULL;
}
void addElement(SET *sp, void *elt){ //does not allocate new memory
    assert (sp != NULL && elt != NULL);
    bool found;

    int locn = search(sp, elt, &found);
    if (!found){
        assert(sp->count < sp->length);
        sp->data[locn] = elt;
        sp->flags[locn] = 'F';
        sp->count++;
    }

}
void *getElements(SET *sp, void *elt){
    void **words = malloc(sp->count*(sizeof(void*)));
    //as sert(words != NULL);
    int i;
    int j=0;
    for(i=0; i < sp->length; i++){
        if( sp->flags[i] == 'F' ){
           words[j] = sp->data[i];
           j++; 
        }
    }
    return words;
}
void removeElement(SET *sp, void *elt){
    assert (sp != NULL && elt != NULL);
    bool found;

    int locn = search(sp, elt, &found);// find elt
    if (found == true){
        assert(sp->count > 0);
        sp->flags[locn] = 'D';    
        sp->count--;
    }
    //no need to shift elts b/c we're using a hash table
}
