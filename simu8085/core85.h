#ifndef core85_h
#define core85_h

#include <stdint.h>
#include <sys/types.h>

#define ADDRESSABLE_RANGE 65536
#define IO_RANGE 256
#define sclear 0



typedef struct core {
    uint8_t acc;
    uint8_t regb;
    uint8_t regc;
    uint8_t regd;
    uint8_t rege;
    uint8_t regh;
    uint8_t regl;
    uint16_t pc;
    uint16_t sp;

    uint8_t flag_reg;

    uint8_t trap;
    uint8_t rst7;
    uint8_t rst6;
    uint8_t rts5;
    uint8_t hold;
    uint8_t hlda;

    uint8_t *memory;
    uint8_t *port;

} core;


void init_core(core* c);
void destroy_core(core* c);

void set_cpu_state();
void reset_cpu_state();

static inline void set_cy(uint8_t *flag_reg);     //Set CY Flag
static inline void set_pa(uint8_t *flag_reg);     //Set Parity Flag
static inline void set_ac(uint8_t *flag_reg);     //Set Auxiliary Carry Flag
static inline void set_ze(uint8_t *flag_reg);     //Set Zero Flag
static inline void set_si(uint8_t *flag_reg);     //Set sign Flag


static inline void reset_cy(uint8_t *flag_reg);     //Set CY Flag
static inline void reset_pa(uint8_t *flag_reg);     //Set Parity Flag
static inline void reset_ac(uint8_t *flag_reg);     //Set Auxiliary Carry Flag
static inline void reset_ze(uint8_t *flag_reg);     //Set Zero Flag
static inline void reset_si(uint8_t *flag_reg);     //Set sign Flag

static inline void increment_pc(uint16_t *pc , uint8_t step );
static inline void increment_sp(uint16_t *sp , uint8_t step);
static inline void increment_reg(uint8_t *reg , uint8_t *flag_reg  , uint8_t step);

static inline void decrement_reg(uint8_t *reg , uint8_t *flag_reg  , uint8_t step);
static inline void decrement_pc(uint16_t *pc , uint8_t step );
static inline void decrement_sp(uint16_t *sp , uint8_t step);

uint8_t read(core *c , uint16_t addr);
void write(core *c , uint16_t addr, uint8_t data);

extern core cpu;            // Global Simpleton CPU in .bss

#endif // core85_h