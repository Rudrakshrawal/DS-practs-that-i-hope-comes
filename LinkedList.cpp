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
struct Node * LSearch(struct Node *p, int key){
  while (p!=NULL){
      if(key==p->data)
        return p;
      p=p->next;
  }
  return NULL;
}
//Recursive Linear search
//Inserting an element at last
//Sorted linked list
//deleting
//removing duplicates
//reversing LL
// concatenating
//doubly LL
//comparision

int main(){
    int A[] = {3,2,56,6,3,6,2,6,2,9};
    create(A,10); // To create a LL

  
    printf("The length is :%d\n",Rcount(first));
    printf("The length is :%d\n",count(first));
    // printf(*last);
    printf("The sun of all the elements is: %d\n",Rsum(first));
    printf("the max number is : %d\n", maxnum(first));

        // foR LSearch
    struct Node *temp; // A temp node 
    temp=LSearch(first,3);
    if(temp)
        printf("Key is Found %d\n", temp->data);
    else
        printf("Key is not found");

  
    return 0;
    }


