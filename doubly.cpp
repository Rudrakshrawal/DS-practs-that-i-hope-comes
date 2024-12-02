#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;

// Create a doubly linked list
void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;
    
    for(i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// Display forward
void Display(struct Node *p) {
   while(p != NULL) { 
       printf("%d ", p->data);
       p = p->next;
   }
   printf("\n");
}

// Display backward
void RDisplay(struct Node *p) {
    // Go to last node
    while(p->next != NULL)
        p = p->next;
    
    // Print backward
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}

// Count elements (recursive)
int Rcount(struct Node *p) {
    if(p != NULL)
        return Rcount(p->next) + 1;
    else
        return 0;
}

// Sum of elements (recursive)
int Rsum(struct Node *p) {
    if(p == 0)
        return 0;
    else
        return Rsum(p->next) + p->data;
}

// Find max number
int maxnum(struct Node *p) {
    int m = INT_MIN;
    while(p) {
        if (p->data > m)
            m = p->data;
        p = p->next;
    }
    return m;
}

// Linear search
struct Node * LSearch(struct Node *p, int key) {
    while (p != NULL) {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

// Insert at a given position
void Insert(struct Node *p, int index, int x) {
    struct Node *t;
    int i;
    
    // Validate index
    if(index < 0 || index > Rcount(p))
        return;
    
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    
    // Insert at the beginning
    if(index == 0) {
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else {
        // Traverse to the position
        for(i = 0; i < index - 1; i++)
            p = p->next;
        
        t->next = p->next;
        t->prev = p;
        
        if(p->next)
            p->next->prev = t;
        
        p->next = t;
    }
}

// Insert in a sorted doubly linked list
void SortedInsert(struct Node* &head, int x) {
    struct Node *t, *p = head, *q = NULL;
    
    // Create new node
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    t->prev = NULL;
    
    // If list is empty or new node should be first
    if(head == NULL || x < head->data) {
        t->next = head;
        if(head) 
            head->prev = t;
        head = t;
        return;
    }
    
    // Traverse to find correct position
    while(p && p->data < x) {
        q = p;
        p = p->next;
    }
    
    // Insert node
    t->next = q->next;
    t->prev = q;
    
    if(q->next)
        q->next->prev = t;
    
    q->next = t;
}

// Delete a node at a given position
int Delete(struct Node* &head, int pos) {
    struct Node *p = head;
    int x = -1;
    
    // Deleting first node
    if(pos == 1) {
        head = head->next;
        if(head) 
            head->prev = NULL;
        
        x = p->data;
        free(p);
        return x;
    }
    else {
        // Traverse to the node to be deleted
        for(int i = 0; i < pos - 1 && p; i++)
            p = p->next;
        
        // If position is valid
        if(p) {
            p->prev->next = p->next;
            
            if(p->next)
                p->next->prev = p->prev;
            
            x = p->data;
            free(p);
            return x;
        }
    }
    
    return x;
}

// Remove duplicates from sorted list
void RemoveDuplicates(struct Node* &head) {
    struct Node *p = head, *q = head->next;
    
    while(q != NULL) {
        if(p->data != q->data) {
            p = q;
            q = q->next;
        }
        else {
            // Adjust links and free duplicate
            p->next = q->next;
            
            if(q->next)
                q->next->prev = p;
            
            free(q);
            q = p->next;
        }
    }
}

// Reverse a doubly linked list (iterative approach)
void Reverse(struct Node* &head) {
    struct Node *p = head, *temp;
    
    while(p != NULL) {
        // Swap prev and next pointers
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        
        // Move head if this is the last node
        if(p->prev == NULL)
            head = p;
        
        p = p->prev;
    }
}

// Concatenate two doubly linked lists
void Concatenate(struct Node* &first, struct Node* second) {
    struct Node *p = first;
    
    // Go to the last node of first list
    while(p->next != NULL)
        p = p->next;
    
    // Link last node of first list to first node of second list
    p->next = second;
    
    // Set prev pointer of first node of second list
    if(second)
        second->prev = p;
}

// Merge two sorted lists
void Merge(struct Node* first, struct Node* second, struct Node* &third) {
    struct Node *last = NULL;
    
    // Initialize third list
    if(first->data < second->data) {
        third = last = first;
        first = first->next;
        third->next = NULL;
        third->prev = NULL;
    }
    else {
        third = last = second;
        second = second->next;
        third->next = NULL;
        third->prev = NULL;
    }
    
    // Compare and merge
    while(first && second) {
        if(first->data < second->data) {
            last->next = first;
            first->prev = last;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else {
            last->next = second;
            second->prev = last;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    
    // Attach remaining list
    if(first) {
        last->next = first;
        first->prev = last;
    }
    if(second) {
        last->next = second;
        second->prev = last;
    }
}

int main() {
    int A[] = {3, 2, 56, 6, 3, 6, 2, 6, 2, 9};
    create(A, 10);
    
    printf("Forward Display: ");
    Display(first);
    
    printf("Backward Display: ");
    RDisplay(first);
    
    printf("List Length: %d\n", Rcount(first));
    printf("Sum of Elements: %d\n", Rsum(first));
    printf("Max Number: %d\n", maxnum(first));
    
    // Linear Search
    struct Node *temp = LSearch(first, 3);
    if(temp)
        printf("Key Found: %d\n", temp->data);
    
    // Sorted Insert
    printf("Sorted Insert (5): ");
    SortedInsert(first, 5);
    Display(first);
    
    // Delete
    printf("Delete at position 3: %d\n", Delete(first, 3));
    Display(first);
    
    // Remove Duplicates
    RemoveDuplicates(first);
    printf("After Removing Duplicates: ");
    Display(first);
    
    // Reverse
    Reverse(first);
    printf("Reversed List: ");
    Display(first);
    
    return 0;
}
