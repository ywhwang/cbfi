#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

enum operation {
  FP2INT = 11,
  INT2FP,
};

enum encoding {
  IEEE754 = 0,
  FIXED,
};

enum fpt_width {
  FLOAT_WIDTH_ALL,
  FLOAT_WIDTH_HALF   = 16,
  FLOAT_WIDTH_SINGLE = 32,
  FLOAT_WIDTH_DOUBLE = 64,
};

enum FPRound_Mode {
  FPRound_TIAEVEN,
  FPRound_TIAAWZERO,
  FPRound_ZERO,
  FPRound_PINFI,
  FPRound_MINFI,
};

enum fpt_detail {
  DISABLE_DETAIL,
  ENABLE_DETAIL,
};

struct ieee754_float_16 {
  unsigned fraction:10;
  unsigned exp:5;
  unsigned sign:1;
};

struct ieee754_float_32 {
  unsigned fraction:23;
  unsigned exp:8;
  unsigned sign:1;
};

struct ieee754_float_64 {
  unsigned long fraction:52;
  unsigned long exp:11;
  unsigned long sign:1;
};

struct convert_attr {
  enum encoding   type;
  enum operation  opt;
  enum fpt_width  bwidth;
  enum fpt_detail detail;
};

struct float_point {
  float  fpt_16;
  float  fpt_32;
  double fpt_64;
};

struct fixed_point {
  unsigned char fixed_16[2];
  unsigned char fixed_32[4];
  unsigned char fixed_64[8];
  unsigned      frac_bits;
};

struct convert {
  /*
    when fp 2 int, input data stored at fpt_set
    when int 2 fp, input data stored the raw
   */
  struct convert_attr attr;
  unsigned char       raw[16];
  struct float_point  fpt_set;
  /*
    when fp to fixed, input data stored at fpt_set, use double only
    when fixed to fp, input data stored at raw
   */
  struct fixed_point  fixed;
};

#endif
