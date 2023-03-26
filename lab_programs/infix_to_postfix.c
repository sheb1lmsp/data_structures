#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define maxstk 20
char s[maxstk];
int top =0;

int precedence(char choice), pop();
void push(char item);

void main()
{
	char infix[maxstk], postfix[maxstk], ch, item;
	int i, j=0;
	printf("Enter the infix expression\n");
	scanf("%s", infix);
	push('#');
	for(i=0;i<strlen(infix);i++)
	{
		ch = infix[i];
		if(isalnum(ch))
		{
			postfix[j++] = ch;
		}
		else if(ch == '(')
		{
			push(ch);
		}
		else if(ch == ')')
		{
			while(s[top] != '(')
			{
				postfix[j++] = pop();
			}
			item = pop();
		}
		else
		{
			while(precedence(s[top])>=precedence(ch))
			{
				postfix[j++] = pop();
			}
			push(ch);
		}
	}
	while(s[top] != '#')
	{
		postfix[j++] = pop();
	}
	postfix[j] = '\0';
	printf("\nPostfix expression is %s", postfix);
}

int precedence(char choice)
{
	switch(choice)
	{
		case '+':
		case '-': return(1);
		case '/':
		case '*': return(2);
		case '^': return(3);
		case '(': 
		case '#': return(0);
	}
}

void push(char item)
{
	++top;
	s[top] = item;
}

int pop()
{
	char item;
	item = s[top];
	--top;
	return(item);
}