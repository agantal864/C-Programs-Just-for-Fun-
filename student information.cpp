#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<unistd.h>

struct node{
	char student_num[100];
	char first_name[100];
	char last_name[100];
	int year_level;
	char course[100];
	int age;
	struct node *link;
};


void add_student(struct node **root);
void display_all(struct node **root);
void display_one_student(struct node** root);
void edit_student(struct node** root);
void delete_all(struct node** root);
void delete_one_student(struct node** root);


int main() {
	
	struct node *root=NULL;
 	int choice;
		
	while(1) {
		system("cls");
		printf("\t\t\t\t\tSTUDENT INFORMATION SYSTEM\n\n\n"); 
		
		
		printf("\t\t[1] Add New Student\n"); 	usleep(20000);
		printf("\t\t[2] Display All Students\n"); 	usleep(20000);
		printf("\t\t[3] Display Single Student\n"); 	usleep(20000);
		printf("\t\t[4] Edit Student\n"); 	usleep(20000);
		printf("\t\t[5] Delete All Students\n"); 	usleep(20000);
		printf("\t\t[6] Delete Single Student\n");	usleep(20000);
		printf("\t\t[0] Exit\n"); 	usleep(20000);
		printf("\n\t\tEnter Choice [1-6] or 0 to exit the prgoram: "); usleep(20000);
		scanf("%d", &choice);
		switch(choice) {
			case 1: {
				system("cls");
				printf("\t\t\t\t\t\tAdd New Student\n\n");
				add_student(&root);
				printf("\n\t\tPress any key to continue..");
				getch();
				break;
			}
			case 2: {
				system("cls");
				printf("\t\t\t\t\t\tDisplay All Students\n\n");
				display_all(&root);
				printf("\n\t\tPress any key to continue..");
				getch();
				break;
			}
			case 3: {
				system("cls");
				printf("\t\t\t\t\t\tDisplay One Student\n\n");
				display_one_student(&root);
				printf("\t\tPress any key to continue..");
				getch();
				break;
			}
			case 4: {
				system("cls");
				printf("\t\t\t\t\t\tEdit One Student\n\n");
				edit_student(&root);
				printf("\n\t\tPress any key to continue..");
				getch();
				break;
			}
			case 5: {
				system("cls");
				printf("\t\t\t\t\t\tDelete All Students\n\n");
				delete_all(&root);
				printf("\n\t\tPress any key to continue..");
				getch();
				break;
			}
			case 6: {
				system("cls");
				printf("\t\t\t\t\t\tDelete One Student\n\n");
				delete_one_student(&root);
				printf("\n\t\tPress any key to continue..");
				getch();
				break;
			}
			case 0: 
				exit(1);
			default: {
				printf("\n\t\tInvalid Input.\n");
				printf("\n\t\tPress any key to continue..");
				getch();
				break;
			}
		}
	}	
 }
 
