#include "tigress.h"

#include "crypto_interface.h"

#ifdef KEY_1
static const unsigned char constant_1 = 214;
static const unsigned char constant_2_inverse = 161;
#endif
#ifdef KEY_2 
static const unsigned char constant_1 = 46;
static const unsigned char constant_2_inverse = 105;
#endif
#ifdef KEY_3 
static const unsigned char constant_1 = 1;
static const unsigned char constant_2_inverse = 127;
#endif


static unsigned char last_cypher_block[16];
static unsigned char tmp_buff[16];

static unsigned int sum(unsigned char *source, int amount){
    unsigned int result = 0;
    for(int i = 0; i < amount; i++)
        result += source[i];
    return result;  
}

static void array_sub(unsigned char *dest, unsigned char constant, int amount){
    for(int i = 0; i < amount; i++)
        dest[i] -= constant;
}

static void array_mult(unsigned char *dest, unsigned char constant, int amount){
    for(int i = 0; i < amount; i++)
        dest[i] *= constant;
}

static void arrays_xor(unsigned char *dest, unsigned char *source, int amount){
    for(int i = 0; i < amount; i++)
        dest[i] ^= source[i];
}

static void array_xor(unsigned char *dest, unsigned char constant, int amount){
    for(int i = 0; i < amount; i++)
        dest[i] ^= constant;
}

void decrypt_data(char* src, DWORD size) {
    int num_iterations = size / 16;
    int bytes_remaining = size % 16;

    unsigned char sum_constant = sum(src + ((num_iterations - 1) * 16), 16);
    for(int i = 0; i < num_iterations - 1; i++){
        array_xor(src + (i * 16), sum_constant, 16);
        arrays_xor(src + (i * 16), src + (num_iterations - 1) * 16, 16);
    }

    arrays_xor(src + num_iterations * 16, src + (num_iterations - 1) * 16, bytes_remaining);
    array_mult(src + num_iterations * 16, constant_2_inverse, bytes_remaining);
    array_sub(src + num_iterations * 16, constant_1, bytes_remaining);

    for(int i = 0; i < num_iterations; i++){
        for(int j = 0; j < 16; j++)
            tmp_buff[j] = src[(i * 16) + j];

        array_mult(src + i * 16, constant_2_inverse, 16);
        array_sub(src + i * 16, constant_1, 16);
        
        if(i != 0)
            arrays_xor(src + i * 16, last_cypher_block, 16);
        
        for(int j = 0; j < 16; j++)
            last_cypher_block[j] = tmp_buff[j];
        
    }
}