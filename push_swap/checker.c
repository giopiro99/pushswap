/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:49:34 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 16:53:41 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Initializes stack 'a' with the given numbers and optionally frees the numbers array.
 *
 * @param a Pointer to the stack to initialize.
 * @param numbers Array of string numbers to convert and add to the stack.
 * @param flags If 1, frees the numbers array after initialization.
 */
static void	ft_bank_data(t_stack **a, char **numbers, int flags)
{
	if (flags == 1)
	{
		init_stack_a(a, numbers, 0);
		ft_clean_matrix(numbers);
	}
	else
		init_stack_a(a, numbers, 0);
}

/**
 * @brief Executes stack operations based on input command line.
 *
 * Supports "rrb", "rrr", "pa", "pb". If command is invalid, prints error and exits.
 *
 * @param a Stack 'a'.
 * @param b Stack 'b'.
 * @param line The input command line string.
 */
void	ft_moves2(t_stack *a, t_stack *b, char *line)
{
	if (ft_strcmp(line, "rrb\n"))
		rrb(&b);
	else if (ft_strcmp(line, "rrr\n"))
		rrr(&a, &b);
	else if (ft_strcmp(line, "pa\n"))
		pa(&a, &b);
	else if (ft_strcmp(line, "pb\n"))
		pb(&a, &b);
	else
	{
		ft_printf(2, "Error\n");
		free(line);
		exit(1);
	}
}

/**
 * @brief Reads and executes multiple stack operation commands from standard input.
 *
 * Supports commands like "ra", "rb", "rr", "sa", "sb", "ss", "rra" and delegates others to ft_moves2.
 * Frees each command line string after processing.
 *
 * @param a Stack 'a'.
 * @param b Stack 'b'.
 */
void	ft_moves(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_strcmp(line, "ra\n"))
			ra(&a);
		else if (ft_strcmp(line, "rb\n"))
			rb(&b);
		else if (ft_strcmp(line, "rr\n"))
			rr(&a, &b);
		else if (ft_strcmp(line, "sa\n"))
			sa(&a);
		else if (ft_strcmp(line, "sb\n"))
			sb(&b);
		else if (ft_strcmp(line, "ss\n"))
			ss(&a, &b);
		else if (ft_strcmp(line, "rra\n"))
			rra(&a);
		else
			ft_moves2(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}

/**
 * @brief Entry point of the program.
 *
 * Parses command line arguments to initialize stack 'a', reads stack operation commands
 * from stdin, applies them, and then prints "OK" if stack 'a' is sorted, else "KO".
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return int Returns 0 on success and sorted stack, 1 otherwise.
 */
int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	char			**numbers;
	char			*line;

	a = NULL;
	b = NULL;
	line = NULL;
	if (argc <= 1)
		return (ft_printf(1, "\n"));
	else if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		ft_bank_data(&a, numbers, 1);
	}
	else if (argc > 2)
		ft_bank_data(&a, &argv[1], 0);
	ft_moves(a, b);
	if (stack_sorted(a))
		return (ft_printf(1, "OK"), 0);
	else
		return (ft_printf(1, "KO"), 1);
}
