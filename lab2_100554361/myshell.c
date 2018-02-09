/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
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
    char arg[BUFFER_LEN] = { 0 };

    // Parse the commands provided using argc and argv

    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Perform string tokenization to get the command and argument
            char *dir;
            memcpy(command, buffer, BUFFER_LEN);
            strtok_r(command, "\n", &dir);
            strcpy(buffer,dir);
            strtok(buffer, "\n");
        // Check the command and execute the operations for each command
        // cd command -- change the current directory
        if (strcmp(command, "cd") == 0)
        {
            // your code here
        }

        //clear command
        else if(strcmp(command, "clr") == 0)
        {
    
        }
        //dir command - display current directory
        else if(strcmp(command, "dir") == 0)
        {
    
        }
        //environ command - list all environmental strings
        else if(strcmp(command, "environ") == 0)
        {
    
        }
        //echo command - displays comment
        else if(strcmp(command, "echo") == 0)
        {
    
        }
        //help command - 
        else if(strcmp(command, "help") == 0)
        {
            int c;
            FILE *file;
            file = fopen("README.txt", "r");
            if (file) {
                while ((c = getc(file)) != EOF)
                    putchar(c);
            
            fclose(file);
            }
        }
        //
        else if(strcmp(command, "pause") == 0)
        {
    
        }
        // quit command -- exit the shell
        else if (strcmp(command, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }

        // Unsupported command
        else
        {
            fputs("Unsupported command, use help to display the manual\n", stderr);
        }
    }
    return EXIT_SUCCESS;
}
