#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR,int*flag1)
{
    int flag=0;
    Dlist *temp2 = *tail2;   // LSB of second number
    int shift = 0;

    *headR = NULL;
    *tailR = NULL;

    while (temp2)
    {
        int carry = 0;
        Dlist *temp1 = *tail1;

        /* partial product list */
        Dlist *headP = NULL, *tailP = NULL;

        /* add positional zeros */
        for (int i = 0; i < shift; i++)
            insert_first(&headP, &tailP, 0);

        /* multiply one digit */
        while (temp1)
        {
            int mul = temp1->data * temp2->data + carry;
            insert_first(&headP, &tailP, mul % 10);
            carry = mul / 10;
            temp1 = temp1->prev;
        }

        if (carry)
            insert_first(&headP, &tailP, carry);

        /* first partial product becomes result */
        if (*headR == NULL)
        {
            *headR = headP;
            *tailR = tailP;
        }
        else
        {
            /* add partial product to result */
            Dlist *headA = NULL, *tailA = NULL;

            addition(headR, tailR,&headP, &tailP,&headA,&tailA,&flag);

            delete_list(headR, tailR);
            delete_list(&headP, &tailP);

            *headR = headA;
            *tailR = tailA;
        }

        temp2 = temp2->prev;
        shift++;
    }

    remove_pre_zeros(headR);
    if (*flag1 == -1)
	{
		(*headR)->data=(*headR)->data*-1;
	}
    return SUCCESS;
}