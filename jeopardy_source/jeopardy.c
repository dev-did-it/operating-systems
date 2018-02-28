/*
 * Tutorial 4 Jeopardy Project 
 * SOFE 3950U Operating Systems
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here
player players[4];
int value;
int question_counter1 = 0;
int counter = 0;
bool valid1;

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
	int counter;
	char name[MAX_LEN];

	printf("Welcome To Jeopardy!\n");

	printf("\nPlease enter the name of each player, seperated by a space... ");
    //Save all player names
	scanf("%s %s %s %s", players[0].name, players[1].name, players[2].name, players[3].name);
    
	//Set all scores to 0
	for (counter = 0; counter < 4; counter++){
			players[counter].score = 0;
	}
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    // initialize each of the players in the array

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
    	//get player's name
    	printf("Enter current player name...");
    	scanf("%s", name);
        
        //Check if player exists
    	if (player_exists(players, NUM_PLAYERS, name)){
    	    	display_categories();
    	    	question_counter1++;

    	    	if (valid1) {
    	    		update_score(players, 4, name, value, true);
    	    	}
                else {
    	    		update_score(players, 4, name, value, false);
    	    	}
    	}

        //Keep track of question counter
    	if (question_counter1 == 12) {
    		int scores[4];
    		for (counter = 0; counter < 4; counter++) {
    			scores[counter] = players[counter].score;
    		}

    		int i, j, a;
    		for (i = 0; i < 4; ++i) {
    			for (j = i + 1; j < 4; ++j) {
    				a = scores[i];
    				scores[i] = scores[j];
    				scores[j] = a;
    			}
    		}

    		for (i = 3; i >= 0; i--){
    			for (j = 0; j < 4; j++){
    				if (players[j].score == scores[i]) {
    					printf ("%s: %d\n", players[j].name,scores[i]);
    				}
    			}
    		}
    		break;
    	}
    }
    return EXIT_SUCCESS;
}

void get_value (int value1){
	value = value1;
}

void valid (bool valid){
	valid1 = valid;
}

//Sort player scores
void sort(void){
	int scores[4];
	for (counter = 0; counter < 4; counter++) {
		scores[counter] = players[counter].score;
	}

	int i, j, a;
	for (i = 0; i < 4; ++i) {
		for (j = i + 1; j < 4; ++j) {
			a = scores[i];
			scores[i] = scores[j];
			scores[j] = a;
		}
	}

    //Print out final sorted result
	printf("FINAL SCORES");

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (players[j].score == scores[i]){
				printf ("%s: %d\n", players[j].name,scores[i]);
			}
		}
	}
}
