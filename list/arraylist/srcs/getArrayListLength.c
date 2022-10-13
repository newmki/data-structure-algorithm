/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getArrayListLength.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:18:08 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 19:18:54 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

int getArrayListLength(ArrayList* pList)
{
	return (pList->currentElementCount);
}
