#ifndef  syncui_h
#define  syncui_h

#include "webui.h"
#include "core85.h"

void sync_cpu_memory(core* acpu , webui_handle_t ui );
void sync_cpu_core(core* acpu , webui_handle_t ui );
void sync_cpu_port(core* acpu , webui_handle_t ui );

#endif //syncui_h