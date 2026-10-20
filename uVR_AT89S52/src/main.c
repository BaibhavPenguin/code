#include "at89s52_reg.h"
#include "uvr_variable.h"
#include "uvr_const.h"
#include "ios.h"
#include "parser.h"
#include "command.h"
#include "driver52.h"
#include "system_core.h"
#include "flags.h"
#include "virtual_stack_manager.h"
#include "handlers.h"

void init_sys(void){
	EA = enable;
	ES = enable;
	ET2 = enable;
	machine_state = state_listener;
	is_recieved = false;
	is_error = false;
	echo_e = false;
	wr_pointer = &input_buffer[0];
	rd_pointer = &input_buffer[0];
	ip_buffer_agent = reset;
	backspace_block = true;
	state_programming_enabled = false;
	state_executing_script = false;
	is_requesting_syscall_access = false;
	is_input_buffer_reset = false;
	is_programmed = false;

	local_conditional_stack[skip_addr] = 255;
	local_loop_stack[return_addr] = 255;
	err_handler = NO_ERROR;

	is_looping = false;
	//Error Codes
	
} 
void init_timer(void){
	//using Timer 2 in 16-Bit Auto Reload Mode 50ms tick
	T2CON = 0x00;
	RCAP2H = timer_h;
	RCAP2L = timer_l;
	TH2 = timer_h;
	TL2 = timer_l;
	TR2 = enable;


}
void init_serial(void){
	/* Uses Timer 1 in  8-Bit Autoreload Mode */
	TMOD = 0x20;				//Set TMOD to Use Timer 1 in 8 Bit Auto Reload
	TH1 = serial_baud_timer;	//Set Reload value
	TL1 = serial_baud_timer;	//Set Initial Value
	TR1 = enable;					//Start Timer 1
	SCON = 0x50;				//Serial Mode 1 , 8 Bit UART
	TI = set;
	RI = reset;
}
void flush_inp_buffer(void){
	ip_buffer_agent = reset;
	rd_pointer = &input_buffer[0];
	wr_pointer = &input_buffer[0];
	loop_counter = reset;
	while(loop_counter < buffer_size){
		input_buffer[loop_counter] = 0;
		loop_counter++;
	};
	loop_counter = reset;
	is_input_buffer_reset = true;
}

void software_delay(void) __critical{
	unsigned int tempY;
	unsigned int tempX;
	
		for(tempX = 0 ; tempX < temp_integer ;tempX++){
			for(tempY = 0 ; tempY < 1275 ; tempY++){
					;
			};
		};

	
		
	return;
} 


void uart_send(char dat){
	while(!TI);
	SBUF = dat;
	TI = reset;
}
void echo(void){
	while(!is_recieved);

	if(echo_e){
		uart_send(backspace);
		return;
	};
	switch(*rd_pointer){
		case 0x0D:
			uart_send('\n');uart_send('\r');
			backspace_block = true;
		default:
			uart_send(*rd_pointer);
			
	};
	
	

}
void input_char_serial_polling(void){
	ES = reset;
	while(!RI);
	temp0 = SBUF;
	RI = reset;
	ES = set;
}
void print_invalid_cmd(void){
	loop_counter = reset;
	while(loop_counter != len_error_code){
		uart_send(error_msg[loop_counter]);
		loop_counter++;
	};

	loop_counter = reset;
	while(loop_counter != len_invalid_cmd_msg){
		uart_send(invalid_msg[loop_counter]);
		loop_counter++;
	}

	return;
}
void print_boot_message(void){
	loop_counter = reset;
	while(loop_counter != len_boot_message){
		uart_send(boot_message[loop_counter]);
		loop_counter++;
	};
	loop_counter = reset;
}
void print_ready_message(void){
	loop_counter = reset;
	while(loop_counter != len_ready_message){
		uart_send(ready_msg[loop_counter]);
		loop_counter++;
	};
	loop_counter = reset;
}

void print_success_message(void){
	loop_counter = reset;
	while(loop_counter != len_success_msg){
		uart_send(success_msg[loop_counter]);
		loop_counter++;
	};
	loop_counter = reset;
}
void print_output_buffers_dec(void){
	loop_counter = reset;
	if(temp_integer == 0){
		uart_send('0');
		uart_send('\r');uart_send('\n');
		is_success = true;
		return;
	};

	while(temp_integer > 0){
		result_char_buffer[loop_counter] = (temp_integer % 10) + 0x30;
		temp_integer /= 10;
		loop_counter++;
	};

	uart_send(result_char_buffer[4]);
	uart_send(result_char_buffer[3]);
	uart_send(result_char_buffer[2]);
	uart_send(result_char_buffer[1]);
	uart_send(result_char_buffer[0]);
	uart_send('\r');uart_send('\n');
	is_success = 1;
	result_char_buffer[0] = 0;
	result_char_buffer[1] = 0;
	result_char_buffer[2] = 0;
	result_char_buffer[3] = 0;
	result_char_buffer[4] = 0;
	return;
	
}
void print_output_buffers_bin(void){

	while(temp_integer){
		temp0 = temp_integer & 0b10000000;
		temp0 = temp0>>7;
		if(temp0){
			uart_send('1');
		}
		else{
			uart_send('0');
		}
		temp_integer = temp_integer << 1;
	}
	uart_send('\r');uart_send('\n');

}
void terminal_reset(void){
	uart_send(esc_char);uart_send(terminal_reset_byte); //Full Reset Terminal
}

