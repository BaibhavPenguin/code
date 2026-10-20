#ifndef system_core_h
#define system_core_h

#define true 1
#define false 0

#define disable 0
#define enable 1

#define state_listener 0
#define state_exec 1

#define set 1
#define reset 0

static void runtime_fail_restore_seq(void);

static inline void runtime_memory_mgmt(void);
static inline void runtime_state_cleanup(void);
static inline void config_machine_state(void);
static inline void increment_ip_buffer_agent(void);
static inline void runtime_reset_state(void);
static inline void runtime_core_seq(void);
static inline void runtime_boot_seq(void);
static inline void runtime_hwinit_seq(void);
static inline void runtime_command_parser(void);   // Uses temp0 , temp1
static inline void increment_virtual_program_counter(void);

static inline void runtime_reset_seq(void);
static inline void runtime_terminal_reset(void);

static inline void runtime_forbidden_access(void);

static inline void runtime_syscall_request_handler(void);

void runtime_program_gen(void);
void runtime_command_exec(void);


#endif //system-core_h