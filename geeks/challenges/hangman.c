#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

struct GameState
{
    int id;
    char randomWord[50];
    char currentWordState[50];
    char guessedLetters[26];
    int lives;
};

void printHangman(int n)
{
    switch (n)
    {
        case 0:
            printf("  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n");
            break;
        case 1:
            printf("  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n");
            break;
        case 2:
            printf("  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n");
            break;
        case 3:
            printf("  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n");
            break;
        case 4:
            printf("  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n");
            break;
        case 5:
            printf("  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n");
            break;
        case 6:
            printf("  +---+\n      |\n      |\n      |\n      |\n      |\n=========\n");
            break;
        case 7:
            printf("  \n      |\n      |\n      |\n      |\n      |\n=========\n");
            break;
        case 8:
            printf("  \n\n\n\n\n\n=========\n");
            break;

        default:
            break;
    }
  
}
char* getWord(int n) //pass by reference instead
{
    FILE * fp;
    char *s;//chosen word
    fp = fopen("words.txt", "r");
    if (fp == NULL){
        printf("Word could not be found\n");
    }
    char buffer[50];
    int i = 0;
    while(i<=n){
        
        fscanf(fp, "%s",buffer);//reads from fp. upto each end of line. stores in buffer
        fgetc(fp);//move pointer onto next line
        i++;
    }
    int len = strlen(buffer) + 1;
    s = (char *)malloc(len);
    strcpy(s, buffer);
    fclose(fp);
    return s;
}

int getRandomNumber(int wordCount){
    //between 1-3000
    srand(time(NULL));
    int r = rand() % wordCount;
    return r;

}

char* createPlaceholder(int wordLength) { 
    int i;
    char * guess; // on stack
    guess = (char *)malloc(wordLength + 1);
    for (i=0; i<wordLength; i++) {
        guess[i] = '_';
    }
    guess[wordLength] = '\0';
    return guess;
}

void printPlaceholder(char* placeholder){
    int length = strlen(placeholder);
    int i;
    for (i=0; i<length; i+=1){
        printf("%c ", placeholder[i]);
    }
    printf("\n");
}

char getInput()
{   
    
    char ch, c;
    printf("\nPlease enter a character: ");
    scanf("%c", &ch);
    c = getchar();
    if (ch== 'S' && c=='A'){
        printf("Your game has now been saved\n");
        while (c!= '\n')
        {
            c = getchar();
        }
        return '$';
    }
    if (!isalpha(ch))
    {
        printf("You have not entered a letter!\n");
        while (c!= '\n')
        {
            c = getchar();
        }
        return getInput();
    } else if (c != '\n')
    {
        printf("You have entered too many letters!\n");
        while (c!= '\n')
        {
            c = getchar();
        }
        return getInput();
    }
    while (c!= '\n')
    {
        c = getchar();
    }
    if (isupper(ch))
    {
        ch = tolower(ch);
    }
 
    return ch;
}

int checkLetter(char* randomWord, char* placeholder, char guessedLetter)
{
    int L = strlen(randomWord);
    int i;
    int ifFound = 0;
    for (i = 0; i<L; i++){
        if (randomWord[i] == guessedLetter)
        {
            placeholder[i] = guessedLetter;
            ifFound = 1;
        }
    }
    return ifFound;
    
}
void printLettersUsed(char lettersUsed[], int marker)
{
    printf("\nLetters used: ");
    for (int i = 0; i < marker; i++)
    {
        if (lettersUsed[i]  != 0){
            printf("%c, ", lettersUsed[i]);
        }
        
    }
    printf("%c\n", lettersUsed[marker]);
}

void saveState(char randomWord[50],char currentWordState[50], char guessedLetters[26], int lives){
    int id = 1;
    FILE *fp;
    struct GameState stored1;
    stored1.id = id;
    strcpy(stored1.randomWord, randomWord);
    strcpy(stored1.currentWordState, currentWordState);
    strcpy(stored1.guessedLetters, guessedLetters);
    stored1.lives = lives;
    fp = fopen("savefile.txt", "w+");
    fwrite(&stored1, sizeof(struct GameState), 1, fp);
    fclose(fp);
}

void single(char* randomWord, char* placeholder, int lives, char lettersUsed[]){
    int correctAnswer;

    char in;
    int lettersUsedMarker = 0;
    
    printf("You can type SAVE at any point to save\n");
    printf("You have %d lives remaining\n", lives);
    while(lives !=0){
        printLettersUsed(lettersUsed, lettersUsedMarker -1);
        char guessedLetter = getInput();
        if (guessedLetter == '$')
        {
            saveState(randomWord,placeholder, lettersUsed, lives);
            return;
        }
        int alreadyGuessed = 0;
        printf("character entered is %c\n", guessedLetter);
        
        for (int j = 0; j<26; j++) 
        {
            if (lettersUsed[j] == guessedLetter)
            {
                printf("You have already guessed the letter %c\n", guessedLetter);
                alreadyGuessed = 1;
                printPlaceholder(placeholder);
                break;
            }
        }
        if(!alreadyGuessed) {
            correctAnswer = checkLetter(randomWord, placeholder, guessedLetter);
            lettersUsed[lettersUsedMarker] = guessedLetter;
            lettersUsedMarker++;
            if (!correctAnswer)
            {
                lives--;
                printf("Your letter is incorrect: ");
                printPlaceholder(placeholder);
            }
            else{
                printf("Your letter was found: ");
                printPlaceholder(placeholder);
            }
            printHangman(lives);
            printf("You have %d lives remaining\n", lives);
            
        }
        if(!strcmp(randomWord, placeholder))
        {
            printf("You have won hangman!\n");
            printf("Your score was %lupts", lives * strlen(randomWord) * 1000);
            break;
        }
    }
    if (lives == 0)
    {
        printf("Sorry, you lose\n");
    }
}




int main(void){
    FILE *fp;
    struct GameState loadState;
    char option=0;
    while (option != 'Q'){
        printf("\nPlease enter a character relating to one of the following options:\n \nN - New Game\nL - Load saved game\nQ - Quit\n");
        scanf("%c", &option);
        getchar();
        if (option == 'Q'){
            break;
        }
        else if (option == 'L')
        {
            fp = fopen("savefile.txt", "r");

            fread(&loadState, sizeof(struct GameState), 1, fp); //each time called goes to start of next structure
            single(loadState.randomWord, loadState.currentWordState,loadState.lives, loadState.guessedLetters );
        }         
        else if(option == 'N') {
            int randomNumber = getRandomNumber(3000);
            printf("random number is %d\n",randomNumber);
            char * randomWord = getWord(randomNumber);
            printf("random word is %s\n", randomWord);
            int L = strlen(randomWord);
            printf("length of word %d\n", L);
            char * placeholder = createPlaceholder(L);
            int lives = 8;
            char lettersUsed[26] = { 0 };
            single(randomWord, placeholder, lives, lettersUsed);
        }
    }
    return 0;
    /*
        only score if they win
        letter count of the random word
        guessed letters
        lives left
        max score = all 8 lives left. guessed lettters = letter count of random word
    */
}

/*
    requirements:
    - what functions?
        -
        -
        -
    - 

    Load game - new game
    press g to make guess
    press l to see previous guesses
    press s to save game
    press q to quit
    if n:
    find random word from file 
        srand(unsigned int seed)
        int r = rand() % 3000;
    int getRandomNumber() //return 1-3000
    *char getWord(int randomnumber) //return malloc address
       
    if g:
    input letter:
    check if single letter
    check if used
    check if in word
    print current word with current spaces
    print hangman + lives remaining 


*/