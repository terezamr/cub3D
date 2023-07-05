#include "../inc/cub3D.h"

void    error_msg(char *message)
{
    printf("%s%s%s\n", RED, "Error", RESET);
    printf("%s\n", message);
    exit(1);
}