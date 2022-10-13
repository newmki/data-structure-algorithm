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
	ListNode *prev;		//������ ����� �� ����� �ּҸ� ���� �׸�
	ListNode *remove;	//������ ����� �ּҸ� ���� �׸�
	
	//����ó��
	if (pList->currentElementCount <= 0 ||
		position > pList->currentElementCount ||
		position < 0)
		return (FALSE);
	
	//�����ϰ� ���� ����� �ּҰ��� �Լ��� �޾ƿ´�.
	remove = getLLElement(pList, position);
	
	//�����ϰ� ���� ����� ��ġ�� ��� ������ ���
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