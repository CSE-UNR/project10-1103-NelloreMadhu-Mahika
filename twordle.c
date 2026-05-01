//Author: Mahika Nellore Madhu
//Date: 04/25/2026
//Purpose: CS135 Project 10

#include <stdio.h>

#define rows 12
#define cols 6

void storeWord(FILE *mystery, char wordle[]);
void getGuess(char guess[]);
int validGuess(char guess[]);
void checkGuess(char wordle[], char guess[], char feedback[]);
int compareWords(char wordle[], char guess[]);
void printBoard(char board[][cols], int rowsUsed);

int main() {
	FILE *mystery;
	char wordle[cols];
	char board[rows][cols];
	char guess[cols];

	mystery = fopen("mystery.txt", "r");

	if (mystery == NULL) {
		printf("Can't open file\n");
			return 0;
	}

	storeWord(mystery, wordle);
	fclose(mystery);

	int attempt = 0;

	while (attempt < 6) {
		printf("\nGuess %d:\n", attempt + 1);
	
	getGuess(guess);
	validGuess(guess);
	int i;
	for(i = 0; i < 5; i++){
		board[attempt * 2][i] = guess[i];
	}
	board[attempt * 2][5] = '\0';

	if(compareWords(wordle, guess)) {
		printf("You guessed the word!\n");
		return 0;
	}

	checkGuess(wordle, board[attempt * 2], board[attempt * 2 + 1]);

	printBoard(board, (attempt * 2) + 2);

	attempt++;
	}

	printf("\nOut of guesses! The word was: %s\n", wordle);

	return 0;
}

// FUNCTION 1
void storeWord(FILE *mystery, char wordle[]){
	fgets(wordle, cols, mystery);
	wordle[5] = '\0';
}

// FUNCTION 2
void getGuess(char guess[]){
	printf("Enter a 5-letter word: ");
	scanf("%5s", guess);
}

// FUNCTION 3 (NEW)
int validGuess(char guess[]){
	int valid;
	int i;
	do{
		valid = 0;
		
		for(i = 0; i < 5; i++){
			if(guess[i] < 'a' || guess[i] > 'z'){
				valid = 1;
			}
		}
		if(guess[5] != '\0'){
			valid = 1;
		}
		
		if(valid == 1){
			printf("Invalid guess. Try again: ");
			scanf("%5s", guess);
		}
	}while(valid == 1);
	
	return 1;
}

// FUNCTION 4
void checkGuess(char wordle[], char guess[], char feedback[]){
	int i, j;
	int found;

	for (i = 0; i < 5; i++){
		found = 0;
		
		for(j = 0; j < 5; j++){
			if(guess[i] == wordle[j]){
				found = 1;
			}
		}
		
		if(found == 1){
			feedback[i] = '^';
		}
		else{
			feedback[i] = ' ';
		}
	}
	feedback[5] = '\0';
}

// FUNCTION 5
int compareWords(char wordle[], char guess[]){
	int i;

	for (i = 0; i < 5; i++){
		if (wordle[i] != guess[i]){
			return 0;
        	}
	}
	return 1;
}

// FUNCTION 6
void printBoard(char board[][cols], int rowsUsed){
	int i = 0;
	for (; i < rowsUsed; i++){
		printf("%s\n", board[i]);
	}
}


