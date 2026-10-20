#include "webui.h"
#include "webview.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

typedef struct {
    webview_t w;
    webui_callbacks_t cbs;
    void *user_data;
} webui_context_t;

static char *parse_json_first_string(const char *json_req) {
    if (!json_req) return NULL;
    const char *start = strchr(json_req, '"');
    if (!start) return NULL;
    start++;
    const char *end = strrchr(start, '"');
    if (!end || end < start) return NULL;

    size_t len = (size_t)(end - start);
    char *out = (char *)malloc(len + 1);
    if (!out) return NULL;

    size_t write_idx = 0;
    for (size_t i = 0; i < len; i++) {
        if (start[i] == '\\' && i + 1 < len) {
            i++;
            switch (start[i]) {
                case 'n':  out[write_idx++] = '\n'; break;
                case 'r':  out[write_idx++] = '\r'; break;
                case 't':  out[write_idx++] = '\t'; break;
                case '"':  out[write_idx++] = '"';  break;
                case '\\': out[write_idx++] = '\\'; break;
                default:   out[write_idx++] = start[i]; break;
            }
        } else {
            out[write_idx++] = start[i];
        }
    }
    out[write_idx] = '\0';
    return out;
}

static void handle_assemble(const char *seq, const char *req, void *arg) {
    webui_context_t *ctx = (webui_context_t *)arg;
    if (ctx->cbs.on_assemble) {
        char *code = parse_json_first_string(req);
        ctx->cbs.on_assemble((webui_handle_t)ctx, code ? code : "", ctx->user_data);
        free(code);
    }
    webview_return(ctx->w, seq, 0, "{}");
}

static void handle_step(const char *seq, const char *req, void *arg) {
    (void)req;
    webui_context_t *ctx = (webui_context_t *)arg;
    if (ctx->cbs.on_step) {
        ctx->cbs.on_step((webui_handle_t)ctx, ctx->user_data);
    }
    webview_return(ctx->w, seq, 0, "{}");
}

static void handle_run(const char *seq, const char *req, void *arg) {
    (void)req;
    webui_context_t *ctx = (webui_context_t *)arg;
    if (ctx->cbs.on_run) {
        ctx->cbs.on_run((webui_handle_t)ctx, ctx->user_data);
    }
    webview_return(ctx->w, seq, 0, "{}");
}

static void handle_hex_key(const char *seq, const char *req, void *arg) {
    webui_context_t *ctx = (webui_context_t *)arg;
    if (ctx->cbs.on_hex_key) {
        char *key = parse_json_first_string(req);
        ctx->cbs.on_hex_key((webui_handle_t)ctx, key ? key : "", ctx->user_data);
        free(key);
    }
    webview_return(ctx->w, seq, 0, "{}");
}

static void handle_terminal_cmd(const char *seq, const char *req, void *arg) {
    webui_context_t *ctx = (webui_context_t *)arg;
    if (ctx->cbs.on_terminal_cmd) {
        char *cmd = parse_json_first_string(req);
        ctx->cbs.on_terminal_cmd((webui_handle_t)ctx, cmd ? cmd : "", ctx->user_data);
        free(cmd);
    }
    webview_return(ctx->w, seq, 0, "{}");
}

static void handle_query_mem(const char *seq, const char *req, void *arg) {
    webui_context_t *ctx = (webui_context_t *)arg;
    if (ctx->cbs.on_query_mem) {
        char *addr = parse_json_first_string(req);
        ctx->cbs.on_query_mem((webui_handle_t)ctx, addr ? addr : "", ctx->user_data);
        free(addr);
    }
    webview_return(ctx->w, seq, 0, "{}");
}

static void handle_reset(const char *seq, const char *req, void *arg) {
    (void)req;
    webui_context_t *ctx = (webui_context_t *)arg;
    if (ctx->cbs.on_reset) {
       ctx->cbs.on_reset((webui_handle_t)ctx, ctx->user_data);
    } else {
        webview_eval(ctx->w, "bsim85.resetUI();");
    }
    webview_return(ctx->w, seq, 0, "{}");
}

webui_handle_t webui_init(const char *title, int width, int height, int debug, const webui_callbacks_t *cbs, void *user_data) {
    webui_context_t *ctx = (webui_context_t *)calloc(1, sizeof(webui_context_t));
    if (!ctx) return NULL;

    if (cbs) ctx->cbs = *cbs;
    ctx->user_data = user_data;

    ctx->w = webview_create(debug, NULL);
    if (!ctx->w) {
        free(ctx);
        return NULL;
    }

    webview_set_title(ctx->w, title ? title : "bsim85");
    webview_set_size(ctx->w, width > 0 ? width : 1200, height > 0 ? height : 800, WEBVIEW_HINT_NONE);

    webview_bind(ctx->w, "assembleCode",    handle_assemble,     ctx);
    webview_bind(ctx->w, "stepCpu",         handle_step,         ctx);
    webview_bind(ctx->w, "runCpu",          handle_run,          ctx);
    webview_bind(ctx->w, "onHexKeyPress",   handle_hex_key,      ctx);
    webview_bind(ctx->w, "execTerminalCmd", handle_terminal_cmd, ctx);
    webview_bind(ctx->w, "queryMemory",     handle_query_mem,    ctx);
    webview_bind(ctx->w, "resetCpu",        handle_reset,        ctx);

    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        char uri[PATH_MAX + 32];
        snprintf(uri, sizeof(uri), "file://%s/index.html", cwd);
        webview_navigate(ctx->w, uri);
    } else {
        webview_navigate(ctx->w, "file://./index.html");
    }

    return (webui_handle_t)ctx;
}

