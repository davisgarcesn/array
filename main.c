//Program: File_handler
//Version: 1.0
//Date: 24-03-2023
//Owner: Davis Garces

/*Description:
This program is designed to allocate memory dynamically based
on user input and write data to the allocated memory. The program
also writes the data to a file named data.txt in the current
working directory.*/

//Files used:
//main.c: main document
//resource.h: all libraries needed
//resource.c: all functions needed

//Main Document
#include "resource.h"

int define_size;
char *memory;//minus * and add []
int memOK; //return 1 when the memory allocation was correct
int fileOK; //return 1 when the file was opened correctly
FILE *file; //File where the data will be saved
int writeOK; //return 1 when the writing process was correct
int releaseOK; //return 1 if data was freed and file was closed

//UI8, UI32, UI64 based on the file I want to write

int main(){

	printf("Enter the size of the memory in bytes: ");
    scanf("%d", &define_size);
	memOK = memory_alloc(define_size, &memory);//works without &

	if (memOK == 1){
			printf("Memory %p allocated correctly.\n",memory);
	}

	//File handler
	fileOK = file_handler(&file);
	if (fileOK == 1){
			printf("File created succesfully.\n");
	}

	writeOK = write_data(define_size, memory, &file);
	if (writeOK == 1){
			printf("Data was written correctly.\n");
	}

	releaseOK = close_file(&file, memory);
	//if (releaseOK == 1){
	//		printf("Data was cleared and File was closed.\n");
	//}

	return 0;
}
