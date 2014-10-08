/**********************************************

* Name: Richard Petrie                        *

* Date: 9-20-14                               *

* Assignment: Project 2: Number sorting       *

***********************************************

* This program takes an input list and sorts  *

***********************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void printLists(int *numberList[]);

int main( int argc, char *argv[])
{
	//printf("%d",argc);
	if (argc == 2) {
		int c;
		char c2;
		int neg = 0;
		//not too many arguments
		FILE *fr = fopen(argv[1], "r");
		if (fr==0) {
		 	printf("Could not open file.\n"); 
		} else {
			fscanf(fr, "%d", &c);
			//First character
			int** numberList;
			numberList = (int**)malloc(c * sizeof(int*));
			int i = 0;
			int l;
			while (fscanf(fr,"%c",&c2) != EOF ) {
				l = 0;
				fscanf(fr, "%d%c", &c, &c2);
				numberList[i] = malloc(c * sizeof(int));
				i++;
				while (c2!='\n' && c2!=EOF) {
					fscanf(fr, "%d", &c);
					numberList[i - 1][l] = c;
					l++;
					fscanf(fr,"%c",&c2);
				}
				//free(&l);
			}
			//All values read in
			printf("Printing!");
			printLists(numberList);
			//free(numberList);
			fclose(fr);
			//free(fr);
		} 
		//Reading done
		

		//Sort stuff here


	} else { printf("Please provide one argument");}
	return 0;
}

void printLists(int *numberList[]) {
	//FILE *fw = fopen("./outlist.txt","w");
	int i;
	int l;
	//printf("\n%d, %d\n", sizeof(numberList), sizeof(int*));
	//printf("%d,%d\n", sizeof(numberList[i], sizeof(int)));
	/*
	for (i = 0; i < (sizeof(numberList)/sizeof(int*)); i++) {
		for (l = 0; l < sizeof(numberList[i])/sizeof(int);i++) {
			printf("%d, ", numberList[i][l]);
		}
		printf("\n");
	}
	fclose(fw);*/
}