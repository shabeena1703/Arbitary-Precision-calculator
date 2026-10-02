#include "apc.h"

int division(node *head1, node *head2, node **headR, node **tailR)
{
    *headR=NULL;
    *tailR=NULL;
    int count=0;
    if(compare_list(head1,head2)==OPERAND2)
    {
        return 0;
    }
    while(compare_list(head1,head2)!=OPERAND2)
    {
        *headR=NULL;
        *tailR=NULL;
        subtraction(get_tail(head1),get_tail(head2) ,headR,tailR);
        remove_pre_zeros(headR);

        while(head1)
        {
            node*temp=head1;
            head1=head1->next;
            free(temp);
        }

        head1=*headR;
        count++;
    }
    return count;

}
