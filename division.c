#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR,int*flag1)
{
    int flag=0;
    /* Temporary copy of dividend */
    Dlist *tempHead = NULL;
    Dlist *tempTail = NULL;

    /*temporary count*/
    Dlist *qHead = NULL, *qTail = NULL;

    /* Constant ONE list */
    Dlist *oneHead = NULL, *oneTail = NULL;

    /* Temporary quotient result*/
    Dlist *newQHead = NULL, *newQTail = NULL;

    /* Step 1: Copy dividend */ 
    copy_list(head1, tail1, &tempHead, &tempTail);

    /* Step 2: If dividend < divisor → quotient = 0 */
    if (compare_list(tempHead, *head2) == 2)
    {
        insert_first(headR, tailR, 0);
        return SUCCESS;
    }

    /* Step 3: Initialize quotient = 0 */
    insert_first(&qHead, &qTail, 0);

    /* Step 4: Create constant ONE */
    insert_first(&oneHead, &oneTail, 1); //

    /* Step 5: Repeated subtraction */
    while (compare_list(tempHead, *head2) == 1 || compare_list(tempHead, *head2) == 0)
    {
        /* dividend = dividend - divisor */
        subtraction(&tempTail, tail2,&tempHead, &tempTail,&flag); // Subtract divisor from the temporary dividend

        /* quotient = quotient + 1 */
        newQHead = NULL;
        newQTail = NULL;

        addition(&qHead, &qTail,&oneHead, &oneTail,&newQHead,&newQTail,&flag); // Add ONE to the current quotient
        qHead = newQHead;
        qTail = newQTail;
    }

    /* Step 6: Assign result */
    *headR = qHead;
    *tailR = qTail;

    printf("Division successful\n");
    if (*flag1 ==-1)
	{
		(*headR)->data=(*headR)->data*-1;
	}
    return SUCCESS;
}

