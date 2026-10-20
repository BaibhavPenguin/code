#include "stringd.h"
#include <stdbool.h>
#include <stdio.h>
//#include <stdlib.h>

bool Stringd(String* s, char* c){
    s->length = 0;
    s->capacity = 0;
    while(*c){
        s->length++;
        c++;
    };
    if(s->length){
        s->capacity = s->length * sizeof(char);
    };
    
    return true;
}

int main(){
    char strings[] = "Hello,World123";
    String stringds;
    bool result = Stringd(&stringds,strings);
    printf("Length of string %d\n",stringds.length);
    printf("Size of string in bytes %d\n",stringds.capacity);
    return 0;
}