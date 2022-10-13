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
	//�迭����Ʈ �Ҵ�
	ArrayList* array = (ArrayList *)malloc(sizeof(ArrayList));
	
	//�޸� �Ҵ� ���н� ���� ó��
	if (array == NULL)
		return (FALSE);
		
	array->maxElementCount = maxElementCount;
	array->currentElementCount = 0;
	
	//���Ҹ� ���� �迭 �޸� �Ҵ�(���� ������ŭ ĭ ����)
	array->pElement = (ArrayListNode *)calloc(maxElementCount, sizeof(ArrayListNode));
	if (array->pElement == NULL)
		return (FALSE);
	return (array);
}