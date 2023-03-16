#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "pqueue.h"
#include "pack.h"

typedef struct node NODE;

int ascii[257];
NODE* node[257];

void readFile(char* file){
    FILE* fp= fopen(file, "r");
    if(fp == NULL){
        puts("file can't be opened");
        return;
    }
    int x = getc(fp);
    while(x != EOF){
        ascii[x]++;
        x = getc(fp);
    }
    fclose(fp);
    return;
}
NODE* makeNode(int data, NODE* left, NODE*right){
    NODE* root = malloc(sizeof(NODE));
    assert(root != NULL);
    root->count = data;
    root->parent = NULL;
    if(left != NULL){
        left->parent = root;
    }
    return root;
}
int depth(NODE* n){
    //assert(n != NULL);
    if(n->parent == NULL){
        return 0;
    }
    return depth(n->parent)+ 1;
}
int nodeCompare(NODE *n1, NODE* n2){
    assert(n1 != NULL && n2 != NULL);
    
    //return bigger node
    return (n1->count < n2->count) ? -1 : (n1->count > n2->count);
}
int main(int argc, char* argv[]){

    //check for file
    if(argc == 2){
        puts("Missing number of files");
        return 0;
    }else{
        readFile(argv[1]);
    }

    PQ *pq = createQueue(nodeCompare);
    int i=0;
    for(; i < 256; i++){
        if(ascii[i] > 0){
            node[i] = makeNode(ascii[i], NULL, NULL);
            addEntry(pq, node[i]);
        }
    }

    node[256] = makeNode(0, NULL, NULL);
    addEntry(pq, node[256]);
    while(numEntries(pq) > 1){
        NODE* left = removeEntry(pq);
        NODE* right = removeEntry(pq);
        NODE* parent= makeNode(left->count + right->count, left, right);
        addEntry(pq, parent);
    }

    int j=0;
    for(; j < 256; j++){
        if(node[j] != NULL){
            printf(isprint(j) ? "%c" : "%03o", j);
            printf(": %d x %d bits = %d bits\n", ascii[j], depth(node[j]), ascii[j]*depth(node[j]));
        }
    }
    pack(argv[1], argv[2], node);
    destroyQueue(pq);
    return 0;

}
