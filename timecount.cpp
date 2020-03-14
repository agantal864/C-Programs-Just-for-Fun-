#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds);

int main() {
	int i;
	while (1) {
		for (i =0; i <= 60; i++) {
		delay(1.5);
		system("cls");
		printf("%d", i);
		if (i == 60) exit(1);
		}
	}
	
}

void delay(int number_of_seconds) { 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
} 
