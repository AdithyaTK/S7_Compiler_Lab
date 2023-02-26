#include<stdio.h>
#include<ctype.h>
#include<string.h>
void main()
{
	int i,j,flag,l=0;
	char ch,str1[20];
    FILE *input;
	input=fopen("input.txt","r");
	char keyword[20][20]={"void","int","main","if","else","while","do","return","for","prinf"};
	while(!feof(input))
	{
		i=0,flag=0;
		ch=fgetc(input);
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='=')
		{
			printf("\n%d\t%c\t operator",l,ch);
		}
		else if(ch=='@'||ch=='{'||ch=='}'||ch=='('||ch==')'||ch=='?'||ch=='%'||ch=='!'||ch==';')
		{
			printf("\n%d\t%c\t Special character",l,ch);
		}
		else if(ch==' ')
		{
			while(ch==' ')
			{
				ch=fgetc(input);
			}
		}
		else if(isdigit(ch))
		{
			while(isdigit(ch))
			{
				str1[i]=ch;
				i++;
				ch=fgetc(input);
			}
			str1[i]='\0';
			printf("\n%d\t%s\t Digit",l,str1);
		}
		else if(isalpha(ch))
		{
			while(isalnum(ch))
			{
				str1[i]=ch;
				i++;
				ch=fgetc(input);
			}
			str1[i]='\0';
			for(j=0;j<20;j++)
			{
				if(strcmp(keyword[j],str1)==0)
				{
					flag=1;
				}
			}
			if(flag==1)
			{
				printf("\n%d\t%s Keyword",l,str1);
			}
			else
				printf("\n%d\t%s identifier",l,str1);
			
		}
		else if(ch=='\n')
			l++;
	}
}