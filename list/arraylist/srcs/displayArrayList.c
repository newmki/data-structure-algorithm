/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayArrayList.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:57:10 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 18:59:35 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <stdio.h>

void displayArrayList(ArrayList* pList)
{
	int i = 0;

	while (i < pList->currentElementCount)
	{
		printf("%d ", pList->pElement[i].data);
		i++;
	}
	printf("\n");
}