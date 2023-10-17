#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define EQUATION   y = pow(x,2) - 4
#define Y_TARGET   0
#define EPSILON    0.0001

#define POP_SIZE     100
#define MAX_GEN    10000

#define MUTATION_STRENGTH  0.1
#define RND_INIT           4

void printheader(void);
float rnd(); // Random values 0.0 to 1.0
void initpop(float *pop, int size);
void offspring(float parent, float mutst, float *pop, int size);

int main(){
    float population[POP_SIZE];
    int   gen = 0;
    float best_ifit = FLT_MAX;  // worst possible
    float best;
    float x, y;
    float ifit;   // inverse fitness
    int i;
    printheader();
    srand(RND_INIT);
    initpop(population, POP_SIZE);
    while(gen < MAX_GEN && best_ifit >= Y_TARGET + EPSILON){

        for(i=0; i < POP_SIZE; i++){
            x = population[i];

            EQUATION;  // y = f(x)

            ifit = fabs(y - Y_TARGET);

            printf("x= %f  =>  y=  %+f,    ifit = %f\n", x, y, ifit);

            // Is there a better one?
            if( ifit < best_ifit ){
                best_ifit = ifit;
                best = x;
            }
        }
        x = best;
        EQUATION;  // y = f(x)

        printf("Generation %4d with best solution:  x= %f --> f(x)= %f\n\n",
                   gen++, best, y);

        offspring(best, MUTATION_STRENGTH, population, POP_SIZE);

    }
}

void printheader(){
    printf("\n\n");
    printf("###############\n");
    printf("## Evolution ##\n");
    printf("###############\n");
}

void initpop(float *pop, int size){
    for(int i = 0; i < size; i++){
        pop[i] = rnd();
    }
}

void offspring(float parent, float mutst, float *pop, int size){
    pop[0] = parent;
    for(int i = 1; i < size; i++){
        if(rand()%2 == 0){
            pop[i] = parent - rnd() * mutst;
        }
        else{
            pop[i] = parent + rnd() * mutst;
        }
    }
}

// Returns a random value between 0.0 and 1.0
float rnd(){
    return rand()/(float) RAND_MAX;
}


/*purpose of EQUATION is to generate a y value to determine what value for an 
offspring would make it successful - high fitness.

Purpose of the while loop is to loop through each new generation until it
gets to the 10 000th one

The for loop inside the while loop is to select the offspring in that generation
that has the best fitness - SELECTION process.

initpop() initialises all members in the population with a random value.

offspring() are all the solutions to the equation and the best offspring/solution
in the population is selected - keeping the best parent from previous generation.

void initpop(float *pop, int size){
    for(int i = 0; i < size; i++){
        pop[i] = rnd();
    }
}

void offspring(float parent, float mutst, float *pop, int size){
    pop[0] = parent;
    for(int i = 1; i < size; i++){
        pop[i] = parent + 0.1 * rnd();
    }
}

while(gen < MAX_GEN && ifit + EPSILON < y ){

    .
    .
    .
    if(ifit < best_ifit){
        
    }

}



*/