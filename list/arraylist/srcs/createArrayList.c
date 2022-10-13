/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createArrayList.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:32:40 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 19:38:12 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <stdlib.h>

ArrayList* createArrayList(int maxElementCount)
{
	//배열리스트 할당
	ArrayList* array = (ArrayList *)malloc(sizeof(ArrayList));
	
	//메모리 할당 실패시 예외 처리
	if (array == NULL)
		return (FALSE);
		
	array->maxElementCount = maxElementCount;
	array->currentElementCount = 0;
	
	//원소를 담을 배열 메모리 할당(원소 개수만큼 칸 생성)
	array->pElement = (ArrayListNode *)calloc(maxElementCount, sizeof(ArrayListNode));
	if (array->pElement == NULL)
		return (FALSE);
	return (array);
}