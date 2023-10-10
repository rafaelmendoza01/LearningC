#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 3.14159
#define TW 100

void myFunction(){
	printf("myFunction working ^^\n");
	unsigned char MyNumber = 'a';
	printf("%d", MyNumber);
	printf("%c",MyNumber);
	
	int number = 42;
    int width = 6; 
    printf("Only this number %*d\n", width, number);
}

void Plotval(float Between01, int TerminalWidth){
	int WIDTH = Between01 * TerminalWidth;
	printf("%*c", WIDTH, '*');
}

int main() {
  unsigned long x = 0;
  float y;
  
  while(x >= 0){

	y = (sin(x * PI / 180)+2)/2;

	printf("x = %d    | y = %0.3f", x, y);
	
	
	Plotval(y, TW);
	printf("\n");
	x++;
	  
	}
	    
		
  return 0;
}

