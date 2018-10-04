//
// Created by JayefDiba on 9/18/18.
//

#ifndef OPEN_CNC_2014_FIRST_PROBLEM_H
#define OPEN_CNC_2014_FIRST_PROBLEM_H

#endif //OPEN_CNC_2014_FIRST_PROBLEM_H

// include the necessary libraries
#include <stdio.h>
#include <string.h>

// This function has the same principle of the "pow" function that included in math.h library
// power(2,4) <==> pow(2,4) = 2^4 = 16
int power(int a,int b) {
    if(b!=0){
        return a*power(a,b-1);
    }
    else return 1;
}

typedef struct {
    int hostID;
    char name[100];
}machine;

#define N 4
machine machinesArray[N];
int t0[4] = {127,53,36,24};

int Host[4] = {200,210,215,220};
char hostName[4][100]={"machinery1","machinery2","machinery3","machinery4"};

// **Question -1-) Verification of the validity of an IP address
int addressIP(int t0[4]){   //Function that had addressIP as a parameter
    for (int i = 0; i <4; i++) {
        if (t0[i]>255||t0[i]<0) return 0;// IP address isn't valid
    }
    return 1;//IP address is valid
}

// **Question -2-) The classes of an IP address
//      2-a)-Calculate the number of machines in the network of the A class
long nbMachinesA(){
    if(t0[0]>=1&&t0[0]<=126) return power(2,24)-2; // pow(a,b) = a^b , this function is included in math.h library
    else return 0; // Isn't A class
    // Number of machines in a network of A class is  2^24 - 2
}

//      2-b)-Determination the class of an IP address
char classAddress(int t0[4]){
    if(addressIP(t0)==0||t0[0]==127) return 'X';
    else
        if(t0[0]>=1&&t0[0]<=126) return 'A';
        else if (t0[0]>=128&&t0[0]<=191) return 'B';
        else if (t0[0]>=192&&t0[0]<=223) return 'C';
}

// **Question -3-) The mask of a network
//      3-a)-Binary Decomposition
void binary(int byte,int bin[8]){// This function convert a decimal to binary number
    if(byte>=0 && byte<=255){ // the byte should be in range of 0 and 255
        for (int i = 0; i < 8; ++i) {
            bin[i] = byte % 2;
            byte /= 2;
        }
    }
}

//      3-b)-The operation "andBinary" between two integers
int andBinary(int x,int y){
    int xBinary[8]={0}, yBinary[8]={0}; // Contains the binary values of x and y
    int productBinaries[8]={0}, result = 0;
    binary(x,xBinary);//0100
    binary(y,yBinary);//0110
    for (int i = 0; i < 8; ++i) {
        productBinaries[i] = xBinary[i]*yBinary[i];
        result +=  productBinaries[i]*power(2,i);
    }
    return result;
}

//      3-c)-Determination of the network ID
void networkID(int t0[4], int netID[4]){
    if(classAddress(t0)=='A'){ // NET Mask = 255.0.0.0
        netID[0] = andBinary(t0[0],255);
        netID[1] = 0;
        netID[2] = 0;
        netID[3] = 0;
    } else if (classAddress(t0)=='B'){// NET Mask = 255.255.0.0
        netID[0] = andBinary(t0[0],255);
        netID[1] = andBinary(t0[1],255);
        netID[2] = 0;
        netID[3] = 0;
    } else if (classAddress(t0)=='C'){// NET Mask = 255.255.255.0
        netID[0] = andBinary(t0[0],255);
        netID[1] = andBinary(t0[1],255);
        netID[2] = andBinary(t0[2],255);
        netID[3] = 0;
    } else printf("Isn't A , B or C class\n");
}

// **Question -4-) The DNS(Domain Name System)
//      4-a)-Dichotomous search in a sorted array
int dichotomousSearch(int n, int T[], int inf, int sup, int x){
    int m = (sup+inf)/2;
    if(inf>sup) return -1;
    if(x==T[m]) return m;
    else if(x>T[m]) return dichotomousSearch(n,T,m+1,sup,x);
    else  return dichotomousSearch(n,T,inf,m-1,x);
}

//      4-b)-Search for the name associated with an address IP
        // Go to CNC_2014_First_Problem.c
