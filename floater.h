#include <stdint.h>

#define FLT_WIDTH 32

#if FLT_WIDTH == 32
/** 32 bit floating point number */
typedef uint32_t Float;
#define SIG_MASK 0x80000000
#define SIG_WIDTH 1
#define EXP_MASK 0x7F800000
#define EXP_WIDTH 8
#define MAN_MASK 0x007FFFFF
#define MAN_WIDTH 23
#define BIAS 127

#else
/** 64 bit floating point number */
#define SIG_MASK 0x80000000
#define SIG_WIDTH 1
#define EXP_MASK 0x7F800000
#define EXP_WIDTH 8
#define MAN_MASK 0x007FFFFF
#define MAN_WIDTH 23
#define BIAS 127
#endif

#define FLT_SIG(f) (((f) & SIG_MASK) >> (FLT_WIDTH - SIG_WIDTH));
#define FLT_EXP(f) (((f) & EXP_MASK) >> MAN_WIDTH);
#define FLT_MAN(f) ((f) & MAN_MASK);

#define IS_NAN(f) f & 0x007FFFFF
#define TO_SIG(s) ((Float)(s) << (FLT_WIDTH - SIG_WIDTH)) & SIG_MASK
#define TO_EXP(e) (((Float)(e) << MAN_WIDTH) & EXP_MASK)
#define TO_MAN(m) ((Float)(m) & MAN_MASK)

Float parse_float(const char *);
char *fmt_float(Float);

Float fadd(Float, Float);
Float fsub(Float, Float);
Float fmul(Float, Float);
Float fdiv(Float, Float);

char *dump_float(Float *num);

Float force_float(char *s);
