#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    *headR=NULL;
    *tailR=NULL;
    node*t1=tail1;
    node *t2=tail2;
    int carry=0;
    while(t1!=NULL || t2!=NULL)
    {
        int data=0;
        if(t1!=NULL && t2!=NULL)
        {
            data =t1->data + t2->data + carry;
        }
        else if(t1==NULL && t2!=NULL)
        {
            data=t2->data+carry;
        }
        else if(t1!=NULL && t2==NULL)
        {
            data=t1->data+carry;
        }

        int digit=data%10;
        carry=data/10;
        insert_first(headR,tailR,digit);

        if(t1!=NULL)
        {
            t1=t1->prev;
        }
        if(t2!=NULL)
        {
            t2=t2->prev;
        }
    }
    if(carry==1)
    {
        insert_first(headR,tailR,carry);
    }
    
    
}
