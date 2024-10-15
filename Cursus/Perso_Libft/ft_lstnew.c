/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lausanne42 <lausanne42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:39:00 by lausanne42        #+#    #+#             */
/*   Updated: 2024/10/15 21:10:17 by lausanne42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (content == 0)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int main(void)
{
	t_list *t1 = ft_lstnew("Hello World");

	printf("%s\n", (char *)t1->content);
	printf("%p\n", t1->next);
}
