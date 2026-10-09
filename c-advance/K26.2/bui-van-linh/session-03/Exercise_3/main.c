#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum {
    PERM_READ    = (1 << 0),  // 0001
    PERM_WRITE   = (1 << 1),  // 0010
    PERM_EXECUTE = (1 << 2),  // 0100
    PERM_DELETE  = (1 << 3)   // 1000
} sys_perms_e;

/**
 * @brief Checks if the user has all the required permissions.
 */
bool has_permission(uint8_t user_perms, uint8_t required_perms)
{
   return (user_perms & required_perms) == required_perms;
}

int main()
{
    uint8_t admin = PERM_DELETE | PERM_EXECUTE | PERM_WRITE | PERM_READ;
    uint8_t required = PERM_WRITE | 0 | PERM_DELETE;

    printf("%d\n", has_permission(admin, required));
    return 0;
}