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

/* BEGIN FUNCTION-DEF sum LOC=UNKNOWN VKEY=1237 */
unsigned int sum(long bogus___32 , void *bogus___31 , double bogus___29 , long bogus___30 ,
                 unsigned char *source , void *bogus___33 , int amount , double bogus___35 ,
                 int bogus___34 ) 
{ 
  unsigned int result ;
  int i ;
  unsigned int _TIG_FN_ox2t_1_sum_next ;

  {
  {
  _TIG_FN_ox2t_1_sum_next = 3U;
  }
  while (1) {
    switch (_TIG_FN_ox2t_1_sum_next) {
    case 1U: ;
    return (result);
    break;
    case 3U: ;
    {
    _TIG_FN_ox2t_1_sum_next = 6U;
    }
    break;
    case 6U: 
#line 21
    result = 0U;
#line 22
    i = 0;
    {
    _TIG_FN_ox2t_1_sum_next = 7U;
    }
    break;
    case 5U: 
#line 23
    result += (unsigned int )*(source + i);
#line 22
    i ++;
    {
    _TIG_FN_ox2t_1_sum_next = 7U;
    }
    break;
    case 7U: ;
    if (i < amount) {
      {
      _TIG_FN_ox2t_1_sum_next = 5U;
      }
    } else {
      {
      _TIG_FN_ox2t_1_sum_next = 1U;
      }
    }
    break;
    default: 
    break;
    }
  }
}
}
/* END FUNCTION-DEF sum LOC=UNKNOWN VKEY=1237 */



