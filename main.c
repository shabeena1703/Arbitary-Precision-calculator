/*NAME: SHAIK SHABEENA
REGISTRATION NO : 25048_004

DESCRIPTION :
This project implements an Arbitrary Precision Calculator that performs arithmetic operations (Addition, Subtraction, Multiplication, Division) 
on numbers of any length, even numbers that exceed the limits of built‑in C data types.
To achieve this, each number is stored as a doubly linked list, where each node contains one digit.
All operations are performed digit‑by‑digit, similar to how calculations are done manually on paper.
The program accepts input in the format:    
										./a.out <number1> <operator> <number2>

                                              //apc.h
* This file defines all the core components required for the Arbitrary Precision Calculator.
  It contains :
  1.node structure :
	. Represents one digit of a large number
	. Has prev and next pointers (doubly linked list)

  2.Macros: SUCCESS, FAILURE,SAME, OPERAND1, OPERAND2 (used for comparing numbers)

  3.Function declarations : 
	addition(), subtraction(), multiplication(), division() cla_validation(), 
	is_valid_signed_number(),create_list(), insert_first(), insert_last() compare_list(), remove_pre_zeros(), print_list(), get_tail()


* This file acts as the blueprint of the project.
* It tells every .c file what data structures and functions exist.


                                                        //apc.c
* This file contains the supporting logic needed by all arithmetic operations.
* It handles input checking, creates digit‑by‑digit linked lists, and provides all basic list operations needed for big‑number arithmetic.


                                                     //main.c
* This file controls the entire flow of the calculator.
* What happens here :
	- Validates input using cla_validation()
	- Extracts signs of both numbers
	- Creates linked lists for both operands
	- Checks the operator and calls the correct arithmetic function:
	- Applies sign rules to the result
	- Removes leading zeros
	- Prints the final answer
* This file acts as the controller.
* It decides what operation to perform and how to display the final result.



                                                        //add.c
* This file contains the logic for adding two large numbers.
  1. Start from the last digit of both numbers (tail nodes).
  2. Add the digits along with carry.
  3. Take the last digit of the sum → insert at the front of result list.
  4. Move to previous digits and continue.
  5. If one number ends, continue with remaining digits.
  6. If carry remains at the end → insert it.



                                                       //sub.c
* This file contains the logic for subtracting one large number from another.
  1. Starts from the last digit
  2. If needed, borrows from the next digit
  3. Computes:(digit1 - borrow) - digit2
  4. Inserts each result digit at the front
  5. Continues until all digits are processed
* Assumes first number ≥ second number
* main.c decides which number should be subtracted from which
* it implements manual subtraction with borrow logic for large numbers.



                                                  //mul.c
* This file contains the logic for multiplying one large number with another
  1. For each digit of the second number:
	 - Multiply it with all digits of the first number
	 - Build a partial result list
     - Handle carry
  2. Add required number of zeros (shifting)
  3. Add partial result to accumulated result using addition()
  4. Free temporary lists to avoid memory leaks

Purpose:
Allows multiplication of very large numbers using linked lists.




                                             //div.c
* This file performs division of big numbers using repeated subtraction.
  1. Compare dividend and divisor.
  2. If dividend < divisor → quotient = 0.
  3. While dividend ≥ divisor:
		- Subtract divisor from dividend using subtraction().
		- Remove leading zeros.
		- Increase quotient count.

  4. Return the quotient.
  5. main.c applies the correct sign.



* This APC project proves that unlimited‑size arithmetic can be implemented using linked lists and modular C programming.

*/
#include "apc.h"

int main(int argc, char *argv[])
{
	if(cla_validation(argc,argv)==FAILURE)
	{
		return 0;
	}
    node *head1 = NULL,*tail1 = NULL;
	node *head2 = NULL, *tail2 = NULL;
	node *headR = NULL, *tailR = NULL;

    char oper = argv[2][0];
	char *str1=argv[1];
	char *str2=argv[3];

	int sign1 = 1;
	int sign2 = 1;
	if(str1[0]=='-')
	{
		sign1 = -1;
	}
	if(str2[0]=='-')
	{
		sign2 = -1;
	}


	create_list(str1,&head1,&tail1);
	create_list(str2,&head2,&tail2);


    switch(oper)
    {
		case '+':
		{
			if(sign1==sign2)
			{
				addition(tail1, tail2, &headR, &tailR);
				remove_pre_zeros(&headR);
				if(sign1 == -1)
				{
					headR->data=-headR->data;
				}
			}
			else
			{
				int ret=compare_list(head1,head2);
				if(ret==SAME)
				{
					insert_first(&headR,&tailR,0);
				}
				else if(ret==OPERAND1)
				{
					subtraction(tail1,tail2,&headR,&tailR);
					remove_pre_zeros(&headR);
					if(sign1==-1)
					{
						headR->data = -headR->data;
					}
				}
				else
				{
					subtraction(tail2,tail1,&headR,&tailR);
					remove_pre_zeros(&headR);
					if(sign2==-1)
					{
						headR->data=-headR->data;
					}
				}
			}
			print_list(headR,0);
			break;
		}
			

		case '-':
		{
			if(sign1 != sign2)
			{
				addition(tail1,tail2,&headR,&tailR);
				remove_pre_zeros(&headR);
				if(sign1 == -1)
				{
					headR->data= -headR->data;
				}
			}
			else
			{
				int ret=compare_list(head1,head2);
				if(ret==SAME)
				{
					insert_first(&headR,&tailR,0);
				}
				else if(ret==OPERAND1)
				{
					subtraction(tail1,tail2,&headR,&tailR);
					remove_pre_zeros(&headR);
					if(sign1 == -1)
					{
						headR->data=-headR->data;
					}
				}
				else
				{
					subtraction(tail2,tail1,&headR,&tailR);
					remove_pre_zeros(&headR);
					if(sign1 ==1)
					{
						headR->data=-headR->data;

					}
				}
			}
			print_list(headR,0);
			break;
		}

		case 'x':
		case 'X':
		{
			multiplication(tail1, tail2, &headR, &tailR);

			remove_pre_zeros(&headR);
			if(sign1 !=sign2)
			{
				headR->data=-headR->data;
			}
			print_list(headR,0);
			break;
		}

		case '/':
		{
			int q = division(head1,head2,&headR,&tailR);
			if(sign1!=sign2)
			{
				q=-q;
			}
			printf("Quotient = %d\n",q);
			break;
		}

		default:
			printf("Invalid operator\n");
	}
	return 0;
}

