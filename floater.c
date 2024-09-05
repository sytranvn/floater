#include "floater.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bit_count(n) 32 - __builtin_clz(n)

Float parse_float(const char *s) {
  Float f = 0;
  int whole_num;
  char decml_num[50];
  int scanned;
  uint32_t exp = BIAS;

  // the decimal part can have leading zeroes, need to handle it manually
  scanned = sscanf(s, "%d.%s", &whole_num, decml_num);
  if (whole_num < 0) {
    f |= TO_SIG(whole_num);
    whole_num = -whole_num;
  }
  // parse whole num
  int bc = sizeof(whole_num) * 8 - __builtin_clz(whole_num);

  if ( bc > 0 && bc < MAN_WIDTH ) {
    // 1100 1100
    // 0_0000 0000_1001 1000 0000 0000 0000 000
    whole_num = whole_num << (MAN_WIDTH - bc + 1);
    exp += bc - 1;
  } else if (bc > MAN_WIDTH) {
    whole_num = whole_num >> (bc - MAN_WIDTH + 1);
  }
  f |= TO_EXP(exp);
  printf("%s\n", dump_float(&f));
  f |= TO_MAN(whole_num);
  printf("%s\n", dump_float(&f));
  
  // end parse whole num
  if (scanned > 1) {
    // TODO: leading zeros in decimal num?
    // handle decml part
  }

  return f;
};
char *fmt_float(Float f) {
  char *s = malloc(100);
  sprintf(s, "%f", *(float *)&f);
  return s;
};

Float fadd(Float a, Float b) {
  Float f;
  uint8_t siga = FLT_SIG(a);
  uint8_t sigb = FLT_SIG(b);
  uint8_t expa = FLT_EXP(a);
  uint8_t expb = FLT_EXP(b);
  uint32_t mana = FLT_MAN(a);
  uint32_t manb = FLT_MAN(b);
  return f;
};
Float fsub(Float a, Float b) {
  Float f;
  return f;
};
Float fmul(Float a, Float b) { return 0; };
Float fdiv(Float a, Float b) { return 0; };

char *dump_float(Float *num) {
  u_int32_t *bits;
  char *out = malloc(33);
  bits = (uint32_t *)num;
  for (int i = 31; i >= 0; --i) {
    out[31 - i] = (*bits >> i) & 1 + '0';
  }
  return out;
}

Float force_float(char *s) {
  size_t l = strlen(s);
  Float f = 0;
  for (int i = 0; i < l; ++i) {
    f |= ((s[i] == '1' ? 1 : 0) << (31 - i));
  }
  return f;
};
