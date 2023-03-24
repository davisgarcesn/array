//Functions
//Description of the functions
//1. memmory_alloc: allocate memory based on the size entered by the user
#include "resource.h"


    int memory_alloc(int size, char *mem){

		// Allocate memory using malloc function
		mem = (char *) malloc(size);

		if(mem == NULL) {
			printf("Error: Out of memory\n");
			exit(1);
		}
		return 1;
	}

	int file_handler(FILE *fp){
		// Open a file to write data
		fp = fopen("data.txt", "w");

		if(fp == NULL) {
			printf("Error: Cannot create file\n");
			exit(1);
		}
		return 1;
	}

	int write_data(int size, char *mem, FILE *fp){
		int i;
		int bytes_written = 0; // Write data to the memory
		char buffer[size]; //Buffer to write data to the memory
		while(bytes_written < size) {
			printf("Enter data to be written (max %d bytes): ", size - bytes_written);
			scanf("%s", buffer);

			// Check if buffer size exceeds the remaining memory size
			if(bytes_written + sizeof(buffer) > size) {
				printf("Error: Exceeds remaining memory size\n");
				break;
			}

			// Write data to the memory
			for(int i = 0; i < sizeof(buffer); i++) {
				mem[bytes_written + i] = buffer[i];
			}

			// Write data to the file
			fprintf(fp, "%s", buffer);

			bytes_written += sizeof(buffer);
		}
		return 1;
	}

	int close_file(FILE *fp, char *mem){
		fclose(fp);
		free(mem);
		return 1;
	}
