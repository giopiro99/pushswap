/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_detector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:52:49 by gnicolo           #+#    #+#             */
/*   Updated: 2025/05/20 16:50:57 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if the input string has a valid numeric syntax.
 *
 * Valid formats include optional leading '+' or '-' followed by digits only.
 *
 * @param str Input string to check.
 * @return int Returns 1 if syntax error detected, 0 otherwise.
 */
int	error_syntax(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Checks if a number is already present in the stack.
 *
 * @param a Pointer to the head of the stack.
 * @param n Number to check for duplicates.
 * @return int Returns 1 if duplicate found, 0 otherwise.
 */
int	error_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

/**
 * @brief Frees all nodes in the stack and resets the stack pointer.
 *
 * @param stack Double pointer to the stack to be freed.
 */
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

/**
 * @brief Frees allocated resources and prints error message before exiting.
 *
 * Frees the stack and optionally frees a matrix of strings if flag is set.
 * Prints "Error" to stderr and exits with status 1.
 *
 * @param a Double pointer to the stack.
 * @param flag If 1, frees the matrix of strings argv.
 * @param argv Matrix of strings to free if flag is set.
 */
void	free_errors(t_stack **a, int flag, char **argv)
{
	free_stack(a);
	if (flag == 1)
		ft_clean_matrix(argv);
	ft_printf(2, "Error\n");
	exit(1);
}
