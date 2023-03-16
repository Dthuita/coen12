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

typedef struct node{
    void *data;
    struct node *next;
    struct node *prev;
}NODE;

typedef struct list{
  int count;
  struct node *head;
  int (*compare)();//function pointer
}LIST;


LIST *createList(int (*compare)()){
    //list creation
    LIST *lp;
    lp =malloc(sizeof(struct list));
    assert(lp != NULL);

    //list compnonets initiazile
    lp->count = 0;
    lp->compare = compare;
    lp->head = malloc(sizeof(struct node));
    assert(lp->head != NULL);

    //connect the nodes
    lp->head->next = lp->head;
    lp->head->prev = lp->head;

    return lp;
}
void destroyList(LIST *lp){
    assert(lp != NULL);

    NODE *pDel = lp->head->prev;
    NODE *pPrev;
    
    while(pDel != lp->head){
        pPrev = pDel->prev;
        free(pDel);
        pDel = pPrev;
    }
    free(pDel);
    free(lp);
}
int numItems(LIST *lp){
    return lp->count;
}
void addFirst(LIST *lp, void *item){
    assert(lp != NULL);

    //create new node
    NODE *node = malloc(sizeof(NODE));
    node->data = item;  
    //assert(lp->head->next->data);

    //connect node to list
    node->prev = lp->head;
    node->next = lp->head->next;
    lp->head->next->prev = node;
    lp->head->next = node; //need to double check this
    
    lp->count++;
}
void addLast(LIST *lp, void *item){
    assert(lp != NULL);

    //create new node
    NODE *node = malloc(sizeof(struct node));
    node->data = item; 

    //connect node to list
    node->next = lp->head;
    node->prev = lp->head->prev;
    lp->head->prev->next = node;
    lp->head->prev = node;

    lp->count++;
}
void *removeFirst(LIST *lp){
    //create node pointed to by head
    NODE *node = lp->head->next;
    
    //sever connections from node and replace
    lp->head->next = node->next;
    node->next->prev = lp->head;
    
    lp->count--;
    return NULL;
    //return node->data;
}
void *removeLast(LIST *lp){
    //create nodes pointed to by head
    NODE *del = lp->head->prev;
    NODE *node = lp->head->prev->prev;

    //sever connections from  node and replace
    node->next = lp->head;
    lp->head->prev = node;

    //free node
    free(del);
    lp->count--;
    return NULL;
}
void *getFirst(LIST *lp){
    assert(lp->head->next->data);
    return lp->head->next->data;
}
void *getLast(LIST *lp){
    assert(lp->head->prev->data);
    return lp->head->prev->data;
}
void removeItem(LIST *lp, void *item){
    assert(lp->head->next != NULL);

    NODE *node = lp->head->next;
    NODE *tempNode = node->next; //random initial value

    int i=0;
    for(;i < lp->count; i++){
        if( (*lp->compare)(node->data, item) == 0){
            
            //initialize tempNode as next after node
            tempNode = node->next;
            
            //reassign connections
            tempNode->prev = node->prev;
            node->prev->next = tempNode;     
            
            //delete item node
            free(node);
            
            //reassign node
            node = tempNode;
            lp->count--;
        }
        node = node->next;
    }
    //return NULL;

}
void *findItem(LIST *lp, void *item){
    assert(lp->head->next != NULL);

    NODE *node = lp->head->next;
    
    int i=0;
    for(;i < lp->count; i++){
        if( (*lp->compare)(node->data, item) == 0){
            return node->data;
        }
        node = node->next;
    } 
    return NULL;
}
void *getItems(LIST *lp){
    assert(lp->head->next != NULL);

    NODE *node = lp->head->next;
    void **arr= malloc(sizeof(void*)*lp->count);    

    int i=0;
    for(;i < lp->count; i++){
        arr[i] = node->data;        
        node = node->next;
    }
    
    return arr;
}









//gcc -o maze maze.o deque.c -lcurses
