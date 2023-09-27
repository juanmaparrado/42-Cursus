/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra < juaparra@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:06:36 by juaparra          #+#    #+#             */
/*   Updated: 2023/09/27 12:26:31 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nodo;

	nodo = malloc(sizeof(t_list));
	if (nodo == NULL)
		return (0);
	nodo -> content = content;
	nodo -> next = NULL;
	return (nodo);
}
