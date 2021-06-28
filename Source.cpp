//get Nth Node from end of a LinkedList
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// A linked list node
struct Node
{
	int data;
	struct Node *next;
};

Node* push(struct Node *head_ref, int new_data)								//insertion in the beginning of the LinkedList
{
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = head_ref;
	head_ref = new_node;

	return head_ref;
}

Node* append(struct Node *head_ref, int new_data)							//insertion at the end of the LinkedList
{
	struct Node *head_ref2;
	head_ref2 = head_ref;
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = NULL;
	while (head_ref2->next != NULL)
		head_ref2 = head_ref2->next;
	head_ref2->next = new_node;
	return head_ref;
}

int getNthFromEnd(struct Node *head_ref, int index)
{
	int length = 0;
	struct Node *curr = head_ref;
	while (curr != NULL)
	{
		curr = curr->next;
		length++;
	}
	curr = head_ref;
	for (int i = 1; i < (length - index + 1); i++)
		curr = curr->next;
	return curr->data;
}
// This function prints contents of linked list starting from head
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}

int main()
{
	struct Node *head = NULL, *first = NULL;
	head = push(head, 8);
	first = push(head, 9);
	first = push(first, 3);
	first = push(first, 1);

	printf("\n Created Linked list (head) is: ");
	printList(head);
	printf("\n Created Linked list (first) is: ");
	printList(first);

	head = append(head, 6);
	head = append(head, 3);
	head = append(head, 2);
	head = append(head, 9);
	printf("\n Created Linked list (head) is: ");
	printList(head);
	printf("\n Created Linked list (first) is: ");
	printList(first);

	printf("\n\n4th index value :  %d", getNthFromEnd(head, 4));
	printf("\n\n1st index value :  %d", getNthFromEnd(first, 1));
	printf("\n\n2nd index value :  %d", getNthFromEnd(first, 2));
	printf("\n\n3rd index value :  %d", getNthFromEnd(first, 3));
	printf("\n\n4th index value :  %d", getNthFromEnd(first, 4));
	printf("\n\n5th index value :  %d", getNthFromEnd(first, 5));
	printf("\n\n6th index value :  %d", getNthFromEnd(first, 6));
	printf("\n\n7th index value :  %d", getNthFromEnd(first, 7));
	printf("\n\n8th index value :  %d", getNthFromEnd(first, 8));
	_getch();
}