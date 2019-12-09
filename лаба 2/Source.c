#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1024
char c;
char *ptr;
char filestr[MAXLINE];

void res(void);
void text(void);
void body(void);

void body(void) {
	FILE *frd, *fwr;
	char *filestr_ptr;
	frd = fopen("text.txt", "rt");
	fwr = fopen("res.txt", "w");
	if (frd == NULL) {
		printf("File hasn't been opened");
		return;
	}
	while (!feof(frd)) {
		filestr_ptr = fgets(filestr, MAXLINE, frd);
		if (filestr_ptr == NULL)
			break;
		while (*filestr_ptr != '\0')
		{
			c = *filestr_ptr;
			if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0')
			{
				fprintf(fwr, "!");
			}
			else
			{
				fprintf(fwr, "%c", c);
			}
			++filestr_ptr;
		}
		fprintf(fwr, "\0");
	}
	fclose(frd);
	fclose(fwr);
}

void text(void)
{
	FILE *fp;
	fp = fopen("text.txt", "rt");
	if (fp == NULL) 
	{
		printf("FILE HAS NOT BEEN OPENED");
		exit(1);
	}
	while (!feof(fp))
	{
		c = fgetc(fp);
		printf("%c", c);
	}
	fclose(fp);
}

void res(void)
{
	FILE *fp;
	fp = fopen("res.txt", "rt");
	if (fp == NULL)
	{
		printf("FILE HAS NOT BEEN OPENED");
		exit(1);
	}
	while (!feof(fp))
	{
		c = fgetc(fp);
		printf("%c", c);
	}
	fclose(fp);
}

int main(void) {
	printf("Current contents of the file text.txt:\n");
	text();
	body();
	printf("\nResult of processing (res.txt):\n");
    res();
	getchar(); getchar();
	return 0;
}