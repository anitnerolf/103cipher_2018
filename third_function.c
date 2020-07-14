/*
** EPITECH PROJECT, 2018
** 103cipher
** File description:
** matrix4x4
*/

#include "my.h"

int	**key_matrix4(char *code_string)
{
    int	**matrix4 = allocate_memory(4, 4);
    int	matrix_counter4 = 0;

    printf("Key Matrix:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (strlen(code_string) > matrix_counter4) {
                matrix4[i][j] = code_string[matrix_counter4];
            } else {
                matrix4[i][j] = 0;
            }
            printf("%d", matrix4[i][j]);
            if (j < 3)
                printf("\t");
            matrix_counter4++;
        }
        printf("\n");
    }
    return (matrix4);
}

int	**text_matrix4(char *text_string, int text_constat4)
{
    int	i = 0;
    int	j = 0;
    int	**text_matrix44 = allocate_memory(text_constat4, 4);
    int	mtext_counter4 = 0;

    for (i = 0; i < text_constat4; i++) {
        for (j = 0; j < 2; j++) {
            if (strlen(text_string) > mtext_counter4) {
                text_matrix44[i][j] = text_string[mtext_counter4];
            } else {
                text_matrix44[i][j] = 0;
            }
            mtext_counter4++;
        }
    }
    return (text_matrix44);
}

int	**encrypted_matrix4(int **text_matrix44, int **matrix4,
                            int text_constat4)
{
    int	**encrypted4 = allocate_memory(text_constat4, 4);
    int	e_counter4 = 0;

    printf("\nEncrypted Message:\n");
    for (int i = 0; i < text_constat4; i++) {
        for (int j = 0; j < 4; j++) {
            encrypted4[i][j] = matrix4[0][e_counter4] * text_matrix44[i][0] +
                matrix4[1][e_counter4] * text_matrix44[i][1];
            printf("%d", encrypted4[i][j]);
            if (i < text_constat4 - 1 || j < 3)
                printf(" ");
            e_counter4++;
        }
        if (e_counter4 == 4) {
            e_counter4 = 0;
        }
    }
    return (encrypted4);
}

void	get_matrix4(int ac, char **av)
{
    char	*text_string = av[1];
    char	*code_string = av[2];
    int	text_constat4 = strlen(text_string) % 4 ==0 ?
        strlen(text_string) / 3 : strlen(text_string) / 3 + 1;
    int	**matrix4 = allocate_memory(4, 4);
    int	**text_matrix44 = text_matrix4(text_string, text_constat4);

    if (strlen(av[2]) <= 16) {
        matrix4 = key_matrix4(code_string);
        encrypted_matrix4(text_matrix44, matrix4, text_constat4);
    }
}
