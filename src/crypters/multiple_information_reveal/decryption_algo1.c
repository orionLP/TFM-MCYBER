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

static void matrix_xor(int (*matrix_1)[NUM_COLUMNS], int (*matrix_2)[NUM_COLUMNS], int (*matrix_result)[NUM_COLUMNS]){
    for(int i = 0; i < NUM_ROWS; i++)
        for(int j = 0; j < NUM_COLUMNS; j++)
            matrix_result[i][j] = matrix_1[i][j] ^ matrix_2[i][j];
}

static void matrix_mul(int (*matrix_1)[NUM_COLUMNS], int (*matrix_2)[NUM_COLUMNS], int (*matrix_result)[NUM_COLUMNS]){
    for(int i = 0; i < NUM_ROWS; i++)
        for(int j = 0; j < NUM_COLUMNS; j++){
            matrix_result[i][j] = 0;
            for(int k = 0; k < NUM_ROWS; k++)
                matrix_result[i][j] += matrix_1[i][k] * matrix_2[k][j];
            matrix_result[i][j] %= 256;
        }
}

static void array_add(char *dest, char *adder){
    for(int i = 0; i < 16; i++){
        dest[i] = (dest[i] + adder[i]) % 256;
    }
}

void decrypt_data(char* src, DWORD size) {
    int num_multiplications = size / 16;
    int bytes_remaining = size % 16;

    for(int i = 0; i < num_multiplications - 1; i++){
        array_add(src + (i * 16), src + ((num_multiplications - 1) * 16));
    }

    for(int i = 0; i < num_multiplications; i++){
        for(int k = 4 * i; k < ((i + 1) * 4); k++)
            for(int j = k * 4; j < ((k+1) * 4); j++)
                data_matrix[k % 4][j % 4] = (unsigned char) src[j];
        
        matrix_mul(data_matrix, key_matrix_inverse, tmp_matrix);
        
        if(i != 0)
            matrix_xor(tmp_matrix, last_matrix, tmp_matrix);

        for(int j = 0; j < NUM_ROWS; j++)
            for(int k = 0; k < NUM_COLUMNS; k++)
                last_matrix[j][k] = data_matrix[j][k];

        for(int k = i * 4; k < (i+1) * 4; k++)
            for(int j = k * 4; j < (k+1) * 4; j++)
                src[j] = tmp_matrix[(j % 16) / 4][(j % 16) % 4];
    }
    
    for(int i = 0; i < (bytes_remaining/4) + 1; i++){
        int j_range = 4;
        if(i == (bytes_remaining / 4))
            j_range = bytes_remaining % 4;
        for(int j = 0; j < j_range; j++)
            src[(size - (size % 16)) + (i * 4) + j] ^= last_matrix[i][j];
    }
}
