#ifndef parser_h
#define parser_h

#define hsh_key 0b00111111

#define bck_spc '\b'

#define whitespc ' '

#define comma ','

#define backspace 0x7F


unsigned char unified_numeric_parser(void);     
static void unified_numeric_word_parser(void);  //USES temp_integer


static void quad_operand_line_parser(void);

static inline void print_parser(void);

static inline void sleep_parser(void);

static inline void exit_parser(void);
static inline void end_parser(void);

static inline void single_operand_line_parserr(void); //define//goto//
static inline void assign_parser(void);

static void dual_operand_line_parser(void);  //increment //decrement //not //delete //print //assign

static inline void fi_parser(void);
static inline void pool_parser(void);

static void if_parser(void);
static inline void hwport_parser(void);

static void tri_operand_line_parser(void);   //hwport //loop //if //load //block

static inline void toggle_parser(void);


#endif //parser_h