//
// Created by JayefDiba on 9/21/18.
//

#include "CNC_2014_Second_Problem_B.h"


int main(int argc, char const *argv[])
{
    // Execution of the question 8
    cnc = &info;
    info.next = &cpge;
    cpge.next = &contest;
    printf("display = %d\n",display());
    // Execution of the question 9
    cnc = &info;
    pFile = fopen(cnc->fileName,"w");
    if(!pFile){
        printf("Couldn't open the file\n");
    }
    fprintf(pFile,"%s","Data Processing Test 2014 nice HardWork Sir...!!");
    if(fclose(pFile)!=0){
        printf("Couldn't close the file\n");
    }
    printf("printFunction = %d\n",printFile());

    return 0;
}