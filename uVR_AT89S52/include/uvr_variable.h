#ifndef uvr_variable_h
#define uvr_variable_h

#define buffer_ptr 0x40  //Starting Address of Program Buffer

// "__data" is used for placing the variables in Internal RAM of At89S52 00H to FFH
// Refer to 89S52MAP.txt for viewing the Memory Map

//=============================== PAGE ONE VARIABLES ============================================
volatile unsigned char __data __at (0x30) loop_counter = 0; //Store Loop Counters

volatile unsigned char __data __at (0x31)  ip_buffer_agent; //Input Buffer Agent
volatile unsigned char __data __at (0x32)  *rd_pointer;
volatile unsigned char __data __at (0x33)  *wr_pointer;

volatile unsigned char __data __at (0x34)  system_tick = 0; //Common System Time
volatile unsigned char __data __at (0x35) op1 = 0; //Operand Buffer
volatile unsigned char __data __at (0x36) op2 = 0; //perand Buffer
volatile unsigned char __data __at (0x37)  err_handler = 0; //To Calculate Timer Differences

volatile unsigned char __data __at (0x38) temp0 = 0;
volatile unsigned char __data __at (0x39) temp1 = 0;
volatile unsigned char __data __at (0x3A) temp2 = 0; //Temporary Variables
volatile unsigned char __data __at (0x3B) temp3 = 0;
volatile unsigned char __data __at (0x3C) virtual_program_counter = 0;

volatile unsigned char __data __at (0x3D) instruction_buffer = 0;
volatile unsigned int __data __at (0x3E) result = 0;


//=============================== MULTIPLEXED BUFFER ===========================================

volatile unsigned char __data __at (0x40) input_buffer[32] = {0};
volatile unsigned char __data __at (0x60) virtual_data_stack[8][2] = {{0}};
volatile unsigned char __data __at(0x71) local_loop_stack[2] = {0};
volatile unsigned char __data __at(0x73) local_conditional_stack[2] = {0};
volatile unsigned char __data __at (0x75) result_char_buffer[5] = {'0'};
volatile unsigned int __data __at(0x7A) temp_integer = 0;

volatile unsigned int __data __at(0x7C) xword = 0;
volatile unsigned char __data __at(0x7E) op3 = 0;
volatile unsigned char __data __at(0x7F) op4 = 0;


volatile unsigned char __idata __at(0x80) virtual_call_stack[4][2] = {{0}};
volatile unsigned char __idata __at(0x88) program_buffer[80] = {0};





//============================== FLAGS ===========================
__bit __at(0x00) is_recieved;
__bit __at(0x01) is_programmed;
__bit __at(0x02) is_error;
__bit __at(0x03) echo_e;
__bit __at(0x04) is_success;
__bit __at(0x05) machine_state;
__bit __at(0x06) is_looping;
__bit __at(0x07) backspace_block;
__bit __at(0x08) state_programming_enabled;
__bit __at(0x09) is_requesting_syscall_access;
__bit __at(0x10) state_executing_script;
__bit __at(0x11) is_input_buffer_reset;
\

#endif //uvr_variable_h