void print_program_enabled_msg(void){
	loop_counter = reset;
	while(loop_counter < len_programming_enabled_msg){
		uart_send(programming_enabled_msg[loop_counter]);
		loop_counter++;
	};
	loop_counter = reset;
	uart_send(esc_char);uart_send('[');uart_send('3');uart_send('5');uart_send('m');
}
void print_program_entered_msg(void){
	loop_counter = reset;
	while(loop_counter < len_program_entered_msg){
		uart_send(program_entered_msg[loop_counter]);
		loop_counter++;
	};
	loop_counter = reset;
}
void print_program_execution_msg(void){
	loop_counter = reset;
	while(loop_counter < len_running_program_msg){
		uart_send(running_program_msg[loop_counter]);
		loop_counter++;
	};
	loop_counter = reset;
}
void print_program_completed_msg(void){
	result = 50 * system_tick;
	uart_send('D');uart_send('u');uart_send('r');uart_send('a');uart_send('t');uart_send('i');uart_send('o');uart_send('n');uart_send('(');
	uart_send('m');uart_send('s');uart_send(')');uart_send(' ');
	if(!result){
		uart_send('<');uart_send(' ');uart_send('5');uart_send('0');uart_send('\r');uart_send('\n');
		goto skip;
	}
	temp_integer = result;
	print_output_buffers_dec();
	skip:
	uart_send(esc_char);uart_send('[');uart_send('0');uart_send('m');

}
void print_program_error_code(void){
	loop_counter = reset;
	while(loop_counter != len_error_code){
		uart_send(error_msg[loop_counter]);
		loop_counter++;
	};

	switch(err_handler){
		case ERR_ZERO_DIVISION: 
			uart_send('0');uart_send('x');uart_send('0');uart_send('1');uart_send('C');uart_send('D');uart_send('C');
			break;
		case ERR_INVALID_TOKEN:
			uart_send('0');uart_send('x');uart_send('0');uart_send('2');uart_send('C');uart_send('D');uart_send('C');
			break;
		case ERR_DATA_STACK_OVERFLOW:
			uart_send('0');uart_send('x');uart_send('0');uart_send('3');uart_send('C');uart_send('D');uart_send('C');
			break;
		case ERR_CALL_STACK_OVERFLOW:
			uart_send('0');uart_send('x');uart_send('0');uart_send('4');uart_send('C');uart_send('D');uart_send('C');
			break;
		case ERR_MISSING_FI:
			uart_send('0');uart_send('x');uart_send('0');uart_send('A');uart_send('C');uart_send('D');uart_send('C');
			break;
		case ERR_GENERIC_EXEC_FAILURE:
			uart_send('0');uart_send('x');uart_send('F');uart_send('F');uart_send('C');uart_send('D');uart_send('C');
			break;
			
	}
	uart_send('\r');uart_send('\n');
}

void reset_stack(void){
	loop_counter = reset;
	while(loop_counter < data_stack_limit){
		virtual_data_stack[loop_counter][0] = reset;
		virtual_data_stack[loop_counter][1] = reset;
		loop_counter++;
	};
	loop_counter = reset;
	while(loop_counter < call_stack_limit){
		virtual_call_stack[loop_counter][0] = reset;
		virtual_call_stack[loop_counter][1] = reset;
		loop_counter++;
	};
	local_conditional_stack[0] = reset;
	local_conditional_stack[1] = 255;
	
	local_loop_stack[0] = reset;
	local_loop_stack[1] = reset;

}

