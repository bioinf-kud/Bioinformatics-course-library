#include<stdio.h>
#include<stdlib.h>
int main(){
    char c;
    FILE*fr;
    FILE*fw;
    fr=fopen("input.txt","r");
    fw=fopen("output.txt","w+");
    while(1){
        c=fgetc(fr);
        if(c==EOF)
            break;
        fputc(c,fw);
    }
    fclose(fr);
    fclose(fw);
}