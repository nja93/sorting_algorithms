#include "sort.h"

void insertion_sort_list(listint_t **list) {
    
	listint_t *current;

	
	if (*list == NULL || (*list)->next == NULL) {
	    return; // Empty or single-node list is already sorted
    }

    listint_t *current = (*list)->next;

    while (current != NULL) {
        listint_t *temp = current;

        while (temp->prev != NULL && temp->n < temp->prev->n) {
            // Swap nodes
            listint_t *prevNode = temp->prev;
            listint_t *nextNode = temp->next;

            if (prevNode->prev != NULL) {
                prevNode->prev->next = temp;
            }

            if (nextNode != NULL) {
                nextNode->prev = prevNode;
            }

            temp->prev = prevNode->prev;
            temp->next = prevNode;
            prevNode->prev = temp;
            prevNode->next = nextNode;

            if (temp->prev == NULL) {
                *list = temp; // Update head if necessary
            }

            // Print the list after each swap
            listint_t *currentNode = *list;
            while (currentNode != NULL) {
                printf("%d ", currentNode->n);
                currentNode = currentNode->next;
            }
            printf("\n");

            temp = prevNode; // Continue checking previous nodes
        }

        current = current->next; // Move to the next node
    }
}

