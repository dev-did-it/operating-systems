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

// Define your utility functions here, these will most likely be functions that you call
// in your myshell.c source file
#define BUFFER_LEN 256

char * change_dir(char * buffer_p, char * direct_p){
	char buffer[BUFFER_LEN];
	char directory[BUFFER_LEN];
	memcpy(buffer, buffer_p, BUFFER_LEN);
	if(buffer[0]!=NULL){
		//fputs(buffer, stderr);
		memcpy(directory, buffer, BUFFER_LEN);
	}
	else{
		memcpy(directory, direct_p, BUFFER_LEN);
	}
	return directory;
}
void wait(void){
	char s[2];
	printf("Paused...Press enter to continue");
	while(strcmp(s, "\n")!= 0){
		fgets(s, 2, stdin);
	}
	printf("Continued\n");
}
char * read_dir(char * buffer_p, char * direct_p){
	char buffer[BUFFER_LEN];
	char directory[BUFFER_LEN];
	memcpy(buffer, buffer_p, BUFFER_LEN);
	if(buffer[0]==NULL){
		fputs("Please enter directory after the dir command\n", stderr);
		memcpy(directory, direct_p, BUFFER_LEN);
	}
	else{
		memcpy(directory, buffer, BUFFER_LEN);
		DIR *currentdir = opendir(buffer);
		struct dirent *entry = NULL;
		while((entry = readdir(currentdir)))
		{
			printf("%s\n", entry->d_name);
		}
		closedir(currentdir);
		return directory;
	}
}
void hlp(void){
	char current_char;
	FILE *file;
	file = fopen("readme.txt", "r");
	if (file) {
		while ((current_char = getc(file)) != EOF)
			putchar(current_char);
		fclose(file);
		printf("\n");
	}
}
