#include<stdio.h> 
#include<string.h>

int length(char *str);
void concat(char *str1, char *str2);
void extract(char *str, int pos, int key_len);
void replace(char *str, char *find, char *replace);

void main() 
{
    char str1[20], str2[20];
    int len, choice, pos, key_len;
    while(1)
    {
        strcpy(str1, "Flowers");
        strcpy(str2, " are beautiful");
        printf("\nString 1 = %s\nString 2 = %s\n", str1, str2);
        printf("Enter your choice\n1 : Length\n2 : Concatenate\n3 : Extract\n4 : Replace\n5 : Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 : len = length(str1);
                     printf("Length of the %s is %d\n", str1, len);
                     break;
            case 2 : concat(str1, str2);
                     break;
            case 3 : printf("Enter the position and length of the substring\n");
                     scanf("%d%d", &pos, &key_len);
                     extract(str1, pos-1, key_len);
                     break;
            case 4 : replace(str2, "are", "is");
                     break;
            case 5 : exit();
        }
    }
}

int length(char *str)
{
    int len=0; 
    while(str[len]!='\0')
    {
        ++len;
    }
    return(len); 
}

void concat(char *str1, char *str2)
{
    int i=0,len_str1;
    len_str1 = length(str1);
    while(str2[i]!='\0')
    {
        str1[len_str1++]=str2[i++]; 
    }
    str1[len_str1]='\0';
    printf("\nConcatenated string = %s",str1);
}

void extract(char *str,int pos, int key_len)
{
    int i=0;
    char substr[20]; 
    while(pos<=key_len) 
    {
        substr[i++]=str[pos++]; 
    }
    substr[i]='\0';
    printf("\nSubstring = %s",substr);
}

void replace(char *str, char *find, char *replace)
{
	char new_str[50];
	int str_len, find_len, rep_len;
	int i, j, m=0, k=0;
	int flag, start;
	str_len = strlen(str);
	find_len = strlen(find);
	rep_len = strlen(replace);
	for(i=0;i<str_len;i++)
	{
		j=0;
		flag = 0;
		start = i;
		while(str[i] == find[j])
		{
			if(j==find_len-1)
			{
				flag = 1;
				break;
			}
			i++;
			j++;
		}
		if(flag==0)
		{
			i = i-j;
			new_str[m++] = str[i];
		}
		else
		{
			for(k=start;k<start+rep_len;k++)
			{
				new_str[m++] = replace[k-start];
			}
		}
	}
	new_str[m] = '\0';
	printf("\nThe string after replacing : %s\n", new_str);
}



