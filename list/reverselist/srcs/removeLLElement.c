/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeLLElement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:36:31 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 17:09:27 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdlib.h>

int removeLLElement(LinkedList* pList, int position)
{
	ListNode *prev;		//삭제할 노드의 전 노드의 주소를 담을 그릇
	ListNode *remove;	//삭제할 노드의 주소를 담을 그릇
	
	//예외처리
	if (pList->currentElementCount <= 0 ||
		position > pList->currentElementCount ||
		position < 0)
		return (FALSE);
	
	//삭제하고 싶은 노드의 주소값을 함수로 받아온다.
	remove = getLLElement(pList, position);
	
	//삭제하고 싶은 노드의 위치가 헤드 다음일 경우
	if (position == 0)
	{
		pList->headerNode.pLink = remove->pLink;
	}
	else
	{
		prev = getLLElement(pList, position - 1);
		prev->pLink = remove->pLink;
	}
	
	remove->data = 0;
	remove->pLink = 0;
	free(remove);
	
	pList->currentElementCount--;
	return (TRUE);
}