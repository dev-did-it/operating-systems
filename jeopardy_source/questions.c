/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2018, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

int counter;
int question_counter = 0;

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array

	//Q1
	strcpy(questions[0].category, "programming");
	strcpy(questions[0].question, "What is the output of this line? string name = Joe; printf(\"%s\", age);");
	strcpy(questions[0].answer, "what is Joe");
	questions[0].value = 100;
	questions[0].answered = false;

	//Q2
	strcpy(questions[1].category, "programming");
	strcpy(questions[1].question, "C is not this type of programming language.");
	strcpy(questions[1].answer, "what is object oriented");
	questions[1].value = 200;
	questions[1].answered = false;

	//Q3
	strcpy(questions[2].category, "programming");
	strcpy(questions[2].question, "What is the IDE used to develop Android apps?");
	strcpy(questions[2].answer, "what is Android Studio");
	questions[2].value = 300;
	questions[2].answered = false;

	//Q4
	strcpy(questions[3].category, "programming");
	strcpy(questions[3].question, "What language is this game written in?");
	strcpy(questions[3].answer, "what is c");
	questions[3].value = 400;
	questions[3].answered = false;

	//Q5
	strcpy(questions[4].category, "algorithms");
	strcpy(questions[4].question, "What kind of algorithm is Bubble sort");
	strcpy(questions[4].answer, "what is sort algorithm");
	questions[4].value = 100;
	questions[4].answered = false;

	//Q6
	strcpy(questions[5].category, "algorithms");
	strcpy(questions[5].question, "Which searching algorithm splits the array in half to find the target?");
	strcpy(questions[5].answer, "what is binary search");
	questions[5].value = 200;
	questions[5].answered = false;

	//Q7
	strcpy(questions[6].category, "algorithms");
	strcpy(questions[6].question, "Is doubly linked list an algorithm?");
	strcpy(questions[6].answer, "what is no");
	questions[6].value = 300;
	questions[6].answered = false;

	//Q8
	strcpy(questions[7].category, "algorithms");
	strcpy(questions[7].question, "Does linear search involve a tree?");
	strcpy(questions[7].answer, "what is no");
	questions[7].value = 400;
	questions[7].answered = false;

	//Q9
	strcpy(questions[8].category, "databases");
	strcpy(questions[8].question, "What does SQL stand for?");
	strcpy(questions[8].answer, "what is structured query language");
	questions[8].value = 100;
	questions[8].answered = false;

	//Q10
	strcpy(questions[9].category, "databases");
	strcpy(questions[9].question, "What does NoSQL stand for?");
	strcpy(questions[9].answer, "what is not only SQL");
	questions[9].value = 200;
	questions[9].answered = false;

	//Q11
	strcpy(questions[10].category, "databases");
	strcpy(questions[10].question, "How is each record uniquely identified");
	strcpy(questions[10].answer, "what is primary key");
	questions[10].value = 300;
	questions[10].answered = false;

	//Q12
	strcpy(questions[11].category, "databases");
	strcpy(questions[11].question, "What key links tables together?");
	strcpy(questions[11].answer, "what is foreign key");
	questions[11].value = 400;
	questions[11].answered = false;

}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
	char category[MAX_LEN] = "category";
	int value = 0;
    // print categories and dollar values for each unanswered question in questions array
	for (counter = 0; counter < 12; counter++){
		if (!questions[counter].answered){
			printf("%s | $%d\n", questions[counter].category, questions[counter].value);
		}
	}

	printf("Choose a category and value, seperated by a space: ");
	scanf("%s %d", category, &value);
	display_question(category, value);
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
	char answer[MAX_LEN];
    
	//If player chose programming
	if (strcmp("programming", category) == 0){
		printf("You chose: Programming\n");
		for (counter = 0; counter < 4; counter++){
			if (value == questions[counter].value){
				if (!questions[counter].answered){
					printf(" $%d - %s\n", questions[counter].value, questions[counter].question);
					scanf(" %[^\n]%*c", &answer);
					valid_answer(category, value, answer);
				} else{
					printf("Question answered, please choose again\n");
					display_categories();
				}
			}
		}
        
	}//if player chose algorithms
	else if (strcmp("algorithms", category) == 0){
		printf("You chose: Algorithms\n");
		for (counter = 4; counter < 8; counter++){
			if (value == questions[counter].value){
				if (!questions[counter].answered){
					printf(" $%d - %s\n", questions[counter].value, questions[counter].question);
					scanf(" %[^\n]%*c", &answer);
					valid_answer(category, value, answer);
				} else{
					printf("Question answered, please choose again\n");
					display_categories();
				}
			}
		}
	} //else if player chose databases
	else if (strcmp("databases", category) == 0){
		printf("You chose: Databases\n");
		for (counter = 8; counter < 12; counter++){
			if (value == questions[counter].value){
				if (!questions[counter].answered){
					printf(" $%d - %s\n", questions[counter].value, questions[counter].question);
					scanf(" %[^\n]%*c", &answer);
					valid_answer(category, value, answer);
				} else{
					printf("Question answered, please choose again\n");
					display_categories();
				}
			}
		}
	}//else if player entered a category that does not exist
	else {
		printf("Category does not exist, please choose again\n");
		display_categories();
	}
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
	question_counter++;
	//printf("%d", question_counter);
	//If player chose programming
	if (strcmp("programming", category) == 0){
		for (counter = 0; counter < 4; counter++){
			if (value == questions[counter].value){
				if (strcmp(answer, questions[counter].answer) == 0){
					printf("\nCorrect");
					questions[counter].answered = true;
					get_value(value);
					valid(true);
					return true;
				} else {
					printf ("\nIncorrect: correct answer is %s", questions[counter].answer);
					get_value(value);
					questions[counter].answered = true;
					valid(false);
					return false;
				}
			}
		}
	}//if player chose algorithms
	else if (strcmp("algorithms", category) == 0){
		printf("You chose: Algorithms");
        
		for (counter = 4; counter < 8; counter++){
			if (value == questions[counter].value){
				if (strcmp(answer, questions[counter].answer) == 0){
					printf("\nCorrect");
					questions[counter].answered = true;
					get_value(value);
					valid(true);
					return true;
				} else {
					printf ("\nIncorrect: correct answer is %s", questions[counter].answer);
					get_value(value);
					questions[counter].answered = true;
					valid(false);
					return false;
				}
			}
		}
	}//if player chose databases
	else if (strcmp("databases", category) == 0){
		printf("You chose: Databases");
		for (counter = 8; counter < 12; counter++){
			if (value == questions[counter].value){
				if (strcmp(answer, questions[counter].answer) == 0){
					printf("\nCorrect");
					questions[counter].answered = true;
					get_value(value);
					valid(true);
					return true;
				} else {
					printf ("\nIncorrect: correct answer is %s", questions[counter].answer);
					questions[counter].answered = true;
					get_value(value);
					valid(false);
					return false;
				}
			}
		}
	}
    return false;
}
