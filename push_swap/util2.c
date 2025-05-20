/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:19:53 by gnicolo           #+#    #+#             */
/*   Updated: 2025/05/20 16:42:38 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the index of a node in the stack.
 *
 * @param stack Pointer to the head of the stack.
 * @param node Pointer to the node to search for.
 * @return Index of the node if found, -1 otherwise.
 */
int	find_index(t_stack *stack, t_stack *node)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->nbr == node->nbr)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}

/**
 * @brief Moves a node to the top of stack A using the shortest path.
 *
 * Performs rotate (ra) or reverse rotate (rra) operations depending on
 * the node's position relative to the size of the stack.
 *
 * @param a Double pointer to stack A.
 * @param node Pointer to the node to bring to the top.
 */
void	move_to_top(t_stack **a, t_stack *node)
{
	int	index;
	int	size;

	size = stack_len(*a);
	index = find_index(*a, node);
	if (index == -1)
		return ;
	if (index == 0)
		return ;
	if (index <= size / 2)
	{
		while ((*a) != node)
			ra(a);
	}
	else
	{
		while ((*a) != node)
			rra(a);
	}
}

/**
 * @brief Moves a node to the top of stack B using the shortest path.
 *
 * Performs rotate (rb) or reverse rotate (rrb) operations depending on
 * the node's position relative to the size of the stack.
 *
 * @param b Double pointer to stack B.
 * @param node Pointer to the node to bring to the top.
 */
void	move_to_top_b(t_stack **b, t_stack *node)
{
	int	index;
	int	size;

	size = stack_len(*b);
	index = find_index(*b, node);
	if (index == -1)
		return ;
	if (index == 0)
		return ;
	if (index <= size / 2)
	{
		while ((*b) != node)
			rb(b);
	}
	else
	{
		while ((*b) != node)
			rrb(b);
	}
}

/**
 * @brief Sorts a stack of exactly three elements in ascending order.
 *
 * Uses a series of specific checks and operations (ra, rra, sa) to
 * efficiently sort the stack.
 *
 * @param a Double pointer to the stack to sort.
 */
void	sort_three(t_stack **a)
{
	t_stack	*biggest;
	t_stack	*min;

	biggest = find_max(*a);
	min = find_min(*a);
	if (stack_sorted(*a))
		return ;
	if ((*a)->nbr == biggest->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
	{
		ra(a);
		sa(a);
	}
	else if ((*a)->next->nbr == biggest->nbr && (*a)->nbr == min->nbr)
	{
		rra(a);
		sa(a);
	}
	else if ((*a)->next->next->nbr == min->nbr && (*a)->nbr != biggest->nbr)
		rra(a);
	else if ((*a)->next->next->nbr == biggest->nbr && (*a)->nbr != min->nbr)
		sa(a);
	else if ((*a)->nbr == biggest->nbr && (*a)->next->next->nbr != min->nbr)
		ra(a);
}

/**
 * @brief Frees a matrix (array of strings) from memory.
 *
 * Each string is freed individually, followed by the matrix itself.
 *
 * @param matrix Null-terminated array of strings.
 */
void	ft_clean_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
