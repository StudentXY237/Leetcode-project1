#include <stdio.h>
#include<strings.h>

int romanToInt(char s[15]){
    int num = 0;
    int i=0,j,N=7;
    int after=0;
    int current=0;
    char rom[15] = {'I','V','X','L','C','D','M'};
    int arab[15] = {1, 5, 10, 50, 100, 500, 1000};

    while(i < strlen(s)){
        for(j = 0; j < N; j++){
            if(s[i] == rom[j]){
                current = arab[j];
            }
            if(s[i+1] == rom[j]){
                after = arab[j];
            }
        }
        if(current >= after){
            num = num + current;
            i++;
        }
        if(current < after){
            num = num + (after - current);
            i = i + 2;
        }
        after=0;
        current=0;
    }
    return num;
}


int main(){
    char chat[15] = "MDCXCV";

    printf("%d", romanToInt(chat));

    return 0;
}
