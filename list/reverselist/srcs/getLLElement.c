/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getLLElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:25:10 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 15:38:34 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode *curr;
	int		index = 0;
	
	//매개변수 position에 노드 개수보다 큰 수가 인자로 들어왔을 시 에러
	if (position >= pList->currentElementCount)
		return (FALSE);
	//curr은 현재 position 0의 노드의 주소값을 참조
	curr = pList->headerNode.pLink;
	
	//노드 순회
	while (index < position)
	{
		curr = curr->pLink;
		index++;
	}
	return (curr);
}