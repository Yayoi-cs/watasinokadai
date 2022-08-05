#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<termios.h>
#include<unistd.h>
#define N 1024
int keydata;
int t = 0;int m = 0;int i = 0;
char a[2048];
char f[2048][2048];
char ch;
char b[2048];
char c[2048];
char s[N];
char *find;
int line = 0;
FILE *fp;
int addword(){
	for(int f = 0; f < 1024; f++){
		a[f]='\0';
	}
	fgets(a, 1024, stdin);
}
int Myfunction(keydata){
	printf("selected key: %d\n", (char)keydata);
	if (keydata == 1){
		printf("open file in read mode\n");
		fp = fopen("Mywordshistory.txt", "r");
		if (fp == NULL){
			printf("Error\nFinish the program");
			return 1;
		}
		else{
			printf("  --successful\n");
		}
		while((ch = fgetc(fp)) != EOF){
				putchar(ch);
		}
		fclose(fp);
		return 1;
	}
	if (keydata == 2){
		printf("open file\n");
		fp = fopen("Mywordshistory.txt", "a");
		if (fp == NULL){
			printf("Error\nFinish the program");
			return 1;
		}
		else{
			printf("  --successful\n");
		}
		printf("put a key you want to add\n");
		addword();
		fgets(a, 1024, stdin);
		strcat(a, " 0");
		for(;(char)a[i] != '0';i++){
			if((char)a[i] == ' '){
				for(;t < i;t++){
					f[m][t]=a[t];
				}
			t++;m++;
			}
		}
		for(int j = 0;j < m;j++){
			for(int y = 0;y < i;y++){
				fprintf(fp, "%c", f[j][y]);
				printf("%c", f[j][y]);
			}
		fputc('\n', fp);
		printf("\n");
		}
	}
	if (keydata == 3){
		fp = fopen("Mywordshistory.txt", "r");
		if (fp == NULL){
			printf("Error\nFinish the program");
			return 1;
		}
		else{
			char *command = "sort -f Mywordshistory.txt -o Mywordshistory.txt";
			int res;
			res = system(command);
		}
	}
	if (keydata == 4){
		fp = fopen("Mywordshistory.txt", "r");
		if (fp == NULL){
			printf("Error\nFinish the program");
			return 1;
		}
		else{
			char *command = "sort -u Mywordshistory.txt -o Mywordshistory.txt";
			int res;
			res = system(command);
		}
	}
	else{
		return 0;
	}
	fclose(fp);
}
int main(void){
	printf("program action\n");
	printf("--------------------------------\n");
	printf("program action successful\n");
	printf("--------------------------------\n");
	printf("show history           --- put 1 key\n");
	printf("add new word           --- put 2 key\n");
	printf("sort words             --- put 3 key\n");
	printf("remove duplicate words --- put 4 key\n");
	printf("exit                   --- put 5 key\n");
	printf("--------------------------------\n");
	printf(">");
	scanf("%d",&keydata);
	if(keydata == 5){
		printf("quit program\n");
		return 0;
	}
	Myfunction(keydata);
	return 0;
}