static unsigned char fetch_variable_data(unsigned char identifier_id){
	loop_counter = reset;
	while(loop_counter < data_stack_limit){
		if(virtual_data_stack[loop_counter][symbol] == identifier_id){
			return virtual_data_stack[loop_counter][data_segment];
		}
		loop_counter++;
	}
	is_error = true;
	err_handler = ERR_INVALID_TOKEN;
	return 255;
}
static void create_data_variable(unsigned char identifier_id){
	loop_counter = reset;
	while(loop_counter < data_stack_limit){
		if((virtual_data_stack[loop_counter][symbol]) == identifier_id){
			return;
		}
		if((virtual_data_stack[loop_counter][symbol]) == reset){
			virtual_data_stack[loop_counter][symbol] = identifier_id;
			return;
		};
		
		loop_counter++;
	};
	loop_counter = reset;
	is_error = true;
	err_handler = ERR_DATA_STACK_OVERFLOW;
}
static unsigned char fetch_variable_slot(unsigned char identifier_id){
	loop_counter = reset;
	while(loop_counter < data_stack_limit){
		if(virtual_data_stack[loop_counter][symbol] == identifier_id){
			return loop_counter;
		}
		loop_counter++;
	}
	is_error = true;
	err_handler = ERR_INVALID_TOKEN;
	return 255;
}
static void assign_data_variable(unsigned char identifier_id , unsigned char data){
	temp3 = fetch_variable_slot(identifier_id);
	if(is_error){
		return;
	}
	virtual_data_stack[temp3][data_segment] = data;
	return;
}
static void allocate_callable_block(unsigned char block_id , unsigned char address){
	loop_counter = reset;
	while(loop_counter < call_stack_limit){
		if(virtual_call_stack[loop_counter][block_seg] == block_id){
			return;
		};
		if(virtual_call_stack[loop_counter][block_seg] == reset){
			virtual_call_stack[loop_counter][block_seg] = block_id;
			virtual_call_stack[loop_counter][return_addr] = address;
			return;
		}
		loop_counter++;
	};
	is_error = true;
	err_handler = ERR_INVALID_TOKEN;
}
unsigned char fetch_block_address(unsigned char block_id){
	loop_counter = reset;
	while(loop_counter < call_stack_limit){
		if(virtual_call_stack[loop_counter][block_seg] == block_id){
			return virtual_call_stack[loop_counter][return_addr];
		};
		loop_counter++;
	};
	is_error = 1;
	err_handler = ERR_CALL_STACK_OVERFLOW;
	return 255;
}


unsigned char unified_numeric_parser(void){
	operand_parser:
	switch(input_buffer[ip_buffer_agent]){
		case backspace:
			increment_ip_buffer_agent();
			goto operand_parser;
		case whitespc:
			increment_ip_buffer_agent();
			goto operand_parser;
		default:
				temp1 = 0;
				while(input_buffer[ip_buffer_agent] != whitespc){
					
					if(input_buffer[ip_buffer_agent] == c_enter){
						break;
					};
					temp1 *= 10;
					temp1 += input_buffer[ip_buffer_agent] - 0x30;
					increment_ip_buffer_agent();
				};
				return temp1;
	}
}
static void unified_numeric_word_parser(void){
	ld_parser:
	switch(input_buffer[ip_buffer_agent]){
		case backspace:
			increment_ip_buffer_agent();
			goto ld_parser;
		case whitespc:
			increment_ip_buffer_agent();
			goto ld_parser;
		default:
				temp_integer  = 0;
				while(input_buffer[ip_buffer_agent] != whitespc){
					
					if(input_buffer[ip_buffer_agent] == c_enter){
						break;
					};
					temp_integer *= 10;
					temp_integer += input_buffer[ip_buffer_agent] - 0x30;
					increment_ip_buffer_agent();
				};
				
	}
}
static inline void single_operand_line_parser(void){
	program_buffer[virtual_program_counter] = instruction_buffer;
	increment_virtual_program_counter();
	op1 = unified_numeric_parser();
	program_buffer[virtual_program_counter] = op1;
	increment_virtual_program_counter();
}
static void dual_operand_line_parser(void){
	op1 = unified_numeric_parser();
	op2 = unified_numeric_parser();
	program_buffer[virtual_program_counter] = instruction_buffer;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = op1;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = op2;
	increment_virtual_program_counter();
}
static void tri_operand_line_parser(void){
	op1 = unified_numeric_parser();
	op2 = unified_numeric_parser();
	op3 = unified_numeric_parser();

	program_buffer[virtual_program_counter] = instruction_buffer;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = op1;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = op2;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = op3;
	increment_virtual_program_counter();
}
static void quad_operand_line_parser(void){

	op1 = unified_numeric_parser();
	op2 = unified_numeric_parser();
	op3 = unified_numeric_parser();
	op4 = unified_numeric_parser();

	program_buffer[virtual_program_counter] = instruction_buffer;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = op1;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = op2;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = op3;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = op4;
	increment_virtual_program_counter();



}
static inline void fi_parser(void){
	program_buffer[virtual_program_counter] = instruction_buffer;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = endifl;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = endifh;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = fcheckfi;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = scheckfi;
	increment_virtual_program_counter();
}
static inline void pool_parser(void){
	program_buffer[virtual_program_counter] = instruction_buffer;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = endloopl;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = endlooph;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = fcheckloop;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = scheckloop;
	increment_virtual_program_counter();
}


