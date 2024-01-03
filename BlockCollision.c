#include <stdio.h>    

struct Block{
    float mass;
    float speed;

}

int main(){    
    struct Block B1;
    struct Block B2;
    B1.mass = 1;
    B1.speed = 0;

    B2.mass = 1;
    B2.speed = -1;
    int collisions = 0;

    while(B2.speed != 0 && B1.speed != 0){
        float u1 = B1.speed;
        float m1 = B1.mass;

        float u2 = B2.speed;
        float m2 = B2.mass;

        B1.speed = ((m1 -m2)*u1 + 2*m2*u2)/(m1 + m2);
        B2.speed = ((2*m1*u1) + u2*(m2 - m1))/(m1 + m2);
        collisions++;

    }

    return 0;   
}  