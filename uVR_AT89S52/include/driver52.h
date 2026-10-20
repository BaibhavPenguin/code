#ifndef driver52_h
#define driver52_h


void init_sys(void);
void init_timer(void);
void init_serial(void);
void uart_send(unsigned char);
void start_timer(void);
void start_interrupts(void);
void flush_inp_buffer(void);


#endif //driver52_h
