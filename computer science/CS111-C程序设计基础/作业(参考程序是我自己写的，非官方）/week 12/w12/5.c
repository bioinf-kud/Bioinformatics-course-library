#include<stdio.h>
#include<stdlib.h>
void is_palindrome(char*a, FILE* b);
int main(void){
    int n;
    FILE* fptrr;
    FILE* fptrw;
    fptrr=fopen("strs 2.txt","r");
    fptrw=fopen("is_palindrome.txt","a+");
    fputs("",fopen("is_palindrome.txt","w+"));
    char a[300];
    fscanf(fptrr,"%d",&n);
    fgetc(fptrr);
    for(int i=0;i<n;i++){
        fgets(a, 100, fptrr);
        is_palindrome(a,fptrw);
    }
    fclose(fptrr);
    fclose(fptrw);
}
void is_palindrome(char*a, FILE* f){
    int b=0;
    while(*(a+b)!='\0'&&*(a+b)!='\n')
        b++;
    *(a+b)='\0';
    int cnt=0;
    for(int i=0;i<b;i++){
        if(*(a+i)!=*(a+b-i-1))
        cnt++;
    }
    if(cnt==0){
        sprintf(a,"%s YES\n",a);
        fputs(a,f);
    }
    else{
        sprintf(a,"%s NO\n",a);
        fputs(a,f);
    }
}