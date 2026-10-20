#ifndef stringd_h
#define stringd_h

#include <stdbool.h>

#define NULLTERM '\0'

typedef struct String String;
typedef struct str str;

struct String{
    char *chars;
    int length;
    int capacity;
    char buffer[16];
    bool is_long;
};

struct str {
    char chars[128];
    int length;
    int capacity;
    bool is_long;
};

String* ToString(str *s);

bool Stringd(String *s, char *c);
String* AppendS(String* s);
String* Strcpy(String *s);
int Strlen(String *s);
int SCap(String* s);
bool Strcmp(String *s);

void Print(String* s);
void strPrint(str *s);

//void Split(String *s , char c);
//void Strip(String *s , char c);
void Trunc(String *s);




#endif //stringd_h