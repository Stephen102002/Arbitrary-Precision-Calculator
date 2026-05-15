#include "apc.h"

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    int sign1 = 1, sign2 = 1, result_sign = 1;
    char oper;

    /* Validate CLA */
    if (validation(argc, argv) == FAILURE)
    {
        printf("Invalid arguments\n");
        return FAILURE;
    }

    /* Detect signs */
    if (argv[1][0] == '-')
        sign1 = -1;
    if (argv[3][0] == '-')
        sign2 = -1;

    oper = argv[2][0];

    /* Convert operands to ABSOLUTE value lists */
    digit_to_list(&head1, &tail1, &head2, &tail2, argv);

    /* Remove leading zeros */
    remove_pre_zeros(&head1);
    remove_pre_zeros(&head2);

    switch (oper)
    {
        case '+':
            if (sign1 == sign2)
            {
                /* same sign → add */
                addition(&head1, &tail1,&head2,&tail2,&headR,&tailR,&sign1);
            }
            else
            {
                /* different sign → subtract */
                int cmp = compare_list(head1, head2);

                if (cmp == 1)
                {
                    subtraction(&tail1, &tail2, &headR, &tailR,&sign1);
                }
                else if (cmp == 2)
                {
                    subtraction(&tail2, &tail1, &headR, &tailR,&sign2);
                }
                else
                {
                    insert_first(&headR, &tailR, 0);
                }
            }
            break;

        case '-':
            /* a - b = a + (-b) */
            sign2 = -sign2;

            if (sign1 == sign2)
            {
                addition(&head1, &tail1, &head2, &tail2, &headR, &tailR,&sign1);
            }
            else
            {
                int cmp = compare_list(head1, head2);

                if (cmp == 1)
                {
                    subtraction(&tail1, &tail2, &headR, &tailR,&sign1);
                }
                else if (cmp == 2)
                {
                    subtraction(&tail2, &tail1, &headR, &tailR,&sign2);
                }
                else
                {
                    insert_first(&headR, &tailR, 0);
                }
            }
            break;

        case 'x':
            result_sign = sign1 * sign2;
            multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR,&result_sign);
            break;

        case '/':
            if (head2->data == 0)
            {
                printf("Division by zero error\n");
                return FAILURE;
            }
            result_sign = sign1 * sign2;
            division(&head1, &tail1, &head2, &tail2, &headR, &tailR,&result_sign);
            break;

        default:
            printf("Invalid operator\n");
            return FAILURE;
    }

    remove_pre_zeros(&headR);

    /* Print result */
    //printf("Result: ");
    /*if (result_sign == -1 && !(headR->data == 0))
        printf("-");*/

    print_list(&headR);
    return SUCCESS;
}



