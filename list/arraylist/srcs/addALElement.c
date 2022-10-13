/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addALElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:42:07 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 19:50:44 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	int i;
	
	//����ó��
	if (position < 0 ||
		position >= pList->maxElementCount ||
		position > pList->currentElementCount ||
		pList->maxElementCount <= pList->currentElementCount)
		return (FALSE);
	
	//�� �ڿ� ���Ҹ� �߰��� ���
	if (position == pList->currentElementCount)
	{
		pList->pElement[position].data = element.data;
	}
	else
	{
		i = pList->currentElementCount;
		//�� ���Ҹ� �� ���� �о��ִ� �۾�
		// 012_
		// 01_2
		// 0_12
		while (i > position)
		{
			pList->pElement[i].data = pList->pElement[i - 1].data;
			i--;
		}
		//�Ű����� element�� ���� ���ڰ��� ����� ������ �־���
		pList->pElement[position].data = element.data;
	}
	
	//currcnt ����
	pList->currentElementCount++;
	return (TRUE);
}