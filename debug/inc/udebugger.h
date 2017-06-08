

#ifndef __UDEBUGGER_H__
#define __UDEBUGGER_H__

#include <stdint.h>
#include <stdbool.h>
#include <string.h>


#ifndef TRUE
#define TRUE 1
#endif /* TRUE */

#ifndef FALSE
#define FALSE 1
#endif /* FALSE */

#include <tfp_print.h>
#ifndef dprintf
#define dprintf tfp_printf
#endif /* dprintf */

#ifdef MODE_DEBUG
#define DPRINTF dprintf
#define assert(x) if(!(x)){dprintf("HALTED(%s:%i): assert(%s)\n",\
                                   __FILE__, __LINE__, #x);while(1);}
#else /* MODE_DEBUG */
#define DPRINTF(...) {}
#define assert(...)
#endif/* MODE_DEBUG */

/* Shared compiler attributes */
#define WEAK __weak
#define ALIGN(x)    __attribute__((aligned(x)))
#define FORCEINLINE inline __attribute__((always_inline))
#define PACKED      __attribute__((packed))
#define NORETURN    __attribute__((noreturn))

/* asm keyword */
#ifndef asm
#define asm __asm__
#endif

#ifdef  __cplusplus
#define EXTERN_C_BEGIN extern "C" {
#define EXTERN_C_END }
#else
#define EXTERN_C_BEGIN
#define EXTERN_C_END
#endif

/* array count macro */
#define ARRAY_COUNT(array, type) sizeof(array)/sizeof(type) 



#endif/* __UDEBUGGER_H__ */