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
	
	//�Ű����� position�� ��� �������� ū ���� ���ڷ� ������ �� ����
	if (position >= pList->currentElementCount)
		return (FALSE);
	//curr�� ���� position 0�� ����� �ּҰ��� ����
	curr = pList->headerNode.pLink;
	
	//��� ��ȸ
	while (index < position)
	{
		curr = curr->pLink;
		index++;
	}
	return (curr);
}