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

void matrix_xor(void *bogus___17 , int (*matrix_2)[4] , double bogus___15 , int bogus___16 ,
                double bogus___19 , int (*matrix_1)[4] , double bogus___18 , int bogus___21 ,
                void *bogus___20 , int (*matrix_result)[4] ) 
{ 
  int i ;
  int j ;
  unsigned int _TIG_FN_99gO_1_matrix_xor_next ;

  {
  {
  _TIG_FN_99gO_1_matrix_xor_next = 9U;
  }
  while (1) {
    switch (_TIG_FN_99gO_1_matrix_xor_next) {
    case 8U: 
#line 29
    i ++;
    {
    _TIG_FN_99gO_1_matrix_xor_next = 2U;
    }
    break;
    case 1U: 
#line 31
    (*(matrix_result + i))[j] = (*(matrix_1 + i))[j] ^ (*(matrix_2 + i))[j];
#line 30
    j ++;
    {
    _TIG_FN_99gO_1_matrix_xor_next = 5U;
    }
    break;
    case 3U: 
#line 30
    j = 0;
    {
    _TIG_FN_99gO_1_matrix_xor_next = 5U;
    }
    break;
    case 9U: 
#line 29
    i = 0;
    {
    _TIG_FN_99gO_1_matrix_xor_next = 2U;
    }
    break;
    case 5U: ;
    if (j < 4) {
      {
      _TIG_FN_99gO_1_matrix_xor_next = 1U;
      }
    } else {
      {
      _TIG_FN_99gO_1_matrix_xor_next = 8U;
      }
    }
    break;
    case 7U: ;
    return;
    break;
    case 2U: ;
    if (i < 4) {
      {
      _TIG_FN_99gO_1_matrix_xor_next = 3U;
      }
    } else {
      {
      _TIG_FN_99gO_1_matrix_xor_next = 7U;
      }
    }
    break;
    default: 
    break;
    }
  }
}
}

void matrix_mul(int (*matrix_result)[4] , long bogus___12 , int bogus___8 , int bogus___13 ,
                void *bogus___10 , int (*matrix_1)[4] , int (*matrix_2)[4] , double bogus___11 ,
                void *bogus___9 , double bogus___14 ) 
{ 
  int i ;
  int j ;
  int k ;
  unsigned int _TIG_FN_99gO_1_matrix_mul_next ;

  {
  {
  _TIG_FN_99gO_1_matrix_mul_next = 18U;
  }
  while (1) {
    switch (_TIG_FN_99gO_1_matrix_mul_next) {
    case 18U: 
#line 35
    i = 0;
    {
    _TIG_FN_99gO_1_matrix_mul_next = 15U;
    }
    break;
    case 4U: ;
    return;
    break;
    case 14U: ;
    if (j < 4) {
      {
      _TIG_FN_99gO_1_matrix_mul_next = 2U;
      }
    } else {
      {
      _TIG_FN_99gO_1_matrix_mul_next = 6U;
      }
    }
    break;
    case 15U: ;
    if (i < 4) {
      {
      _TIG_FN_99gO_1_matrix_mul_next = 10U;
      }
    } else {
      {
      _TIG_FN_99gO_1_matrix_mul_next = 4U;
      }
    }
    break;
    case 3U: 
#line 39
    (*(matrix_result + i))[j] += (*(matrix_1 + i))[k] * (*(matrix_2 + k))[j];
#line 38
    k ++;
    {
    _TIG_FN_99gO_1_matrix_mul_next = 9U;
    }
    break;
    case 11U: 
#line 40
    (*(matrix_result + i))[j] %= 256;
#line 36
    j ++;
    {
    _TIG_FN_99gO_1_matrix_mul_next = 14U;
    }
    break;
    case 9U: ;
    if (k < 4) {
      {
      _TIG_FN_99gO_1_matrix_mul_next = 3U;
      }
    } else {
      {
      _TIG_FN_99gO_1_matrix_mul_next = 11U;
      }
    }
    break;
    case 6U: 
#line 35
    i ++;
    {
    _TIG_FN_99gO_1_matrix_mul_next = 15U;
    }
    break;
    case 10U: 
#line 36
    j = 0;
    {
    _TIG_FN_99gO_1_matrix_mul_next = 14U;
    }
    break;
    case 2U: 
#line 37
    (*(matrix_result + i))[j] = 0;
#line 38
    k = 0;
    {
    _TIG_FN_99gO_1_matrix_mul_next = 9U;
    }
    break;
    default: 
    break;
    }
  }
}
}

void array_add(double bogus___3 , double bogus___7 , int bogus___5 , double bogus___4 ,
               char *dest , int bogus___1 , int bogus___6 , char *adder , double bogus___2 ) 
{ 
  int i ;
  unsigned int _TIG_FN_99gO_1_array_add_next ;

  {
  {
  _TIG_FN_99gO_1_array_add_next = 5U;
  }
  while (1) {
    switch (_TIG_FN_99gO_1_array_add_next) {
    case 4U: ;
    if (i < 16) {
      {
      _TIG_FN_99gO_1_array_add_next = 1U;
      }
    } else {
      {
      _TIG_FN_99gO_1_array_add_next = 0U;
      }
    }
    break;
    case 1U: 
#line 46
    *(dest + i) = (char )(((int )*(dest + i) + (int )*(adder + i)) % 256);
#line 45
    i ++;
    {
    _TIG_FN_99gO_1_array_add_next = 4U;
    }
    break;
    case 5U: 
#line 45
    i = 0;
    {
    _TIG_FN_99gO_1_array_add_next = 4U;
    }
    break;
    case 0U: ;
    return;
    break;
    default: 
    break;
    }
  }
}
}

