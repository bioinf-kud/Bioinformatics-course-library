#include<stdio.h>
#include<stdlib.h>
struct cor{//坐标
    float x,y;
};
struct rect{//长方形
    struct cor a1,a2;//upper left ,lower right
};
float area(const struct rect r);
struct cor center(const struct rect r);
void move(struct rect r,int x,int y);
int ifin(const struct cor p,const struct rect r);
void prtcor(const struct cor p);//打印点
void prtrect(const struct rect r);//打印长方体
int main(){
    struct rect re;
    struct cor p;
    p.x=4;
    p.y=5;
    re.a1.x=3;
    re.a1.y=7;
    re.a2.x=6;
    re.a2.y=4;
    printf("%.2f\n",area(re));
    prtcor(center(re));
    printf("\n");
    move(re,3,4);
    prtrect(re);
    printf("%d",ifin(p,re));
    return 0;
}
float area( const struct rect r){
    float a,b;
    a=r.a2.x-r.a1.x;
    b=r.a1.y-r.a2.y;
    return a*b;
}
struct cor center(const struct rect r){
    struct cor a;
    a.x=(r.a1.x+r.a2.x)/2;
    a.y=(r.a1.y+r.a2.y)/2;
    return a;
}
void move(struct rect r,int x,int y){
    r.a1.x+=x;
    r.a2.x+=x;
    r.a1.y+=y;
    r.a2.y+=y;
}
int ifin(const struct cor p,const struct rect r){
    if((r.a1.x<p.x)&&(r.a2.x>p.x)&&(r.a2.y<p.y)&&(r.a1.y>p.y))
        return 1;//true
    else
        return 0;//false
}
void prtcor(const struct cor p){
    printf("(%.1f,%.1f) ",p.x,p.y);
}
void prtrect(const struct rect r){
    prtcor(r.a1);
    prtcor(r.a2);
    printf("\n");
}