/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_chunks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:37:13 by gnicolo           #+#    #+#             */
/*   Updated: 2025/05/20 16:50:15 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Assigns chunk indices to each node in the stack based on their sorted index.
 *
 * Divides the stack into chunks of fixed size (20 if stack size ≤ 100, else 39).
 * Each node's chunk is set by integer division of its index by chunk size.
 *
 * @param stack Pointer to the head of the stack.
 * @return int The highest chunk index assigned.
 */
int	assign_chunk(t_stack *stack)
{
	int			size_a;
	int			chunk_size;
	t_stack		*head;
	t_stack		*max;

	head = stack;
	size_a = stack_len(stack);
	if (size_a <= 100)
		chunk_size = 20;
	else
		chunk_size = 39;
	while (stack)
	{
		stack->chunk = stack->index / chunk_size;
		stack = stack->next;
	}
	stack = head;
	max = find_max(stack);
	return (max->chunk);
}

/**
 * @brief Finds the median value of the stack based on node values.
 *
 * Assumes the stack is sorted or partially sorted. Returns the middle element's nbr.
 *
 * @param stack Pointer to the head of the stack.
 * @return int The median number value; 0 if stack is empty.
 */
int	find_median(t_stack *stack)
{
	int			size;
	int			i;
	int			median;
	t_stack		*tmp;

	size = stack_len(stack);
	i = 0;
	median = 0;
	if (size == 0)
		return (0);
	tmp = stack;
	while (i < size / 2)
	{
		tmp = tmp->next;
		i++;
	}
	median = tmp->nbr;
	return (median);
}

/**
 * @brief Checks if any node in the stack belongs to the given chunk.
 *
 * @param a Pointer to the head of the stack.
 * @param chunk The chunk index to search for.
 * @return int Returns 1 if any node has the chunk, 0 otherwise.
 */
int	has_chunk(t_stack *a, int chunk)
{
	while (a)
	{
		if (a->chunk == chunk)
			return (1);
		a = a->next;
	}
	return (0);
}

/**
 * @brief Moves nodes from stack 'a' to stack 'b' chunk by chunk.
 *
 * Iterates through stack 'a', pushing nodes belonging to the current chunk to 'b'.
 * If the pushed node in 'b' has a value less than the median of 'b', rotates 'b'.
 * Increments the chunk index once no nodes of the current chunk remain in 'a'.
 *
 * If stack 'a' has 3 or fewer elements, sorts it directly and returns 3.
 *
 * @param a Double pointer to stack 'a'.
 * @param b Double pointer to stack 'b'.
 * @param max_chunk The highest chunk index to process.
 * @return int Returns 3 if sorted directly due to small stack size, 0 otherwise.
 */
int	move_chunks_to_b(t_stack **a, t_stack **b, int max_chunk)
{
	t_stack		*tmp;
	int			current_chunk;

	tmp = NULL;
	current_chunk = 0;
	if (stack_len(*a) <= 3)
	{
		sort_three(a);
		return (3);
	}
	while (*a && current_chunk < max_chunk)
	{
		tmp = (*a);
		if (tmp->chunk == current_chunk)
		{
			pb(a, b);
			if (*b && (*b)->next && (*b)->nbr < find_median(*b))
				rb(b);
		}
		else
			ra(a);
		if (!has_chunk(*a, current_chunk))
			current_chunk++;
	}
	return (0);
}
