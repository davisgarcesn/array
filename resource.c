//Functions
//Description of the functions
//1. memmory_alloc: allocate memory based on the size entered by the user
//2. file_handler: create/open a file called "data.txt"
//3. write_data: get the data from the user, saves data into the memory and check the size availability. If available, writes the data into the file.
//4. close_file: release memory and close the file.
#include "resource.h"


    int memory_alloc(int size, char **mem){

		// Allocate memory using malloc function
		*mem = (char *) malloc(size);

		if(*mem == NULL) {
			printf("Error: Out of memory\n");
			exit(1);
		}
		return 1;
	}

	int file_handler(FILE **fp){
		// Open a file to write data
		*fp = fopen("data.txt", "w");

		if(fp == NULL) {
			printf("Error: Cannot create file\n");
			exit(1);
		}
		return 1;
	}

	int write_data(int size, char *mem, FILE **fp){
		int bytes_written = 0; // Write data to the memory
		char buffer[size]; //Buffer to write data to the memory
		memset(buffer, 0, size);
		while(bytes_written < size) {
			printf("Enter data to be written (max %d bytes): ", size - bytes_written);
			scanf("%s", buffer);

			// Check if buffer size exceeds the remaining memory size
			if(bytes_written + strlen(buffer) > size) {
				printf("Error: Exceeds remaining memory size\n");
				break;
			}

			// Write data to the memory
			for(int i = 0; i < strlen(buffer); i++) {
				mem[bytes_written + i] = buffer[i];
			}

			// Write data to the file
			fprintf(*fp, "%s", buffer);

			bytes_written += strlen(buffer);
		}

		return 1;
	}

	int close_file(FILE **fp, char *mem){
		if(fclose(*fp) != 0)
        {
            fprintf(stderr, "Error closing file: %s", strerror(errno));
        }
        else
            printf("File closed correctly.\n");

        free(mem);
		//if (free(mem) != 0)
        //{
        //    printf("Error releasing memory.\n");
        //}
        //else
            printf("Memory %p released correctly.\n",mem);

		return 1;
	}
