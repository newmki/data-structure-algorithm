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
	
	//예외처리
	if (position < 0 ||
		position >= pList->maxElementCount ||
		position >= pList->currentElementCount)
		return (FALSE);
	
	//맨 뒤 원소를 삭제할 경우
	if (position == pList->currentElementCount - 1)
	{
		pList->pElement[position].data = 0;
		pList->currentElementCount--;
	}
	else
	{
		i = position;
		//뒤 원소를 앞으로 땡겨주는 작업
		// 0123
		// 0223
		// 0233
		// 023_
		while (i < pList->currentElementCount)
		{
			pList->pElement[i].data = pList->pElement[i + 1].data;	
			i++;
		}
		//다 땡겨지고 남은 마지막 자리 초기화
		pList->pElement[i].data = 0;
		pList->currentElementCount--;
	}
	return (TRUE);
}