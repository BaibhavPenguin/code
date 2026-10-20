#ifndef ttl52bool_h
#define ttl52bool_h

#define BOOL(x) (!!(x))

#define true 1
#define false 0

#define set 1
#define reset 0

#define enable 1
#define disable 0


typedef enum {
    _false = 0,
    _true = 1
}_bool;
typedef _bool ttl52_bool;
typedef _bool bool8t;

typedef __bit flag;

#endif //ttl52bool_h
#define is_true_false_defined 1