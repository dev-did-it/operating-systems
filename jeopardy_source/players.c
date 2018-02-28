#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.h"


int counter;

// Returns true if the player name matches one of the existing players
bool player_exists(player *players, int num_players, char *name)
{
	for (counter = 0; counter < 4; counter++){
		if (strcmp(name, players[counter].name) == 0){
			return true;
		}
	}
    return false;
}

// Go through the list of players and update the score for the 
// player given their name
void update_score(player *players, int num_players, char *name, int score, bool right_wrong)
{
	//printf("%d", right_wrong);
	if (right_wrong){
		for (counter = 0; counter < num_players; counter++){
			if (strcmp(name, players[counter].name) == 0){
				players[counter].score = players[counter].score + score;
				printf("\n%s: %d\n", players[counter].name, players[counter].score);
			}
		}
	} else if (!right_wrong) {
		for (counter = 0; counter < num_players; counter++){
			if (strcmp(name, players[counter].name) == 0){
				players[counter].score = players[counter].score - score;
				printf("\n%s: %d\n", players[counter].name, players[counter].score);
			}
		}
	}
}
