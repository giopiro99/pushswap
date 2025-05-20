/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:29:57 by gnicolo           #+#    #+#             */
/*   Updated: 2025/05/20 16:43:49 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swaps the first two elements of the given stack.
 *
 * If the stack has fewer than two elements, nothing is done.
 *
 * @param head Double pointer to the head of the stack.
 */
static void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*head) || !(*head)->next)
		return ;
	first = (*head);
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

/**
 * @brief Executes a swap operation on stack A and prints "sa".
 *
 * Internally calls swap() to switch the top two elements.
 *
 * @param a Double pointer to stack A.
 */
void	sa(t_stack **a)
{
	if (!a)
		return ;
	swap(a);
	ft_printf(1, "sa\n");
}

/**
 * @brief Executes a swap operation on stack B and prints "sb".
 *
 * Internally calls swap() to switch the top two elements.
 *
 * @param b Double pointer to stack B.
 */
void	sb(t_stack **b)
{
	if (!b)
		return ;
	swap(b);
	ft_printf(1, "sb\n");
}

/**
 * @brief Executes a simultaneous swap on stacks A and B and prints "ss".
 *
 * Swaps the top two elements of both stacks.
 *
 * @param a Double pointer to stack A.
 * @param b Double pointer to stack B.
 */
void	ss(t_stack **a, t_stack **b)
{
	if (!a || !b)
		return ;
	swap(a);
	swap(b);
	ft_printf(1, "ss\n");
}
