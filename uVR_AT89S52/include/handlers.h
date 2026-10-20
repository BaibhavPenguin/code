#ifndef handlers_h
#define handlers_h

static inline void live_reset_handler(void);
static inline void live_program_stream_handler(void);
static inline void live_program_run_handler(void);
static inline void live_terminal_clear_handler(void);
static inline void live_debug_parser_handler(void);
static inline void prog_erase_handler(void);

static inline void prog_handler(void);
static inline void exit_handler(void);
static inline void run_handler(void);
static inline void end_handler(void);
static inline void parse_handler(void);
static inline void print_handler(void);
static inline void sleep_handler(void);

static void unified_arithmetic_core(void);
static void single_operand_logic_handler(void);


static inline void define_handler(void);
static inline void assign_handler(void);

static void rshift_handler(void);
static void lshift_handler(void);
static void if_handler(void);
static inline void hwport_handler(void);


static inline void copy_handler(void);
static void fi_handler(void);
static void pool_handler(void);
static void load_handler(void);
static void break_handler(void);
static inline void block_handler(void);
static inline void goto_handler(void);




#endif //handlers_h