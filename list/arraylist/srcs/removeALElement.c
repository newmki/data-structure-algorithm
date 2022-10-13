/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeALElement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:01:18 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 19:35:57 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

int removeALElement(ArrayList* pList, int position)
{
	int i;
	
	//����ó��
	if (position < 0 ||
		position >= pList->maxElementCount ||
		position >= pList->currentElementCount)
		return (FALSE);
	
	//�� �� ���Ҹ� ������ ���
	if (position == pList->currentElementCount - 1)
	{
		pList->pElement[position].data = 0;
		pList->currentElementCount--;
	}
	else
	{
		i = position;
		//�� ���Ҹ� ������ �����ִ� �۾�
		// 0123
		// 0223
		// 0233
		// 023_
		while (i < pList->currentElementCount)
		{
			pList->pElement[i].data = pList->pElement[i + 1].data;	
			i++;
		}
		//�� �������� ���� ������ �ڸ� �ʱ�ȭ
		pList->pElement[i].data = 0;
		pList->currentElementCount--;
	}
	return (TRUE);
}