void add_student(struct node **root) {
 	
 	struct node *temp; struct node *p; struct node *q; struct node *r;
 	int count = 0;
	p = *root;
	q = *root;
	r = *root;
 	temp = (struct node*) malloc (sizeof(struct node));
 	
 	
	printf("\t\tEnter the following information: \n\n"); 
	printf("\t\tStudent Number: "); 
 	scanf("%s", temp->student_num);
 	temp->link = NULL;
 	
	while (q != NULL) {
		int ret = strcmp (temp->student_num, q->student_num);
		while (ret == 0) {
			printf("\n\t\t%s exists. PLease enter a unique Student Number.\n\n", temp->student_num); 
			printf("\t\tStudent Number: "); 
			q = *root;
 			scanf("%s", temp->student_num);
 			ret = strcmp (temp->student_num, q->student_num);
		}
		q = q->link;
	}
	
 	printf("\n\t\tFirst Name: "); 
 	fflush(stdin);
 	gets(temp->first_name);
 	printf("\t\tLast Name: "); 
	gets(temp->last_name);
	printf("\t\tAge: "); 
	scanf("%d", &temp->age);
	printf("\t\tYear level: "); 
	scanf("%d", &temp->year_level);
	printf("\t\tCourse: ");
	scanf("%s", temp->course);
	printf("\n\t\tStudent number %s is added to the list.\n", temp->student_num); 

 	if (*root == NULL) *root = temp;
	else {
		char temp_one[100];
		char temp_two[100];
		strcpy (temp_one, temp->student_num);
		strcpy (temp_two, r->student_num);
		int m = strlen(temp_one);
		int n = strlen(temp_two);
		int pos = 1;
		if (strlen(temp_two)>strlen(temp_one)) {
			for (int k = m; m < n; k++) {
				for(int i=m; i>=pos; i--)  temp_one[i] = temp_one[i-1];        
        		temp_one[pos-1] = '0';
        		m++;
        		temp_one[m] = '\0';
			}
		} else {
			for (int k = n; n < m; k++) {
				for(int i=n; i>=pos; i--)  temp_two[i] = temp_two[i-1];        
        		temp_two[pos-1] = '0';
        		n++;
        		temp_two[n] = '\0';
			}	
		}
		
			int len = strcmp(temp_one, temp_two);
			if (len < 0) {
			temp->link = *root;
			*root = temp;
			count++;
			} 
			int x = 0;
			while (len > 0) {
			if (r->link != NULL) {
				r = r->link;
				x++;
				if (x > 1) p = p->link;
				strcpy(temp_one, temp->student_num);
				strcpy(temp_two, r->student_num);
				int m = strlen(temp_one);
				int n = strlen(temp_two);
				int pos = 1;
				if (strlen(temp_two)>strlen(temp_one)) {
					for (int k = m; m < n; k++) {
						for(int i=m; i>=pos; i--)  temp_one[i] = temp_one[i-1];        
        				temp_one[pos -1] = '0';
        				m++;
        				temp_one[m] = '\0';
					}
				} else {
					for (int k = n; n < m; k++) {
					for(int i=n; i>=pos; i--)  temp_two[i] = temp_two[i-1];        
        			temp_two[pos-1] = '0';
        			n++;
        			temp_two[n] = '\0';
					}	
				}
				len = strcmp(temp_one, temp_two);
			} else {
				r->link = temp;
				count++;
				}		
			}
			
			if (count == 0) {
				p->link = temp;
				temp->link = r;		
			}
			return;		
					
	}
}
		 
void display_all(struct node **root) {
	struct node *temp;
	temp = *root;
	if (temp == NULL) printf("\n\t\tList is empty.\n");
	else {
		printf("\t\t======================================================================================\n");
		printf("\t\tStudent Number\t\tName\t\t    Age\t\t  Year Level\t\tCourse\n");
		printf("\t\t======================================================================================\n\n");
		while (temp != NULL) {
			printf("\t\t  %s", temp->student_num);
			if (strlen(temp->student_num) < 20) {
				for (int k = strlen(temp->student_num); k < 10; k++) printf(" ");
			}
			printf("\t  %s ", temp->first_name);
			printf("%s", temp->last_name);
			
			if ((strlen(temp->first_name) + strlen(temp->last_name))  < 26) {
				for (int i = (strlen(temp->first_name) + strlen(temp->last_name)); i < 26; i++) printf(" ");
			}
			printf("%d", temp->age);
			printf("\t\t       %d", temp->year_level);
			printf("\t\t %s\n\n", temp->course);
			temp = temp->link;
		}
		printf("\n\n");
	}
}

