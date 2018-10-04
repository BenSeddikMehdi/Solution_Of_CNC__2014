//
// Created by JayefDiba on 9/18/18.
//

#include "CNC_2014_First_Problem.h"

int machineName(int n, machine array[], int x, char nameR[100]);

int main(int argc, char const *argv[])
{
	char nameR[100]="";
	for (int i = 0; i < 4; ++i) {
		machinesArray[i].hostID = Host[i];
		strcpy(machinesArray[i].name,hostName[i]);
	}
	// Now I got this :
	// Now I've my struct "arrayMachines" here and I'll fill it by hostID
	// and machines names values with two new arrays that I created before
	// as a global variables  Host[4] and hostName[4]
	/*  ________________________________________________________
 	 * |   field |arrMach[0]|arrMach[1] |arrMach[2] |arrMach[3] |
 	 * |_________|__________|___________|___________|___________|
	 * | hostID  |   200    |   210     |   215     |   220     |
	 * |_________|__________|___________|___________|___________|
 	 * | names   | machine1 | machine2  | machine3  | machine4  |
 	 * |_________|__________|___________|___________|___________|
 	 */
	printf("MachinesName returned = %d\n",machineName(N,machinesArray,200,nameR));
	printf("nameR = %s\n",nameR);
	return 0;
}
int machineName(int n, machine array[], int x, char nameR[100]){
	// This is a hard Question I answered it  inside the main function


	// I made this bloc because it's hard to put array[i].hostID in the
	// dichotomousSearch function as a second variable I thought is incompatible
	// so I created below a new int array Host[4] that contains array[i].hostID values
	int Host[4] = {0};
	for (int i = 0; i < 4; ++i){
		Host[i] = array[i].hostID;
	}
	if(dichotomousSearch(n,Host,0,n-1,x)==-1){
		strcpy(nameR,"");
		return -1;
	} else {
		strcpy(nameR,array[dichotomousSearch(n,Host,0,n-1,x)].name);
		return dichotomousSearch(n,Host,0,n-1,x);
	}
}


