#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<winuser.h>

// Creating a node
struct node {
  int id;
  int days_to_go;
  struct node *next;
};

// unsorted list of people
void printLinkedlist(struct node *p) {
  printf("Unsorted list: \n");
  while (p != NULL) {
    printf(" iD: %d ", p->id);
    printf("\t\t days to go: %d", p->days_to_go);
    printf("\n");
    p = p->next;
  }
}

//sort the list of people
void sortList(struct node *head) {
    //Node current will point to head

    struct node *current = head, *index = NULL;
    int temp;
    int temp_2;

    if(head == NULL) {
        return;
    }
    else {
        while(current != NULL) {
            //Node index will point to node next to current
            index = current->next;

            while(index != NULL) {
                //If current node's data is greater than index's node data, swap the data between them
                if(current->days_to_go > index->days_to_go) {
                    temp = current->days_to_go;
                    current->days_to_go = index->days_to_go;
                    index->days_to_go = temp;

                    temp_2 = current->id;
                    current->id = index->id;
                    index->id = temp_2;

                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

//Print Sorted Linked List
void printSortedLinkedlist(struct node *p) {
  printf("Sorted list: \n");
  while (p != NULL) {
    printf(" iD: %d ", p->id);
    printf("\t\t days to go: %d", p->days_to_go);
    printf("\n");
    p = p->next;
  }
}

//print list with new member
void printNew(struct node *p)
{
    printf("New list with added element: \n");
    while (p != NULL) {
    printf(" iD: %d ", p->id);
    printf("\t\t days to go: %d", p->days_to_go);
    printf("\n");
    p = p->next;
  }
}

//insert element in the linked list
void insertElement(struct node *head)
{
    struct node *newNode;

    newNode = malloc(sizeof(struct node));
    newNode->days_to_go = 90;
    newNode->id = 4004;
    newNode->next = NULL;

    struct node *temp = head;
    while(temp->next != NULL){
    temp = temp->next;
}

temp->next = newNode;
}


int main() {
  // Initialize nodes
  struct node *head;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;

  // Allocate memory
  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));

  // Assign value values
  one->id = 1001;
  two->id = 2002;
  three->id = 3003;

  one->days_to_go = 45;
  two->days_to_go = 23;
  three->days_to_go = 68;

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;

  // printing node-value
  head = one;
  printLinkedlist(head);
  sortList(head);
  printSortedLinkedlist(head);

  insertElement(head);
  printNew(head);

  sleep(5);


}


