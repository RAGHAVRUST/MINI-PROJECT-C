#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_WRONG 7

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[36m"
#define RESET   "\033[0m"

typedef struct {
    char word[20];
    int used[26];
    int wrong;
}Game;

const char *WORDS[] = { 
    "computer", 
    "programming", 
    "algorithm", 
    "function", 
    "variable", 
    "pointer",
    "array","loop","condition","recursion",
    "stack","queue","tree","graph","hashmap",
    "sorting","searching","dynamic","memory","compile"   
};
 const int WORD_COUNT = sizeof(WORDS) / sizeof(WORDS[0]);

 void initGame(Game *g) {
    strcpy (g->word, WORDS[rand() % WORD_COUNT]);
    for (int i = 0; i < 26; i++) 
        g->used[i] = 0;
    
    g->wrong = 0;
}
int inWord(const Game *g, char letter) {
    for (int i = 0; i<strlen(g->word); i++) 
        if (g->word[i] == letter) 
            return 1;
            return 0;
}
 int isWon(const Game *g) {
    for (int i =0; i<(int)strlen(g->word); i++) 
        if (!g->used[g->word[i] - 'a']) 
            return 0;
            return 1;
 }
  
 void printWord(const Game *g) {
    for (int i = 0; i < (int)strlen(g->word); i++) {
       char c=g->word[i];
        if (g->used[c - 'a']) 
            printf(GREEN "%c " RESET, c);
        else 
            printf("_ ");
    }
    printf("\n");
}

void printWrongLetter(const Game *g) {
    printf( "Wrong letters: " );
    for (int i = 0; i < 26; i++) {
        char letter ='a' + i;
        if (g->used[i] && !inWord(g, letter))
            printf(RED "%c " RESET, letter);
    }
    printf("\n");
}

void printScreen(const Game *g){
    printf("\n");
    printWord(g);
    printf("\n");
    printWrongLetter(g);
    printf("Lives left; %d\n\n", MAX_WRONG -g-> wrong);
}
    void playGame(Game *g) {
        char input[64];

        printf(BLUE "=== WORD GUESSING GAME ===" RESET "\n");
        printf("Guess the word one letter at a time. \n");
        printf("You can make up to %d wrong guesses. \n", MAX_WRONG);     

        while(g->wrong < MAX_WRONG && !isWon(g)) {
            printfScreen(g);
            printf("Enter a letter: ");

            if (fgets(input, sizeof(input), stdin) == NULL) 
                return;
            
                char letter = tolower ((unsigned  char)input[0]);

                if(!isaplha((unsigned char)letter)) {
                    printf("Please enter a letter .\n");
                continue;
                }

                if (g->used[letter - 'a']) {
                    printf("You already guessed that letter. Try again.\n");
                    continue;
                }
                
                g->used[letter - 'a'] = 1;

                if(inWorld(g, letter)) {
                    printf(GREEN "Good guess!\n" RESET);
                } else {
                    printf(RED "Wrong guess!\n" RESET);
                    g->wrong++;

                }
            }

            printScreen(g);
            if (isWon(g)) 
                printf(GREEN "Congratulations! You guessed the word: %s\n" RESET, g->word);
            else 
                printf(RED "Game over! The word was: %s\n" RESET, g->word);
            }
            int main (void){
                char again [16];
                srand((unsigned int)time(NULL));
                do{
                    Game game;
                    initGame(&game);
                    playGame(&game);
                    printf("Play again? (y/n): ");
                    if (fgets(again, sizeof(again), stdin) == NULL) 
                        break;
                    }while (tolower((unsigned char)again[0]) == 'y');
                    printf("Thanks for playing!\n");
                    return 0;

                }
            
            
        
    


        
    


    
    
        