/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256

// Put global environment variables here

// Define functions declared in myshell.h here

int main(int argc, char *argv[])
{
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    char command[BUFFER_LEN] = { 0 };
    char directory[BUFFER_LEN] = {"/home"};
    getcwd(directory, BUFFER_LEN);
    // Parse the commands provided using argc and argv
    printf("%s/myshell>",directory);
    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, stdin))
    {
    	char *dir;
    	memcpy(command, buffer, BUFFER_LEN);
        strtok_r(command, "\n ", &dir);
        strcpy(buffer, dir);
        strtok(buffer, "\n");

        //help command -- print out help file
        if (strcmp(command, "help") == 0){
        	hlp();
        }
        // cd command -- change the current directory
        else if (strcmp(command, "cd") == 0)
        {
        	memcpy(directory, change_dir(buffer, directory), BUFFER_LEN);
        }
        // quit command -- exit the shell
        else if (strcmp(command, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }
        // clear command -- Clear shell
        else if (strcmp(command, "clear") == 0){
        	int i;
        	//For eclipse ascii codes don't work
        	for(i = 0;i<10;i++)
        		printf("\n");
        }
        //pause command -- pause shell until enter key is pressed
        else if (strcmp(command, "pause") == 0){
        	wait();
        }
        //environ command -- list environmental variables
        else if (strcmp(command, "environ") == 0){
        	system("env");
        }
        //echo command -- repeat text is console
        else if (strcmp(command, "echo") == 0){
        	printf("%s\n",buffer);
        }
        //dir command -- read files from directory
        else if (strcmp(command, "dir") == 0){
        	memcpy(directory, read_dir(buffer, directory), BUFFER_LEN);
        }
        // Unsupported command
        else
        {
        	fputs("Unsupported command, use help to display the manual\n", stderr);
        }
        int i = 1333333;   // This number is equivalent to 100 ms
        //delay so fputs comes first
        while (i>0)
        {
        	i--;
        }
        printf("%s/myshell>",directory);
    }
    return EXIT_SUCCESS;
}
