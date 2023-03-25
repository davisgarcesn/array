--------------------Memory Allocation Program-----------------------------------
This program is designed to allocate memory dynamically based on user input and write data to the allocated memory. The program also writes the data to a file named data.txt in the current working directory.

/*Getting Started*/
1. Download the zip file or copy all the files, except the zip file, into a folder.
2. Open the project file using Code::Block IDE Multi Complier, or create a new project and add the files: " main.c", "resource.h" and "resource.c".
3. Compile the program.
4. Run the program using ./File_handler

/*NOTE*/
The file "data.txt" will be created in the same folder where the project is located.

Usage
1. The program will prompt the user to enter the size of the memory in bytes.
2. Enter the desired size of the memory and press Enter.
3. The program will allocate memory using the malloc() function and create a buffer to write data to the memory.
4. The program will prompt the user to enter data to be written to the memory.
5. Enter the desired data and press Enter. The program will check if the buffer size exceeds the remaining memory size.
6. If the buffer size exceeds the remaining memory size, the program will display an error message and terminate.
7. If the buffer size is within the remaining memory size, the program will write the data to both the allocated memory and the file.
8. The program will continue to prompt the user for data until the allocated memory is full or the user enters invalid data.
9. Once the allocated memory is full or the user enters invalid data, the program will free the allocated memory and terminate.