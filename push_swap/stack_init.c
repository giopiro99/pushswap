/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:41:46 by gnicolo           #+#    #+#             */
/*   Updated: 2025/05/20 16:44:49 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Appends a new node with the given number to the end of the stack.
 *
 * Allocates memory for a new node, initializes it with the given number,
 * and attaches it to the end of the stack.
 *
 * @param stack Double pointer to the head of the stack.
 * @param n Integer value to store in the new node.
 */
static void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = ft_calloc(sizeof(t_stack), 1);
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
		*stack = node;
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
	}
}

/**
 * @brief Initializes stack A with integer values parsed from argv.
 *
 * Validates input for syntax errors, integer range, and duplicates.
 * If an error is found, the function frees memory and exits.
 *
 * @param a Double pointer to stack A to initialize.
 * @param argv Array of strings representing integers.
 * @param flag Indicator used for memory cleanup (split or not).
 */
void	init_stack_a(t_stack **a, char **argv, int flag)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a, flag, argv);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, flag, argv);
		if (error_duplicate((*a), (int)n))
			free_errors(a, flag, argv);
		append_node(a, (int)n);
		i++;
	}
}
