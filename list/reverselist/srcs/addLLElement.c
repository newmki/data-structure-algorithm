/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addLLElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:44:27 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 17:24:21 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *prev;	//삽입하고 싶은 위치의 전 노드
	ListNode *node;	//세번째 인자인 노드를 복사할 그릇

	//매개변수 position에 노드 개수보다 큰 수가 인자로 들어왔을 시 에러
	if (position > pList->currentElementCount || position < 0)
		return (FALSE);
	//세번째 인자로 들어온 노드를 통째로 복사할 공간을 할당
	node = (ListNode*)malloc(sizeof(ListNode));
	
	node->data = element.data;
	node->pLink = 0;

	//헤드 노드 바로 뒤에 신규 노드를 삽입하는 경우
	if (position == 0)
	{
		node->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = node;
	}
	else
	{	
		//삽입하고 싶은 위치의 전 노드
		prev = getLLElement(pList, position - 1);
		node->pLink = prev->pLink;
		prev->pLink = node;
	}
	
	//노드가 삽입될 때마다 currcnt를 증가
	pList->currentElementCount++;
	return (TRUE);
}