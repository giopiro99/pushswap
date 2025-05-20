/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:53:43 by gnicolo           #+#    #+#             */
/*   Updated: 2025/05/20 16:48:06 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pushes the top element from the source stack to the destination stack.
 *
 * Removes the top node from the source stack and adds it to the top of the destination stack.
 *
 * @param dst Double pointer to the destination stack.
 * @param src Double pointer to the source stack.
 */
static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!src || !(*src))
		return ;
	push_node = *src;
	*src = (*src)->next;
	push_node->next = *dst;
	*dst = push_node;
}

/**
 * @brief Pushes the top element from stack B to stack A and prints "pa".
 *
 * @param a Double pointer to stack A (destination).
 * @param b Double pointer to stack B (source).
 */
void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf(1, "pa\n");
}

/**
 * @brief Pushes the top element from stack A to stack B and prints "pb".
 *
 * @param a Double pointer to stack A (source).
 * @param b Double pointer to stack B (destination).
 */
void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf(1, "pb\n");
}
