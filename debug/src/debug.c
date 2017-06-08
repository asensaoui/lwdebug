

#include <udebugger.h>


#define DEBUG_PRINT_HEAD(x) {\
    DPRINTF("\n***********************************************************\n");\
    DPRINTF("                    "x"\n");\
    DPRINTF("***********************************************************\n\n");\
}
#define DEBUG_PRINT_END()   {\
    DPRINTF("***********************************************************\n\n");\
}


/* FIXME: For now, we use only semihosting */
#define DEBUG_MAX_BUFFER 128
uint8_t g_buffer[DEBUG_MAX_BUFFER];
int g_buffer_pos;

WEAK void default_putc(uint8_t data)
{
    if (g_buffer_pos < (DEBUG_MAX_BUFFER - 1)) {
        g_buffer[g_buffer_pos++] = data;
    } else {
        data = '\n';
    }

    if (data == '\n') {
        g_buffer[g_buffer_pos] = 0;
        asm volatile(
            "mov r0, #4\n"
            "mov r1, %[data]\n"
            "bkpt #0xAB\n"
            :
            : [data] "r" (&g_buffer)
            : "r0", "r1"
        );
        g_buffer_pos = 0;
    }
}

/** debug_exception_stack_frame
 *
 * OUT : 
 *
 * @param  			 
 *
 */
static void debug_exception_stack_frame(uint32_t lr, uint32_t sp)
{
	
}