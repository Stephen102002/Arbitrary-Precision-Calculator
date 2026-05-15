#ifndef APC_H
#define APC_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

/*store the operands into the list */
//void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,int*flag);

/*subtraction*/
int subtraction(Dlist **tail1,Dlist **tail2,Dlist **headR,Dlist **tailR,int*result);

/*Multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,int*flag1);


/*Division */
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,int*flag1);

int insert_first(Dlist **head,Dlist**tail,int data);
int insert_last(Dlist **head, Dlist **tail, int data);
int digit_to_list(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,char *argv[]);
void print_list(Dlist **head);
/* Utility / helper functions */
int copy_list(Dlist **head, Dlist **tail,Dlist **newHead, Dlist **newTail);

int compare_list(Dlist *head1, Dlist *head2);

int delete_list(Dlist **head, Dlist **tail);

void remove_pre_zeros(Dlist **head);

int validation(int argc, char *argv[]);


#endif