static void unified_arithmetic_core(void){
	instruction_buffer = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op1 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op2 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op3 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op4 = program_buffer[virtual_program_counter];

	temp0 = reset;
	temp1 = reset;

	switch(op1){
		case val_flag:
			temp0 = op2;
			temp1 = op3;
			temp_integer = 0;
			break;
		case dot_result:
			temp0 = op2;
			temp1 = 0;
			temp_integer = result;
			op4 = op3;
			break;
		case dot_xword:
			temp0 = op2;
			temp1 = 0;
			temp_integer = xword;
			op4 = op3;
			break;
		case dat_flag:
			temp0 = fetch_variable_data(op2);
			temp1 = fetch_variable_data(op3);
			temp_integer = 0;
			break;
		default:
			is_error = 1;
			err_handler = ERR_INVALID_OPERAND;
	};

	switch(instruction_buffer){
		case cadd:
			temp_integer += temp0 + temp1;
			break;

		case csub:
			if(temp1 == 0){
				temp_integer = temp_integer - temp0;
				break;
			}
			else{
				temp_integer =  temp0 - temp1;
			};
			break;

		case cmul:
			if(temp1 == 0){
				temp_integer = temp_integer * temp0;
				break;
			}
			else{
				temp_integer =  temp0 * temp1;
			};
			break;

		case cdiv:
			if(temp0 == 0){
				is_error = 1;
				err_handler = ERR_ZERO_DIVISION;
				break;
			};
			if(temp1 == 0){
				temp_integer = temp_integer / temp0;
				break;
			}
			else{
				temp_integer =  temp0 / temp1;
			};
			break;

		case cmod:
			if(temp0 == 0){
				is_error = 1;
				err_handler = ERR_ZERO_DIVISION;
				break;
			};
			if(temp1 == 0){
				temp_integer = temp_integer % temp0;
				break;
			}
			else{
				temp_integer =  temp0 % temp1;
			};
			break;
		
		case cand:
			if(temp0 == 0){
				is_error = 1;
				err_handler = ERR_INVALID_OPERAND;
				break;
			};
			if(temp1 == 0){
				temp_integer = temp_integer & temp0;
				break;
			}
			else{
				temp_integer =  temp0 & temp1;
			};
			break;

			case corr:
			if(temp0 == 0){
				is_error = 1;
				err_handler = ERR_INVALID_OPERAND;
				break;
			};
			if(temp1 == 0){
				temp_integer = temp_integer | temp0;
				break;
			}
			else{
				temp_integer =  temp0 | temp1;
			};
			break;

		case cxor:
			if(temp0 == 0){
				is_error = 1;
				err_handler = ERR_INVALID_OPERAND;
				break;
			};
			if(temp1 == 0){
				temp_integer = temp_integer & temp0;
				break;
			}
			else{
				temp_integer =  temp0 & temp1;
			};
			break;

		default:
				is_error = 1;
				err_handler = ERR_INVALID_OPERAND;
	}

	switch(op4){
		case dot_result:
			result = temp_integer;
			break;
		case dot_xword:
			xword = temp_integer;
			break;
		default:
			temp0 = temp_integer;
			assign_data_variable(op4,temp0);
	}
	

	

}
static void single_operand_logic_handler(void){
	instruction_buffer = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op1 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op2 = program_buffer[virtual_program_counter];
	
	switch(instruction_buffer){
		case cnot:
			if(op1 == dat_flag){
				temp0 = fetch_variable_data(op2);
				temp0 = ~temp0;
				assign_data_variable(op2,temp0);
				break;
			};
			if(op1 == dot_result ){
				result = ~result;
				break;
			};
			if(op1 == dot_xword){
				xword = ~xword;
				break;
			};
			break;

		case cincrement:
			if(op1 == dat_flag){
				temp0 = fetch_variable_data(op2);
				temp0++;
				assign_data_variable(op2,temp0);
				break;
			};
			if(op1 == dot_result ){
				result++;
				break;
			};
			if(op1 == dot_xword){
				xword++;
				break;
			};
			break;
		case cdecrement:
			if(op1 == dat_flag){
				temp0 = fetch_variable_data(op2);
				temp0--;
				assign_data_variable(op2,temp0);
				break;
				};
			if(op1 == dot_result ){
				result--;
				break;
				};
			if(op1 == dot_xword){
				xword--;
				break;
				};
			break;
		default:
			is_error = 1;
			err_handler = ERR_INVALID_OPERAND;
	};
	

}
static inline void end_parser(void){
	program_buffer[virtual_program_counter] = instruction_buffer;
	increment_virtual_program_counter();
}
static inline void end_handler(void){
	state_executing_script = false;
	is_success = true;
	print_program_completed_msg();
}
static inline void prog_handler(void){
	state_programming_enabled = true;
	state_executing_script = false;
	loop_counter = reset;
	while(loop_counter < 80){
		program_buffer[loop_counter] = 0;
		loop_counter++;
	}
	loop_counter = reset;
	print_program_enabled_msg();
}
static inline void run_handler(void){
	if(is_programmed){
		state_programming_enabled = false;
		state_executing_script = true;
		print_program_execution_msg();
	}
	else{
		//print_invalid_prog_msg();
	}
}
static inline void parse_handler(void){
	op1 = unified_numeric_parser();
	temp_integer = op1;
	print_output_buffers_dec();
}
static inline void exit_handler(void){
	state_programming_enabled = false;
	is_programmed = true;
	print_program_entered_msg();
}

