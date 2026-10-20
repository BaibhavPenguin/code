#include "ll.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

bool init_list(ll *list){
    //State Transition from Uninitialized to Empty.
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return true;
}

bool append_list(ll *list){

    // Add first element to an empty list.
    if(!list->head){
        list->head = (node_t*)calloc(1,sizeof(node_t));
        if(list->head){
            list->head->next = NULL;
            list->tail = list->head;
            list->size = 1;
        };
        return true;
    };

    //Add additional elements to an empty list.
    list->tail->next = (node_t*)calloc(1,sizeof(node_t));
    node_t* new = list->tail->next;
    if(new){
        list->tail = list->tail->next;
        list->size++;
        return true;
    };
    return false;
}













node_t* retrieve_data(ll* list, int index){

    // Semantic Rule - Cannot Retrieve from empty list
    if(!list->head){
        return NULL;
    }

    //Out of Bounds Check
    if(list->size <= index){
        return NULL;
    }

    // Add one element to end of list from tail.
    node_t* node = list->head;      //Retrieval starts at Head of the List
    int node_count = 1;         // IMPORTANT! , im using 1 insted of index 0 because the list head is index 0
    while(node_count <= index){     //Using <= so that all elements are accessible. 
        node = node->next;      
        if(!node){          
            break;
        }
        node_count++;
    }

    return node;

}


bool deallocate_list(ll *list){
    if(!list->head){
        return false;
    };

    node_t* next;
    node_t* current = list->head->next;
    while(current){
        next = current->next;
        free(current);
        current = next;
    }
    
    list->head = NULL;
    list->tail= NULL;
    list->size = 0;
    return true;


}

