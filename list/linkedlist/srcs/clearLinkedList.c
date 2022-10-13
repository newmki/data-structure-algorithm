/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearLinkedList.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:57:13 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 17:05:05 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdlib.h>

void clearLinkedList(LinkedList* pList)
{	
	while (removeLLElement(pList, 0));
}
