/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteLinkedList.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:36:19 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 17:10:15 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "linkedlist.h"
#include <stdlib.h>

void deleteLinkedList(LinkedList* pList)
{
	//��带 ������ ��� ��� ����
	clearLinkedList(pList);
	
	//��� ��� ����
	pList->currentElementCount = 0;
	pList->headerNode.data = 0;
	pList->headerNode.pLink = 0;
	free(pList);
}