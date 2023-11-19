/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:03:16 by yojablao          #+#    #+#             */
/*   Updated: 2023/11/18 16:26:18 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list* newNode = (t_list *)malloc(sizeof(t_list));
    if(newNode == NULL)
        return (NULL);
    newNode -> content = content;
    newNode -> next = NULL;
    return (newNode);
}

