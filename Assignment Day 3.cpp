
                                        // ASSIGNMENT DAY 3

// Question:
// Implement the following functions for a single linked list:
// 1. Insert at end
// 2. Delete from beginning
// 3. Delete from end

#include <iostream>
#include<malloc.h>
#include<stdlib.h>
using namespace std;

struct node
{
    int info;
    struct node *link;    // Node Type Pointer 
};
struct node *START=NULL;  // Node Type Pointer and initially assigned null



void create_node()
{
    struct node *temp,*ptr;
    int n;
    cout<<"\nEnter -1 to Stop Creating the List.\n\n";
    cout<<"Enter the value:";
    cin>>n;
    while(n!=-1)
    {
        
        temp=(struct node *)malloc(sizeof(struct node));
        temp->info=n;
        if (START==NULL)
        {
            START=temp;
            START->link=NULL;
        }
        else
        {
            ptr=START;
            while(ptr->link!=NULL)
                ptr=ptr->link;
            ptr->link=temp;
            temp->link=NULL;
        }
        cout<<"Enter the value: ";
        cin>>n;
    }
    
}

void display()
{
    struct node *ptr;
    if (START==NULL)
        cout<<"\nNo Values to Show\n";
    else
    {
        ptr=START;
        cout<<"\nValues are: \n";
        while (ptr!=NULL)
        {
            cout<<ptr->info<<" ";
            ptr=ptr->link;
        }
        cout<<"\n";
    }
}

void insert_at_end()
{
    struct node *ptr,*cpt;
    cpt=(struct node *)malloc(sizeof(struct node));
    cout<<"\nEnter Value: ";
    cin>>cpt->info;
    ptr=START;
    while( ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=cpt;
    cpt->link=NULL;
}

void delete_at_beg()
{   
    struct node *ptr;
    ptr=START;
    START=START->link;
    cout<<"\nValue Deleted: "<<ptr->info;
    free(ptr);
}

void delete_at_end()
{
    struct node *ptr,*cpt;
    ptr=START;
    while (ptr->link!=NULL)
    {
        cpt=ptr;
        ptr=ptr->link;
    }
    cpt->link=NULL;
    free(ptr);

}

int main()
{
    int i=1,n;
    printf("\n\tSingly Linked List\n");
    while(i==1)
    {
        cout<<"\nPress\n1. To Create Linked List\n2. To Display Linked List elements.\n3. To Insert Value at End\n4. To Delete Value from Begining\n5. To Delete from End\n6. To Exit\n\n";
        cin>>n;

        
        switch (n)
        {
            case 1: create_node();
                    break;

            case 2: display();
                    break;

            case 3: insert_at_end();
                    break;

            case 4: delete_at_beg();
                    break;

            case 5: delete_at_end();
                    break;
                
            case 6: exit(0);  //exit() is defined in <stdlib.h>
        
            default: cout<<"Wrong Input. Please Try Again.\n";
                    break;
        }
    }
    return 0;
}

        