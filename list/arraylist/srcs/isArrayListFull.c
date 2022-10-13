/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isArrayListFull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:19:09 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 19:20:02 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

int isArrayListFull(ArrayList* pList)
{
	if (pList->currentElementCount == pList->maxElementCount)
		return (TRUE);
	return (FALSE);
}