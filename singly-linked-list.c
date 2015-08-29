/*************************************************************************
 * Description  : Singly Linked list implementation and operations in C
 *                Basic Operations on singly linked list includes:
 *                  1) Creation of list
 *                  2) Traversal of list
 *                  3) Insertion of new node in list
 *                  4) Deletion of node from the list
 *                  5) Counting total number of nodes
 *                  6) Reversing of list
 * Author       : Pankaj Prakash (pankajprakashh)
 * Website      : http:\\codeforwin.blogspot.in\
 * Last updated : 29 August 2015 09:04 AM
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0x00
#define ERROR 0xff
#define OUT_OF_MEMORY 0xfe
#define LIST_IS_EMPTY 0x01

/*
 * Node structure of the Singly Linked list
 */
typedef struct node {
    int data;
    struct node * next;
}SinglyLinkedList;

SinglyLinkedList * head;

/*
 * Operations performed on a singly linked list
 */
int createNewList();
void printList();
int insertAtBeginning(int data);
int insertAtEnd(int data);
int insertAtN(int position, int data);
int deleteList();
int deleteAtBeginning();
int deleteAtEnd();
int deleteAtN(int position);
long count();
int reverseList();

void clrscr();

int main()
{
    int choice, data, position, result;

    while(1)
    {
        clrscr();

        printf("=================================================\n");
        printf("    WELCOME TO THE SINGLY LINKED LIST PROGRAM    \n");
        printf("=================================================\n");
        printf("Operations performed on a singly linked list\n");
        printf("-------------------------------------------------\n");
        printf("1. Create a new list\n");
        printf("2. Insert an element - at beginning of list\n");
        printf("3. Insert an element - at end of list\n");
        printf("4. Insert an element - at n position\n");
        printf("5. Delete an element - at beginning of list\n");
        printf("6. Delete an element - at end of list\n");
        printf("7. Delete an element - at n position\n");
        printf("8. Delete entire list\n");
        printf("9. Count total elements\n");
        printf("10.Reverse order of list\n");
        printf("11.Print entire list\n");
        printf("0. Exit Program\n");
        printf("---------------------------------------------------\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch(choice)
        {
            //Create New list
            case 1:
                result = createNewList();
                if(result == SUCCESS)
                {
                    printf("List created successfully\n");
                    printf("Enter the data of first node: ");
                    scanf("%d", &head->data);
                }
                else
                {
                    printf("\nList is not empty first delete all elements.");
                }
                break;

            //Insert new node at beginning of list
            case 2:
                printf("\nEnter node data: ");
                scanf("%d", &data);

                result = insertAtBeginning(data);
                if(result == SUCCESS)
                {
                    printf("\nData inserted successfully at the beginning of list.");
                }
                else if(result == OUT_OF_MEMORY)
                {
                    printf("\nSort of memory. Create allocate new memory");
                }
                break;

            //Insert new node at end of list
            case 3:
                printf("\nEnter node data: ");
                scanf("%d", &data);

                result = insertAtEnd(data);
                if(result == SUCCESS)
                {
                    printf("\nData inserted successfully at the end of list.");
                }
                else if(result == LIST_IS_EMPTY)
                {
                    printf("\nList is empty. Please first create list.");
                }
                break;

            //Insert new node at n position
            case 4:
                printf("\nEnter position where you want to insert new node: ");
                scanf("%d", &position);
                printf("\nEnter node data: ");
                scanf("%d", &data);
                result = insertAtN(position, data);

                if(result == SUCCESS)
                {
                    printf("\nData inserted successfully.");
                }
                else if(result == LIST_IS_EMPTY)
                {
                    printf("\nList is empty. Please first create list.");
                }
                break;

            //Delete node from beginning of list
            case 5:
                result = deleteAtBeginning();
                if(result == SUCCESS)
                {
                    printf("\nSuccessfully deleted node from list.");
                }
                else if(result == LIST_IS_EMPTY)
                {
                    printf("\nList is empty. Please first create list.");
                }
                break;

            //Delete node from end of the list
            case 6:
                result = deleteAtEnd();
                if(result == SUCCESS)
                {
                    printf("\nSuccessfully deleted node from list.");
                }
                else if(result == LIST_IS_EMPTY)
                {
                    printf("\nList is empty. Please first create list");
                }
                break;

            //Delete node from n position of the list
            case 7:
                printf("\nEnter node position to delete: ");
                scanf("%d", &position);

                result = deleteAtN(position);
                if(result == SUCCESS)
                {
                    printf("\nSuccessfully deleted node from list");
                }
                else if(result == LIST_IS_EMPTY)
                {
                    printf("\nList is empty. Please first create list");
                }
                break;

            //Deletes entire nodes from the list
            case 8:
                result = deleteList();
                if(result == SUCCESS)
                {
                    printf("\nSuccessfully deleted entire list.");
                }
                else if(result == ERROR)
                {
                    printf("\nSomething went wrong while deleting entire list.");
                }
                break;

            //Counts total number of nodes in list
            case 9:
                printf("\nTotal number of elements in list = %ld", count());
                break;

            //Reverse the order of entire list.
            case 10:
                result = reverseList();
                if(result == SUCCESS)
                {
                    printf("\nSuccessfully reversed order of list.");
                }
                else if(result == LIST_IS_EMPTY)
                {
                    printf("\nCan't reverse an empty list.");
                }
                break;

            //Prints entire list
            case 11:
                printList();
                break;

            //Exits from program
            case 0:
                if(head != NULL)
                    deleteList();

                exit(SUCCESS);
            break;

            //Invalid input
            default:
                printf("\nInvalid input please enter again.\n");
        }

        printf("\n");
        system("pause");
    }

    return 0;
}

/*
 * Clears the console screen
 */
void clrscr()
{
    system("cls");
}

/*
 * Creates a empty Linked list
 */
int createNewList()
{
    if(head==NULL)
    {
        head = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
        head->next = NULL;

        return SUCCESS;
    }

    return ERROR;
}

/*
 * Prints all data of the list from beginning
 */
void printList()
{
    SinglyLinkedList * temp;
    int count = 1;

    /*
     * Checks if the list is empty
     */
    if(head == NULL)
    {
        printf("\nList is empty. Please first create a list.");
        return;
    }

    temp = head;

    printf("\nDATA IN LIST\n");
    printf("============\n");
    while(temp!=NULL)
    {
        printf("Data %d = %d\n", count, temp->data);
        printf("----------------------\n\n");

        count++;
        temp = temp->next;
    }
}

/*
 * Insert a node at the beginning of the list
 */
int insertAtBeginning(int data)
{
    SinglyLinkedList * newNode;

    /*
     * Creates a new node and adds at the beginning of list
     */
    newNode = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
    if(newNode != NULL)
    {
        newNode->next = head;
        newNode->data = data;

        head = newNode;

        return SUCCESS;
    }

    return OUT_OF_MEMORY;
}

/*
 * Inserts a node at the end of the list
 */
int insertAtEnd(int data)
{
    SinglyLinkedList *newNode, *lastNode;

    /*
     * Checks if the list is empty
     */
    if(head == NULL)
    {
        return LIST_IS_EMPTY;
    }

    lastNode = head;
    while(lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }

    /*
     * Creates a new node and adds at the end of list
     */
    newNode = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
    if(newNode != NULL)
    {
        newNode->data = data;
        newNode->next = NULL;

        lastNode->next = newNode;

        return SUCCESS;
    }

    return OUT_OF_MEMORY;
}

/*
 * Inserts a new node at the specified position
 */
int insertAtN(int position, int data)
{
    SinglyLinkedList *newNode, *temp;
    int count;

    /*
     * Checks if the list is empty
     */
    if(head == NULL)
    {
        return LIST_IS_EMPTY;
    }

    /*
     * If the position is 1 then insert the new node at the beginning of list
     */
    if(position == 1)
    {
        return insertAtBeginning(data);
    }

    temp = head;

    for(count=1; count<position-1 && temp!=NULL; count++)
    {
        temp = temp->next;
    }

    /*
     * Creates a new node and adds to N position in the list
     */
    newNode = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
    if(newNode != NULL)
    {
        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;

        return SUCCESS;
    }

    return OUT_OF_MEMORY;
}

/*
 * Deletes entire list from the memory and also clears the memory occupied by the list
 */
int deleteList()
{
    SinglyLinkedList *nextNode, *curNode;

    if(head == NULL)
    {
        return LIST_IS_EMPTY;
    }

    curNode = head;
    while(curNode != NULL)
    {
        nextNode = curNode->next;
        free(curNode);
        curNode = nextNode;
    }

    head = NULL;

    return SUCCESS;
}

/*
 * Deletes or removes first node of the list.
 */
int deleteAtBeginning()
{
    SinglyLinkedList *startNode;

    /*
     * Check if the list is empty
     */
    if(head == NULL)
    {
        return LIST_IS_EMPTY;
    }

    startNode = head;
    head = head->next;

    free(startNode);

    return SUCCESS;
}

/*
 * Deletes or removes the last node of the list
 */
int deleteAtEnd()
{
    SinglyLinkedList *lastNode, *secondLastNode;

    /*
     * Check if the list is empty
     */
    if(head == NULL)
    {
        return LIST_IS_EMPTY;
    }

    /*
     * Traverse to the last node
     */
    lastNode = head;
    while(lastNode->next != NULL)
    {
        secondLastNode = lastNode;
        lastNode = lastNode->next;
    }

    free(lastNode);
    secondLastNode->next = NULL;

    return SUCCESS;
}

/*
 * Deletes node from the list at specified position
 */
int deleteAtN(int position)
{
    SinglyLinkedList *nthNode, *temp;
    int count;

    /*
     * Checks if the list is empty
     */
    if(head == NULL)
    {
        return LIST_IS_EMPTY;
    }

    temp = head;

    for(count=1; count<position-1 && temp!=NULL; count++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        return ERROR;
    }

    /*
     * Creates a link from n-1 node to n+1 node and deletes nth node
     */
    nthNode = temp->next;
    temp->next = nthNode->next;
    free(nthNode);

    return SUCCESS;
}

/*
 * Returns the total number of nodes in the list
 */
long count()
{
    long total = 0;
    SinglyLinkedList *temp;

    temp = head;
    while(temp != NULL)
    {
        total++;
        temp = temp->next;
    }

    return total;
}

/*
 * Reverses the order of the list.
 */
int reverseList()
{
    SinglyLinkedList *previousNode, *curNode;

    /*
     * Checks if the list is empty
     */
    if(head == NULL)
    {
        return LIST_IS_EMPTY;
    }

    previousNode = head;
    curNode = head->next;
    head = head->next;
    previousNode->next = NULL; //First node becomes last node

    while(head != NULL)
    {
        head = head->next;
        curNode->next = previousNode;

        previousNode = curNode;
        curNode = head;
    }

    head = previousNode; //Last node becomes the head node

    return SUCCESS;
}