static inline void prog_erase_handler(void){
	loop_counter = reset;
	while(loop_counter < 80){
		program_buffer[loop_counter] = 0;
		loop_counter++;
	}
	loop_counter = reset;
	while(loop_counter < len_prog_erased){
		uart_send(program_erased_msg[loop_counter]);
		loop_counter++;
	};
	loop_counter = reset;
	is_programmed = false;
	//print_prog_erased_msg();
}
static inline void print_handler(void){
	increment_virtual_program_counter();
	op1 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op2 = program_buffer[virtual_program_counter];
	switch(op1){
		case dot_xword:
			uart_send('x');uart_send('W');uart_send('O');uart_send('R');uart_send('D');uart_send(':');uart_send(' ');
			temp_integer = xword;
			break;
		case dot_result:
			uart_send('v');uart_send('A');uart_send('C');uart_send('C');uart_send(':');uart_send(' ');
			temp_integer = result;
			break;
		default:
			temp_integer = fetch_variable_data(op1);
	};

	switch(op2){
		case formatted_decimal:
			print_output_buffers_dec();
			break;
		case formatted_bin:
			print_output_buffers_bin();
			break;
		case formatted_raw:
			temp0 = temp_integer;
			uart_send(temp0);
			break;
		case formatted_dec_bin:
			int temp = temp_integer;
			print_output_buffers_dec();
			temp_integer = temp;
			print_output_buffers_bin();
			break;
		default:
			is_error = true;
			err_handler = ERR_INVALID_OPERAND;
			
	};
	
}
static inline void unified_parser_data16(void){
	unified_numeric_word_parser();
	program_buffer[virtual_program_counter] = instruction_buffer;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = temp_integer;
	temp_integer = temp_integer >> 8;
	increment_virtual_program_counter();
	program_buffer[virtual_program_counter] = temp_integer;
	increment_virtual_program_counter();
}
static inline void sleep_handler(void){
	increment_virtual_program_counter(); //Instruction Buffer
	increment_virtual_program_counter(); //Lower Byte
	temp_integer = program_buffer[virtual_program_counter];
	temp_integer = temp_integer << 8;
	virtual_program_counter--;
	temp_integer |= program_buffer[virtual_program_counter];
	
	software_delay();
}
static inline void define_handler(void){
	increment_virtual_program_counter();
	op1 = program_buffer[virtual_program_counter];
	create_data_variable(op1);
}
static inline void assign_handler(void){
	increment_virtual_program_counter();
	op1 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op2 = program_buffer[virtual_program_counter];
	assign_data_variable(op1,op2);
}
static void lshift_handler(void){
	increment_virtual_program_counter();
	op1 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op2 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op3 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op4 = program_buffer[virtual_program_counter];

	switch(op1){
		case dat_flag:
			temp_integer = fetch_variable_data(op2);
			break;
		case dot_result:
			temp_integer = result;
			break;
		case dot_xword:
			temp_integer = xword;
			break;
		default:
			is_error = true;
			err_handler = ERR_INVALID_OPERAND;
			return;
		
	}
	temp_integer = temp_integer << op3;
	

	switch(op4){
		case dot_result:
			result = temp_integer;
			break;
		case dot_xword:
			xword = temp_integer;
			break;
		default:
			temp0 = temp_integer;
			assign_data_variable(op4,temp0);
			
	}
	return;
}
static void rshift_handler(void){
	increment_virtual_program_counter();
	op1 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op2 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op3 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op4 = program_buffer[virtual_program_counter];

	switch(op1){
		case dat_flag:
			temp_integer = fetch_variable_data(op2);
			break;
		case dot_result:
			temp_integer = result;
			op4 = op3;
			op3 = op2;
			break;
		case dot_xword:
			temp_integer = xword;
			op4 = op3;
			op3 = op2;
			break;
		default:
			is_error = true;
			err_handler = ERR_INVALID_OPERAND;
			return;
		
	}
	temp_integer = temp_integer >> op3;
	

	switch(op4){
		case dot_result:
			result = temp_integer;
			break;
		case dot_xword:
			xword = temp_integer;
			break;
		default:
			temp0 = temp_integer;
			assign_data_variable(op4,temp0);
			
	}
	return;
}
static void hwport_handler(void){
	increment_virtual_program_counter();
	op1 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op2 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op3 = program_buffer[virtual_program_counter];

	if(op1 == operand_read){
		switch(op2){
			case port0:
				temp0 = P0;
				break;
			case port1:
				temp0 = P1;
				break;
			case port2:
				temp0 = P2;
				break;
			case port3:
				temp0 = P3;
				break;
			default:
				is_error = 1;
				err_handler = ERR_INVALID_TOKEN;
				return;
		};
		assign_data_variable(op3,temp0);
		return;
	};

	if(op1 == operand_write){
		temp0 = fetch_variable_data(op3);
		switch(op2){
			case port0:
				P0 = temp0;
				break;
			case port1:
				P1 = temp0;
				break;
			case port2:
				P2 = temp0;
				break;
			case port3:
				P3 = temp0;
				break;
			default:
				is_error = 1;
				err_handler = ERR_INVALID_TOKEN;
				return;
		};
		return;
	};
	
	
	switch(op2){
			case port0:
				P0 = op3;
				break;
			case port1:
				P1 = op3;
				break;
			case port2:
				P2 = op3;
				break;
			case port3:
				P3 = op3;
				break;
			default:
				is_error = 1;
				err_handler = ERR_INVALID_TOKEN;
				return;
		};
	
	return;
}
static inline void copy_handler(void){
	increment_virtual_program_counter();
	op1 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op2 = program_buffer[virtual_program_counter];

	temp0 = fetch_variable_data(op1);
	assign_data_variable(op2,temp0);

}
static void if_handler(void){
	increment_virtual_program_counter();
	temp3 = virtual_program_counter;
	if(local_conditional_stack[skip_addr] < prog_buffer_size ){
		goto condt_eval;
	};
	while(temp3 < 80){
		if((program_buffer[temp3 + 1] == cfi)&&
			(program_buffer[temp3 + 2] == endifl)&&
			(program_buffer[temp3 + 3] == endifh)&&
			(program_buffer[temp3 + 4] == fcheckfi)&&
			(program_buffer[temp3 + 5] == scheckfi))
		{
			local_conditional_stack[skip_addr] = temp3;
			break;
		};
		temp3++;
		
	}
	

	condt_eval:
	op1 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op2 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op3 = program_buffer[virtual_program_counter];

	temp0 = fetch_variable_data(op1);
	temp1 = fetch_variable_data(op3);

	//DEBUG temp_integer = local_conditional_stack[skip_addr];
	//DEBUG print_output_buffers_dec();uart_send('\r');uart_send('\n');
	
	switch(op2){
		case operand_exceeds:
			if(temp0 > temp1){
				local_conditional_stack[condition] = true;
				break;
			};
			local_conditional_stack[condition] = false;
			break;
		case operand_precedes:
			if(temp0 < temp1){
				local_conditional_stack[condition] = true;
				break;
			};
			local_conditional_stack[condition] = false;
			break;
		case operand_equ:
			if(temp0 == temp1){
				local_conditional_stack[condition] = true;
				break;
			};
			local_conditional_stack[condition] = false;
			break;
		case operand_neq:
			if(temp0 != temp1){
				local_conditional_stack[condition] = true;
				break;
			};
			local_conditional_stack[condition] = false;
			break;
		default:
			is_error = true;
			err_handler = ERR_INVALID_TOKEN;
	};


	if(local_conditional_stack[condition] == false){
		virtual_program_counter = local_conditional_stack[skip_addr];
	}

	return;



}
static void fi_handler(void){
	temp0 = reset;
	while(temp0 > 5){
		increment_virtual_program_counter(); //cfi //endifl //endifh //fchecfi //scheckfi
		temp0++;
	};
	local_conditional_stack[skip_addr] = 255;
	local_conditional_stack[condition] = false;
	return;
	

}

