#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
int main()
{
    int foo,randomize,big;
    char ** ask;
    bool used[10];
    FILE * fp;
    fp = fopen("tiku.txt","r");
    if(fp == NULL) {printf("Ensure there is a tiku.txt within where this program exists!"); getch(); return -1;}
    fscanf(fp,"%d",&big);
    ask = (char**)malloc(sizeof(char*)*big);
    for(foo=0;foo<big;foo++){
        ask[foo] = (char*)malloc(sizeof(char)*1000);
    }
    for(foo=0;foo<big;foo++){used[foo] = false;
    fscanf(fp,"%s",ask[foo]);
    }
    srand((unsigned)time(NULL));
    for(foo = 0;foo < big;foo++){
        do{randomize = (rand()%big);
        }
        while(used[randomize] == true);
        printf("%s\n",ask[randomize]);
        used[randomize] = true;
        getch();
    }
    return 0;
}
