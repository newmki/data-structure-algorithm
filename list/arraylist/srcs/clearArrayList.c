/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearArrayList.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:21:32 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 19:53:31 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

void clearArrayList(ArrayList* pList)
{
	int i = 0;
	
	//�տ�����ó �迭�� ��ȸ�ϸ� 0���� �ʱ�ȭ
	while (i < pList->currentElementCount)
	{
		pList->pElement[i].data = 0;
		i++;
	}
	pList->currentElementCount = 0;
}