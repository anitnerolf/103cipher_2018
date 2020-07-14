/*
** EPITECH PROJECT, 2018
** 103cipher
** File description:
** usage
*/

#include "my.h"

void	get_length(int ac, char **av)
{
    char	*text_string = av[1];
    char	*code_string = av[2];
    int	text_constat = strlen(text_string) % 3 == 0 ?
        strlen(text_string) / 3 : strlen(text_string) / 3 + 1;
    int	**matrix = allocate_memory(3, 3);
    int	**text_matrix = text_matrix1(text_string, text_constat);
    int	text_constat2 = strlen(text_string) % 2 == 0 ?
        strlen(text_string) / 2 : strlen(text_string) / 2 + 1;
    int	**matrix2 = allocate_memory(2, 2);
    int	**text_matrix22 = text_matrix2(text_string, text_constat2);

    if (strlen(av[2]) <= 4) {
        matrix2 = key_matrix2(code_string);
        encrypted_matrix2(text_matrix22, matrix2, text_constat2);
    } else if (strlen(av[2]) <= 9) {
        matrix = key_matrix(code_string);
        encrypted_matrix(text_matrix, matrix, text_constat);
    } else
        get_matrix4(ac, av);
}

void	my_condition(int ac, char **av)
{
    if ((av[3][0] == '0' || av[3][0] == '1') && !av[3][1]) {
        if (av[3][0] == '0') {
            get_length(ac, av);
            printf("\n");
	} else
            exit (84);
    } else
        exit (84);
}

int	my_usage(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h' && !av[1][2]) {
        my_usage_h();
        return (0);
    }
    exit (84);
}

void	my_usage_h(void)
{
    printf("USAGE\n");
    printf("\t./103cipher message key flag\n\n");
    printf("DESCRIPTION\n");
    printf("\tmessage\t");
    printf("a message, made of ASCII characters\n");
    printf("\tkey\t");
    printf("the encryption key, made of ASCII characters\n");
    printf("\tflag\t");
    printf("0 for the message to be encrypted, 1 to be decrypted\n");
}
