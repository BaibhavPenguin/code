#include "core85.h"
#include "stateful.h"
#include <stdlib.h>
#include <stdint.h>

core cpu;                //Define Main CPU Core

void init_core(core* cpux){
    cpux->acc = 0;
    cpux->regb = 0;
    cpux->regc = 0;
    cpux->regd = 0;
    cpux->rege = 0;
    cpux->regh = 0;
    cpux->regl = 0;
    cpux->pc = 0;
    cpux->sp = 0xffff;
    cpux->memory = (uint8_t*)calloc(MAX_ADDRESSABLE_MEMORY,sizeof(uint8_t));
    cpux->port = (uint8_t*)calloc(MAX_PARALLEL_IO_PORTS,sizeof(uint8_t));
} 

void destroy_core(core *c){
    free(c->memory);
    free(c->port);
    c->memory = NULL;
    c->port = NULL;
}

void increment_pc(uint16_t *pc, uint8_t step){
    *pc += step;     //Increment Program Counter by {step}
}

void increment_sp(uint16_t *sp, uint8_t step){
    *sp += step;        //Increment Stack Pointer by {step}
}

void decrement_pc(uint16_t *pc, uint8_t step){
    *pc -= step;
}

void decrement_sp(uint16_t *sp, uint8_t step){
    *sp -= step;
}

