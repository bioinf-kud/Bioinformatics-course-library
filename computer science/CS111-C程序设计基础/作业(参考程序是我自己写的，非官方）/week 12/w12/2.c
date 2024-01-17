#include<stdio.h>
#include<stdlib.h>
void read(int**a,int m,int n,FILE*f);//读取
int max(int**a,int m,int n);//遍历找最大值
void transout(int**a,int m,int n,FILE*f);
int main(){
    FILE*fr;
    FILE*fw;
    fr=fopen("matrix.txt","r+");
    fw=fopen("matrix.txt","a+");
    int m,n;
    fscanf(fr,"%d %d",&m,&n);
    int**a=(int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++)
        a[i]=(int*)malloc(sizeof(int*)*n);
    read(a,m,n,fr);
    fclose(fr);
    fprintf(fw,"%d\n",max(a,m,n));
    transout(a,m,n,fw);
    fclose(fw);
}
void read(int**a,int m,int n,FILE*f){
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            fscanf(f,"%d",*(a+i)+j);
}
int max(int**a,int m,int n){
    int max=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(*(*(a+i)+j)>max)
                max=*(*(a+i)+j);
    return max;
}
void transout(int**a,int m,int n,FILE*f){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            fprintf(f,"%d ",*(*(a+j)+i));
        fprintf(f,"\n");
    }
}