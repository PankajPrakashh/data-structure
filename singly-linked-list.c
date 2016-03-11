/**
 * @author          Pankaj Prakash
 * @website         http://www.codeforwin.in/
 * @lastmodified    March 10, 2016
 * @description     C program to implement all operations of a singly linked 
 *                  list. Basic operations performed on a singly linked list are:
 *                  1.  Creation
 *                  2.  Insertion at beginning
 *                  3.  Insertion at end
 *                  4.  Insertion at any position
 *                  5.  Deletion from beginning
 *                  6.  Deletion from end
 *                  7.  Deletion from any position
 *                  8.  List traversal or display contents
 *                  9.  Count number of elements
 *                  10. Search element in list
 *                  11. Reverse entire list
 *                  12. Sort elements of the list 
 -----------------------------------------------------------------------------*/
 
#include <stdio.h>
#include <stdlib.h>


/*
 * Basic structure of the node in list.
 */
typedef struct node {
   int data;
   struct node *next;
}node; 
 
 
 

/*
 * Function declarations 
 */
node * createList(int);
void insertAtBeginning(node **, int);
void insertAtEnd(node **, int);
void insertAtN(node **, int, int);
int  deleteFirst(node **);
int  deleteLast(node **);
int  deleteAtN(node **, int);
void deleteAll(node **);
void displayList(node **);
int  count(node **);
int  search(node **, int);
void reverseList(node **);
void sortList(node **);





/**
 * Program starts from here.
 */
int main()
{
    int choice, position, data, result;
    char confirm;
    node *head = NULL;    
    
    //Runs indefinitely till user chooses to exit 
    while(1)
    {
        system("clear");
        
        printf("    WELCOME TO SINGLY LINKED LIST PROGRAM\n");
        printf("---------------------------------------------\n");
        printf("  1. Create list\n");
        printf("  2. Insert node at beginning \n");
        printf("  3. Insert node at end \n");
        printf("  4. Insert node at n \n");
        printf("  5. Delete first node \n");
        printf("  6. Delete last node \n");
        printf("  7. Delete node at n \n");
        printf("  8. Clear list \n");
        printf("  9. Display list \n");
        printf(" 10. Count nodes \n");
        printf(" 11. Search in list \n");
        printf(" 12. Reverse list \n");
        printf(" 13. Sort list \n");
        printf(" 00. Exit program \n");
        printf("---------------------------------------------\n");
        printf(" Enter your choice : ");
        
        scanf("%d", &choice);
        getchar(); //To eliminate new line entry by scanf(); 
        
        
        printf("\n\n---------------------------------------------\n");
        switch(choice)
        {
            case  1: //Creation of node
                printf("How many nodes you want to create: ");
                scanf("%d", &data);
                
                //Operation function call
                head = createList(data);
                
                break;
                
            case  2: //Insert at beginning
                printf("Enter value of first node: ");
                scanf("%d", &data);
                
                //Operation function call
                insertAtBeginning(&head, data);
                break;
                
            case  3: //Insert at end
                printf("Enter value of last node: ");
                scanf("%d", &data);
                
                //Operation function call
                insertAtEnd(&head, data);
                
                break;
                
            case  4: //Insert at n
                printf("Where exactly you want to insert new node: ");
                scanf("%d", &position);
                printf("Enter data of %d node: ", position);
                scanf("%d", &data);
                
                //Operation function call
                insertAtN(&head, position, data);
                
                break;
                
            case  5: //Delete first
                printf("\nARE YOU SURE TO DELETE FIRST NODE (y/n): ");
                confirm = getchar();
                
                if(confirm =='y' || confirm == 'Y')
                {
                    //Operation function call
                    result = deleteFirst(&head);
                    printf("Freed %d from memory\n", result); 
                }
                
                break;
                
            case  6: //Delete last
                printf("\nARE YOU SURE TO DELETE LAST NODE (y/n): ");
                confirm = getchar();
                
                if(confirm == 'y' || confirm == 'Y')
                {
                    //Operation function call
                    result = deleteLast(&head);
                    printf("Freed %d from memory\n", result);
                }
                
                break;
                
            case  7: //Delete at n
                printf("Which node you want to delete: ");
                scanf("%d", &position);
                getchar(); //Avoid the newline entry
                
                printf("\nARE YOU SURE TO DELETE %d NODE (y/n): ", position);
                confirm = getchar();
                
                if(confirm == 'y' || confirm == 'Y')
                {
                    //Operation function call
                    result = deleteAtN(&head, position);
                    printf("Freed %d from memory\n", result);
                }
                
                break;
                
            case  8: //Clear list
                printf("\nTHIS OPERATION WILL DELETE ALL NODES. ARE YOU SURE TO DELETE (y/n): ");
                confirm = getchar();
                
                if(confirm == 'y' || confirm == 'Y')
                {
                    //Operation function call
                    deleteAll(&head);
                }
                
                break;
                
            case  9: //Display list
            
                //Operation function call
                displayList(&head);
                
                break;
                
            case 10: //Count nodes
            
                //Operation function call
                result = count(&head);
                printf("\nTotal number of nodes in list is: %d\n", result);
                
                break;
                
            case 11: //Search in list
                printf("What are you looking for in list: ");
                scanf("%d", &data);
                
                //Operation function call
                result = search(&head, data);
                
                if(result == -1)
                {
                    printf("Ummm! looks as %d does not exists in list.\n", data);
                }
                else
                {
                    printf("Yeah, %d is present at %d position.\n", data, result);
                }
                
                break;
                
            case 12: //Reverses list
                printf("\nTHIS OPERATION WILL REVERSE THE ORDER OF LIST. SURE TO CONTINUE (y/n): ");
                confirm = getchar();
                
                if(confirm == 'y' || confirm == 'Y')
                {
                    //Operation function call
                    reverseList(&head);
                }
                
                break;
                
            case 13: //Sorts list
                printf("\nARE YOU SURE TO SORT LIST IN ASCENDING ORDER (y/n): ");
                confirm = getchar();
                
                if(confirm == 'y' || confirm == 'Y')
                {
                    //Operation function call
                    sortList(&head);
                }
                
                break;
                
            case  0: //Exits program
                printf("\nREALLY YOU WANT TO QUIT ME (y/n): ");
                confirm = getchar();
                
                if(confirm == 'y' || confirm == 'Y')
                {
                    //Operation function call
                    deleteAll(&head);
                    
                    exit(0);
                }
                
                break;
                
            default: //Invalid choices
                printf("Looks as you didn't choose correct option.\n");
                printf("Please read menu carefully and try again. \n");
        }
        
        
        getchar(); //To eliminate new lines
        printf("\n---------------------------------------------\n");
        printf(" Press any key to continue...");
        getchar();
    }
    
    
    return 0;
}





