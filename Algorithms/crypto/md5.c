#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FunF(x, y, z)	((x & y) | (~(x) & z))
#define FunG(x, y, z)	((x & z) | (~(z) & y))
#define FunH(x, y, z)	(x ^ y ^ z)
#define FunI(x, y, z)	(y ^ (~(z) | x))

#define LE_LEFTSHIFT(x, c)  (((x) << (c)) | ((x) >> (32 - (c))))
#define LE32_TO_BE32(num)   ((((num) >> 24) & 0xff) | (((num) << 8) & 0xff0000) | (((num) >> 8) & 0xff00) | (((num) << 24) & 0xff000000))
    
static uint32_t const T[64] = 
{
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};
static uint32_t const t_shift[64] = 
{
    7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
    5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

uint32_t* __cust_md5(uint8_t* __input_msg, size_t __input_length)
{
    uint8_t* msg = NULL;

    uint32_t hA = 0x67452301;
    uint32_t hB = 0xefcdab89;
    uint32_t hC = 0x98badcfe;
    uint32_t hD = 0x10325476;

    size_t length_new = ((((__input_length + 8) / 64) + 1) * 64) - 8;
 
    msg = calloc(length_new + 64, 1);
    memcpy(msg, __input_msg, __input_length);
    msg[__input_length] = 128;
 
    uint32_t length_bits = __input_length * 8;
    memcpy(msg + length_new, &length_bits, 4);

    for (uint32_t offset = 0; offset < length_new; offset += (512 / 8))
    {
        uint32_t* block = (uint32_t*)(msg + offset);

        uint32_t A = hA;
        uint32_t B = hB;
        uint32_t C = hC;
        uint32_t D = hD;
          
        for (uint32_t i = 0; i < 64; ++i)
        {
            uint32_t func, ii;

            if (i < 16) 
            {
                func = FunF(B, C, D);
                ii = i;
            } 
            else if (i < 32) 
            {
                func = FunG(B, C, D);
                ii = (5 * i + 1) % 16;
            } 
            else if (i < 48) 
            {
                func = FunH(B, C, D);
                ii = (3 * i + 5) % 16;          
            } 
            else 
            {
                func = FunI(B, C, D);
                ii = (7 * i + 0) % 16;
            };

            uint32_t tmp = D;
            D = C; 
            C = B;
            B += LE_LEFTSHIFT((A + func + T[i] + block[ii]), t_shift[i]);
            A = tmp;
        };

        hA += A;
        hB += B;
        hC += C;
        hD += D;
    };

    free(msg);

    uint32_t* res = (uint32_t*)malloc(4 * sizeof(uint32_t));
    *(res + 0) = LE32_TO_BE32(hA);
    *(res + 1) = LE32_TO_BE32(hB);
    *(res + 2) = LE32_TO_BE32(hC);
    *(res + 3) = LE32_TO_BE32(hD);

    return res;
};