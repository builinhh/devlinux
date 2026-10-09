#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct __attribute__((packed)) Packed_1_t
{
    union test
    {
        uint32_t first;
        uint8_t arr[5];
    }t_1;
} pack_1_t;

typedef struct __attribute__((packed)) Packed_2_t
{
    union __attribute__((packed)) test_pack
    {
        uint32_t first;
        uint8_t arr[5];
    }t_2;
} pack_2_t;

typedef struct bitmap
{
    uint32_t EN:1;
    uint32_t MODE:3;
    uint32_t FLAG:1;
    uint32_t res:27;
} reg;

int main()
{
    pack_1_t test_1;
    pack_2_t test_2;

    printf("%zu\n", sizeof(test_1));
    printf("%zu\n", sizeof(test_2));

    reg regg = {0};
    regg.EN = 1;
    printf("%zu\n", sizeof(reg));
    return 0;
}