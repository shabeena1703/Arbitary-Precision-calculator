#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *headR1 =NULL;
    node *tailR1=NULL;
    node *headR2=NULL;
    node *tailR2=NULL;

    node *t2=tail2;
    
    int count=0;

    while(t2!=NULL)
    {
        node *t1=tail1;
        int carry=0;
        if(headR1==NULL)
        {
            while(t1!=NULL)
            {
                int product = t1->data * t2->data+carry;
                int digit=product % 10;
                carry=product / 10;
                insert_first(&headR1,&tailR1,digit);
                t1=t1->prev;
            }
            if(carry)
            {
                insert_first(&headR1,&tailR1,carry);
            }
        }
        else
        {
            headR2=tailR2=NULL;
            while(t1!=NULL)
            {
                int product=t1->data * t2->data +carry;
                int digit=product % 10;
                carry = product/10;
                insert_first(&headR2,&tailR2,digit);
                t1=t1->prev;
            }

            if(carry)
            {
                insert_first(&headR2,&tailR2,carry);
            }

            //add zeros
            for(int i=0;i<count;i++)
            {
                insert_last(&headR2,&tailR2,0);
            }

            //add headR1 and headR2
            *headR=NULL;
            *tailR=NULL;
            addition(tailR1,tailR2,headR,tailR);

            while(headR1)
            {
                node *temp=headR1;
                headR1=headR1->next;
                free(temp);
            }
            //update headR1 with headR
            headR1=*headR;
   
            tailR1=*tailR;

            while(headR2)
            {
                node *tmp=headR2;
                headR2=headR2->next;
                free(tmp);
            }
        }
        count++;
        t2=t2->prev;
    }
    *headR=headR1;
    *tailR=tailR1;
    
    

}
