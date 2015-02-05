/*File Name : insert_to_list.c
 Author Name : K.S.Krishna Chandran
 Description : Program to insert elements at the head or tail of the head 
 Date : 05-01-15*/


#include<stdio.h>
#include<stdlib.h>

int count;

struct node                                                 //Structer declaration
{
	int num;                                               //Node elements to store number and address of next node    
	struct node *link;
}*head=NULL;                                              // Head node declaration

int display_head();                                      //Function to display the elements from the head
int display_tail();                                      //Function to display the elements from the tail
int insert_at_head();                                    //Function to insert the elements to the head
int insert_at_tail();                                    //Function to insert the elements to the tail
int display();
int delete_node();
int search_modify();
 
int main() {
	
	system("clear");
	char ch;
	int n;
	do {
		system("clear");
		printf("\n\nLinked List Menu\n");
		printf("\n1.Insert at head of node\n2.Insert at tail of node\n3.Search and modify that node\n4.Delete Element\n5.Exit\n");
		printf("\nPlease enter an option     ");
		scanf("%d", &n);
		switch(n) {
			case 1 : printf("\n\n**Insert at head**\n");
				insert_at_head();                                           //Calling function to add elemenets at the head 
				display_head();
				break;
			
			case 2 : printf("\n\n**Insertat tail**\n");
				insert_at_tail();                                           //Calling function to add elemenets at the tail
				display_tail();
				break;
			
			case 3 : printf("\n\n**Search and modify a node**\n\n");
				modify_list();
				dipslay();
				break;
				
			case 4 : printf("\n\n**Delete from node**\n\n");
					delete_node();
					display();
					break;
				
			case 5 : exit(0);
				
			default : printf("\n\nPlease enter a valid option  ");
		}
		printf("\n\nDo you want to continue (Y/N)   ");
		scanf(" %c", &ch);
	}while(ch == 'Y' || ch == 'y');
	printf("\n\n");
	return 0;
}


int insert_at_head() {
	count++;
	char choice1;
	do {
		struct node *head_new;
		head_new = (struct node *)malloc(sizeof(struct node));
		printf("\nEnter the number to add at the heaad of the node        ");
		scanf("%d",&head_new->num);
		head_new->link = NULL;
		if(head == NULL) {
			head = he
			d_new;
		}
		else {
			head_new->link = head;
			head = head_new;
		}
		printf("\n\nDo you want to insert more at head  (Y/N)  ");
		scanf(" %c", &choice1);
	}while(choice1 == 'Y' || choice1 == 'y');
	
}

int insert_at_tail() {
	char choice2;
	do {
		struct node *tail_new, *temp;
		temp = head;
		tail_new = (struct node *)malloc(sizeof(struct node));
		printf("\nEnter the number to add at the tail of the node         ");
		scanf("%d",&tail_new->num);
		tail_new->link = NULL;
		if(head == NULL) {
			head = tail_new;
		}
		else {
			while(temp->link != NULL) {
				temp = temp->link;
			}
			temp->link = tail_new;
		}
		printf("\nDo you want to insert more at tail  (Y/N)   ");
		scanf(" %c",&choice2);
	}while(choice2 == 'Y' || choice2 == 'y');
	printf("\n\n");
}

int modify_list()
{
	struct node *modify;
	modify = head;
	int nod;
	printf("\nEnter the node number of the list to modify     ");
}	
int display() {
	system("clear");
	printf("\n\n\n");
	struct node *t;
	t = head;
	while(t != NULL) {
		printf("%d->",t->num);
		t = t->link;
	}
	printf("NULL");
	printf("\n\n");
}
	
int display_tail() {
	system("clear");
	printf("\n\n\n");
	struct node *t;
	t = head;
	while(t != NULL) {
		printf("%d->",t->num);
		t = t->link;
	}
	printf("NULL");
	printf("\n\n");
}

int display_head() {
	system("clear");
	printf("\n\n\n");
	struct node *tm;
	tm = head;
	while(tm != NULL) {
		printf("%d<-",tm->num);
		tm = tm->link;
	}
	printf("NULL");
	printf("\n\n");
}
