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
#include "polylist.h"

LinkedList *createLinkedList()
{
	LinkedList *headPointer;
	
	headPointer = (LinkedList*)malloc(sizeof(LinkedList));
	headPointer->currentElementCount = 0;
	headPointer->headerNode.coef = 0;
	headPointer->headerNode.degree = 0;
	headPointer->headerNode.pLink = 0;
	
	return (headPointer);
}