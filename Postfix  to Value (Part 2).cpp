#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char ch;
	struct node *link;
};
void enqueue(struct node **queue, char digit);
void push_stack(struct node **stack, struct node **queue, char digit);
void pop_stack (struct node **stack, struct node **queue, struct node **p);
void push_stack2(struct node **stack, struct node**queue);
void dequeue (struct node **stack, struct node **queue);
void display_stack(struct node **stack, int *i);
void operate (struct node **stack, struct node **queue, int *i, int *k, int *count);
int is_operator(char digit);
int precedence(char digit1, char digit2);
void display(struct node **queue);


int main() {
	struct node *queue = NULL;
	struct node *stack = NULL;
	char expression[100];
	int i, k, count=0;
	
	printf("Enter expression: ");
	scanf("%s", expression);
	int x = strlen(expression);
	
	
	for (int i = 0; i < x; i++) {
		if (is_operator(expression[i]) == 0) {
			enqueue(&queue, expression[i]);	
		} else if (is_operator(expression[i]) == 1) {
			push_stack(&stack, &queue, expression[i]);	
		}
	}


	push_stack2(&stack, &queue);
	display(&queue);
	
	while (queue != NULL) {
		if (is_operator(queue->ch) == 0) dequeue(&stack, &queue);
		if (is_operator(queue->ch) == 1) operate(&stack, &queue, &i, &k, &count);
		queue = queue->link;	
	}
 	
    display_stack(&stack, &i);
	
}

int is_operator(char digit) {
	if (digit == '+' || digit == '-' || digit == '*' || digit == '/') return 1;
	else return 0;
}

int precedence(char digit1, char digit2) {
	if (digit1 == '*' && digit2 == '+') return 1;
	if (digit1 == '*' && digit2 == '-') return 1;
	if (digit1 == '/' && digit2 == '+') return 1;
	if (digit1 == '/' && digit2 == '-') return 1;	
	return 0;
}

void enqueue(struct node **queue, char digit) {
	//ibutang sa temp ang first char
	struct node *temp;
	temp = (struct node*) malloc (sizeof(struct node));
	temp->ch = digit; 
	temp->link = NULL;
			
	//i save sa list ang char, i insert sa ending
	if (*queue == NULL) *queue = temp;
	else {
		struct node *p;
		p = *queue;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = temp;
	}
}

void push_stack(struct node **stack, struct node **queue, char digit) {
	//ibutang sa temp ang first char
	struct node *temp;
	temp = (struct node*) malloc (sizeof(struct node));
	temp->ch = digit; 
	temp->link = NULL;
	//I butang sa beginning pag null pa ang list
	if (*stack == NULL) *stack = temp;
	else {
		//i compare niya ang every data sa list if equal or not
		struct node *p;
		p = *stack;	
		while (p != NULL) {
			if (precedence(temp->ch, p->ch) == 1) {
				//beginning ibutang
				temp->link = *stack;
				*stack = temp;	
			//else if equals to precedence and small precedence
			//if high and precedence (/,+),(/,-),(*,+),(*,-)
			} else if (precedence(temp->ch, p->ch) == 0) {	
			//i pop ang p->ch tas ibutang sa queue tapos ibutang ang temp sa stack (before ibutang kay i compare napod balik)
			//	pop_stack(p->ch);		
				pop_stack(stack, queue, &p);
			}
			p = p->link;	
		}
		//pag hurot na og pop ang p->ch
		if (*stack == NULL) *stack = temp;
	}	
}

void pop_stack (struct node **stack, struct node **queue, struct node **p) {
	struct node *temp_one;
	struct node *s;
	s = *p;
	temp_one = (struct node*) malloc (sizeof(struct node));
	temp_one->ch = s->ch;
	temp_one->link = NULL;
	*stack = s->link;
	//isulod sa end sa queue ang p->ch 
	if (*queue == NULL) *queue = temp_one;
	else {
		struct node *t;
		t = *queue;
		while (t->link != NULL) {
		t = t->link;
		}
		t->link = temp_one;
	}	
}

void push_stack2 (struct node **stack, struct node **queue) {
	struct node *temp;
	struct node *p;
	p = *stack;
	
	while (p != NULL) {
		temp = (struct node*) malloc (sizeof(struct node));
		temp->ch = p->ch;
		temp->link = NULL;
		*stack = p->link;
	
		if (*queue == NULL) *queue = temp;
		else {
			struct node *t;
			t = *queue;
			while (t->link != NULL) {
				t = t->link;
			}
			t->link = temp;
		}
		p = p->link;
	}	
}

void display(struct node **queue) {
	struct node *q;
	q = *queue;	
	while (q != NULL) {
		printf("%c", q->ch);
		q = q->link;
	}
}

void dequeue (struct node **stack, struct node **queue) {
	struct node *p;
	p = *stack;
	struct node *q;
	q = *queue;
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->ch = q->ch;
	temp->link = NULL;
	
	if (*stack == NULL) *stack = temp;
	else {
		temp->link = *stack;
		*stack = temp;	
	}
}

void operate (struct node **stack, struct node **queue, int *i, int *k, int *count) {
	struct node *p;
	p = *stack;
	struct node *q;
	q = *queue;
	
	
	int a = atoi(&p->ch);
	p = p->link;
	int b = atoi(&p->ch);
	*stack = p->link;
	
	char Operator = q->ch;
	int result;

		if (q->ch == '+') result = b + a;
		if (q->ch == '-') result = b - a;
		if (q->ch == '*') result = b * a;
		if (q->ch == '/') result = b / a;
		
    
	char ans;
	 
	struct node *temp;
	temp = (struct node*) malloc (sizeof(struct node));
	itoa (result, &(temp->ch), 10);
	temp->link = NULL;
	
	if (*stack == NULL) *stack = temp;
	else {
		temp->link = *stack;
		*stack = temp;	
	}

	
}

void display_stack(struct node **stack, int *i) {
	struct node *p;
	p = *stack;
	printf("\n\n");
	while (p != NULL) {
		printf("%d", atoi(&p->ch));
		p = p->link;
	}
}


