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
	ListNode *prev;	//�����ϰ� ���� ��ġ�� �� ���
	ListNode *node;	//����° ������ ��带 ������ �׸�

	//�Ű����� position�� ��� �������� ū ���� ���ڷ� ������ �� ����
	if (position > pList->currentElementCount || position < 0)
		return (FALSE);
	//����° ���ڷ� ���� ��带 ��°�� ������ ������ �Ҵ�
	node = (ListNode*)malloc(sizeof(ListNode));
	
	node->data = element.data;
	node->pLink = 0;

	//��� ��� �ٷ� �ڿ� �ű� ��带 �����ϴ� ���
	if (position == 0)
	{
		node->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = node;
	}
	else
	{	
		//�����ϰ� ���� ��ġ�� �� ���
		prev = getLLElement(pList, position - 1);
		node->pLink = prev->pLink;
		prev->pLink = node;
	}
	
	//��尡 ���Ե� ������ currcnt�� ����
	pList->currentElementCount++;
	return (TRUE);
}