/**
 * Creates a list of n nodes. 
 * @totalNodes Total number of nodes in the list.
 * @returns On success returns pointer to the head node otherwise returns NULL.
 */
node * createList(int totalNodes)
{
    int i;
    node *head, *newNode, *temp;
    
    if(totalNodes >= 1)
    {
        head = (node *)malloc(sizeof(node)); //Allocates memory
        head->next = NULL;
        
        printf("Enter data of 1 node: ");
        scanf("%d", &head->data);
        
        temp = head;
        for(i=2; i<=totalNodes; i++)
        {
            newNode = (node *)malloc(sizeof(node));
            newNode->next = NULL;
            
            printf("Enter data of %d node: ", i);
            scanf("%d", &newNode->data);
            
            //Links previous node with newly created node
            temp->next = newNode;
            temp = temp->next;
        }
        
        printf("\nYeah! list with %d nodes created successfully.\n", totalNodes);
        
        return head;
    }
    else 
    {
        printf("\nOops! I am sorry, I can't create such node.\n");
        return NULL;
    }
}





/**
 * Inserts a node at the beginning of the singly linked list.
 * @head Pointer to node pointing at first node of the list
 * @data Data added to the newly created node.
 */
void insertAtBeginning(node ** head, int data)
{
    node *newNode = NULL;
    
    if(*head == NULL)
    {
        printf("\nOops! looks as the list is empty. Please first create list.\n");
    }   
    else
    {
        newNode = (node *)malloc(sizeof(node));
        newNode->next = NULL;
        newNode->data = data;
        
        newNode->next = *head;
        *head = newNode;
        
        printf("\nYeah! node added successfully at begninning of the list.\n");
    }
}





