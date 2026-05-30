#include "tigress.h"

#include "crypto_interface.h"

#ifdef KEY_1
static const unsigned char constant_1 = 214;
static const unsigned char constant_2_inverse = 161;
#elifdef KEY_2 
static const unsigned char constant_1 = 46;
static const unsigned char constant_2_inverse = 105;
#else 
static const unsigned char constant_1 = 1;
static const unsigned char constant_2_inverse = 127;
#endif

static unsigned char last_cypher_block[16];
static unsigned char tmp_buff[16];

/* BEGIN FUNCTION-DEF decrypt_data LOC=UNKNOWN VKEY=1082 */
void decrypt_data(char *src , uint32_t size ) 
{ 
  int i_inline_9 ;
  int i_inline_8 ;
  int i_inline_7 ;
  int i_inline_6 ;
  int i_inline_5 ;
  int i_inline_4 ;
  unsigned int result_inline_3 ;
  int i_inline_2 ;
  int i_inline_1 ;
  int i_inline_0 ;
  int num_iterations ;
  int bytes_remaining ;
  unsigned char sum_constant ;
  unsigned int tmp ;
  int i ;
  int i___0 ;
  int j ;
  int j___0 ;
  unsigned char *dest11 ;
  unsigned char constant12 ;
  int amount13 ;
  unsigned char *dest15 ;
  unsigned char constant16 ;
  int amount17 ;
  unsigned char *dest19 ;
  unsigned char constant20 ;
  int amount21 ;
  unsigned char *source23 ;
  int amount24 ;
  unsigned int ret_sum27 ;
  unsigned char *dest28 ;
  unsigned char *source29 ;
  int amount30 ;
  unsigned char *dest32 ;
  unsigned char *source33 ;
  int amount34 ;
  unsigned char *dest36 ;
  unsigned char *source37 ;
  int amount38 ;
  unsigned char *dest40 ;
  unsigned char constant41 ;
  int amount42 ;
  unsigned char *dest44 ;
  unsigned char constant45 ;
  int amount46 ;

  {
  {
#line 48
  num_iterations = (int )(size / 16U);
#line 49
  bytes_remaining = (int )(size % 16U);
  source23 = (unsigned char *)(src + (num_iterations - 1) * 16);
  amount24 = 16;
  {
#line 21
  result_inline_3 = 0U;
#line 22
  i_inline_4 = 0;
#line 22
  while (i_inline_4 < amount24) {
#line 23
    result_inline_3 += (unsigned int )*(source23 + i_inline_4);
#line 22
    i_inline_4 ++;
  }
  {
#line 24
  ret_sum27 = result_inline_3;
#line 24
  goto _TIG_IL_TxP7_1_INLINE_sum;
  }
  }
  _TIG_IL_TxP7_1_INLINE_sum: /* CIL Label */ 
  tmp = ret_sum27;
#line 51
  sum_constant = (unsigned char )tmp;
#line 52
  i = 0;
  }
#line 52
  while (i < num_iterations - 1) {
    {
    dest11 = (unsigned char *)(src + i * 16);
    constant12 = sum_constant;
    amount13 = 16;
    {
#line 43
    i_inline_0 = 0;
#line 43
    while (i_inline_0 < amount13) {
#line 44
      *(dest11 + i_inline_0) = (unsigned char )((int )*(dest11 + i_inline_0) ^ (int )constant12);
#line 43
      i_inline_0 ++;
    }
#line 45
    goto _TIG_IL_TxP7_1_INLINE_array_xor;
    }
    _TIG_IL_TxP7_1_INLINE_array_xor: /* CIL Label */ ;
    {
    dest28 = (unsigned char *)(src + i * 16);
    source29 = (unsigned char *)(src + (num_iterations - 1) * 16);
    amount30 = 16;
    {
#line 38
    i_inline_5 = 0;
#line 38
    while (i_inline_5 < amount30) {
#line 39
      *(dest28 + i_inline_5) = (unsigned char )((int )*(dest28 + i_inline_5) ^ (int )*(source29 + i_inline_5));
#line 38
      i_inline_5 ++;
    }
#line 40
    goto _TIG_IL_TxP7_1_INLINE_arrays_xor;
    }
    _TIG_IL_TxP7_1_INLINE_arrays_xor: /* CIL Label */ ;
#line 52
    i ++;
    }
    }
  }
  {
  {
  dest32 = (unsigned char *)(src + num_iterations * 16);
  source33 = (unsigned char *)(src + (num_iterations - 1) * 16);
  amount34 = bytes_remaining;
  {
#line 38
  i_inline_6 = 0;
#line 38
  while (i_inline_6 < amount34) {
#line 39
    *(dest32 + i_inline_6) = (unsigned char )((int )*(dest32 + i_inline_6) ^ (int )*(source33 + i_inline_6));
#line 38
    i_inline_6 ++;
  }
#line 40
  goto _TIG_IL_TxP7_1_INLINE_arrays_xor___0;
  }
  _TIG_IL_TxP7_1_INLINE_arrays_xor___0: /* CIL Label */ ;
  dest15 = (unsigned char *)(src + num_iterations * 16);
  constant16 = (unsigned char )constant_2_inverse;
  amount17 = bytes_remaining;
  }
  {
#line 33
  i_inline_1 = 0;
#line 33
  while (i_inline_1 < amount17) {
#line 34
    *(dest15 + i_inline_1) = (unsigned char )((int )*(dest15 + i_inline_1) * (int )constant16);
#line 33
    i_inline_1 ++;
  }
#line 35
  goto _TIG_IL_TxP7_1_INLINE_array_mult;
  }
  _TIG_IL_TxP7_1_INLINE_array_mult: /* CIL Label */ ;
  {
  dest40 = (unsigned char *)(src + num_iterations * 16);
  constant41 = (unsigned char )constant_1;
  amount42 = bytes_remaining;
  {
#line 28
  i_inline_8 = 0;
#line 28
  while (i_inline_8 < amount42) {
#line 29
    *(dest40 + i_inline_8) = (unsigned char )((int )*(dest40 + i_inline_8) - (int )constant41);
#line 28
    i_inline_8 ++;
  }
#line 30
  goto _TIG_IL_TxP7_1_INLINE_array_sub;
  }
  _TIG_IL_TxP7_1_INLINE_array_sub: /* CIL Label */ ;
#line 61
  i___0 = 0;
  }
  }
#line 61
  while (i___0 < num_iterations) {
#line 62
    j = 0;
#line 62
    while (j < 16) {
#line 63
      tmp_buff[j] = (unsigned char )*(src + (i___0 * 16 + j));
#line 62
      j ++;
    }
    {
    dest19 = (unsigned char *)(src + i___0 * 16);
    constant20 = (unsigned char )constant_2_inverse;
    amount21 = 16;
    {
#line 33
    i_inline_2 = 0;
#line 33
    while (i_inline_2 < amount21) {
#line 34
      *(dest19 + i_inline_2) = (unsigned char )((int )*(dest19 + i_inline_2) * (int )constant20);
#line 33
      i_inline_2 ++;
    }
#line 35
    goto _TIG_IL_TxP7_1_INLINE_array_mult___0;
    }
    _TIG_IL_TxP7_1_INLINE_array_mult___0: /* CIL Label */ ;
    {
    dest44 = (unsigned char *)(src + i___0 * 16);
    constant45 = (unsigned char )constant_1;
    amount46 = 16;
    {
#line 28
    i_inline_9 = 0;
#line 28
    while (i_inline_9 < amount46) {
#line 29
      *(dest44 + i_inline_9) = (unsigned char )((int )*(dest44 + i_inline_9) - (int )constant45);
#line 28
      i_inline_9 ++;
    }
#line 30
    goto _TIG_IL_TxP7_1_INLINE_array_sub___0;
    }
    _TIG_IL_TxP7_1_INLINE_array_sub___0: /* CIL Label */ ;
    }
    }
#line 68
    if (i___0 != 0) {
      {
      dest36 = (unsigned char *)(src + i___0 * 16);
      source37 = last_cypher_block;
      amount38 = 16;
      {
#line 38
      i_inline_7 = 0;
#line 38
      while (i_inline_7 < amount38) {
#line 39
        *(dest36 + i_inline_7) = (unsigned char )((int )*(dest36 + i_inline_7) ^ (int )*(source37 + i_inline_7));
#line 38
        i_inline_7 ++;
      }
#line 40
      goto _TIG_IL_TxP7_1_INLINE_arrays_xor___1;
      }
      _TIG_IL_TxP7_1_INLINE_arrays_xor___1: /* CIL Label */ ;
      }
    }
#line 71
    j___0 = 0;
#line 71
    while (j___0 < 16) {
#line 72
      last_cypher_block[j___0] = tmp_buff[j___0];
#line 71
      j___0 ++;
    }
#line 61
    i___0 ++;
  }
#line 75
  return;
}
}
/* END FUNCTION-DEF decrypt_data LOC=UNKNOWN VKEY=1082 */