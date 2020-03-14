#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	char ch;
	NODE *next;
}NODE;

NODE *create_node();
void get_info(char *st);
int check_symbol(char *digit);
void push_stack(NODE **stack, char *digit);
void pop_stack(NODE **stack, char *digit);
int compare_digit(NODE **currNODE, char **digit);

int main() {
	NODE *stack = NULL; 
	char st[100]; char digit;

		get_info(st);
		for (int i = 0; i < strlen(st); i++) {
		digit = st[i];
		if ((check_symbol(&digit)) == 0) {
			push_stack(&stack, &digit);
		} else if ((check_symbol(&digit)) == 1) {
			pop_stack(&stack, &digit);
		}
		}
		printf("\Valid");
	

}

NODE *create_node() {
	NODE *newINFO;
	if ((newINFO=(NODE*)malloc(sizeof(NODE))) == NULL) return NULL;
	newINFO->ch = '0';
	newINFO->next = NULL;
	return (newINFO); 
}

void get_info(char *st) {
	printf("Enter symbols: ");
	scanf("%s", st);	
}

int check_symbol(char *digit) {
	if (*digit == '(' || *digit == '[' || *digit == '{') return 0;
	else if (*digit == ')' || *digit == ']' || *digit == '}') return 1;
}

void push_stack(NODE **stack, char *digit) {
	NODE *newNODE = create_node();
	newNODE->ch = *digit;
	newNODE->next = NULL;
	
	if (*stack == NULL)  *stack = newNODE;
	else {
		newNODE->next = *stack;
		*stack = newNODE;
	}
}

void pop_stack(NODE **stack, char *digit) {
	if (*stack == NULL) {
		printf("INVALID");
		exit(1);
	}
	NODE *currNODE = *stack; 
	if (compare_digit(&currNODE, &digit) == 1) {
		*stack = (*stack)->next;
	} else if (compare_digit(&currNODE, &digit) == 0) {
		printf("\nNot Valid");
		exit(1);
	}
}

int compare_digit(NODE **currNODE, char **digit) {
	if ((*currNODE)->ch == '(' && (**digit) == ')') return 1;
	else if ((*currNODE)->ch == '[' && (**digit) == ']') return 1;	
	else if ((*currNODE)->ch == '{' && (**digit) == '}') return 1;		
	else return 0;
}