/**
 * Inserts a node at the end of the singly linked list.
 * @head Pointer to node pointing at first node of the list
 * @data Data to be added at the end of list.
 */
void insertAtEnd(node ** head, int data)
{
    node *newNode, *temp;
    
    if(*head == NULL)
    {
        printf("\nOops! looks list the list is empty. Please first create list.\n");
    }
    else
    {
        newNode = (node *)malloc(sizeof(node));
        newNode->next = NULL;
        newNode->data = data;
        
        //Move to the end of list
        temp = *head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = newNode;
        
        printf("\nYeah! successfully added node at the end of list.\n");
    }
}





/**
 * Inserts node at nth position in the list.
 * @head     Pointer to node pointing at first node of the list
 * @position Position where you want to insert new node.
 * @data     Data inserted at the given position.
 */
void insertAtN(node ** head, int position, int data)
{
    node *newNode, *temp;
    int i;
    
    if(*head == NULL)
    {
        printf("\nOops! looks like list is empty. Please first create list.\n");
    }   
    else
    {
        if(position == 1)
            insertAtBeginning(head, data);
        else
        {
            //Moves to the desired position - 1
            temp = *head;
            for(i=1; i<position-1; i++)
            {
                temp = temp->next;
                
                if(temp == NULL)
                    break;
            }
            
            
            //Checks for invalid position
            if(temp == NULL)
            {
                printf("\nOops! can't insert node at the specified position. Try again.\n");
            }
            else
            {
                newNode = (node *)malloc(sizeof(node));
                newNode->next = NULL;
                newNode->data = data;
                
                newNode->next = temp->next; //Links previous node to newnode
                temp->next = newNode; //Links newnode to next node
                
                
                printf("\nYeah! node successfully inserted at %d position.\n", position);
            }
        }
    }
}





/**
 * Deletes first node in the list and releases the memory occupied by it.
 * @head Pointer to node pointing at first node of the list
 */
int deleteFirst(node ** head)
{
    node * toDelete;
    int data = -1;
    
    //Checks for empty list
    if(*head == NULL)
    {
        printf("\nOops! can't delete from an empty list. Please first create list.\n");
    }
    else
    {
        toDelete = *head;
        
        *head = (*head)->next;
        
        //Backup data and release resource occupied by toDelete
        data = toDelete->data;
        free(toDelete);
        toDelete = NULL; //Always make this NULL to avoid dangling pointer situations
        
        printf("\nYeah! successfully deleted first node and freed %lu bytes.\n", sizeof(node));
    }
    
    return data;
}





/**
 * Deletes last node in the list and releases the memory occupied by it.
 * @head Pointer to node pointing at first node of the list 
 */
int deleteLast(node ** head)
{
    node *toDelete, *last;
    int data = -1;
    
    //Checks for empty list
    if(*head == NULL)
    {
        printf("\nOops! can't delete from an empty list. Please first create list.\n");
    }
    else
    {
        //Moves to last node
        last = *head;
        toDelete = last->next;
        while(toDelete->next != NULL)
        {
            last = last->next;
            toDelete = toDelete->next;
        }
        
        //Backup data and releases resource occupied by toDelete
        data = toDelete->data;
        free(toDelete);
        toDelete = NULL;
        
        //Make sure now last node points to NULL
        last->next = NULL;
        
        printf("\nYeah! successfully deleted last node and freed %lu bytes.\n", sizeof(node));
    }
    
    return data;
}





/**
 * Deletes node from the list from specified position and releases the resource
 * occupied by it.
 * @head        Pointer to node pointing at first node of the list
 * @position    Position which needs to be deleted from list
 */
