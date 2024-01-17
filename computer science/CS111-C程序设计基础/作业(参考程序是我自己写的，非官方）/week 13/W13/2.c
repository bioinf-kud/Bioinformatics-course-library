#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct color{
    int r,g,b;
};
struct color make_color(int r,int g,int b);
int getRed(struct color c);
bool equal_color(struct color c1,struct color c2);
struct color brighter(struct color c);
struct color darker(struct color c);
void prtc(struct color c);
int main(){
    struct color test=make_color(0,243,0);
    prtc(brighter(test));
    prtc(darker(test));
    return 0;
}
struct color make_color(int r,int g,int b){
    struct color a;
    a.r=r;
    a.g=g;
    a.b=b;
    if(a.r>255)
        a.r=255;
    if(a.g>255)
        a.g=255;
    if(a.b>255)
        a.b=255;
    if(a.r<0)
        a.r=0;
    if(a.g<0)
        a.g=0;
    if(a.b<0)
        a.b=0;
    return a;
}
int getRed(struct color c){
    return c.r;
}
bool equal_color(struct color c1,struct color c2){
    if((c1.r==c2.r)&&(c1.g==c2.g)&&(c1.b==c2.b))
        return true;
    else
        return false;
}
struct color brighter(struct color c){
    struct color b=make_color(c.r,c.g,c.b);
    if(c.r==0&&c.g==0&&c.b==0)
        b.r=b.g=b.b=3;
    else{
        if(c.r==0)
            b.r=3;
        if(c.g==0)
            b.g=3;
        if(c.b==0)
            b.b=3;
    }
    b=make_color((int)(b.r/0.7),(int)(b.g/0.7),(int)(b.b/0.7));
    
    return b;
}
struct color darker(struct color c){
    struct color b=make_color((int)(c.r*0.7),(int)(c.g*0.7),(int)(c.b*0.7));
    return b;
}
void prtc(struct color c){
    printf("(%d,%d,%d)\n",c.r,c.g,c.b);
}