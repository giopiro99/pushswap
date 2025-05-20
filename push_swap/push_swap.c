/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:16:58 by gnicolo           #+#    #+#             */
/*   Updated: 2025/05/20 16:48:37 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Initializes stacks 'a' and 'tmp' with numbers parsed from input.
 *
 * Depending on the flags value, it calls init_stack_a with different flags.
 *
 * @param a Double pointer to stack 'a' to initialize.
 * @param tmp Double pointer to a temporary stack to initialize.
 * @param numbers Array of strings representing the numbers to push into the stacks.
 * @param flags Flag to indicate parsing mode (1 for split input, 0 otherwise).
 */
static void	ft_bank_data(t_stack **a, t_stack **tmp, char **numbers, int flags)
{
	if (flags == 1)
	{
		init_stack_a(a, numbers, 1);
		init_stack_a(tmp, numbers, 1);
	}
	else
	{
		init_stack_a(a, numbers, 0);
		init_stack_a(tmp, numbers, 0);
	}
}

/**
 * @brief Entry point of the program that initializes stacks and performs sorting.
 *
 * Parses command-line arguments, initializes stacks, checks if the stack is sorted,
 * indexes the list, assigns chunk sizes, moves chunks between stacks, and finally sorts the stacks.
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return int Returns 0 on successful completion.
 */
int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*tmp;
	char		**numbers;
	int			max_chunk;

	a = NULL;
	b = NULL;
	tmp = NULL;
	if (argc <= 1)
		return (ft_printf(1, "\n"));
	else if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		ft_bank_data(&a, &tmp, numbers, 1);
	}
	else if (argc > 2)
		ft_bank_data(&a, &tmp, &argv[1], 0);
	if (stack_sorted(a))
		return (free_stack(&a), free_stack(&b), free_stack(&tmp), 0);
	ft_index_list(&a, &tmp);
	max_chunk = assign_chunk(a);
	if (move_chunks_to_b(&a, &b, max_chunk) == 3)
		return (free_stack(&a), free_stack(&b), 0);
	return (insertion_sort(&a, &b), 0);
}
