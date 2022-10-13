/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getALElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:37:48 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 18:54:23 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (position < 0 ||
		position >= pList->maxElementCount ||
		position >= pList->currentElementCount)
		return (FALSE);
	return (&pList->pElement[position]);
}