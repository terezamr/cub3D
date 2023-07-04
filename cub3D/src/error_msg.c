#include "../inc/cub3D.h"

void    error_msg(char *message)
{
    printf("%s%s%s\n%s\n", RED, "Error", RESET, message);
    exit(1);
}