//
// Created by JayefDiba on 9/20/18.
//

#ifndef C_TUTORIAL_CNC_2014_SECOND_PROBLEM_A_H
#define C_TUTORIAL_CNC_2014_SECOND_PROBLEM_A_H

#endif //C_TUTORIAL_CNC_2014_SECOND_PROBLEM_A_H

#include <stdio.h>
#include <string.h>

#define MAX 4
char T[MAX][80] = {"f1.txt","f2.txt","f3.txt"};
int endIndex = 0;

// This's a just a function that I had created to display The array values and
// the endIndex value
void display() {
    for (int i = 0; i < MAX; ++i) {
        printf("T[%d] = %s\n",i,*(T+i));
    }
    printf("endIndex = %d\n",endIndex);
}

// ***Question 5-) Preliminary functions
//      5-a)-Waiting Line initialization
void initialize() {
    for (int i = 0; i < MAX; ++i) {
        strcpy(*(T+i),"");// <==> T[i] = ""; empty string
    }
    endIndex = -1;
}

//      5-b)-Empty Waiting Line
int empty() {
    for (int i = 0; i < MAX; ++i) {
        if (strcmp(*(T+i),"")!=0) {// If there's T[i]!="" it returns 0 so isn't empty
            return 0;
        }
    }
    endIndex = -1;
    return 1;// It means that the array T[MAX][80] is empty
}

//      5-c)-Full waiting Line
int full() {
    for (int i = 0; i < MAX; ++i) {
        if (strcmp(*(T+i),"")==0) {// If there's T[i]=="" It means the array isn't full
            endIndex = i-1;
            return 0;
        }
    }
    endIndex = MAX-1;// Updating the endIndex
    return 1;// It means the array T[MAX][80] is full
}

// ***Question 6-) Add a file to the end of the print server queue
int add(char fileName[]) {
    if (full() != 1) {// Checking if the array T[] ins't full with the full() function
        strcpy(*(T+endIndex+1),fileName);// Adding the file to the end
        endIndex++;// Updating the endIndex
        return 1;// Successful Addition of the file
    } else return 0;// Failure adding of the file
}

// ***Question 7-) Deleting the first file name that enters the queue
int delete(char fileName[]) {
    if (empty() != 1) {// Should checks that the array isn't empty
        strcpy(fileName,*T);// Copying the first file name of the array T in the fileName variable
        for (int i = 0; i <endIndex ; ++i) {
            strcpy(*(T+i),*(T+i+1));//Updating the Array
        }
        strcpy(*(T+endIndex),"");// filling the last file name of the array with an empty string ""
        endIndex--;//Updating The endIndex
        return 1;// Successful deleting
    } else return 0;// Failure Deleting
}
