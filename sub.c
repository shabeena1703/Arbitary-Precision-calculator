#include "apc.h"

void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    *headR=NULL;
    *tailR=NULL;
    node *t1=tail1;
    node *t2=tail2;
    int borrow=0;
    while(t1!=NULL || t2!=NULL)
    {
        int data=0;
        if(t1!=NULL && t2!=NULL)
        {
            if(t1->data-borrow >=t2->data)
            {
                data=(t1->data-borrow)-t2->data;
                borrow=0;
            }
            else
            {
                data=(t1->data-borrow+10)-t2->data;
                borrow=1;
            }
        }
        else if(t1==NULL && t2!=NULL) //since t1 is null,dont access t1_data
        {
            if(0-borrow >=t2->data)
            {
                data=(0-borrow)-t2->data;
                borrow=0;
            }
            else
            {
                data=(0-borrow+10)-t2->data;
                borrow=1;
            }
        }

        else if(t1!=NULL && t2==NULL)
        {
            if(t1->data-borrow >= 0)    //since t2 is null,dont access t2->data
            {
                data=(t1->data-borrow)-0;
                borrow=0;
            }
            else
            {
                data=(t1->data-borrow + 10)-0;
                borrow=1;
            }
        }
        insert_first(headR,tailR,data);

        if(t1!=NULL)
        {
            t1=t1->prev;
        }
        if(t2!=NULL)
        {
            t2=t2->prev;
        }
    }
        
}