static void loop_handler(void){
	increment_virtual_program_counter();
	if(is_looping == true){
		return;
	};
	op1 = program_buffer[virtual_program_counter];
	op1--;
	local_loop_stack[loop_var] = op1;
	local_loop_stack[return_addr] = virtual_program_counter;
	is_looping = true;
}
static void pool_handler(void){
	temp0 = local_loop_stack[loop_var];
	
	if(temp0 > 0){
		is_looping = true;
		temp0--;
		local_loop_stack[loop_var] = temp0;
		virtual_program_counter = local_loop_stack[return_addr];
		return;
	};
	local_loop_stack[loop_var] = 0;
	local_loop_stack[return_addr] = 0;
	is_looping = false;
	temp0 = reset;
	while(temp0 > 5){
		increment_virtual_program_counter(); //cfi //endifl //endifh //fchecfi //scheckfi
		temp0++;
	};
	

}

static void break_handler(void){
	if(is_looping == false){
		return;
	}
	temp3 = virtual_program_counter;
	while(temp3 < 80){
		if((program_buffer[temp3 + 1] == cpool)&&
			(program_buffer[temp3 + 2] == endloopl)&&
			(program_buffer[temp3 + 3] == endlooph)&&
			(program_buffer[temp3 + 4] == fcheckloop)&&
			(program_buffer[temp3 + 5] == scheckloop))
		{
			local_loop_stack[loop_var] = reset;
			virtual_program_counter = temp3;
			break;
		};
		temp3++;
		
	}
}
static void move_handler(void){
	increment_virtual_program_counter();
	op1 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op2 = program_buffer[virtual_program_counter];
	increment_virtual_program_counter();
	op3 = program_buffer[virtual_program_counter];
	
	switch(op2){
		case dat_flag:
			temp_integer = fetch_variable_data(op3);
			break;
		case dot_result:
			temp_integer = result;
			break;
		case dot_xword:
			temp_integer = xword;
			break;
		default:
			is_error = 1;
			err_handler = ERR_INVALID_OPERAND;
			return;
	}
	

	move_val:
	if(op1 == dot_result){
		result = temp_integer;
		return;
	}
	if(op1 == dot_xword){
		xword = temp_integer;
		return;
	}
	is_error = 1;
	err_handler = ERR_INVALID_TOKEN;
	return;
}
static void load_handler(void){
	increment_virtual_program_counter(); //Insytruction Buffer
	increment_virtual_program_counter(); //Lower Byte
	temp_integer = program_buffer[virtual_program_counter];
	temp_integer = temp_integer << 8;
	virtual_program_counter--;
	temp_integer |= program_buffer[virtual_program_counter];
	result = temp_integer;
}

