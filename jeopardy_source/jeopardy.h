#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#define MAX_LEN 256

player players[4];

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
extern void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
extern void show_results(player *players, int num_players);

extern void get_value(int value1);

extern void valid (bool valid);

extern void sort (void);

#endif /* JEOPARDY_H_ */
