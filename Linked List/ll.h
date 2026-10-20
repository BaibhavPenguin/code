#ifndef LL_H
#define LL_H

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct ll ll;
typedef struct node_t node_t;


struct node_t{
    int arr[100];
    node_t* next;
};

struct ll {
    node_t* head;
    node_t* tail;
    int size;
};


bool init_list(ll *list);
bool deallocate_list(ll *list);
bool append_list(ll *list );
node_t* retrieve_data(ll *list, int index);


#endif //LL_H