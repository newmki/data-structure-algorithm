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

#include "polylist.h"

ListNode* getLLElement(LinkedList* pList, int degree)
{
	ListNode *curr;
	
  //����Ʈ ���� �������� ���ڷ� ���� degree�� ���� Ŭ ��� -> 0 ��ȯ : head��� �ڿ� �����ϴ� �������� ���
	if (!pList->headerNode.pLink ||
    degree >= pList->headerNode.pLink->degree)
		return (FALSE);
	curr = pList->headerNode.pLink;
	
	while (curr->pLink)
	{
    // ���ڷ� ������ degree���� ��, �� ����� ���� ���� ũ���� ���
    if(curr->degree >= degree && curr->pLink->degree < degree)
      return (curr);
    //���ڷ� ���� degree�� �� �� ����� ��庸�� ���� �� -> while���� ���鼭 �� ���� ���� ������ �ٽ� �����Ŵ�
		curr = curr->pLink;
	}
	return (curr);
}