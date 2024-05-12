#include <stdio.h>    

struct Block{
    int mass;
    int speed;
};

int main(){    
    struct Block B1;
    struct Block B2;
    B1.mass = 1;
    B1.speed = 0;

    B2.mass = 1;
    B2.speed = -1;
    int collisions = 0;
    int u1 = B1.speed;
    int m1 = B1.mass;

    int u2 = B2.speed;
    int m2 = B2.mass;

    while(B2.speed != u2 || B1.speed != u1){
        u1 = B1.speed;
        u2 = B2.speed;

        B1.speed = ((m1 -m2)*u1 + 2*m2*u2)/(m1 + m2);
        B2.speed = ((2*m1*u1) + u2*(m2 - m1))/(m1 + m2);
        collisions++;
        printf("%d", collisions);

    }
    printf("%d", collisions);

    return 0;   
}  