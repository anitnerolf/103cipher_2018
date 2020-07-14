/*
** EPITECH PROJECT, 2018
** 103_cipher
** File description:
** functions
*/

#include "my.h"

int	**key_matrix2(char *code_string)
{
    int	**matrix2 = allocate_memory(2, 2);
    int	matrix_counter2 = 0;

    printf("Key Matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (strlen(code_string) > matrix_counter2) {
                matrix2[i][j] = code_string[matrix_counter2];
            } else {
                matrix2[i][j] = 0;
            }
            printf("%d", matrix2[i][j]);
            if (j < 1)
                printf("\t");
            matrix_counter2++;
        }
        printf("\n");
    }
    return (matrix2);
}

int	**text_matrix2(char *text_string, int text_constat2)
{
    int	i = 0;
    int	j = 0;
    int	**text_matrix22 = allocate_memory(text_constat2, 2);
    int	mtext_counter2 = 0;

    for (i = 0; i < text_constat2; i++) {
        for (j = 0; j < 2; j++) {
            if (strlen(text_string) > mtext_counter2) {
                text_matrix22[i][j] = text_string[mtext_counter2];
            } else {
                text_matrix22[i][j] = 0;
            }
            mtext_counter2++;
	}
    }
    return (text_matrix22);
}

int	**encrypted_matrix2(int **text_matrix22, int **matrix2,
                            int text_constat2)
{
    int	**encrypted2 = allocate_memory(text_constat2, 2);
    int	e_counter2 = 0;

    printf("\nEncrypted Message:\n");
    for (int i = 0; i < text_constat2; i++) {
        for (int j = 0; j < 2; j++) {
            encrypted2[i][j] = matrix2[0][e_counter2] * text_matrix22[i][0] +
	        matrix2[1][e_counter2] * text_matrix22[i][1];
            printf("%d", encrypted2[i][j]);
            if (i < text_constat2 - 1 || j < 1)
                printf(" ");
            e_counter2++;
	}
        if (e_counter2 == 2) {
            e_counter2 = 0;
        }
    }
    return (encrypted2);
}
