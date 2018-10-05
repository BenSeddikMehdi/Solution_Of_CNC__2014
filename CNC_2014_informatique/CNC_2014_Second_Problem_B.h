//
// Created by JayefDiba on 9/21/18.
//

#ifndef C_TUTORIAL_CNC_2014_SECOND_PROBLEM_B_H
#define C_TUTORIAL_CNC_2014_SECOND_PROBLEM_B_H

#endif //C_TUTORIAL_CNC_2014_SECOND_PROBLEM_B_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char fileContents[80];
FILE *pFile;

typedef struct waitingLine {
    char fileName[80];
    struct waitingLine *next;
}headList  ;

headList *cnc;

headList info = {"ProcessingData.txt",NULL};
headList cpge = {"Cpge.txt",NULL};
headList contest = {"Contest.txt",NULL};

headList table[3];
char strings[3][5]={"Jayef","Amigo","Douzi"};


// ***Question 8-) Displaying in the waiting order of file names
int display(){
    int count = 0;
    while (cnc!=NULL){
        printf("fileName = %s\n",cnc->fileName);
        cnc = cnc->next;
        count++;
    }
    return count;
}

// ***Question 9-) Simulation of file printing
int printFile(){
    int count = 0;
    pFile=fopen(cnc->fileName,"r");
    fgets(fileContents,80,pFile);
    printf("%s = %s\n",cnc->fileName,fileContents);
    fclose(pFile);
    while (cnc!=NULL){
        cnc = cnc->next;
        if(cnc!=NULL){
            printf("fileName = %s\n",cnc->fileName);
            count++;
        }
    }
    return count;
}