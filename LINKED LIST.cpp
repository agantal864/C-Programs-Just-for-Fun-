#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};
struct node *root=NULL;



void append();
void addatbegin();
void addatafter();
void length_of_node();
void display();
void delete_node();
int length_of_nodes();



int length;


main() {
	int choice;
	while (1) {
		printf("Single Linked List Operations\n\n");
		printf("1. Append\n");
		printf("2. Addatbegin\n");
		printf("3. Addatafter\n");
		printf("4. Length\n");
		printf("5. Display\n");
		printf("6. Delete\n");
		printf("7. Exit\n\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1: {
				append();
				break;
			}
			case 4: {
				length = length_of_nodes();
				printf("Length of Nodes present: %d \n\n", length);
				break;
			}
			case 5: {
				display();
				break;
			}
			case 6: {
				delete_node();
				break;
			}
			case 7: exit(1);
			default: printf("\nInvalid Input\n");
		}
	}	
}


void append() {
	struct node *temp;
	temp = (struct node*) malloc (sizeof(struct node));
	printf("Enter data: ");
	scanf("%d", &temp->data);
	temp->link = NULL;
	
	
	if (root == NULL) root = temp;
	else {
		struct node *p;
		p = root; 
		while (p->link != NULL) {
			p = p -> link;
		}
		p->link = temp; 
	}

}
int length_of_nodes() {
	int count = 0;
	struct node *temp;
	temp = root;
	while (temp != NULL) {
		count++;
		temp = temp -> link; 
	}
	return count;
}
void display() {
	struct node *temp;
	temp = root;
	if (temp == NULL) printf("\nThere is no NODES to present.\n\n");
	else {
		while (temp != NULL) {
			printf("%d-->", temp->data);
			temp = temp->link;
		}
		printf("\n\n");
	}
}
void delete_node() {

	struct node *temp; 
	int loc;
	printf("\nPlease enter location of node: ");
	scanf("%d", &loc);
	if (loc > length) printf("\nThere is no such location.\n");
	else if (loc == 1) {
		temp = root;
		root = temp->link;
		temp -> link = NULL;
		free(temp);
	} else {
		struct node *p;
		struct node *q;
		p = root;
		int i = 1;
		while (i < loc - 1) {
			p = p->link;
			i++;
		}
		q = p->link;
		p->link = q->link;
		q->link = NULL;
		free(q);
	}
	
}

