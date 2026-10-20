#ifndef uvr_const_h
#define uvr_const_h

// Micro Virtual Runtime 2026 : Ported for AT89S52 : Unique ROM Literals

//=================================== COMMAND LIST ==========================================


//================================== LITERALS ===============================================

#define hw_stack 0xD7 //Starting Address of Hardware Stack

#define timer_l 0x00  //50 ms Master tick at T0 for 11.0592MHz

#define timer_h 0x4C //50 ms Master tick at T0

#define serial_baud_timer 0xFD  //Using Timer 1 for Serial at 9600 Baud Rate

#define esc_char 0x1B

#define terminal_reset_byte 0x63

#define buffer_size 32

#define prog_buffer_size 80





//================================== STRING MESSAGES  ==========================================

#define len_boot_message 54

__code static char boot_message[54] = {
    'M','i','c','r' ,'o', ' ' ,'V','i','r','t','u','a','l','-','R',
    ' ','C','o','p','y','r','i','g','h','t', ' ' ,'2','0','2','6',
    ' ','B','a','i','b','h','a','v',' ','B','h','a','t','t','a',
    'c','h','r','y','a','\r','\n'
};

#define len_ready_message 7
__code static char ready_msg[7] = {
    'R','e','a','d','y' , '\r' ,'\n'
};

#define len_invalid_cmd_msg 35

__code static char invalid_msg[35] = {
    'I','n','v','a','l','i','d',' ','o','r',' ','I','n','c','o','m','p','l','e','t','e',' ','C','o','m','m','a','n','d','\r','\n' , 0x1B , '[' , '0' ,'m'
};


#define len_success_msg 6
__code static char success_msg[6] = {
    'D' , 'o','n','e', '\r' , '\n'
};

#define len_error_code 12
__code static char error_msg[12] = {
    0x1B , '[' , '3', '1' , 'm' , 'E' , 'R' , 'R' , 'O' , 'R' , '!' , ' ',
};

#define len_program_erased 17
__code static char prog_erased_msg[17] = "Program Erased\r\n";

#define len_programming_enabled_msg 59
__code static char programming_enabled_msg[59] = "\033[32mLive programming enabled.\r\nEnter code line by line.\r\n";

#define len_program_entered_msg 57
__code static char program_entered_msg[57] = "\033[0mProgram loaded in memory, use 'run' for execution.\r\n";

#define len_running_program_msg 35
__code static char running_program_msg[35] = "\033[33mExecuting script at runtime\r\n";


#define len_prog_erased 18
__code static char program_erased_msg[18] = "Program Erased!\r\n";



//================================= System Definitions ==================================

#define supported_ansi_color_operands 0x08 //Supported Colors 
#define ascii_zero_char '0'
#define ascii_three_char '3'




//===================== ERR CODES =================

#define ERR_GENERIC_EXEC_FAILURE 0xff
#define ERR_ZERO_DIVISION 0x01
#define ERR_INVALID_TOKEN 0x02
#define ERR_DATA_STACK_OVERFLOW 0x03
#define ERR_CALL_STACK_OVERFLOW 0x04
#define ERR_NONPERMITTED_ACCESS 0x05
#define ERR_INVALID_BLOCK 0x06
#define ERR_INVALID_OPERAND 0x07
#define ERR_MISSING_FI 0x08
#define NO_ERROR 0x00











#endif //uvr_const_h



