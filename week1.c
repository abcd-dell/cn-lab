#include<stdio.h>
#include<string.h>

void bitstuffing(char* a){
    int c=0;
    int i=0;
    for(i=0;i<=strlen(a);i++){
        printf("%c",a[i]);
        if(a[i]=='1') c++;
        else c=0;
        if(c==5){
            printf("0");
            c=0;
        }
    }
    printf("\n");
}

void main(){
char a[20];
printf("Enter binary data");
scanf("%s",a);
bitstuffing(a);
return 0;
}
