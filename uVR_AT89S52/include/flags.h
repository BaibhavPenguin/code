#ifndef flags_h
#define flags_h

#define port0 136
#define port1 137
#define port2 138
#define port3 139
#define vport1 212
#define term 37
#define dot_result 88
#define dot_xword 252




#define operand_put 246   // put
#define operand_get 210   // get

#define operand_failsafe 205    //failsafe
#define operand_infloops 247    // infloops

#define formatted_decimal 208   //&d
#define formatted_raw 222   //&r
#define formatted_bin 206   //&b
#define formatted_dec_bin 14 //&d&b


#define val_flag 223 //.value
#define dat_flag 253 //.datax

#define operand_exceeds 119     // exceeds
#define operand_precedes 199       // preceeds
#define operand_equ 131 // equ
#define operand_neq 139 // neq


#define operand_read 130 //.read
#define operand_write 33 // .write
#define operand_wrdata 29 //.wrdata

#endif //flags_h