void display_one_student(struct node **root) {
	
	if (*root == NULL) {
		printf("\n\t\tList is empty.\n\n");
		return;
	} 
	
	struct node *temp;
	struct node *o;
	struct node *p;
	int ret, count=0;
	
	temp = (struct node*) malloc (sizeof(struct node));
	temp->link = NULL;
	o = *root;
	p = *root;
	printf("\t\tEnter Student Number: ");
	scanf("%s", &temp->student_num);
	if (*root == NULL) printf("\t\tList is empty.\n\n");
	while (o != NULL) {
		ret = strcmp(temp->student_num, o->student_num);
		if (ret == 0) {
			count++;
		}
		o = o->link;
	}
	if (count == 0) {
		printf("\n\t\tStudent Number %s does not exist!\n", temp->student_num);
		return;	
	}
	while (p != NULL) {
		int comp;
		comp = strcmp(temp->student_num, p->student_num);
		if (comp == 0) {
			printf("\n\n\t\tStudent Number: %s", p->student_num);
			printf("\n\t\tStudent Name: %s, ", p->last_name);
			printf("%s", p->first_name);
			printf("\n\t\tAge: %d", p->age);
			printf("\n\t\tYear Level: %d", p->year_level);
			printf("\n\t\tCourse: %s\n\n", p->course);
		} 
		p = p->link;
	}
}

void edit_student(struct node** root) {
	
	if (*root == NULL) {
		printf("\n\t\tList is empty.\n");
		return;
	} 
	
	struct node *o;
	struct node *p;
	struct node *temp;
	int ch, count=0;;
	
	temp = (struct node*) malloc (sizeof(struct node));
	p = *root;
	o = *root;
	
	printf("\n\t\tStudent Number: ");
	scanf("%s", &temp->student_num);
	
	while (o != NULL) {
		int ret = strcmp(temp->student_num, o->student_num);
		if (ret == 0) count++;
		o = o->link;
	}
	if (count == 0) {
		printf("\n\t\tStudent Number %s does not exist!\n", temp->student_num);
		return;
	}
	
	int ret = strcmp(temp->student_num, p->student_num);
	if (ret == 0) {
		while (1) {
			fflush(stdout);
			printf("\n\t\t[1]First Name: %s", p->first_name);
			fflush(stdout);
			printf("\n\t\t[2]Last Name: %s", p->last_name);
			printf("\n\t\t[3]Age: %d", p->age);
			printf("\n\t\t[4]Year Level: %d", p->year_level);
			printf("\n\t\t[5]Course: %s", p->course);
			printf("\n\t\t[0]Back to Main Menu\n\n");
			printf("\t\tEnter data to edit [1-5] or 0 to go back to Main Menu: ");
			scanf("%d", &ch);
	
			switch(ch) {
				case 1: {
					printf("\t\tEnter First Name: ");
					fflush(stdin);
					gets(p->first_name);
					break;
				}
				case 2: {
					printf("\t\tEnter Last Name: ");
					fflush(stdin);
					gets(p->last_name);
					break;
				}
				case 3: {
					printf("\t\tEnter Age: ");
					scanf("%d", &p->age);
					break;
				}
				case 4: {
					printf("\t\tEnter Year Level: ");
					scanf("%d", &p->year_level);
					break;
				}
				case 5: {
					printf("\t\tEnter Course: ");
					fflush(stdin);
					gets(p->course);
					break;
				}
				case 0: {
					return;
				}
			}
		}
		
		
	} else {
		struct node* q;
		struct node* r;
		struct node* s;
		q = *root;
		r = q->link;

		while (r != NULL) {
			ret = strcmp(temp->student_num, r->student_num);
			if (ret == 0) {
 			while (1) {
				printf("\n\t\t[1]First Name: %s", r->first_name);
				printf("\n\t\t[2]Last Name: %s", r->last_name);
				printf("\n\t\t[3]Age: %d", r->age);
				printf("\n\t\t[4]Year Level: %d", r->year_level);
				printf("\n\t\t[5]Course: %s", r->course);
				printf("\n\t\t[0]Back to Main Menu\n\n");
				printf("\t\tEnter data to edit [1-5] or 0 to go back to Main Menu: ");
				scanf("%d", &ch);
	
				switch(ch) {
					case 1: {
						printf("\t\tEnter First Name: ");
						fflush(stdin);
						gets(r->first_name);
						break;
					}
					case 2: {
						printf("\t\tEnter Last Name: ");
						fflush(stdin);
						gets(r->last_name);
						break;
					}
					case 3: {
						printf("\t\tEnter Age: ");
						scanf("%d", &r->age);
						break;
					}
					case 4: {
						printf("\t\tEnter Year Level: ");
						scanf("%d", &r->year_level);
						break;
					}
					case 5: {
						printf("\t\tEnter Course: ");
						fflush(stdin);
						gets(r->course);
						break;
					}
					case 0: {
						return;
					}
				}
			}		
	 		}
	 		q = q->link;
	 		r= r->link;
		}	
	}
}
 