static inline void block_handler(void){
	increment_virtual_program_counter();
	op1 = program_buffer[virtual_program_counter];
	allocate_callable_block(op1,virtual_program_counter);
}
static inline void goto_handler(void){
	increment_virtual_program_counter();
	op1 = program_buffer[virtual_program_counter];
	temp0 = fetch_block_address(op1);
	virtual_program_counter = temp0;
}



//==================================================================================

void Serial_ISR(void) __using(1) __interrupt(4)
{
	if(RI){
		switch(SBUF){
			case backspace:
				if(wr_pointer > &input_buffer[0] && !backspace_block){
					wr_pointer--;
					*wr_pointer = 0;
				}
				echo_e = true;
				break;
			default:
			*wr_pointer = SBUF;
			echo_e = false;
			wr_pointer++;
			
		};
		is_recieved = true;
		RI = false;
		
	}
}

void Timer2_ISR(void) __using(2) __interrupt(5)
{
	system_tick++;
}



//========================= RUNTIME SEQUENCES
static inline void runtime_fail_restore_seq(void){
	ES = disable;
	EA = disable;
	instruction_buffer = reset;
	loop_counter = reset;
	while(loop_counter < 32){
		input_buffer[loop_counter] = reset;
		loop_counter++;
	}
	loop_counter = reset;

	op1 = reset;
	op2 = reset;
	loop_counter = reset;
	is_recieved = false;
	wr_pointer = &input_buffer[0];
	rd_pointer = &input_buffer[0];
	ip_buffer_agent = reset;
	if(state_programming_enabled){
		uart_send(esc_char);uart_send('[');uart_send('3');uart_send('5');uart_send('m');
	}

	EA = enable;
	ES = enable;

}
static inline void config_machine_state(void){
	if(*rd_pointer == c_enter){
		machine_state = state_exec;
	}
	else{
		machine_state = state_listener;
	}
}
static inline void increment_ip_buffer_agent(void){
	ip_buffer_agent++;
	ip_buffer_agent &= 0x1f;				//Apply Bitmask to keep under 32 (buffer Size)	
}
static inline void increment_virtual_program_counter(void){
	virtual_program_counter++;
	virtual_program_counter &= 0x3f;

}
static inline void runtime_memory_mgmt(void){
	if(is_input_buffer_reset == true){
		goto skip_buffer_mgmt;
	}
	if(echo_e){
		if(!backspace_block){
			rd_pointer--;
		}
		
		echo_e = false;
		
	}
	else{
		rd_pointer++;
		backspace_block = false;
		
	};
	if(rd_pointer < &input_buffer[0]){
		rd_pointer++;
	}

	if(rd_pointer > &input_buffer[31]){
		rd_pointer = &input_buffer[0];
	};

	if(wr_pointer > &input_buffer[31]){
		wr_pointer = &input_buffer[0];
	};
	skip_buffer_mgmt:
	is_input_buffer_reset = false;

}

