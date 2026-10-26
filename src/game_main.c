#include "xport.h"

/* Unresolved until the original PsyQ graph type storage is audited */
const uint32 xport_gpu_graph_type_address = 0u;

/* Unresolved CD bindings until original storage is audited */
const uint32 xport_cd_sync_callback_address = 0u;
const uint32 xport_cd_ready_callback_address = 0u;
const uint32 xport_cd_status_address = 0u;
const uint32 xport_cd_setloc_table_address = 0u;

void res_game_main_8001107c(void);

/* Preserve the incoming guest return address at the native entry boundary */
void res_kernel_entry(uint32 original_return_address)
{
    uint32 address = 0x80062D90;
    uint32 stack_limit;
    uint32 heap_size;

    FUNCTION_MARKER(0x80010B08, "KERNEL.BIN");

    do
    {
        w_u32(address, 0);
        address += 4;
    } while (address < 0x8006C118);

    stack_limit = r_u32(0x80010BB8);
    heap_size = stack_limit - r_u32(0x8005A1B4) - 0x6C118;
    w_u32(0x80062D90, original_return_address);
    InitHeap(0x8006C11C, heap_size);
    r_u32(0x80062D90);
    res_game_main_8001107c();
    xport_mips_break(1);
}

void xport_main(void)
{
    return;
}
