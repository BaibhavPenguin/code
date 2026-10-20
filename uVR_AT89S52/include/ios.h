
#ifndef ios_h
#define ios_h



void echo(void);
void print_ready_message(void);
void print_boot_message(void);
void print_wait_message(void);
void print_success_message(void);
void print_invalid_cmd(void);
void terminal_reset(void);

void print_output_buffers_dec(void);
void print_output_buffers_bin(void);


void print_program_enabled_msg(void);
void print_program_entered_msg(void);
void print_program_execution_msg(void);

void print_program_completed_msg(void);
void print_program_error_code(void);
#endif //ios_h
