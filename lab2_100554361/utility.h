/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2018, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#ifndef UTILITY_H_
#define UTILITY_H_

// Include your relevant functions declarations here they must start with the 
// extern keyword such as in the following example:
// extern void display_help(void);
extern char * change_dir(char * buffer_p, char * direct_p);
extern void wait(void);
extern char * read_dir(char * buffer_p, char * direct_p);
extern void hlp(void);

#endif /* UTILITY_H_ */
