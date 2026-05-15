#include "apc.h"

int insert_first(Dlist **head,Dlist**tail,int data)
{
	Dlist *new = malloc(sizeof(Dlist)); // Allocate memory for a new node
        if (new == NULL)
    {
        return FAILURE;
    }

    new->data = data; //update the node's data field
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL) // If the list is empty, set both head and tail to the new node
    {
        *head = *tail = new;
        return SUCCESS;
    }
    Dlist *temp = *head; // Store the current head in a temporary variable
    temp->prev = new; // Update the previous pointer of the current head to point to the new node
    new->next = *head; // Update the next pointer of the new node to point to the current head
    *head = new; // Update the head pointer to point to the new node, making it the new head of the list
    return SUCCESS;
}

int digit_to_list(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,char *argv[])
{
    char *op1 = argv[1]; //to store operand1 
    char *op2 = argv[3]; //to store operand2
    int i;

    /* ---------- Operand 1 ---------- */
    i = 0;

    /* Skip optional sign */
    if (op1[i] == '+' || op1[i] == '-')
        i++;

    /* Skip leading zeros */
    while (op1[i] == '0')
        i++;

    /* Convert digits */
    for (; op1[i] != '\0'; i++)
    {
        insert_last(head1, tail1, op1[i] - '0');
    }

    /* If number was all zeros */
    if (*head1 == NULL)
        insert_last(head1, tail1, 0);

    /* ---------- Operand 2 ---------- */
    i = 0;

    /* Skip optional sign */
    if (op2[i] == '+' || op2[i] == '-')
        i++;

    /* Skip leading zeros */
    while (op2[i] == '0')
        i++;

    /* Convert digits */
    for (; op2[i] != '\0'; i++)
    {
        insert_last(head2, tail2, op2[i] - '0');
    }

    /* If number was all zeros */
    if (*head2 == NULL)
        insert_last(head2, tail2, 0);

    return SUCCESS;
}

int insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist)); // Allocate memory for a new node
    if (new == NULL)
        return FAILURE;

    new->data = data; //update the node's data field
    new->next = NULL;
    new->prev = *tail;

    if (*tail) // If the list is not empty, update the next pointer of the current tail to point to the new node
        (*tail)->next = new;
    else
        *head = new; // If the list is empty, set the head to the new node

    *tail = new; // Update the tail pointer to point to the new node, making it the new tail of the list
    return SUCCESS;
}

void print_list(Dlist **head)
{
     if (*head == NULL)
    { 
        printf("0\n");
        return;
    }

    Dlist *temp = *head; // Temporary pointer to traverse the list
    printf("Result: "); 
    while (temp != NULL) // Traverse the list and print each digit
    {   
        printf("%d", temp->data);
        temp = temp->next; // Move to the next node
    }
    printf("\n");
}
// Calculate length of linked list
int list_len(Dlist*head)
{
    int count = 0;

    // Traverse and count nodes
    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

// Compare two linked lists representing numbers
int compare_list(Dlist*head1,Dlist*head2)
{
   int len1 = list_len(head1);
    int len2 = list_len(head2);

    // Compare based on number of digits
    if (len1 > len2)
        return 1;

    if (len1 < len2)
        return 2;

    Dlist*temp1 = head1; // Temporary pointer to traverse first list from head
    Dlist*temp2 = head2; // Temporary pointer to traverse second list from head
  while(temp1 && temp2)
    {
        if (temp1->data > temp2->data) // If a digit in the first number is greater than the corresponding digit in the second number, return 1
            return 1;
        else if (temp1->data < temp2->data) // If a digit in the first number is less than the corresponding digit in the second number, return 2
            return 2;

        temp1 = temp1->next; // Move to the next digit in the first number
        temp2 = temp2->next; // Move to the next digit in the second number
    }
    return 0; // If all digits are equal, return 0
}


// Remove leading zeros from the number
void remove_pre_zeros(Dlist**head)
{
    // Remove zeros only from the beginning
	while ((*head)->data == 0)
	{
        // Stop if only one digit remains
		if ((*head)->next == NULL)
			return;

        // Delete leading zero node
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
}
int copy_list(Dlist **head, Dlist **tail,Dlist **newHead, Dlist **newTail)
{
    *newHead = NULL; // Initialize new head and tail pointers
    *newTail = NULL; // Temporary pointer to traverse the original list

    Dlist *temp = *head; // Traverse the original list and copy each node's data to the new list

    while (temp)
    {
        insert_last(newHead, newTail, temp->data); // Insert the data of the current node into the new list
        temp = temp->next; // Move to the next node in the original list
    }

    return SUCCESS;
}
// Delete entire linked list
int delete_list(Dlist **head, Dlist **tail)
{
    // Check if list is already empty
    if (*head == NULL)
        return FAILURE;

    Dlist *temp = *head;

    // Free all nodes
    while (temp)
    {
        Dlist *next = temp->next; // Store the next node before freeing the current node
        free(temp);
        temp = next; // Move to the next node
    }

    // Reset head and tail
    *head = NULL;
    *tail = NULL;

    return SUCCESS;
}

int validation(int argc, char *argv[])		// validation of CLA
{
    int i;

    // Check for correct number of arguments
	if (argc == 4)
	{
        /* -------- Validate first operand -------- */
        i = 0;

        // Skip optional sign
		if (argv[1][i] == '+' || argv[1][i] == '-')
        {
    		i++;
        }
        // Ensure all remaining characters are digits
		while (argv[1][i])
        {
            if (argv[1][i] >= '0' && argv[1][i] <= '9')
            {
                i++;
            }
            else
            {
                return FAILURE; // Invalid character found
            }                    
        }

        /* -------- Validate second operand -------- */
        i = 0;

        // Skip optional sign
		if (argv[3][i] == '+' || argv[3][i] == '-')
        {
    		i++;
        }
        // Ensure all remaining characters are digits
        while (argv[3][i])
        {
            if (argv[3][i] >= '0' && argv[3][i] <= '9')
            {
                i++;
            }
            else
            {
                return FAILURE;// Invalid character found
            }   
        }
        // Both operands are valid
        return SUCCESS;
	}

    // Incorrect number of arguments
	return FAILURE;
}
