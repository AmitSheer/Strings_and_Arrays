//
// Created by Amit-Sheer Cohen on 23/12/2020.
//

#include "txtfind.h"
#include <stdio.h>
#define LINE 256
#define WORD 30
#define MAX_TEXT_LINES 250

int getWordLen(char* w){
    int len = 0;
    for (; len < WORD; ++len) {
        if(*(w+len)==' '||*(w+len)=='\n'||*(w+len)=='\t'||*(w+len)=='\r'||*(w+len)=='\0')
            return len;
    }
    return WORD;
}
int getLineLen(char* l){
    int len = 0;
    for (; len < WORD; ++len) {
        if(*(l+len)=='\n'||*(l+len)==EOF)
            return len;
    }
    return LINE;
}



int checkSimilar(char* searchWord,char* line, int index, int searchWordLen){
    for (int i = 0; i < searchWordLen; ++i) {
        if(*(line+index+i)!=*(searchWord+i))
            return 0;
    }
    return 1;
}

int similarAfterSub(char* searchWord,char* line, int index, int searchWordLen){
    char subWord[searchWordLen];
    int i =0;
    for (; i < searchWordLen; ++i) {
        if(*(line+index+i)==*(searchWord+i)){
            *(subWord+i) = *(line+index+i);
        }else if(*(line+index+i)!=*(searchWord+i)&&*(line+index+i+1)==*(searchWord+i)){
            *(subWord+i) = *(line+index+i+1);
        }else if(*(line+index+i)!=*(searchWord+i)&&*(line+index+i+1)!=*(searchWord+i)){
            return 0;
        }
    }
    return checkSimilar(searchWord,subWord,0,searchWordLen );
}

void printWord(char* text,int index,int len){
    for (int j = 0; j < len + 1; ++j) {
        printf("%c", *(text+index+j));
    }
    printf("\n");
}
void printSimilarWords(char searchWord[],int len){
    char text[MAX_TEXT_LINES*LINE];
    while(fgets(text, MAX_TEXT_LINES*LINE, stdin)){
        int lineLen = getLineLen(text);
        for (int i = 0; i < lineLen; ++i) {
            if(checkSimilar(searchWord,text, i, len)){
                printWord(text,i,len);
                break;
            }else if(similarAfterSub(searchWord, text,i,len)) {
                    printWord(text,i,len);
            }

            i=i+getWordLen(text+i);
        }
    }
}

void printShowLines(char searchWord[],int len){
    char text[MAX_TEXT_LINES*LINE];
    while(fgets(text, MAX_TEXT_LINES*LINE, stdin)){
        int lineLen = getLineLen(text);
        for (int i = 0; i < lineLen; ++i) {
            if(checkSimilar(searchWord,text, i, len)){
                printf(" %s\n", text);
                break;
            }
            i=i+getWordLen(text+i);
        }
    }
}

int main(){
    char text[MAX_TEXT_LINES*LINE];
    fgets(text,  MAX_TEXT_LINES*LINE, stdin);
    int len = getWordLen(text);
    char searchWord[len];
    for (int i = 0; i < len; ++i) {
        *(searchWord+i) = *(text+i);
    }
    if(*(text+len+1)=='a'){
        printShowLines(searchWord, len);
    }else if(*(text+len+1)=='b'){
        printSimilarWords(searchWord,len);
    }
}