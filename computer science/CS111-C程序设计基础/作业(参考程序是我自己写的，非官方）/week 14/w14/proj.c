//本程序为成绩管理系统，第一次使用时需进行初始化，提供班级中的人数信息，之后可以对数据进行处理和维护。
#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[20];
    char gender;
    int number;
    int score[5];//0，1，2语数英 3总分 4平均
    int rank;//排名
};
void struct_swap(struct student*a,struct student*b);//结构体交换
int length(char*a);//字符串长度
void swapstr(char*a,char*b);//字符串交换
void copystr(char*a,char*b);//字符串复制
void swap(int *a,int *b);//数字交换
void total_sort(struct student*a,int n);//插入排序
void file_print(struct student*a,int n,int pn,FILE*f);//输出结构体
void getstr(char*a);//读取字符串
void fgetstr(char*a,FILE*f);//文件读取字符串
void read_data(struct student*a);//读取一名学生的数据
void fread_data(struct student*a,FILE*f);//从文件中读取一名学生的数据
void add(struct student*a,int*pn,int*n);//添加学生
void del(struct student*a,int*pn,int*n);//删除学生
void show(struct student*a,int pn,int n);//在程序中展示学生成绩
void sort(struct student*a,int n);//冒泡排序，可指定排序项目和排序类型
int sort_pattern(int a,int b,int p);
void find(struct student*a,int*pn,int*n);
char sort_base[]="0:姓名 1:学号,2:语文,3:数学,4:英语,5:总分";
char desktop[]="---------------------------------\n************成绩管理*************\n***     1.增加     2.删除     ***\n***     3.显示     4.排序     ***\n***     5.查找     0.退出     ***\n*********************************\n---------------------------------\n";
int main(){
    FILE*fr,*fw,*fa;
    fr=fopen("studen_grad.txt","r+");
    fa=fopen("studen_grad.txt","a+");
    int n/*班级总人数*/,pn/*目前录入的人数*/;
    char a=fgetc(fr);
    struct student*stu;
    printf("欢迎进入学生成绩管理系统！\n");
    if(a==EOF){//初始化
        printf("请输入班级学生总人数:");
        scanf("%d",&n);
        stu=(struct student*)malloc(sizeof(struct student)*n);
        printf("请输入初始化想要登入成绩的学生的个数:");
        scanf("%d",&pn);
        printf("请输入pn个学生数据:(姓名(不能包含空格），学号，性别(F/M)，三科成绩):\n");
        for(int i=0;i<pn;i++){
            getchar();
            read_data(stu+i);
        }
        total_sort(stu,pn);
        printf("初始化完毕。\n");
    }
    else{
        n=(int)(a-'0');
        fscanf(fr,",%d",&pn);
        stu=(struct student*)malloc(sizeof(struct student)*n);
        fgetc(fr);
        for(int i=0;i<pn;i++)
            fread_data(stu+i,fr);
        printf("信息加载完毕。\n");
    }
    while(1){
        int operator;
        printf("%s",desktop);
        scanf("%d",&operator);
        switch(operator){
            case 0://退出
                printf("请问您是否要退出？(Y/N)\n");
                getchar();
                char q;
                scanf("%c",&q);
                if(q=='Y'){
                    fw=fopen("studen_grad.txt","w+");
                    fclose(fw);
                    fprintf(fw,"");
                    
                    file_print(stu,n,pn,fa);
                    printf("数据保存完毕，欢迎下次使用。");
                    return 0;
                }
                else
                    break;
            case 1://添加同学
                add(stu,&pn,&n);
                break;
            case 2://删除同学
                del(stu,&pn,&n);
                break;
            case 3://显示
                show(stu,pn,n);
                break;
            case 4://排序
                sort(stu,pn);
                break;
            case 5://查找
                find(stu,&pn,&n);
                break;
        }
    }
}
void getstr(char*a){
    int cnt=0;
    while(1){
        char c=getchar();
        if(c==' ')
            break;
        *(a+cnt)=c;
        cnt++;
    }
}
void fgetstr(char*a,FILE*f){
    int cnt=0;
    while(1){
        char c=fgetc(f);
        if(c==' ')
            break;
        *(a+cnt)=c;
        cnt++;
    }
}
void read_data(struct student*a){
    getstr(a->name);
    scanf("%d %c %d %d %d",&a->number,&a->gender,&a->score[0],&a->score[1],&a->score[2]);
    a->score[3]=0;
    for(int i=0;i<3;i++)
        a->score[3]+=a->score[i];
    a->score[4]=a->score[3]/3;
}
void fread_data(struct student*a,FILE*f){
    fgetstr(a->name,f);
    fscanf(f,"%d %c %d %d %d %d %d %d\n",&a->number,&a->gender,&a->score[0],&a->score[1],&a->score[2],&a->score[3],&a->score[4],&a->rank);
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
void swapc(char *a,char *b){
    char c=*a;
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
    swapc(&a->gender,&b->gender);
    swap(&a->number,&b->number);
    swap(&a->rank,&b->rank);
    for(int i=0;i<5;i++)
        swap(&a->score[i],&b->score[i]);
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
void file_print(struct student*a,int n,int pn,FILE*f){
    fprintf(f,"%d,%d\n",n,pn);
    for(int i=0;i<pn;i++)
        fprintf(f,"%s %d %c %d %d %d %d %d %d\n",(a+i)->name,(a+i)->number,(a+i)->gender,(a+i)->score[0],(a+i)->score[1],(a+i)->score[2],(a+i)->score[3],(a+i)->score[4],(a+i)->rank);
}
void show(struct student*a,int pn,int n){
    printf("本班级共有%d名学生,已录入%d名\n",n,pn);
    for(int i=0;i<pn;i++)
        printf("姓名:%s 学号:%d 性别:%c 语文:%d 数学:%d 英语:%d 总分:%d 平均分:%d 排名:%d\n",(a+i)->name,(a+i)->number,(a+i)->gender,(a+i)->score[0],(a+i)->score[1],(a+i)->score[2],(a+i)->score[3],(a+i)->score[4],(a+i)->rank);
}
void add(struct student*a,int*pn,int*n){//1
    if(pn==n){
        printf("当前班级已满，请先删除部分数据再进行添加\n");
        return;
    }
    int s;
    int cnt[*n];
    for(int i=0;i<*n;i++)
        cnt[i]=0;
    for(int i=0;i<*pn;i++)
        cnt[(a+i)->number-1]=1;
    printf("当前系统中缺少");
    for(int i=0;i<*n;i++){
        if(cnt[i]==0)
            printf(",%d",i+1);
    }
    printf("号同学的数据\n");
    printf("请输入要添加的一名学生的数据(姓名(不能包含空格），学号，性别(F/M)，三科成绩):\n");
    getchar();
    read_data(a+*pn);
    *pn+=1;
    total_sort(a,*pn);
    printf("添加成功!\n");
}
void del(struct student*a,int*pn,int*n){
    int s;
    int cnt[*n];
    for(int i=0;i<*n;i++)
        cnt[i]=0;
    for(int i=0;i<*pn;i++)
        cnt[(a+i)->number-1]=1;
    printf("当前系统中有");
    for(int i=0;i<*n;i++){
        if(cnt[i]==1)
            printf(",%d",i+1);
    }
    printf("号同学的数据\n");
    printf("请输入想要删除同学的学号:");
    scanf("%d",&s);
    for(int i=0;i<*pn;i++)
        if((a+i)->number==s){
            (a+i)->score[3]=0;
            (a+i)->number=0;
        }
    
    total_sort(a,*pn);
    *pn-=1;
    printf("删除完毕\n");
}
void sort(struct student*a,int n){
    int m,p;
    printf("你想根据什么信息进行排序?%s\n",sort_base);
    scanf("%d",&m);
    printf("按照1升序还是0降序?\n");
    scanf("%d",&p);
    switch(m){
        case 0://姓名
            for(int i=0;i<n-1;i++)
                for(int j=0;j<n-i-1;j++)
                    for(int k=0;k<length((a+j)->name);k++){
                        if(sort_pattern((a+j)->name[k],(a+j+1)->name[k],p)==1){
                            struct_swap(a+j,a+j+1);
                            break;
                        }
                        if(sort_pattern((a+j)->name[k],(a+j+1)->name[k],p)==0)
                            break;
                    };
            break;
        case 1://学号
            for(int i=0;i<n-1;i++)
                for(int j=0;j<n-i-1;j++)
                    if(sort_pattern((a+j)->number,(a+j+1)->number,p)==1)
                        struct_swap(a+j,a+j+1);
            break;
        case 2://语文
        case 3://数学
        case 4://英语
        case 5://总分
            for(int i=0;i<n-1;i++)
                for(int j=0;j<n-i-1;j++)
                    if(sort_pattern((a+j)->score[m-2],(a+j+1)->score[m-2],p)==1)
                        struct_swap(a+j,a+j+1);
            break;
        default:
            break;
    }
    printf("排序完毕！\n");
}
int sort_pattern(int a,int b,int p){//决定排序中的升降序
    if(p==0){
        if(a<b)
            return 1;
        if(a>b)
            return 0;
        return 2;
    }
    else{
        if(a>b)
            return 1;
        if(a<b)
            return 0;
        return 2;
    }
}
void find(struct student*a,int*pn,int*n){
    int s;
    int cnt[*n];
    for(int i=0;i<*n;i++)
        cnt[i]=0;
    for(int i=0;i<*pn;i++)
        cnt[(a+i)->number-1]=1;
    printf("当前系统中有");
    for(int i=0;i<*n;i++){
        if(cnt[i]==1)
            printf(",%d",i+1);
    }
    printf("号同学的数据\n");
    printf("请输入想要查询同学的学号:");
    scanf("%d",&s);
    printf("该同学的信息为:\n");
    for(int i=0;i<*pn;i++)
        if((a+i)->number==s)
            printf("姓名:%s 学号:%d 性别:%c 语文:%d 数学:%d 英语:%d 总分:%d 平均分:%d 排名:%d\n",(a+i)->name,(a+i)->number,(a+i)->gender,(a+i)->score[0],(a+i)->score[1],(a+i)->score[2],(a+i)->score[3],(a+i)->score[4],(a+i)->rank);
}