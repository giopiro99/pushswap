/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:54:55 by gnicolo           #+#    #+#             */
/*   Updated: 2025/05/20 16:40:56 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Returns the last node of the stack.
 *
 * @param stack Pointer to the head of the stack.
 * @return Pointer to the last node, or NULL if stack is empty.
 */
t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/**
 * @brief Calculates the number of nodes in the stack.
 *
 * @param stack Pointer to the head of the stack.
 * @return The number of elements in the stack.
 */
int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

/**
 * @brief Checks if the stack is sorted in ascending order.
 *
 * @param stack Pointer to the head of the stack.
 * @return true if sorted, false otherwise.
 */
bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/**
 * @brief Finds the node with the minimum value in the stack.
 *
 * @param stack Pointer to the head of the stack.
 * @return Pointer to the node with the minimum value, or NULL if stack is empty.
 */
t_stack	*find_min(t_stack *stack)
{
	long			min;
	t_stack			*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

/**
 * @brief Finds the node with the maximum value in the stack.
 *
 * @param stack Pointer to the head of the stack.
 * @return Pointer to the node with the maximum value, or NULL if stack is empty.
 */
t_stack	*find_max(t_stack *stack)
{
	long			max;
	t_stack			*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
