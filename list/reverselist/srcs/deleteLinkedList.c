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
	//헤드를 제외한 모든 노드 삭제
	clearLinkedList(pList);
	
	//헤드 노드 삭제
	pList->currentElementCount = 0;
	pList->headerNode.data = 0;
	pList->headerNode.pLink = 0;
	free(pList);
}