#include "../inc/cub3D.h"

void    check_map(t_data *data)
{
    (void)data;
}



// void    check_border(char *line)
// {
//     int i;

//     i = 0;
//     while (line[i])
//     {
//         i++;
//     }
// }

// void    check_all_ones(char *line)
// {
//     int i;

//     i = -1;
//     while (line[++i])
//         if (line[i] != '1')
//             error_msg(INVALID_BORDER);
// }

// void    check_line(char *line, int ones)
// {
//     char    **splitted;
//     int     i;

//     i = 0;
//     splitted = ft_split(line, ' ');
//     while (splitted[i])
//     {
//         if (ones)
//             check_all_ones(splitted[i]);
//         else
//             check_border(splitted[i]);
//         i++;
//     }
// }

// void    check_map(t_data *data)
// {
//     int i;

//     i = 0;
//     if (ft_mtxlen(data->map) < 3)
//         error_msg(INVALID_MAP);
//     check_line(data->map[i++], 1);
//     while (data->map && data->map[i + 1])
//         check_line(data->map[i++], 0);
//     check_line(data->map[i], 1);
// }

