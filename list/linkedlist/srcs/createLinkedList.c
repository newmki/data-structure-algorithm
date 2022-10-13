/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createLinkedList.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:58:53 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 16:25:33 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "linkedlist.h"

LinkedList *createLinkedList()
{
	//링크드 리스트의 머리 생성
	LinkedList *headPointer;
	
	//메모리 할당
	headPointer = (LinkedList*)malloc(sizeof(LinkedList));
	//현재 노드 개수 0개 (헤드 제외)
	headPointer->currentElementCount = 0;
	//생성된 ListNode의 data값 초기화
	headPointer->headerNode.data = 0;
	//생성된 ListNode의 pLink값 초기화
	headPointer->headerNode.pLink = 0;
	
	return (headPointer);
}