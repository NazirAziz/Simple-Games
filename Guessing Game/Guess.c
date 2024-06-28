#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void write(char *name, int score){
    FILE *ptr = fopen("Score.txt", "w");
    fprintf(ptr, "%s" ,name);
    fprintf(ptr, "%c", '\n');
    fprintf(ptr, "%d" ,score);

    fclose(ptr);
}
int read(){
    FILE *ptr = fopen("Score.txt", "r");
    char name[15];
    int HighScore;
    fgets(name, 15, ptr);
    fscanf(ptr, "%d", &HighScore);
    int length = strlen (name);
    if (name[length - 1] == '\n')
        name[length - 1] = '\0';
    printf("%s %d\n", name, HighScore);
    fclose(ptr);
    return HighScore;
}

int main(){
    
    printf("The highest score: ");
    int Highscore = read();
    printf("Press Enter to start\n");
    getchar();
    printf("--------------------------------------\n");
    printf("You have 3 tries. Guess! (1 - 10)\n");  

    srand(time(NULL));
    int ComputerChoice = rand() % 10 + 1;
    int GameChances = 3;
    int score = 0;
    while (GameChances > 0){
        GameChances--;
        int PlayerChoice;
        scanf("%d", &PlayerChoice);
        if (PlayerChoice > ComputerChoice) printf("Too high\n");
        else if (PlayerChoice < ComputerChoice) printf ("Too low\n");
        else{
            switch(GameChances){
                case 2: score += 5;
                break;
                case 1: score += 3;
                break;
                case 0: score += 2;
            }
            GameChances = 3;
            printf("Cool. Your score is %d\n",score);
            printf("You have 3 tries. Guess! (1 - 10)\n");  
            ComputerChoice = rand() % 10 + 1;
        }
    }
    printf("You lost. Score: %d\n", score);
    if (score > Highscore){
        printf("Great! You got the highest score. What's your name?\n");
        char name[15];
        scanf("%s",name);
        write(name, score);
    }
    getchar();
    getchar();

}
