/*
** EPITECH PROJECT, 2018
** sdfgh
** File description:
** sdfgh
*/

#include "my.h"

int	**allocate_memory(int line, int col)
{
    int	**ptr;
    int	i = 0;

    if ((ptr = malloc(sizeof(int *) * line + 1)) == NULL)
	return (NULL);
    ptr[i] = malloc(sizeof(int *) * col + 1);
    for(i = 0; i < line; i++)
	ptr[i] = malloc(sizeof(int) * col + 1);
    ptr[i] = NULL;
    return (ptr);
}

int	**key_matrix(char *code_string)
{
    int	**matrix = allocate_memory(3, 3);
    int	matrix_counter = 0;

    printf("Key Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (strlen(code_string) > matrix_counter) {
                matrix[i][j] = code_string[matrix_counter];
            } else {
                matrix[i][j] = 0;
            }
            printf("%d", matrix[i][j]);
            if (j < 2)
                printf("\t");
            matrix_counter++;
        }
        printf("\n");
    }
    return (matrix);
}

int	**text_matrix1(char *text_string, int text_constat)
{
    int	i = 0;
    int	j = 0;
    int	**text_matrix = allocate_memory(text_constat, 3);
    int	mtext_counter = 0;

    for (i = 0; i < text_constat; i++) {
    	for (j = 0; j < 3; j++) {
            if (strlen(text_string) > mtext_counter) {
                text_matrix[i][j] = text_string[mtext_counter];
            } else {
                text_matrix[i][j] = 0;
            }
            mtext_counter++;
    	}
    }
    return (text_matrix);
}

int	**encrypted_matrix(int **text_matrix, int **matrix, int text_constat)
{
    int	**encrypted = allocate_memory(text_constat, 3);
    int	e_counter = 0;

    printf("\nEncrypted Message:\n");
    for (int i = 0; i < text_constat; i++) {
        for (int j = 0; j < 3; j++) {
            encrypted[i][j] = matrix[0][e_counter] * text_matrix[i][0] +
                matrix[1][e_counter] * text_matrix[i][1] +
                matrix[2][e_counter] * text_matrix[i][2];
            printf("%d", encrypted[i][j]);
            if (i < text_constat - 1 || j < 2)
                printf(" ");
            e_counter++;
        }
        if (e_counter == 3) {
            e_counter = 0;
        }
    }
    return (encrypted);
}

int	main(int ac, char **av)
{
    if (ac == 2) {
        my_usage(av);
    } else if (ac == 4) {
        if (strlen(av[1]) == 0 || strlen(av[2]) == 0)
            exit (84);
        else
            my_condition(ac, av);
    } else
        exit (84);
    return (0);
}
