//
// Created by JayefDiba on 9/20/18.
//

#include "CNC_2014_Second_Problem_A.h"

int main(int argc, char const *argv[])
{

    char fileName[80] ;
    printf("fileName = %s\n",fileName);
    printf("empty = %d\n",empty());
    printf("full = %d\n",full());
    display();
    printf("add = %d\n",add("f4.txt"));
    printf("empty = %d\n",empty());
    printf("full = %d\n",full());
    display();
    printf("delete = %d\n",delete(fileName));
    printf("fileName = %s\n",fileName);
    printf("empty = %d\n",empty());
    printf("full = %d\n",full());
    display();

    return 0;
}