static inline void runtime_terminal_reset(void){
	terminal_reset();
}
static inline void runtime_reset_seq(void){
	EA = disable; //Disable All Interrupts Temporarily
	WDTRST = 0x1E;  //Actication Byte 1
	WDTRST = 0xE1;	//Activation Byte 2
	while(1);

}
static inline void runtime_state_cleanup(void){
	if(is_success){
		print_success_message();
		is_success = false;

		result = reset;
		xword = reset;
		op1 = reset;
		op2 = reset;
		op3 = reset;
		op4 = reset;
		
	};

	if(is_error){
		print_program_error_code();
		print_invalid_cmd();
		runtime_fail_restore_seq();
		is_error = false;
	};
		is_recieved = false;
}
static inline void runtime_reset_state(void){
	machine_state = state_listener;
}
static inline void runtime_core_seq(void){
	if(machine_state){
		ES = disable;				//Disable Serial Interrupt;
		runtime_command_parser();
		runtime_syscall_request_handler();
		runtime_command_exec();
		instruction_buffer = reset;
		flush_inp_buffer();
		ES = enable;
	};
}
static inline void runtime_boot_seq(void){
	terminal_reset();
	print_boot_message();
	print_ready_message();
}
static inline void runtime_hwinit_seq(void){
	SP = hw_stack; 		//initiaslze Stack Pointer;
	init_sys();
	init_serial();
	//init_timer();
}
static inline void runtime_syscall_request_handler(void){
	if(is_requesting_syscall_access == true && state_programming_enabled == false){
		switch(instruction_buffer){
			case crst:
				runtime_reset_seq();
				break;
			case cclr:
				runtime_terminal_reset();
				break;
			case cparse:
				parse_handler();
				break;
			case cprog:
				prog_handler();
				break;
			case crun:
				run_handler();
				break;
			case no_op:
				break;
			case cerase:
				prog_erase_handler();
				break;
			default:
				is_error = true;

		}
		is_requesting_syscall_access = false;
	}
}
static inline void runtime_command_parser(void){
	instruction_buffer = unified_numeric_parser();
	if(state_programming_enabled == false){
			is_requesting_syscall_access = true;
			goto skip;
		}
	
	parser_loop:
	switch(instruction_buffer){
		case crshift:
		case clshift:
		case cand:
		case corr:
		case cxor:
		case cdiv:
		case cmod:
		case cmul:
		case csub:
		case cadd:
			quad_operand_line_parser();
			break;
		case cloop:
		case cprint:
		case cassign:
		case ccopy:
		case cnot:
		case cincrement:
		case cdecrement:
			dual_operand_line_parser();
			break;
		case cmove:
		case cif:
		case hwport:
			tri_operand_line_parser();
			break;
		case cexit:
			exit_handler();
			break;
		case csleep:
		case cload:
			unified_parser_data16();
			break;
		case cblock:
		case cgoto:
		case cdefine:
			single_operand_line_parser();
			break;
		case cfi:
			fi_parser();
			break;
		case cbreak:
		case cend:
			end_parser();
			break;
		case cpool:
			pool_parser();
			break;
		case no_op:
			break;
		default:
			is_error = true;
	}

	skip:
}
void runtime_command_exec(void){
	if(!state_executing_script){
		return;
	};

	virtual_program_counter = reset;
	TR2 = disable; 				//Disable timer2 for preventing misallignment
	system_tick = reset;
	init_timer();

	while(state_executing_script){
		instruction_buffer = program_buffer[virtual_program_counter];
		switch(instruction_buffer){
			case cand:
			case corr:
			case cxor:
			case cadd:
			case csub:
			case cmul:
			case cdiv:
			case cmod:
				unified_arithmetic_core();
				break;
			case cnot:
			case cincrement:
			case cdecrement:
				single_operand_logic_handler();
				break;
			case cprint:
				print_handler();
				break;
			case csleep:
				sleep_handler();
				break;
			case cif:
				if_handler();
				break;
			case crshift:
				rshift_handler();
				break;
			case clshift:
				lshift_handler();
				break;
			case cdefine:
				define_handler();
				break;
			case cassign:
				assign_handler();
				break;
			case hwport:
				hwport_handler();
				break;
			case ccopy:
				copy_handler();
				break;
			case cmove:
				move_handler();
				break;
			case cload:
				load_handler();
				break;
			case cloop:
				loop_handler();
				break;
			case cpool:
				pool_handler();
				break;
			case cbreak:
				break_handler();
				break;
			case cgoto:
				goto_handler();
				break;
			case cblock:
				block_handler();
				break;
			case cend:
				end_handler();
				break;
			default:
				
			
		};
		if(is_error){
			state_executing_script = false;
			is_success = false;
		};
		increment_virtual_program_counter();
	}
	TR2 = disable; 			//Disable timer2 after execution
	virtual_program_counter = reset;
	reset_stack();
}



//========================================================================================

void main(void){
	runtime_hwinit_seq();
	runtime_boot_seq();
	
	while(true){
		echo();					
		config_machine_state();		
		runtime_core_seq();
		runtime_memory_mgmt();
		runtime_state_cleanup();
		runtime_reset_state();	

	}
}
	

