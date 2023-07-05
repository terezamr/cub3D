#include "../inc/cub3D.h"

int error_message(char *message)
{
    ft_printf("%s", RED);
    ft_printf("%s", "Error: ");
    ft_printf("%s", RESET);
    ft_printf("%s\n", message);
    return (1);
}