void webui_run(webui_handle_t ui) {
    if (!ui) return;
    webui_context_t *ctx = (webui_context_t *)ui;
    webview_run(ctx->w);
}

void webui_destroy(webui_handle_t ui) {
    if (!ui) return;
    webui_context_t *ctx = (webui_context_t *)ui;
    webview_destroy(ctx->w);
    free(ctx);
}

void webui_update_cpu(webui_handle_t ui,
                      uint8_t a, uint8_t b, uint8_t c,
                      uint8_t d, uint8_t e, uint8_t h, uint8_t l,
                      uint16_t pc, uint16_t sp, uint8_t flags) {
    if (!ui) return;
    webui_context_t *ctx = (webui_context_t *)ui;
    char js[256];
    snprintf(js, sizeof(js),
        "bsim85.updateCpu({"
          "a:0x%02X, b:0x%02X, c:0x%02X, "
          "d:0x%02X, e:0x%02X, h:0x%02X, l:0x%02X, "
          "pc:0x%04X, sp:0x%04X, flags:0x%02X"
        "});",
        a, b, c, d, e, h, l, pc, sp, flags);
    webview_eval(ctx->w, js);
}

void webui_sync_core(webui_handle_t ui, const core *c) {
    if (!ui || !c) return;
    webui_update_cpu(ui, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

void webui_set_register(webui_handle_t ui, char reg_name, uint8_t val) {
    if (!ui) return;
    webui_context_t *ctx = (webui_context_t *)ui;
    char js[64];
    snprintf(js, sizeof(js), "bsim85.setRegister('%c', 0x%02X);", reg_name, val);
    webview_eval(ctx->w, js);
}

void webui_set_pc(webui_handle_t ui, uint16_t pc) {
    if (!ui) return;
    webui_context_t *ctx = (webui_context_t *)ui;
    char js[64];
    snprintf(js, sizeof(js), "bsim85.setPC(0x%04X);", pc);
    webview_eval(ctx->w, js);
}

void webui_set_sp(webui_handle_t ui, uint16_t sp) {
    if (!ui) return;
    webui_context_t *ctx = (webui_context_t *)ui;
    char js[64];
    snprintf(js, sizeof(js), "bsim85.setSP(0x%04X);", sp);
    webview_eval(ctx->w, js);
}

void webui_set_flags(webui_handle_t ui, uint8_t flags) {
    if (!ui) return;
    webui_context_t *ctx = (webui_context_t *)ui;
    char js[64];
    snprintf(js, sizeof(js), "bsim85.setFlags(0x%02X);", flags);
    webview_eval(ctx->w, js);
}

void webui_update_port(webui_handle_t ui, uint8_t port, uint8_t val) {
    if (!ui) return;
    webui_context_t *ctx = (webui_context_t *)ui;
    char js[64];
    snprintf(js, sizeof(js), "bsim85.updatePort(0x%02X, 0x%02X);", port, val);
    webview_eval(ctx->w, js);
}

void webui_update_7seg_3byte(webui_handle_t ui, uint8_t high_byte, uint8_t mid_byte, uint8_t low_byte) {
    if (!ui) return;
    webui_context_t *ctx = (webui_context_t *)ui;
    char js[64];
    snprintf(js, sizeof(js), "bsim85.update7Seg(0x%02X, 0x%02X, 0x%02X);", high_byte, mid_byte, low_byte);
    webview_eval(ctx->w, js);
}

void webui_update_7seg(webui_handle_t ui, uint8_t high_byte, uint8_t low_byte) {
    webui_update_7seg_3byte(ui, 0x00, high_byte, low_byte);
}

void webui_update_memory(webui_handle_t ui, uint16_t start_addr, const uint8_t *bytes, size_t len) {
    if (!ui || !bytes || len == 0) return;
    webui_context_t *ctx = (webui_context_t *)ui;
    size_t buf_size = 64 + (len * 8);
    char *js = (char *)malloc(buf_size);
    if (!js) return;

    int offset = snprintf(js, buf_size, "bsim85.updateMemory(0x%04X, [", start_addr);
    for (size_t i = 0; i < len; i++) {
        offset += snprintf(js + offset, buf_size - (size_t)offset, "0x%02X%s", bytes[i], (i + 1 < len) ? "," : "");
    }
    snprintf(js + offset, buf_size - (size_t)offset, "]);");
    webview_eval(ctx->w, js);
    free(js);
}

void webui_log_terminal(webui_handle_t ui, const char *msg, const char *type) {
    if (!ui || !msg) return;
    webui_context_t *ctx = (webui_context_t *)ui;
    const char *t = type ? type : "info";
    size_t buf_size = strlen(msg) + 64;
    char *js = (char *)malloc(buf_size);
    if (!js) return;

    snprintf(js, buf_size, "bsim85.logTerminal(\"%s\", \"%s\");", msg, t);
    webview_eval(ctx->w, js);
    free(js);
}

void webui_reset(webui_handle_t ui) {
    if (!ui) return;
    webui_context_t *ctx = (webui_context_t *)ui;
    webview_eval(ctx->w, "bsim85.resetUI();");
}

void webui_set_html(webui_handle_t ui, const char *html) {
    if (!ui || !html) return;
    webui_context_t *ctx = (webui_context_t *)ui;
    webview_set_html(ctx->w, html);
}