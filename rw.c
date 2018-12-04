#include <time.h>
#include <stdio.h>
#include <stdlib.h> 


int main(void){

    time_t t;
    char map[10][10], toWrite;
    int i, j, random, seed, walkUp, walkDown, walkLeft, walkRight;
    
    //[p][q] point to coordinates of the walk
    int p = 0;
    int q = 0;

    //sets seed
    seed = (int) time(NULL); 
    //initializes random seed
    srand(seed);            

    //fills the 10 x 10 map with dots
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            map[i][j] = '.';
        }
    }


    //initializes the walk with character A and currentPosition with 0.
    toWrite = 'A';
    map[p][q] = toWrite;
    toWrite++;
    while(toWrite <= 90){

        //Reset the values of blocked coordinates;
        walkUp = 1;
        walkDown = 1;
        walkLeft = 1;
        walkRight = 1;
        if (isalpha(map[p-1][q]) || (p-1) < 0){
            walkUp = 0;
        }if (isalpha(map[p+1][q]) || (p+1) > 9){
            walkDown = 0;
        }if (isalpha(map[p][q-1]) || (q-1) < 0){
            walkLeft = 0;
        }if (isalpha(map[p][q+1]) || (q+1) > 9){
            walkRight = 0;
        }

        //if all roads are blocked, program is terminated
        if (walkUp == 0 && walkDown == 0 && walkLeft == 0 && walkRight == 0){
            return 0;
        }

        //generates a random number between 0-3, inclusive
        //number 0 moves upwards
        //number 1 moves downwards
        //number is 2 moves towards left
        //number 3 moves towards right
        random = rand() % 4;
        if (walkUp == 1 && random == 0){
            p--;
            map[p][q] = toWrite;
            toWrite++;
        }else if (walkDown == 1 && random == 1){
            p++;
            map[p][q] = toWrite;
            toWrite++;  
        }else if (walkLeft == 1 && random == 2){
            q--;
            map[p][q] = toWrite;
            toWrite++;    
        }else if (walkRight == 1 && random == 3){
            q++;
            map[p][q] = toWrite;
            toWrite++;   
        }
    }
    
    //prints the created array matrix containing the walk
    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            printf("%c ", map[i][j]);
        }
    printf("\n");
    }
    
    return 0;
}
