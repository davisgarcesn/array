//Main Document
#include "resource.h"
#include "resource.c"

int define_size;
char memory[];
int memOK; //return 1 when the memory allocation was correct
int fileOK; //return 1 when the file was opened correctly
FILE *file; //File where the data will be saved
int writeOK; //return 1 when the writing process was correct
int releaseOK; //return 1 if data was freed and file was closed

//UI8, UI32, UI64 based on the file I want to write

int main(){

	printf("Enter the size of the memory in bytes: ");
    scanf("%d", &define_size);
	memOK = memory_alloc(define_size, memory);

	if (memOK == 1){
			printf("Memory allocated correctly.\n");
	}

	//File handler
	fileOK = file_handler(file);
	if (fileOK == 1){
			printf("File created succesfully.\n");
	}

	writeOK = write_data(define_size, memory, file);
	if (writeOK == 1){
			printf("Data was written correctly.\n");
	}

	releaseOK = close_file(file, memory);
	if (releaseOK == 1){
			printf("Data was cleared and File was closed.\n");
	}

	return 0;
}