void delete_all(struct node** root) { 
	struct node* p = *root; 
	struct node* q; 
	char ch;
   
	if (p == NULL) {
		printf("\n\t\tList is empty.\n");
		return;
	} 
	
	printf("\n\t\tAre you sure to want to delete all records? [Y/N]: ");
	scanf(" %c", &ch);
    if (ch == 'Y' || ch == 'y') {
		while (p != NULL) { 
			q = p->link; 
			free(p); 
			p = q; 
		}
		*root = NULL;
		printf("\n\t\tAll student records deleted.\n\n");	
	}

} 

void delete_one_student(struct node** root) { 

	struct node *p;
	struct node *o;
	struct node *temp;
	int count = 0;
	char ch;
	temp = (struct node*) malloc (sizeof(struct node));
	p = *root;
	o = *root;
	
	if (p == NULL) {
		printf("\n\t\tList is empty.\n");
		return;
	} 
	
	printf("\n\t\tPlease enter student number: ");
	scanf("%s", &temp->student_num);
	
	while (o != NULL) {
		int ret = strcmp(temp->student_num, o->student_num);
		if (ret == 0) count++;
		o = o->link;
	}
	if (count == 0) {
		printf("\n\t\tStudent Number %s does not exist!\n", temp->student_num);
		return;
	}
	
	int ret = strcmp(temp->student_num, p->student_num);
	if (ret == 0) {
		printf("\n\n\t\tStudent Number: %s", p->student_num);
		printf("\n\t\tStudent Name: %s, %s", p->last_name, p->first_name);
		printf("\n\t\tAge: %d", p->age);		
		printf("\n\t\tYear Level: %d", p->year_level);
		printf("\n\t\tCourse: %s\n\n", p->course);
		printf("\t\tAre you sure to want to delete all records? [Y/N]:  ");
		scanf(" %c", &ch);
		if (ch == 'Y' || ch == 'y') {
			printf("\n\t\tRecord for %s is deleted\n", p->student_num);
			*root = p->link;
			p->link = NULL;
			free(p);
		}
	} else {
		struct node* q;
		struct node* r;
		struct node* s;
		q = *root;
		r = q->link;

		while (r != NULL) {
			ret = strcmp(temp->student_num, r->student_num);
			if (ret == 0) {
				printf("\n\n\t\tStudent Number: %s", r->student_num);
				printf("\n\t\tStudent Name: %s, %s", r->last_name, r->first_name);
				printf("\n\t\tAge: %d", r->age);		
				printf("\n\t\tYear Level: %d", r->year_level);
				printf("\n\t\tCourse: %s\n\n", r->course);
				printf("\t\tAre you sure to want to delete all records? [Y/N]:  ");
				scanf(" %c", &ch);
				if (ch == 'Y' || ch == 'y') {
					printf("\n\t\tRecord for %s is deleted\n", r->student_num);
					q->link = r->link;
 					r->link = NULL;
 					free(r);
 				}
	 		}
	 		q = q->link;
	 		r= r->link;
		}	
	}
}


