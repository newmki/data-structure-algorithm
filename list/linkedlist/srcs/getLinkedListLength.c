/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getLinkedListLenght.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:51:16 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 16:54:25 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

int getLinkedListLength(LinkedList* pList)
{
	int		len = 0;
	ListNode *curr;
	
	curr = pList->headerNode.pLink;
	
	while(curr)
	{
		curr = curr->pLink;
		len++;
	}
	return (len);
}