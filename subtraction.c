#include "apc.h"

int subtraction(Dlist **tail1,Dlist **tail2, Dlist **headR,Dlist **tailR,int*result)
{
	/* Definition goes here */
	Dlist*temp1=*tail1;
	Dlist*temp2=*tail2;
	int borrow=0;
	*headR=*tailR=NULL;
	while(temp1||temp2)
	{
		int num1=0,num2=0;
		if(temp1)
		{
			num1=temp1->data;
			temp1=temp1->prev;
		}
		if(temp2)
		{
			num2=temp2->data;
			temp2=temp2->prev;
		}
		if(borrow==1)
		{
			num1=num1-1;
			borrow=0;
		}
		if(num1<num2)
		{
			num1=num1+10;
			borrow=1;
		}
		int sub=num1-num2;
		insert_first(headR,tailR,sub);
	}
	remove_pre_zeros(headR);// Remove leading zeros from the number
	//printf("Subtraction is successful\n");
	if(*result==-1)
	{
		(*headR)->data=(*headR)->data*-1;
	}
	return SUCCESS;
}
