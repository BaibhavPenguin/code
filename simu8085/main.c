#include "webui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core85.h"

static const char k_index_html[] = {
#embed "index.html"
, '\0'
};

static const char k_styles_css[] = {
#embed "styles/index.css"
, '\0'
};

static const char k_bridge_js[] = {
#embed "scripts/bridge.js"
, '\0'
};

static const char k_scripts_js[] = {
#embed "scripts/index.js"
, '\0'
};

static void cb_assemble(webui_handle_t ui, const char *code, void *user_data) {
    (void)code; (void)user_data;
    printf("[UI] Assemble clicked.\n");
    webui_log_terminal(ui, "Assemble triggered.", "info");
}

static void cb_step(webui_handle_t ui, void *user_data) {
    (void)user_data;
    printf("[UI] Step clicked.\n");
    webui_log_terminal(ui, "Single step executed.", "info");
}

static void cb_run(webui_handle_t ui, void *user_data) {
    (void)user_data;
    printf("[UI] Run clicked.\n");
    webui_log_terminal(ui, "Continuous run started.", "info");
}

static void cb_hex_key(webui_handle_t ui, const char *key, void *user_data) {
    (void)user_data;
    printf("[UI] Keypad pressed: %s\n", key);

    char msg[64];
    snprintf(msg, sizeof(msg), "Keypad input: %s", key);
    webui_log_terminal(ui, msg, "info");

    
}

static void cb_terminal_cmd(webui_handle_t ui, const char *cmd, void *user_data) {
    (void)user_data;
    printf("[UI] Terminal command: %s\n", cmd);

    char msg[128];
    snprintf(msg, sizeof(msg), "Executed: %s", cmd);
    webui_log_terminal(ui, msg, "command");
}

static void cb_query_mem(webui_handle_t ui, const char *addr_str, void *user_data) {
    (void)user_data;
    printf("[UI] Memory query: %s\n", addr_str);

    char msg[64];
    snprintf(msg, sizeof(msg), "Querying memory address 0x%s", addr_str);
    webui_log_terminal(ui, msg, "info");
}

static void cb_cpu_reset(webui_handle_t ui, void *user_data) {
    (void)user_data;
    printf("[UI] CPU reset.\n");
    webui_log_terminal(ui, "Hardware Reset Signal Sent.", "error");
}

static char *bundle_ui(void) {
    size_t alloc_size = sizeof(k_index_html) + 
                        sizeof(k_styles_css) + 
                        sizeof(k_bridge_js)  + 
                        sizeof(k_scripts_js) + 512;

    char *bundle = (char *)malloc(alloc_size);
    if (!bundle) return NULL;

    snprintf(bundle, alloc_size,
        "<!DOCTYPE html>"
        "<html>"
        "<head>"
        "<meta charset=\"UTF-8\">"
        "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
        "<style>%s</style>"
        "</head>"
        "<body>"
        "%s"
        "<script>%s</script>"
        "<script>%s</script>"
        "</body>"
        "</html>",
        k_styles_css,
        k_index_html,
        k_bridge_js,
        k_scripts_js
    );

    return bundle;
}

int main(void) {

    init_core(&cpu);          //Initialize registers and allocate memory for 64KiB Simulated Memory.

    webui_callbacks_t cbs = {
        .on_assemble     = cb_assemble,
        .on_step         = cb_step,
        .on_run          = cb_run,
        .on_reset        = cb_cpu_reset,
        .on_hex_key      = cb_hex_key,
        .on_terminal_cmd = cb_terminal_cmd,
        .on_query_mem    = cb_query_mem
    };

    webui_handle_t ui = webui_init("bsim85", 
                                   1280, 820, 1, &cbs, NULL);
    if (!ui) {
        fprintf(stderr, "Error: Could not initialize webview engine.\n");
        return 1;
    }

    char *full_page = bundle_ui();
    if (full_page) {
        webui_set_html(ui, full_page);
        free(full_page);
    }

    webui_log_terminal(ui, "bsim85 shell loaded successfully.", "success");


    webui_run(ui);
    webui_destroy(ui);      
    destroy_core(&cpu);         //Free memory allocated for 64KiB Simulated RAM

    return 0;
}