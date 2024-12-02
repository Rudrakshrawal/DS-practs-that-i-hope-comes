#include<iostream>

// we'll do a mix of C/C++
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first;


// TO create a linked list
void create(int A[], int n){
    int i;
    struct Node *t, *last;
    first=(struct Node *)malloc (sizeof(struct Node));
    first->data= A[0];
    first->next= NULL;
    last = first;
    
    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next =NULL;
        last->next = t;
        last=t;
    }
}

// To display the contents of the linked list 
void Display(struct Node *p){
   while(p!=NULL){ 
       printf("%d\n", p->data);
       p=p->next;
   }
}

// To count the elements in LL
int count(struct Node *p){
    int l =0;
    while(p){
        l++;
        p=p->next;
}   
    return l;
    
}
// To recursively count
int Rcount(struct Node *p){
    if(p!=NULL)
        return Rcount(p->next)+1;
    else
        return 0;
}

// To recursively get the sum of elements of LL
int Rsum(struct Node *p){
    if(p==0)
        return 0;
    else
        return Rsum(p->next)+p->data;
    
}

// To find the max number in the LL
int maxnum(struct Node *p){
    int m = -23;
    while(p){
        if (p->data > m)
            m=p->data;
        p=p->next;
    }
    return m;
}

// Linear srearch 
struct Node* rSearch(struct Node *p, int key) {
    if(p==NULL){
        printf("Data not available\n");
        return NULL;}
    if(key==p->data)
       { printf("The data is found" );
        return p;}
    return rSearch(p->next,key);
}



//Recursive Linear search
struct Node* rSearch(struct Node *p, int key) {
    if(p==NULL){
        printf("Data not available\n");
        return NULL;}
    if(key==p->data)
        printf("The data is found" );
        return p;
    return rSearch(p->next,key);
}
//Inserting an element at last
void Insert(struct Node *p, int index, int x) {
    struct Node *t;
    
    // Validate index
    if(index < 0 || index > Rcount(p))
        return;
    
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    
    // Insert at the beginning
    if(index == 0) {
        t->next = first;
        first = t;
    }
    else {
        for(int i = 0; i < index - 1; i++)
            p = p->next;
        
        t->next = p->next;
        p->next = t;
    }
}

//Adding a new node
void Append(struct Node *p, int x) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    // If the list is empty
    if (first == NULL) {
        first = t;
        return;
    }

    // Traverse to the end of the list
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = t;
}


//deleting
int Delete(struct Node *p,int index)
{
    struct Node *q=NULL;
    int x=-1,i;
    if(index < 1 || index > count(p))
        return -1;
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
        }
    else
    {
        for(i=0;i<index-1;i++)
            {
            q=p;
            p=p->next;
            }
    q->next=p->next;
    x=p->data;
    free(p);
    return x;}
    }


int main(){
    int A[] = {3,2,56,6,3,6,2,6,2,9};
    create(A,10); // To create a LL

  
    printf("The length is :%d\n",Rcount(first));
    printf("The length is :%d\n",count(first));
    // printf(*last);
    printf("The sun of all the elements is: %d\n",Rsum(first));
    printf("the max number is : %d\n", maxnum(first));

    //for search
    LSearch(first,3);
    rSearch(first,3);

    //for adding an element
    Insert(first, 0, 5);
    display(first);

    Append(first, 243);
    Delete(first,3);
    return 0;
    }


