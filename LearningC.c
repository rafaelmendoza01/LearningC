#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 3.14159
#define FREQ 10
#define TW 100
#define TickWidth 10
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"


void Plotval(float Between01, int TerminalWidth){
	int WIDTH = Between01 * TerminalWidth;
	
	
	printf(RED "%*c" RESET, WIDTH, '*');
}


int main() {
  unsigned long x = 0;
  float y;
  
  while(x <= 1500){

	
	y = (sin(FREQ *x * PI / 180.0)+1.0)/2.0;

	//printf("x = %d    | y = %0.3f", x, y);
	
	//Let there be 20 characters between = & |
	char NumAsString[20];
	sprintf(NumAsString, "%d", x);
	
	
	int temporary;
	for(int i = 0; i < strlen(NumAsString); i++){
		if(NumAsString[i] != ' '){
			temporary = i + 1;
		}
	}

	printf("x = %d", x);
	printf("%*c | y = %0.4f", 5 - temporary, ' ',y);
	int ToPrintTick = x%10;
	if(ToPrintTick == 0){
		printf("---");
	} 
	else{
		printf("   ");
	}
	
	Plotval(y, TW);
	printf("\n");
	x++;
	  
	}
	printf(RED "red\n"     RESET);
	    
		
  return 0;
}

