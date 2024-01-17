#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void read(char**a,int n,FILE*f);//读取
int length(char*a);//字符串长度
int count_specific_char(char *a,char c);//特定字母个数
char* max_specific_char(char **a,int n,char c,int max);//返回含特定字母最多字符串指针
int main(){
    FILE *fr;
    FILE *fw;
    int n,max=0;
    char c;
    fr=fopen("strs.txt","r");
    fw=fopen("spec.txt","a+");
    fscanf(fr,"%d",&n);
    fgetc(fr);
    c=fgetc(fr);
    fgetc(fr);
    char**a=(char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++)
        a[i]=(char*)malloc(sizeof(char)*100);
    read(a,n,fr);
    fclose(fr);
    fputs(max_specific_char(a,n,c,max),fw);
    fprintf(fw,"\n%d\n",count_specific_char(max_specific_char(a,n,c,max),c));
    fclose(fw);
    return 0;
}
int length(char*a){
    int cnt=0;
    while(a[cnt]!='\0'){
        if(a[cnt]=='\n'){
            a[cnt]='\0';
            break;
        }
        cnt++;
    }
    return cnt;
}
void read(char**a,int n,FILE*f){
    for(int i=0;i<n;i++)
        fgets(a[i],100,f);
}
int count_specific_char(char *a,char c){
    int l=length(a);
    int cnt=0;
    for(int j=0;j<l;j++)//数特定字母个数
        if(tolower(*(a+j))==c)
            cnt++;
    return cnt;
}
char* max_specific_char(char **a,int n,char c,int max){
    char* maxp=a[0];
    for(int i=0;i<n;i++){
        if(count_specific_char(*(a+i),c)>max){//存储最多重复次数字符串指针
            maxp=*(a+i);
            max=count_specific_char(*(a+i),c);
        }
    }
    return maxp;
}