#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR,int*flag)
{
	/* Definition goes here */
	int carry=0;
	int sum;
	int result;
	Dlist*temp1=*tail1;
	Dlist*temp2=*tail2;
	while(temp1!=NULL||temp2!=NULL)
	{
      sum=carry;
	  if(temp1!=NULL)
	  {
		sum=sum+temp1->data;
		temp1=temp1->prev;
	  }
	  if(temp2!=NULL)
	  {
		sum=sum+temp2->data;
		temp2=temp2->prev;
	  }
	  if(sum>9)
	  {
        result=sum%10;
		carry=sum/10;
		insert_first(headR, tailR, result);
	  }
	  else
	  {
        result=sum;
		carry=0;
		insert_first(headR, tailR, result);
	  }
	}
	if(carry!=0)
	{
		insert_first(headR,tailR,carry);
	}
	if (*flag == -1)
	{
		(*headR)->data=(*headR)->data*-1;
	}
	return SUCCESS; 
}

