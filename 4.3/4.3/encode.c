#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

int main()
{
	FILE *in=fopen("in.txt","r");
	FILE *out=fopen("in_crpyt.txt","w");
	char key[100],new[100];
	int i,j,k,flag=0;
	gets(key);
	for(i=0;i<strlen(key);i++)
	{
		for(j=i+1;j<strlen(key);j++)
		{
			if(key[i]==key[j])
			{
				for(k=j;k<strlen(key)-1;k++)
				{
					key[k]=key[k+1];
				}
				key[k]='\0';
			}
		}
	}

	for(i=32;i<=126;i++)
	{
		for(j=0;j<strlen(key);j++)
		{
			if(i==key[j])
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			key[j]=i;
			key[j+1]='\0';
		}
		flag=0;
	}
	flag=0;
	int a,b;
	b=key[0];
	while(strlen(key)>1)
	{
		a=key[flag];
		for(i=flag;i<strlen(key)-1;i++)
		{
			key[i]=key[i+1];
		}
		key[i]='\0';
		flag=(flag+a-1)%strlen(key);
		new[a-32]=key[flag];
	}
	new[flag-32]=b;
	new[flag-31]='\0';
	char c;
	c=fgetc(in);
	while(c!=EOF)
	{
		if(32<=c&&c<=126)
		{
			fprintf(out,"%c",new[c-32]);
		}
		else
		{
			fprintf(out,"%c",c);
		}
		c=fgetc(in);
	}
	fclose(in);
	fclose(out);
	return 0;
}
