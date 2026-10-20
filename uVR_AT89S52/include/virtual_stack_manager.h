#ifndef virtual_stack_manager_h
#define virtual_stack_manager_h

#define data_stack_limit 8
#define symbol 0
#define data_segment 1

#define loop_var 0
#define return_addr 1

#define condition 0
#define skip_addr 1



#define call_stack_limit 4
#define block_seg 0


static unsigned char fetch_data_variable(unsigned char);
static void create_data_variable(unsigned char);
static void assign_data_variable(unsigned char,unsigned char);

static unsigned char fetch_variable_slot(unsigned char);


static unsigned char fetch_block_address(unsigned char);
static void allocate_callable_block(unsigned char,unsigned char);


static void reset_stack(void);

#endif //virtual_stack_manager_h