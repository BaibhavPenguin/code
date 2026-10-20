#ifndef WEBUI_H
#define WEBUI_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "core85.h"

#ifdef __cplusplus
extern "C" {
#endif

// Forward declaration for webview handle
typedef void* webui_handle_t;

/* Updated callback signatures: each function receives 'ui' as the 1st parameter */
typedef void (*webui_on_assemble_fn)(webui_handle_t ui, const char *asm_source, void *user_data);
typedef void (*webui_on_step_fn)(webui_handle_t ui, void *user_data);
typedef void (*webui_on_run_fn)(webui_handle_t ui, void *user_data);
typedef void (*webui_on_hex_key_fn)(webui_handle_t ui, const char *key_name, void *user_data);
typedef void (*webui_on_terminal_cmd_fn)(webui_handle_t ui, const char *command, void *user_data);
typedef void (*webui_on_query_mem_fn)(webui_handle_t ui, const char *address_str, void *user_data);
typedef void (*webui_on_reset_fn)(webui_handle_t ui, void *user_data);

void webui_set_html(webui_handle_t ui, const char *html);

typedef struct {
    webui_on_assemble_fn     on_assemble;
    webui_on_step_fn         on_step;
    webui_on_run_fn          on_run;
    webui_on_reset_fn        on_reset;
    webui_on_hex_key_fn      on_hex_key;
    webui_on_terminal_cmd_fn on_terminal_cmd;
    webui_on_query_mem_fn    on_query_mem;
} webui_callbacks_t;

webui_handle_t webui_init(const char *title, int width, int height, int debug, const webui_callbacks_t *cbs, void *user_data);
void webui_run(webui_handle_t ui);
void webui_destroy(webui_handle_t ui);

void webui_update_cpu(webui_handle_t ui, uint8_t a, uint8_t b, uint8_t c,uint8_t d, uint8_t e, uint8_t h, uint8_t l, uint16_t pc, uint16_t sp, uint8_t flags);
void webui_sync_core(webui_handle_t ui, const core *c);
void webui_set_register(webui_handle_t ui, char reg_name, uint8_t val);
void webui_set_pc(webui_handle_t ui, uint16_t pc);
void webui_set_sp(webui_handle_t ui, uint16_t sp);
void webui_set_flags(webui_handle_t ui, uint8_t flags);
void webui_update_port(webui_handle_t ui, uint8_t port, uint8_t val);

/* 3-Byte 7-Segment display updater */
void webui_update_7seg_3byte(webui_handle_t ui, uint8_t high_byte, uint8_t mid_byte, uint8_t low_byte);
void webui_update_7seg(webui_handle_t ui, uint8_t high_byte, uint8_t low_byte);

void webui_update_memory(webui_handle_t ui, uint16_t start_addr, const uint8_t *bytes, size_t len);
void webui_log_terminal(webui_handle_t ui, const char *msg, const char *type);
void webui_reset(webui_handle_t ui);

#ifdef __cplusplus
}
#endif

#endif /* WEBUI_H */