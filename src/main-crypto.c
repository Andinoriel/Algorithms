#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

uint32_t* __cust_md5(uint8_t* __input_msg, size_t __input_length);

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        char* msg = argv[1];
        size_t length = strlen(msg);

        uint32_t* res = __cust_md5(msg, length);

        fprintf(stdout, "%x", *(res + 0));
        fprintf(stdout, "%x", *(res + 1));
        fprintf(stdout, "%x", *(res + 2));
        fprintf(stdout, "%x", *(res + 3));
        fprintf(stdout, "\n");

        free(res);
    }
    else
    {
        fprintf(stdout, "Using: %s <string>\n", argv[0]);
    };

    return 0;
};