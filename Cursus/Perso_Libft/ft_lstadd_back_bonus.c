/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:23:09 by hdougoud          #+#    #+#             */
/*   Updated: 2024/10/17 11:53:35 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
		while ((*lst)->next != NULL)
		{
			(*lst) = (*lst)->next;
		}
		(*lst)->next = new;
}

//int main(void)
//{
//	t_list	*p1;
//	t_list	*p2;
//	t_list	*new;
//	p1 = malloc(sizeof(t_list));
//	p2 = malloc(sizeof(t_list));
//	new = malloc(sizeof(t_list));
//	p1->content = "Hello";
//	p1->next = p2;
//	p2->content = "World";
//	p2->next = NULL;
//	new->content = "test";
//	new->next = NULL;
//	ft_lstadd_back(&p1 ,new);
//	printf("%d\n", ft_lstsize(p1));
//}
