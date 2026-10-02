#include "apc.h"

// Function definitions
int is_valid_signed_number(char *str)
{
    int i=0;
    if(str[0]=='+' || str[0]=='-')
    {
        i=1;
    }

    //check remaining characters
    while(str[i]!='\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return FAILURE;
        }
        i++;
    }
    return SUCCESS;
}



int cla_validation(int argc,char *argv[])
{
    if(argc != 4)
    {
        printf("Usage : %s <num1> <op> <num2>\n",argv[0]);
        return FAILURE;
    }

    char op=argv[2][0];
    if(op!='+' && op!='-' && op!='x' && op!='X' && op!='/')
    {
        printf("Invalid operator\n");
        return FAILURE;
    }
    //operand 1 validation
    if(is_valid_signed_number(argv[1])==FAILURE)
    {
        printf("Invalid operand\n");
        return FAILURE;
    }
    //operand 2 validation
    if(is_valid_signed_number(argv[3])==FAILURE)
    {
        printf("Invalid operand\n");
        return FAILURE;
    }

    if(op=='/' && strcmp(argv[3],"0")==0)
    {
        printf("Division by zero not possible\n");
        return FAILURE;
    }
    return SUCCESS;
}




void create_list(char *str,node **head,node **tail)
{
    *head=NULL;
    *tail=NULL;
    int i=0;
    if(str[0]=='+' || str[0]=='-')
    {
        i=1;
    }
    while(str[i]!='\0')
    {
        int data=str[i]-'0';
        insert_last(head,tail,data);        //will be implemented 2 times since create_list is called 2 times
        i++;
    }
}




int insert_last(node **head,node **tail,int data)
{
    node *newNode=malloc(sizeof(node));
    if(newNode==NULL)
    {
        return FAILURE;
    }
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(*head==NULL)
    {
        *head=newNode;
        *tail=newNode;
        return SUCCESS;
    }
    (*tail)->next=newNode;
    newNode->prev=*tail;
    *tail=newNode;
    return SUCCESS;
}



int insert_first(node **head, node **tail, int data)
{
    node *newNode=malloc(sizeof(node));
    if(newNode==NULL)
    {
        return FAILURE;
    }
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    if(*head==NULL)
    {
        *head=newNode;
        *tail=newNode;
        return SUCCESS;
    }
    newNode->next=*head;
    (*head)->prev=newNode;
    *head=newNode;
    return SUCCESS;
}



void print_list(node *head,int flag)
{
    if(head == NULL)
    {
        printf("Head -> 0 <- Tail\n");
        return;
    }
    printf("Result : ");
    printf("Head -> ");
    if(head->data < 0)
    {
        printf("-%d", -head->data);
    }
    else
    {
        printf("%d", head->data);
    }
    head = head->next;
    while (head)
    {
        printf(" <-> %d",head->data);
        head=head->next;
    }
    printf(" <- Tail\n");
    
}




node* get_tail(node *head)
{
    while (head && head->next)
    {
        head = head->next;
    }
    return head;
}






int compare_list(node *head1,node *head2)
{
    node *t1=head1;
    node *t2=head2;
    int list1_count=0;
    int list2_count=0;

    while(t1!=NULL)
    {
        list1_count++;
        t1=t1->next;
    }

    while(t2!=NULL)
    {
        list2_count++;
        t2=t2->next;
    }

    if(list1_count > list2_count)
    {
        return OPERAND1;
    }
    if(list1_count < list2_count)
    {
        return OPERAND2;
    }
    t1=head1;
    t2=head2;
    while(t1!=NULL && t2!=NULL)
    {
        if(t1->data > t2->data)
        {
            return OPERAND1;
        }
        if(t1->data < t2->data)
        {
            return OPERAND2;
        }
        t1=t1->next;
        t2=t2->next;
    }
    return SAME;
}





void remove_pre_zeros(node **head)
{
    while (*head && (*head)->data == 0 && (*head)->next != NULL)
    {
        node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}
