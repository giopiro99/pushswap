/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:20:31 by gnicolo           #+#    #+#             */
/*   Updated: 2025/05/20 16:45:49 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates the stack upwards by moving the first element to the end.
 *
 * The first node becomes the last one, and the second node becomes the new head.
 *
 * @param head Double pointer to the head of the stack.
 */
static void	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*head) || !(*head)->next)
		return ;
	first = *head;
	last = find_last(*head);
	*head = first->next;
	first->next = NULL;
	last->next = first;
}

/**
 * @brief Rotates stack A upwards and prints "ra".
 *
 * Moves the top element of stack A to the bottom.
 *
 * @param a Double pointer to stack A.
 */
void	ra(t_stack **a)
{
	rotate(a);
	ft_printf(1, "ra\n");
}

/**
 * @brief Rotates stack B upwards and prints "rb".
 *
 * Moves the top element of stack B to the bottom.
 *
 * @param b Double pointer to stack B.
 */
void	rb(t_stack **b)
{
	rotate(b);
	ft_printf(1, "rb\n");
}

/**
 * @brief Rotates both stacks A and B upwards and prints "rr".
 *
 * Moves the top element of both stacks A and B to the bottom.
 *
 * @param a Double pointer to stack A.
 * @param b Double pointer to stack B.
 */
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf(1, "rr\n");
}
