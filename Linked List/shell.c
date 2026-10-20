#include "ll.h"
#include <stdio.h>

int main(){
    ll new_list;
    bool result = init_list(&new_list);
    bool new = append_list(&new_list);
    bool new2 = append_list(&new_list);
    node_t *my_node = retrieve_data(&new_list , 1 );
    printf("Initialization Result %d \n" , result);
    printf("Appending First Element %d \n" , new);
    printf("Appending Second Element %d \n" , new);
    printf("Address of List Header is  %p \n", (void*)new_list.head->next);
    printf("Address of Node at index 1 is %p \n", (void*)my_node);
    printf("Number of Elements in list %d\n",new_list.size);
    deallocate_list(&new_list);
    if(new_list.head || new_list.tail){
        printf("Destruction failed\n");
    }else{
        printf("Linked List was destroyed.\n");
    }
    return 0;
}
