
//LAB 5 COEN12
/*
*File:        prior.c
*
*Copyright:   2022, David C. Thuita
*
*Description: 
*
*/
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "pqueue.h"

#define Left(x) (2*x+1)
#define Right(x) (2*x+2)
#define Parent(x) ((x-1)/2)

typedef struct pqueue{
    int count;
    int length;
    void **data;
    int (*compare)();
}PQ;

PQ *createQueue(int (*compare)()){
    PQ *pq = malloc(sizeof(PQ));

    pq->count=0;
    pq->length= 10;
    pq->data = malloc(pq->length*sizeof(void*));
    pq->compare = compare;
    
    assert(pq != NULL);
    assert(pq->data != NULL);

    return pq;//must return pq struct
}
void destroyQueue(PQ *pq){
    assert(pq != NULL);

    //free each array index
    int i=0;
    for(; i < pq->count; i++){
        free(pq->data[i]);
    }

    //free data container
    free(pq->data);

    //free pq struct
    free(pq);
}
int numEntries(PQ *pq){
    assert(pq != NULL);
    
    return pq->count;
}
void addEntry(PQ *pq, void *entry){
    assert(pq != NULL && entry != NULL);
        
    if(pq->count == pq->length){
        pq->length *=2;
        pq->data = realloc(pq->data, pq->length*sizeof(void*));
    }
    int x = pq->count;
    pq->data[x] = entry;

    //child smaller than parent. swap pos.
    while(x != 0 && (*pq->compare)(pq->data[Parent(x)], pq->data[x]) > 0){
        void* temp= pq->data[x];
        pq->data[x] = pq->data[Parent(x)];
        pq->data[Parent(x)] = temp;
        x = Parent(x);    
    }
    pq->count++;
    return;
}
void *removeEntry(PQ *pq){
    assert(pq != NULL);

    void *deleted = pq->data[0];
    pq->data[0] = pq->data[pq->count-1];//move last position data to root
        
    //reheap
    int x=0;
    
    while(Left(x) <= pq->count-1 ){
        int small = Left(x);
        if( Right(x) <= pq->count-1 ){  
	            if( (*pq->compare)(pq->data[Right(x)], pq->data[Left(x)]) < 0 )
                    small =Right(x);                       
        }
        if( (*pq->compare)(pq->data[x], pq->data[small]) < 0 ){//if parent smaller than childern
            break;
        }else{ //parent not smallest so swap
          void *temp = pq->data[x];
          pq->data[x] = pq->data[small];
          pq->data[small] = temp;
        }
        x =small;
    }
    pq->count--;
    return deleted;

}