/* BEGIN FUNCTION-DEF array_xor LOC=UNKNOWN VKEY=1179 */
void array_xor(void *bogus___17 , int bogus___15 , int amount , unsigned char constant ,
               long bogus___18 , unsigned char *dest , void *bogus___19 , double bogus___21 ,
               int bogus___16 , int bogus___20 ) 
{ 
  int i ;
  unsigned int _TIG_FN_ox2t_1_array_xor_next ;

  {
  {
  _TIG_FN_ox2t_1_array_xor_next = 1U;
  }
  while (1) {
    switch (_TIG_FN_ox2t_1_array_xor_next) {
    case 1U: 
#line 43
    i = 0;
    {
    _TIG_FN_ox2t_1_array_xor_next = 6U;
    }
    break;
    case 6U: ;
    if (i < amount) {
      {
      _TIG_FN_ox2t_1_array_xor_next = 5U;
      }
    } else {
      {
      _TIG_FN_ox2t_1_array_xor_next = 0U;
      }
    }
    break;
    case 5U: 
#line 44
    *(dest + i) = (unsigned char )((int )*(dest + i) ^ (int )constant);
#line 43
    i ++;
    {
    _TIG_FN_ox2t_1_array_xor_next = 6U;
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
/* END FUNCTION-DEF array_xor LOC=UNKNOWN VKEY=1179 */


/* BEGIN FUNCTION-DEF array_sub LOC=UNKNOWN VKEY=1150 */
void array_sub(void *bogus___13 , double bogus___9 , double bogus___12 , unsigned char constant ,
               long bogus___10 , int bogus___14 , int bogus___11 , int amount , void *bogus___8 ,
               unsigned char *dest ) 
{ 
  int i ;
  unsigned int _TIG_FN_ox2t_1_array_sub_next ;

  {
  {
  _TIG_FN_ox2t_1_array_sub_next = 5U;
  }
  while (1) {
    switch (_TIG_FN_ox2t_1_array_sub_next) {
    case 4U: ;
    if (i < amount) {
      {
      _TIG_FN_ox2t_1_array_sub_next = 1U;
      }
    } else {
      {
      _TIG_FN_ox2t_1_array_sub_next = 0U;
      }
    }
    break;
    case 1U: 
#line 29
    *(dest + i) = (unsigned char )((int )*(dest + i) - (int )constant);
#line 28
    i ++;
    {
    _TIG_FN_ox2t_1_array_sub_next = 4U;
    }
    break;
    case 5U: 
#line 28
    i = 0;
    {
    _TIG_FN_ox2t_1_array_sub_next = 4U;
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
/* END FUNCTION-DEF array_sub LOC=UNKNOWN VKEY=1150 */

/* BEGIN FUNCTION-DEF array_mult LOC=UNKNOWN VKEY=1121 */
void array_mult(long bogus___2 , double bogus___3 , unsigned char constant , int bogus___6 ,
                double bogus___4 , double bogus___5 , long bogus___1 , double bogus___7 ,
                int amount , unsigned char *dest ) 
{ 
  int i ;
  unsigned int _TIG_FN_ox2t_1_array_mult_next ;

  {
  {
  _TIG_FN_ox2t_1_array_mult_next = 0U;
  }
  while (1) {
    switch (_TIG_FN_ox2t_1_array_mult_next) {
    case 1U: ;
    return;
    break;
    case 3U: 
#line 34
    *(dest + i) = (unsigned char )((int )*(dest + i) * (int )constant);
#line 33
    i ++;
    {
    _TIG_FN_ox2t_1_array_mult_next = 5U;
    }
    break;
    case 5U: ;
    if (i < amount) {
      {
      _TIG_FN_ox2t_1_array_mult_next = 3U;
      }
    } else {
      {
      _TIG_FN_ox2t_1_array_mult_next = 1U;
      }
    }
    break;
    case 0U: 
#line 33
    i = 0;
    {
    _TIG_FN_ox2t_1_array_mult_next = 5U;
    }
    break;
    default: 
    break;
    }
  }
}
}
/* END FUNCTION-DEF array_mult LOC=UNKNOWN VKEY=1121 */

/* BEGIN FUNCTION-DEF arrays_xor LOC=UNKNOWN VKEY=1208 */
void arrays_xor(void *bogus___28 , unsigned char *source , void *bogus___24 , int amount ,
                double bogus___27 , int bogus___25 , void *bogus___23 , void *bogus___22 ,
                unsigned char *dest , double bogus___26 ) 
{ 
  int i ;
  unsigned int _TIG_FN_ox2t_1_arrays_xor_next ;

  {
  {
  _TIG_FN_ox2t_1_arrays_xor_next = 2U;
  }
  while (1) {
    switch (_TIG_FN_ox2t_1_arrays_xor_next) {
    case 1U: ;
    if (i < amount) {
      {
      _TIG_FN_ox2t_1_arrays_xor_next = 5U;
      }
    } else {
      {
      _TIG_FN_ox2t_1_arrays_xor_next = 0U;
      }
    }
    break;
    case 5U: 
#line 39
    *(dest + i) = (unsigned char )((int )*(dest + i) ^ (int )*(source + i));
#line 38
    i ++;
    {
    _TIG_FN_ox2t_1_arrays_xor_next = 1U;
    }
    break;
    case 0U: ;
    return;
    break;
    case 2U: 
#line 38
    i = 0;
    {
    _TIG_FN_ox2t_1_arrays_xor_next = 1U;
    }
    break;
    default: 
    break;
    }
  }
}
}
/* END FUNCTION-DEF arrays_xor LOC=UNKNOWN VKEY=1208 */

/* BEGIN FUNCTION-DEF decrypt_data LOC=UNKNOWN VKEY=1227 */
void decrypt_data(char *src , uint32_t size ) 
{ 
  int num_iterations ;
  int bytes_remaining ;
  unsigned char sum_constant ;
  unsigned int tmp ;
  int i ;
  int i___0 ;
  int j ;
  int j___0 ;
  unsigned int _TIG_FN_ox2t_1_decrypt_data_next ;

  {
  {
  _TIG_FN_ox2t_1_decrypt_data_next = 27U;
  }
  while (1) {
    switch (_TIG_FN_ox2t_1_decrypt_data_next) {
    case 18U: 
#line 72
    last_cypher_block[j___0] = tmp_buff[j___0];
#line 71
    j___0 ++;
    {
    _TIG_FN_ox2t_1_decrypt_data_next = 23U;
    }
    break;
    case 25U: 
#line 57
    arrays_xor(0, (unsigned char *)(src + (num_iterations - 1) * 16), 0, bytes_remaining,
               0., num_iterations, 0, 0, (unsigned char *)(src + num_iterations * 16),
               3.);
#line 58
    array_mult(7L, 9., (unsigned char )constant_2_inverse, num_iterations, 6., 1.,
               8L, 8., bytes_remaining, (unsigned char *)(src + num_iterations * 16));
#line 59
    array_sub(0, 7., 5., (unsigned char )constant_1, 8L, i, i, bytes_remaining, 0,
              (unsigned char *)(src + num_iterations * 16));
#line 61
    i___0 = 0;
    {
    _TIG_FN_ox2t_1_decrypt_data_next = 19U;
    }
    break;
    case 4U: 
#line 62
    j = 0;
    {
    _TIG_FN_ox2t_1_decrypt_data_next = 29U;
    }
    break;
    case 15U: ;
    if (i___0 != 0) {
      {
      _TIG_FN_ox2t_1_decrypt_data_next = 7U;
      }
    } else {
      {
      _TIG_FN_ox2t_1_decrypt_data_next = 3U;
      }
    }
    break;
    case 12U: ;
    if (i < num_iterations - 1) {
      {
      _TIG_FN_ox2t_1_decrypt_data_next = 21U;
      }
    } else {
      {
      _TIG_FN_ox2t_1_decrypt_data_next = 25U;
      }
    }
    break;
    case 23U: ;
    if (j___0 < 16) {
      {
      _TIG_FN_ox2t_1_decrypt_data_next = 18U;
      }
    } else {
      {
      _TIG_FN_ox2t_1_decrypt_data_next = 22U;
      }
    }
    break;
    case 3U: 
#line 71
    j___0 = 0;
    {
    _TIG_FN_ox2t_1_decrypt_data_next = 23U;
    }
    break;
    case 16U: 
#line 65
    array_mult(0L, 0., (unsigned char )constant_2_inverse, j, 2., 3., 9L, 9., 16,
               (unsigned char *)(src + i___0 * 16));
#line 66
    array_sub(0, 0., 5., (unsigned char )constant_1, 8L, j, j, 16, 0, (unsigned char *)(src + i___0 * 16));
    {
    _TIG_FN_ox2t_1_decrypt_data_next = 15U;
    }
    break;
    case 21U: 
#line 53
    array_xor(0, i, 16, sum_constant, 5L, (unsigned char *)(src + i * 16), 0, 0.,
              i, i);
#line 54
    arrays_xor(0, (unsigned char *)(src + (num_iterations - 1) * 16), 0, 16, 1., bytes_remaining,
               0, 0, (unsigned char *)(src + i * 16), 0.);
#line 52
    i ++;
    {
    _TIG_FN_ox2t_1_decrypt_data_next = 12U;
    }
    break;
    case 26U: ;
    return;
    break;
    case 9U: 
#line 48
    num_iterations = (int )(size / 16U);
#line 49
    bytes_remaining = (int )(size % 16U);
#line 51
    tmp = sum(0L, 0, 8., 2L, (unsigned char *)(src + (num_iterations - 1) * 16), 0,
              16, 5., j);
#line 51
    sum_constant = (unsigned char )tmp;
#line 52
    i = 0;
    {
    _TIG_FN_ox2t_1_decrypt_data_next = 12U;
    }
    break;
    case 19U: ;
    if (i___0 < num_iterations) {
      {
      _TIG_FN_ox2t_1_decrypt_data_next = 4U;
      }
    } else {
      {
      _TIG_FN_ox2t_1_decrypt_data_next = 26U;
      }
    }
    break;
    case 17U: 
#line 63
    tmp_buff[j] = (unsigned char )*(src + (i___0 * 16 + j));
#line 62
    j ++;
    {
    _TIG_FN_ox2t_1_decrypt_data_next = 29U;
    }
    break;
    case 27U: ;
    {
    _TIG_FN_ox2t_1_decrypt_data_next = 9U;
    }
    break;
    case 22U: 
#line 61
    i___0 ++;
    {
    _TIG_FN_ox2t_1_decrypt_data_next = 19U;
    }
    break;
    case 7U: 
#line 69
    arrays_xor(0, last_cypher_block, 0, 16, 7., bytes_remaining, 0, 0, (unsigned char *)(src + i___0 * 16),
               8.);
    {
    _TIG_FN_ox2t_1_decrypt_data_next = 3U;
    }
    break;
    case 29U: ;
    if (j < 16) {
      {
      _TIG_FN_ox2t_1_decrypt_data_next = 17U;
      }
    } else {
      {
      _TIG_FN_ox2t_1_decrypt_data_next = 16U;
      }
    }
    break;
    default: 
    break;
    }
  }
}
}
/* END FUNCTION-DEF decrypt_data LOC=UNKNOWN VKEY=1227 */

