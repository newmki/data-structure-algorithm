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
	
	//예외처리
	if (position < 0 ||
		position >= pList->maxElementCount ||
		position > pList->currentElementCount ||
		pList->maxElementCount <= pList->currentElementCount)
		return (FALSE);
	
	//맨 뒤에 원소를 추가할 경우
	if (position == pList->currentElementCount)
	{
		pList->pElement[position].data = element.data;
	}
	else
	{
		i = pList->currentElementCount;
		//앞 원소를 뒤 원소 밀어주는 작업
		// 012_
		// 01_2
		// 0_12
		while (i > position)
		{
			pList->pElement[i].data = pList->pElement[i - 1].data;
			i--;
		}
		//매개변수 element로 들어온 인자값을 비워진 공간에 넣어줌
		pList->pElement[position].data = element.data;
	}
	
	//currcnt 증가
	pList->currentElementCount++;
	return (TRUE);
}