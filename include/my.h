/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** 103cipher_2018
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

int	main(int ac, char **av);
int	**allocate_memory(int line, int col);
int	**key_matrix(char *code_string);
int	**text_matrix1(char *text_string, int text_constat);
int	**encrypted_matrix(int **text_matrix, int **matrix,
                           int text_constat);
int	**key_matrix2(char *code_string);
int	**text_matrix2(char *text_string, int text_constat2);
int	**encrypted_matrix2(int **text_matrix22, int **matrix2,
                            int text_constat2);
int	**key_matrix4(char *code_string);
int	**text_matrix4(char *text_string, int text_constat4);
int	**encrypted_matrix4(int **text_matrix44, int **matrix4,
                            int text_constat4);
int	my_usage(char **av);
void	my_usage_h(void);
void	my_condition(int ac, char **av);
void	get_length(int ac, char **av);
void	get_matrix4(int ac, char **av);

#endif /* MY_H_ */