void decrypt_data(char *src , uint32_t size ) 
{ 
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
  unsigned int _TIG_FN_99gO_1_decrypt_data_next ;

  {
  {
  _TIG_FN_99gO_1_decrypt_data_next = 4U;
  }
  while (1) {
    switch (_TIG_FN_99gO_1_decrypt_data_next) {
    case 25U: 
#line 78
    j_range = 4;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 62U;
    }
    break;
    case 52U: 
#line 81
    j___2 = 0;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 19U;
    }
    break;
    case 4U: ;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 31U;
    }
    break;
    case 30U: 
#line 68
    j___0 ++;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 47U;
    }
    break;
    case 62U: ;
    if (i___1 == bytes_remaining / 4) {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 0U;
      }
    } else {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 52U;
      }
    }
    break;
    case 14U: ;
    if (i___1 < bytes_remaining / 4 + 1) {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 25U;
      }
    } else {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 29U;
      }
    }
    break;
    case 15U: 
#line 77
    i___1 ++;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 14U;
    }
    break;
    case 56U: 
#line 77
    i___1 = 0;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 14U;
    }
    break;
    case 31U: 
#line 51
    num_multiplications = (int )(size / 16U);
#line 52
    bytes_remaining = (int )(size % 16U);
#line 54
    i = 0;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 1U;
    }
    break;
    case 1U: ;
    if (i < num_multiplications - 1) {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 53U;
      }
    } else {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 32U;
      }
    }
    break;
    case 23U: 
#line 82
    *(src + (((size - size % 16U) + (uint32_t )(i___1 * 4)) + (uint32_t )j___2)) = (char )((int )*(src + (((size - size % 16U) + (uint32_t )(i___1 * 4)) + (uint32_t )j___2)) ^ last_matrix[i___1][j___2]);
#line 81
    j___2 ++;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 19U;
    }
    break;
    case 3U: 
#line 70
    last_matrix[j___0][k___0] = data_matrix[j___0][k___0];
#line 69
    k___0 ++;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 9U;
    }
    break;
    case 57U: ;
    if (k < (i___0 + 1) * 4) {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 2U;
      }
    } else {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 61U;
      }
    }
    break;
    case 26U: 
#line 69
    k___0 = 0;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 9U;
    }
    break;
    case 11U: 
#line 61
    data_matrix[k % 4][j % 4] = (int )((unsigned char )*(src + j));
#line 60
    j ++;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 27U;
    }
    break;
    case 9U: ;
    if (k___0 < 4) {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 3U;
      }
    } else {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 30U;
      }
    }
    break;
    case 19U: ;
    if (j___2 < j_range) {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 23U;
      }
    } else {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 15U;
      }
    }
    break;
    case 32U: 
#line 58
    i___0 = 0;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 46U;
    }
    break;
    case 55U: 
#line 74
    *(src + j___1) = (char )tmp_matrix[(j___1 % 16) / 4][(j___1 % 16) % 4];
#line 73
    j___1 ++;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 34U;
    }
    break;
    case 6U: 
#line 59
    k ++;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 57U;
    }
    break;
    case 27U: ;
    if (j < (k + 1) * 4) {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 11U;
      }
    } else {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 6U;
      }
    }
    break;
    case 38U: 
#line 68
    j___0 = 0;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 47U;
    }
    break;
    case 61U: 
#line 63
    matrix_mul(tmp_matrix, 3L, j_range, i, 0, data_matrix, (int (*)[4])(key_matrix_inverse),
               5., 0, 8.);
    {
    _TIG_FN_99gO_1_decrypt_data_next = 39U;
    }
    break;
    case 58U: 
#line 58
    i___0 ++;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 46U;
    }
    break;
    case 34U: ;
    if (j___1 < (k___1 + 1) * 4) {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 55U;
      }
    } else {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 22U;
      }
    }
    break;
    case 22U: 
#line 72
    k___1 ++;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 44U;
    }
    break;
    case 28U: 
#line 73
    j___1 = k___1 * 4;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 34U;
    }
    break;
    case 53U: 
#line 55
    array_add(8., 8., k___1, 0., src + i * 16, k, k___1, src + (num_multiplications - 1) * 16,
              3.);
#line 54
    i ++;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 1U;
    }
    break;
    case 47U: ;
    if (j___0 < 4) {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 26U;
      }
    } else {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 7U;
      }
    }
    break;
    case 44U: ;
    if (k___1 < (i___0 + 1) * 4) {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 28U;
      }
    } else {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 58U;
      }
    }
    break;
    case 10U: 
#line 66
    matrix_xor(0, last_matrix, 8., k___1, 3., tmp_matrix, 0., j_range, 0, tmp_matrix);
    {
    _TIG_FN_99gO_1_decrypt_data_next = 38U;
    }
    break;
    case 0U: 
#line 80
    j_range = bytes_remaining % 4;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 52U;
    }
    break;
    case 46U: ;
    if (i___0 < num_multiplications) {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 43U;
      }
    } else {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 56U;
      }
    }
    break;
    case 39U: ;
    if (i___0 != 0) {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 10U;
      }
    } else {
      {
      _TIG_FN_99gO_1_decrypt_data_next = 38U;
      }
    }
    break;
    case 7U: 
#line 72
    k___1 = i___0 * 4;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 44U;
    }
    break;
    case 29U: ;
    return;
    break;
    case 43U: 
#line 59
    k = 4 * i___0;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 57U;
    }
    break;
    case 2U: 
#line 60
    j = k * 4;
    {
    _TIG_FN_99gO_1_decrypt_data_next = 27U;
    }
    break;
    default: 
    break;
    }
  }
}
}