/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteArrayList.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:20:25 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 19:43:16 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <stdlib.h>

void deleteArrayList(ArrayList* pList)
{
	clearArrayList(pList);
	free(pList->pElement);
	free(pList);
}
