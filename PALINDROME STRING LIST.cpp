#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Palindrome checker linked list - STRING VERSION 2.0     Azis Agantal - UP Mindanao 
typedef struct NODE{
	char ch;
	NODE *next;
}NODE;

NODE *create_node();
void destroy_NODE (NODE *new_info, NODE **head);
void get_info(char *st, int *len);
void insert_NODE(NODE **head, char *st, int *count, int *len);
void check_NODE(NODE **head, int *count);
void print_all(NODE **head, int *count, int *len);

int main () {
	NODE *head = NULL;
	char st[100]; int len=0,count=0;
	get_info(st, &len);
	insert_NODE(&head, st, &count, &len);
	check_NODE(&head, &count);
	print_all(&head, &count, &len);	

}

NODE *create_node() {
	NODE *new_info;
	if ((new_info = (NODE*)malloc(sizeof(NODE))) == NULL) return (NULL);
	new_info->ch = '0';
	new_info->next = NULL;
	return (new_info);
}

void destroy_NODE (NODE *new_info) {
	free(new_info);
}

void get_info(char *st, int *len) {
	printf("Enter string: ");
	scanf("%s", st);
	*len = strlen(st);
}

void insert_NODE(NODE **head, char *st, int *count, int *len) {
	NODE *newNODE;

	for (int i = 0; i < *len; i++) {
		newNODE = create_node();
		newNODE->ch = st[i];
		newNODE->next = NULL;
		*count = *count + 1; //counts how many nodes in the list
		if (*head == NULL) {
			*head = newNODE;
		}
		else {
			NODE *currNODE = *head;
			while (currNODE->next != NULL) {
				currNODE = currNODE->next;
			}
			currNODE->next = newNODE;
		}
	}
}

void check_NODE(NODE **head, int *count) {
	NODE *front; NODE *rear;
	int i = 0, j;

    while (i != (*count / 2)) {
        front = rear = *head;
        for (j = 0; j < i; j++) {
            front = front->next;
        } for (j = 0; j < (*count - (i + 1)); j++) {
           	 rear = rear->next;
        } if (front->ch != rear->ch) {
            printf("The linked list is NOT A PALINDROME.\n\n");
            return;
        }
         else i++;
    }
    printf("The linked list is a PALINDROME\n\n");
    return;	
}

void print_all(NODE **head, int *count, int *len) {
	NODE *temp = *head;
	
	if (temp == NULL) printf("\nList is empty");
	while (temp != NULL) {
		printf("%c->", temp->ch);
		temp = temp->next;
	}
	//printf("\ncount = %d, len = %d", *count, *len);
}

