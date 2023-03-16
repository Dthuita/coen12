
#include <stdio.h>
#include <string.h>

# define MAX_WORD_LENGTH 30

//word counter program

int main(int argc, char *argv[]){
    
    FILE *fp;
    char words[MAX_WORD_LENGTH+1];
    int counter=0;

    fp = fopen(argv[1],"r");

    if( fp == NULL || argc != 2 ){
        printf("ERROR");
        return 0;
    }


    while( (fscanf(fp, "%s", words)) == 1){
        counter++;
    }

    fclose(fp);
    printf("%d words \n",counter);

    return 0;
}
