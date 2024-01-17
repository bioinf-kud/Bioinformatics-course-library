#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[20];
    int number;
    int score[4];
    int rank;
};
void initialize(struct student*a,int n,FILE*f);//构造数据
void file_print(struct student*a,int n,FILE*f);//输出结构体
void struct_swap(struct student*a,struct student*b);//结构体交换
int length(char*a);//字符串长度
void swapstr(char*a,char*b);//字符串交换
void copystr(char*a,char*b);//字符串复制
void swap(int *a,int *b);//数字交换
void bsort(struct student*a,int n);//冒泡排序
void total_sort(struct student*a,int n);//插入排序
int main(){
    FILE* fr;
    FILE* fw;
    fr=fopen("name.txt","r");
    fw=fopen("students.txt","a+");
    int n;
    fscanf(fr,"%d",&n);
    fgetc(fr);
    struct student*stu=(struct student*)malloc(sizeof(struct student)*n);
    initialize(stu,n,fr);
    total_sort(stu,n);
    bsort(stu,n);
    file_print(stu,n,fw);
    fclose(fr);
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
void swap(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
void swapstr(char*a,char*b){
    char c[99];
    copystr(c,a);
    copystr(a,b);
    copystr(b,c);
}
void copystr(char*a,char*b){//b--->a
    int la=length(a),lb=length(b);
    if(la>lb){
        for(int i=0;i<la;i++){
            if(i<lb)
                *(a+i)=*(b+i);
            else
                *(a+i)='\0';
        }
    }
    else{
        for(int i=0;i<lb;i++){
            *(a+i)=*(b+i);
        *(a+lb)='\0';
    }
    }
}
void struct_swap(struct student*a,struct student*b){
    swapstr(a->name,b->name);
    swap(&a->number,&b->number);
    swap(&a->rank,&b->rank);
    for(int i=0;i<4;i++)
        swap(&a->score[i],&b->score[i]);
}
void initialize(struct student*a,int n,FILE*f){
    for(int i=0;i<n;i++){
        fgets((a+i)->name,10,f);
    }
    for(int i=0;i<n;i++){
        int c=length((a+i)->name);
    }
    for(int i=0;i<n;i++){
        (a+i)->number=i+1;
        (a+i)->score[3]=0;
        for(int j=0;j<3;j++){
            (a+i)->score[j]=rand()%101;
            (a+i)->score[3]+=(a+i)->score[j];//我把cal_total 整合到initialize里面了
        }
    }     
}
void file_print(struct student*a,int n,FILE*f){
    fprintf(f,"%d\n",n);
    for(int i=0;i<n;i++)
        fprintf(f,"%d %s %d %d %d %d %d\n",(a+i)->number,(a+i)->name,(a+i)->score[0],(a+i)->score[1],(a+i)->score[2],(a+i)->score[3],(a+i)->rank);
}
void bsort(struct student*a,int n){//升序冒泡排序,按照学号排
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if((a+j)->number>(a+j+1)->number)
                struct_swap(a+j,a+j+1);
}
void total_sort(struct student*a,int n){//降序插入排序，按照成绩排
    for(int i=1;i<n;i++)
        for(int j=i-1;j>=0;j--){
            if((a+j)->score[3]<(a+j+1)->score[3])
                struct_swap(a+j,a+j+1);
            else   
                break;
        }
    for(int i=0;i<n;i++){
        (a+i)->rank=i+1;
    }
}