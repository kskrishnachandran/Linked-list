/*File Name:insert_to_tail.c
  Author:K.S.Krishna Chandran
  Description:Program to insert numbers to the tail of a linked list
  Date:01-02-15*/





#include<stdio.h>

struct node {
	int number;
	struct node *link;
} *head=NULL;

int add_at_tail();
int display();

int main() {
	system("clear");
	add_at_tail();
	display();
	printf("\n\n");
	return 0;
}

int add_at_tail() {
	char ch;
	do {
		struct node *new;
		struct node *temp;
		new=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter the numer to the tail   ");
		scanf("%d",&new->number);
		new->link=NULL;
		if(head==NULL) {
			head=new;
			temp=new;
		}
		else {
			temp->link=new;
			temp=new;
		}
		printf("\nDo you want to enter more numbers  (Y/N)");
		scanf(" %c",&ch);
	}while(ch=='Y'||ch=='y');
}

int display() {
	struct node *disp;
	disp=head;
	printf("\nThe numbers in the list are\n");
	while(disp!=NULL) {
		printf("%d --> ",disp->number);
		disp=disp->link;
	}
	printf("NULL");
}
