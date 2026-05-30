#include "tigress.h"

#include "crypto_interface.h"

#define NUM_ROWS (4)
#define NUM_COLUMNS (4)

#ifdef KEY_1
static const int key_matrix_inverse[NUM_ROWS][NUM_COLUMNS] = {
    {124, 188, 152, 99}, 
    {60, 88, 23, 36}, 
    {163, 98, 190, 170},
    {220, 89, 88, 9}
};
#elifdef KEY_2
static const int key_matrix_inverse[NUM_ROWS][NUM_COLUMNS] = {
    {101, 30, 253, 12}, 
    {196, 83, 65, 203}, 
    {55, 237, 18, 22},
    {48, 117, 150, 244}
};
#else 
static const int key_matrix_inverse[NUM_ROWS][NUM_COLUMNS] = {
    {37, 111, 153, 238}, 
    {14, 43, 227, 137}, 
    {186, 86, 49, 204},
    {228, 208, 175, 81}
};
#endif

static int data_matrix[NUM_ROWS][NUM_COLUMNS] = {0};
static int last_matrix[NUM_ROWS][NUM_COLUMNS] = {0};
static int tmp_matrix[NUM_ROWS][NUM_COLUMNS] = {0};

/* BEGIN FUNCTION-DEF decrypt_data LOC=UNKNOWN VKEY=1068 */
void decrypt_data(char *src , uint32_t size ) 
{ 
  int j_inline_5 ;
  int i_inline_4 ;
  int i_inline_3 ;
  int k_inline_2 ;
  int j_inline_1 ;
  int i_inline_0 ;
  int num_multiplications ;
  int bytes_remaining ;
  int i ;
  int i___0 ;
  int k ;
  int j ;
  int j___0 ;
  int k___0 ;
  int k___1 ;
  int j___1 ;
  int i___1 ;
  int j_range ;
  int j___2 ;
  int (*matrix_116)[4] ;
  int (*matrix_217)[4] ;
  int (*matrix_result18)[4] ;
  char *dest22 ;
  char *adder23 ;
  int (*matrix_125)[4] ;
  int (*matrix_226)[4] ;
  int (*matrix_result27)[4] ;

  {
#line 58
  num_multiplications = (int )(size / 16U);
#line 59
  bytes_remaining = (int )(size % 16U);
#line 61
  i = 0;
#line 61
  while (i < num_multiplications - 1) {
    {
    dest22 = src + i * 16;
    adder23 = src + (num_multiplications - 1) * 16;
    {
#line 52
    i_inline_3 = 0;
#line 52
    while (i_inline_3 < 16) {
#line 53
      *(dest22 + i_inline_3) = (char )(((int )*(dest22 + i_inline_3) + (int )*(adder23 + i_inline_3)) % 256);
#line 52
      i_inline_3 ++;
    }
#line 55
    goto _TIG_IL_KAJD_1_INLINE_array_add;
    }
    _TIG_IL_KAJD_1_INLINE_array_add: /* CIL Label */ ;
#line 61
    i ++;
    }
  }
#line 65
  i___0 = 0;
#line 65
  while (i___0 < num_multiplications) {
#line 66
    k = 4 * i___0;
#line 66
    while (k < (i___0 + 1) * 4) {
#line 67
      j = k * 4;
#line 67
      while (j < (k + 1) * 4) {
#line 68
        data_matrix[k % 4][j % 4] = (int )((unsigned char )*(src + j));
#line 67
        j ++;
      }
#line 66
      k ++;
    }
    {
    matrix_116 = data_matrix;
    matrix_217 = (int (*)[4])(key_matrix_inverse);
    matrix_result18 = tmp_matrix;
    {
#line 42
    i_inline_0 = 0;
#line 42
    while (i_inline_0 < 4) {
#line 43
      j_inline_1 = 0;
#line 43
      while (j_inline_1 < 4) {
#line 44
        (*(matrix_result18 + i_inline_0))[j_inline_1] = 0;
#line 45
        k_inline_2 = 0;
#line 45
        while (k_inline_2 < 4) {
#line 46
          (*(matrix_result18 + i_inline_0))[j_inline_1] += (*(matrix_116 + i_inline_0))[k_inline_2] * (*(matrix_217 + k_inline_2))[j_inline_1];
#line 45
          k_inline_2 ++;
        }
#line 47
        (*(matrix_result18 + i_inline_0))[j_inline_1] %= 256;
#line 43
        j_inline_1 ++;
      }
#line 42
      i_inline_0 ++;
    }
#line 49
    goto _TIG_IL_KAJD_1_INLINE_matrix_mul;
    }
    _TIG_IL_KAJD_1_INLINE_matrix_mul: /* CIL Label */ ;
    }
#line 72
    if (i___0 != 0) {
      {
      matrix_125 = tmp_matrix;
      matrix_226 = last_matrix;
      matrix_result27 = tmp_matrix;
      {
#line 36
      i_inline_4 = 0;
#line 36
      while (i_inline_4 < 4) {
#line 37
        j_inline_5 = 0;
#line 37
        while (j_inline_5 < 4) {
#line 38
          (*(matrix_result27 + i_inline_4))[j_inline_5] = (*(matrix_125 + i_inline_4))[j_inline_5] ^ (*(matrix_226 + i_inline_4))[j_inline_5];
#line 37
          j_inline_5 ++;
        }
#line 36
        i_inline_4 ++;
      }
#line 39
      goto _TIG_IL_KAJD_1_INLINE_matrix_xor;
      }
      _TIG_IL_KAJD_1_INLINE_matrix_xor: /* CIL Label */ ;
      }
    }
#line 75
    j___0 = 0;
#line 75
    while (j___0 < 4) {
#line 76
      k___0 = 0;
#line 76
      while (k___0 < 4) {
#line 77
        last_matrix[j___0][k___0] = data_matrix[j___0][k___0];
#line 76
        k___0 ++;
      }
#line 75
      j___0 ++;
    }
#line 79
    k___1 = i___0 * 4;
#line 79
    while (k___1 < (i___0 + 1) * 4) {
#line 80
      j___1 = k___1 * 4;
#line 80
      while (j___1 < (k___1 + 1) * 4) {
#line 81
        *(src + j___1) = (char )tmp_matrix[(j___1 % 16) / 4][(j___1 % 16) % 4];
#line 80
        j___1 ++;
      }
#line 79
      k___1 ++;
    }
#line 65
    i___0 ++;
  }
#line 84
  i___1 = 0;
#line 84
  while (i___1 < bytes_remaining / 4 + 1) {
#line 85
    j_range = 4;
#line 86
    if (i___1 == bytes_remaining / 4) {
#line 87
      j_range = bytes_remaining % 4;
    }
#line 88
    j___2 = 0;
#line 88
    while (j___2 < j_range) {
#line 89
      *(src + (((size - size % 16U) + (uint32_t )(i___1 * 4)) + (uint32_t )j___2)) = (char )((int )*(src + (((size - size % 16U) + (uint32_t )(i___1 * 4)) + (uint32_t )j___2)) ^ last_matrix[i___1][j___2]);
#line 88
      j___2 ++;
    }
#line 84
    i___1 ++;
  }
#line 91
  return;
}
}
/* END FUNCTION-DEF decrypt_data LOC=UNKNOWN VKEY=1068 */
