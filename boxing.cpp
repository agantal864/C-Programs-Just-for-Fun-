#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int champ = 0;
int ai = 1;
int champ_hp = 100;
int ai_hp = 100;
unsigned int impact;

	int action,  punch_player = 0, defend_player = 3, punch_ai = 0, defend_ai = 3;
    int lower = 0, upper = 1, count = 1;

int random(int lower, int upper, int count) 
{ 
    int i; 
    for (i = 0; i < count; i++) { 
        int num = (rand() % 
           (upper - lower + 1)) + lower; 
        return num;
    } 
} 

void player_turn(int *punch, int *defend, int *punch_enemy, int *defend_enemy);
void ai_turn(int *punch, int *defend, int *punch_enemy, int *defend_enemy);

int main() {

    srand(time(0)); 
    
    
    
    int turn = random(lower, upper, count); 
    if (turn == 0) {
    	player_turn(&punch_player, &defend_player, &punch_ai, &defend_ai);
	} else if (turn == 1) {
		ai_turn(&punch_ai, &defend_ai, &punch_player, &defend_player);
	}
    	
  
}


void player_turn(int *punch, int *defend, int *punch_enemy, int *defend_enemy) {
	printf("\nPlayer's Turn\n'");
	int action;
	printf("\nEnter choice: [1]Punch or [2]Defend: ");
	scanf("%d", &action);
	if (action == 1) {
		printf("\nPLAYER ACTION: PUNCH\n");
		if (*punch_enemy != 0) {
				impact = *punch_enemy;
				if (impact < 0) impact = 0;
				printf("\nImpact of players punch is %d\n", impact);
				champ_hp = champ_hp - impact;
				printf("\nPlayer health: %d\n", champ_hp);
				printf("\nAi health: %d\n", ai_hp);
				*punch_enemy = 0;
				impact= 0;
			}
		
		*punch = random(1,5,1);
		printf("\nYou punched with a damage of %d\n", *punch);
		ai_turn(&punch_ai, &defend_ai, &punch_player, &defend_player);
	} else {
		printf("\nPLAYER ACTION: DEFEND\n");
		*defend = 3;
		printf("\nDefend: %d\n", *defend);
		if (*punch_enemy != 0) {
				impact = *punch_enemy - *defend;
				if (impact < 0) impact = 0;
				printf("\nImpact of players punch is %d\n", impact);
				champ_hp = champ_hp - impact;
				printf("\nPlayer health: %d\n", champ_hp);
				printf("\nAi health: %d\n", ai_hp);
				*punch_enemy = 0;
				impact= 0;
		}
		ai_turn(&punch_ai, &defend_ai, &punch_player, &defend_player);
	}
}

void ai_turn(int *punch, int *defend, int *punch_enemy, int *defend_enemy) {
	printf("\nAI's Turn\n'"); 
	int action;
	action = random(1,2,1);
	if (action == 1) {
			printf("\nAI ACTION: PUNCH\n");
			if (*punch_enemy != 0) {
				impact = *punch_enemy;
				if (impact < 0) impact = 0;
				printf("\nImpact of players punch is %d\n", impact);
				ai_hp = ai_hp - impact;
				printf("\nAi health: %d\n", ai_hp);
				printf("\nPlayer health: %d\n", champ_hp);
				*punch_enemy = 0;
				impact= 0;
			}
		*punch = random(1,5,1);
		printf("\nThe ai punched with a damage of %d\n", *punch);
		player_turn(&punch_player, &defend_player, &punch_ai, &defend_ai);
		
	} else {
		printf("\nAI ACTION: DEFEND\n");
		*defend = 3;
		printf("\nDefend: %d\n", *defend);
		if (*punch_enemy != 0) {
				impact = *punch_enemy - *defend;
				if (impact < 0) impact = 0;
				printf("\nImpact of players punch is %d\n", impact);
				ai_hp = ai_hp - impact;
				printf("\nAi health: %d\n", ai_hp);
				printf("\nPlayer health: %d\n", champ_hp);
				*punch_enemy = 0;
				impact= 0;
		}
		player_turn(&punch_player, &defend_player, &punch_ai, &defend_ai);
	}
}
