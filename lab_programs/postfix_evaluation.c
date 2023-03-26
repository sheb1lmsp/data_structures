#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define maxstk 20
int s[maxstk];
int top = 0;

void push(int item);
int pop();

void main()
{
	char postfix[maxstk], ch;
	int i, op1, op2, res;
	printf("Enter the postfix expression\n");
	scanf("%s", postfix);
	for(i=0;i<strlen(postfix);i++)
	{
		ch = postfix[i];
		if(isdigit(ch))
		{
			push(ch-'0');
		}
		else
		{
			op2 = pop();
			op1 = pop();
			switch(ch)
			{
				case '+': res = op1 + op2;
						  break;
				case '-': res = op1 - op2;
						  break;
				case '*': res = op1 * op2;
						  break;
				case '/': res = op1 / op2;
						  break;
				case '^':
						  res = 1;
						  for(i=1;i<=op2;i++)
						  {
							  res = res * op1;
						  }
						  break;
				default: printf("Invalid character");
			}
			push(res);
		}
	}
	printf("Result of above expression is %d", pop());
}

void push(int item)
{
	++top;
	s[top] = item;
}

int pop()
{
	int item = s[top];
	--top;
	return(item);
}