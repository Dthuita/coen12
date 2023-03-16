/*
 *File: list.c
 *
 *Copyright: 2022, David C. Thuita
 *
 *Description:
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct node{
    void **data;
    int count;
    int front;
    int length;
    struct node* next;
    struct node* prev;
}NODE;
typedef struct list{
    int count; //total # of items not total # of nodes
    struct node *head;
    struct node *tail;
}LIST;

LIST *createList(void){//O(???)  
    LIST *lp= malloc(sizeof(LIST));

    lp->count=0;

    lp->head= malloc(sizeof(NODE));
    lp->head->data = malloc(sizeof(void*)*4); //2d array
    lp->head->count = 0;
    lp->head->front = 0;
    lp->head->length = 4;

    lp->tail= malloc(sizeof(NODE));
    lp->tail->data = malloc(sizeof(void*)*4); //2d array
    lp->tail->count = 0;
    lp->tail->front=0;
    lp->tail->length = 4;

    lp->head->next = lp->tail;
    lp->tail->prev = lp->head;

    return lp;
}
void destroyList(LIST *lp){//O(???)  
    assert(lp != NULL);
          
    free(lp);
}
int numItems(LIST *lp){//O(1)
    assert(lp != NULL);

    return lp->count;
}
void addFirst(LIST *lp, void *item){//O(???)  

    NODE *temp = lp->head;
 
    //first node array is full
    if(temp->count == temp->length){ //count for array is equal to size of array AKA array is full
        
        //initilaize new node
        NODE *new = malloc(sizeof(NODE));
        new->data = malloc(2*temp->length*sizeof(void*));
        new->count = 0;
        new->front = 2*temp->length - 1;
	    new->length = 2*temp->length;

        //insert new value
        new->data[new->front] = item;
       
        //connect new node to first of circular list
	    //use uncircular list will be easy to understand
        //you can just add the new node at the prev position of head
	    new->next = lp->head;
	    lp->head->prev = new;

	    //dont make it circular
	    //new->prev = lp->tail;
	    //lp->tail->next = new;

	    //and then change the head;
	    lp->head = new;

        //add new item to count
        lp->head->count++;
        lp->count++;
	//printf("new %s\n", lp->head->data[(lp->head->front)]);
    }else{ //first node array is not full
      
      //adjust the front index
      if( lp->head->front != 0){
        lp->head->front--;
      }else{
        lp->head->front = lp->head->length-1;
      }

      lp->head->data[lp->head->front] = item;
      lp->head->count++;
      lp->count++;
      //printf("%s\n", lp->head->data[lp->head->front]);
    }
    
    //printf("%d\n", lp->head->count);
    return;
}
void addLast(LIST *lp, void *item){//O(???)  

    NODE *temp = lp->tail;

 
    //first node array is full
    if(temp->count == temp->length){ //count for array is equal to size of array AKA array is full
        
        //initilaize new node
        NODE *new = malloc(sizeof(NODE));
        new->data = malloc(2*temp->length*sizeof(void*));
        new->count = 0;
        new->front = 2*temp->length - 1;
	    new->length = 2*temp->length;

        //add new item to count
        new->count++;
        lp->count++;
	
        //insert new value
        new->data[new->front] = item;
       
        //connect new node to first of circular list
	    //use uncircular list will be easy to understand
        //you can just add the new node at the prev position of head
	    new->prev = lp->tail;
	    lp->tail->next = new;

	    //and then change the head;
	    lp->tail = new;

	    //printf("tail count %d\n", lp->tail->count);
	    //printf("new %s\n", lp->tail->data[lp->tail->front]);
    }else{ //first node array is not full

      //add new item to count
      lp->tail->count++;
      lp->count++;

      lp->tail->data[(lp->tail->front+lp->tail->count-1)%lp->tail->length] = item;
      //printf("%s\n", lp->tail->data[(lp->tail->front+lp->tail->count-1)%lp->tail->length]);
    }

    return;
}
void *removeFirst(LIST *lp){//O(???) 
 
      if(lp->head->count == 0){
		lp->head = lp->head->next;
		free(lp->head->prev);
		lp->head->prev = NULL;
	}
	//printf("%d\n", lp->head->count);
	//we already had "front" to record the first position;
	void *dItem = lp->head->data[lp->head->front];
	lp->head->front++;
	lp->head->count--;
	lp->count--;
	if(lp->head->front == lp->head->length)lp->head->front = 0;

	return dItem;

}
void *removeLast(LIST *lp){ //O(???)  
    assert( lp != NULL);

    void *dItem;

    if(lp->tail->count == 0){
      lp->tail = lp->tail->prev;
      free(lp->tail->next);
      lp->tail-> next = NULL;
    }

    if( (lp->tail->front+lp->tail->count-1)%lp->tail->length  == lp->tail->front ){
          dItem = lp->tail->data[lp->tail->front];
	  /*->tail = lp->tail->prev;
	  free(lp->tail->next);
	  lp->tail->next = NULL;*/
    }else{
      dItem = lp->tail->data[ (lp->tail->front+lp->tail->count-1)%lp->tail->length ];
    }

    //sert( lp->tail->count != 0);
    
    lp->tail->count--;
    lp->count--;
    
    return dItem;

}
void *getFirst(LIST *lp){//O(???)  
    assert(lp != NULL);

    return lp->head->data[lp->head->front];
}
void *getLast(LIST *lp){//O(???)  
    assert(lp != NULL);

    if(lp->tail->count == 0){
      lp->tail = lp->tail->prev;
      free(lp->tail->next);
      lp->tail-> next = NULL;
    }

    return lp->tail->data[ ( lp->tail->front + lp->tail->count -1 ) % lp->tail->length];
}
void *getItem(LIST *lp, int index){//O(???)  

    NODE *n = lp->head; //starting at the head

    while(index >= n->count){
        index -= n->count;
        n = n->next;
    }
    return (n->data[index]); 
}
void setItem(LIST *lp, int index, void *item){//O(???)  
    //search through nodes and adjust for length size
    assert(lp != NULL);

    NODE *temp = lp->head;

    while( index > temp->count  && temp->next != NULL){
            index -= temp->count;
            temp = temp->next;
    }

    temp->data[index] = item;
}
/*
int main(){
	LIST *lp = createList();
	int i;	
	

	for(i = 1; i < 8; i++){
	        addFirst(lp, "lol");
	        addFirst(lp, "yup");
	}

	printf("the number of items %d\n", numItems(lp));

       

	for(i = 1; i < 14; i++){
	  printf("%s\n", getItem(lp, i));
	}

	setItem(lp, 3, "hello");

	for(i = 1; i < 14; i++){
	  printf("%s\n", getItem(lp, i));
	}

	destroyList(lp);

	return 0;
}
*/