int deleteAtN(node ** head, int position)
{
    node *toDelete, *prev;
    int i, data = -1;
    
    //Checks for empty list
    if(*head == NULL)
    {
        printf("\nOops! can't delete from an empty list. Please first create list.\n");
    }
    else
    {
        //If delete position is first then let deleteFirst() handle this
        if(position == 1)
        {
            return deleteFirst(head);
        }
            
        //Moves to the desired position - 1
        prev = *head;
        for(i=1; i<position-1; i++)
        {
            prev = prev->next;
            
            if(prev == NULL)
                break;
        }
        
        //Checks for invalid position
        if(prev == NULL || prev->next == NULL)
        {
            printf("\nOops! can't delete at specified position. Please try again.\n");
        }
        else
        {
            //Copies the address of node which is to be deleted
            toDelete = prev->next; 
            
            //Backup data, maintain the link and releases resources occupied by toDelete
            prev->next = toDelete->next; //Links previous node with the next node ahead of deleting node
            data = toDelete->data;
            free(toDelete);
            toDelete = NULL; //To avoid dangling pointer
            
            printf("\nYeah! successfully deleted %d node and freed %lu bytes.\n", position, sizeof(node));
        }
    }
    
    return data;
}





/**
 * Deletes all nodes from the list and releases the resources occupied by them.
 * Or in general clears the list.
 * @head Pointer to node pointing at first node of the list
 */
void deleteAll(node ** head)
{
    node *toDelete;
    int count = 0;
    
    
    //Run till the last node
    while(*head != NULL)
    {
        //Copies the current node to toDelete
        toDelete = *head;
        *head = (*head)->next; //Move the head node ahead
        
        free(toDelete); //Releases resources
        toDelete = NULL; //To avoid dangling pointer
        
        count++;
    }
    
    printf("\nYeah, successfully deleted %d nodes and free %lu bytes.\n", count, (count * sizeof(node)));
}





/**
 * Displays the content of the list sequentially.
 * @head Pointer to node pointing at first node of the list
 */
void displayList(node ** head)
{
    node *temp = *head;
    int count = 1;
    
    printf("---------------------------------------------\n");
    printf("              DATA IN THE LIST\n");
    printf("\n---------------------------------------------\n");
    
    //Runs till the end of list
    while(temp != NULL)
    {
        printf("NODE %d => DATA %d\n", count, temp->data);
        
        temp = temp->next;
        count++;
    }
}





/**
 * Counts total number of nodes in the list.
 * @head Pointer to node pointing at first node of the list
 */
int count(node ** head)
{
    int count = 0;
    node *temp = *head;
    
    //Runs till end of the list
    while(temp != NULL)
    {
        count++;
        temp = temp->next;   
    }
    
    return count;
}





/**
 * Searches for a specific data in the list. A linear search is performed to search
 * data element in the list.
 * @head Pointer to node pointing at first node of the list
 * @data Data to be searched in the list
 */
int search(node ** head, int data)
{
    int index = -1;
    node * temp;
    
    //Checks for an empry list
    if(*head == NULL)
    {
        printf("\nOops! looking for something in empty room. Please first create list.\n");
    }
    else
    {
        index = 1;
        //Runs till the end of list
        temp = *head;
        while(temp != NULL)
        {
            if(temp->data == data)
            {
                //Found element hence return its index
                return index;
            }
            
            temp = temp->next;
            index++;
        }
    }
    
    return -1; //Not found
}





/**
 * Reverses the order of list.
 * @head Pointer to node pointing at first node of the list
 * @see To understand this concept more clearly visit
 * http://www.codeforwin.in/2015/09/c-program-to-reverse-singly-linked-list.html
 */
void reverseList(node ** head)
{
    node *prev, *cur, *next;
    
    //Checks for empty list
    if(*head == NULL)
    {
        printf("\nOops! I really can't reverse an empty list. Please first create list.\n");
    }
    else
    {
        prev = *head;
        cur = (*head)->next;
        
        prev->next = NULL; //Make sure now first node is last node
        //Runs till the end of list
        while(cur != NULL)
        {
            next = cur->next; 
            
            cur->next = prev; 
            prev = cur;
            cur = next;
        }
        
        *head = prev;
        
        printf("\nYeah! successfully reversed the order of list.\n");
    }
}





/**
 * Sorts the list in increasing order or say in ascending order of their elements.
 * @head Pointer to node pointing at first node of the list
 */
void sortList(node ** head)
{
    //Yet to be implemented
    printf("\nOops! I haven't added any logic to this.\n");
}
