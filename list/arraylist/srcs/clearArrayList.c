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
	
	//앞에서부처 배열을 순회하며 0으로 초기화
	while (i < pList->currentElementCount)
	{
		pList->pElement[i].data = 0;
		i++;
	}
	pList->currentElementCount = 0;
}