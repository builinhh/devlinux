#include <stdio.h>
#include <stdint.h>

typedef union {
    uint32_t fullword;
    uint8_t byte[4];
} endian_checker_u;

int main()
{
    endian_checker_u endian_check;
    endian_check.fullword = 0x11223344;

    for(int i = 0; i < sizeof(endian_check.fullword); i++)
    {
        printf("%2x\n", endian_check.byte[i]);
    }
    return 0;
}