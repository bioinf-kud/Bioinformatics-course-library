#include<stdio.h>
#include<stdlib.h>
void read(int*a,int n,FILE*f);
int vecdot(int*a,int*b,int n);
int main(){
    FILE* fr;
    FILE* fw;
    fr=fopen("vec.txt","r+");
    fw=fopen("vec.txt","a+");
    int n;
    fscanf(fr,"%d",&n);
    fgetc(fr);
    int*a=(int*)malloc(sizeof(int)*n);
    read(a,n,fr);
    int*b=(int*)malloc(sizeof(int)*n);
    read(b,n,fr);
    fclose(fr);
    fprintf(fw,"dot:%d\n",vecdot(a,b,n));
    fclose(fw);
    return 0;
}
void read(int*a,int n,FILE*f){
    for(int i=0;i<n;i++)
        fscanf(f,"%d",a+i);
}
int vecdot(int*a,int*b,int n){
    int cnt=0;
    for(int i=0;i<n;i++)
        cnt+=*(a+i)*(*(b+i));
    return cnt;
}