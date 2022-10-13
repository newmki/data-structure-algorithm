/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getLLElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:25:10 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 15:38:34 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polylist.h"

ListNode* getLLElement(LinkedList* pList, int degree)
{
	ListNode *curr;
	
  //리스트 안의 지수보다 인자로 들어온 degree의 값이 클 경우 -> 0 반환 : head노드 뒤에 삽입하는 조건으로 사용
	if (!pList->headerNode.pLink ||
    degree >= pList->headerNode.pLink->degree)
		return (FALSE);
	curr = pList->headerNode.pLink;
	
	while (curr->pLink)
	{
    // 인자로 들어오는 degree값이 앞, 뒤 노드의 지수 사이 크기일 경우
    if(curr->degree >= degree && curr->pLink->degree < degree)
      return (curr);
    //인자로 들어온 degree가 앞 뒤 모두의 노드보다 작을 때 -> while문이 돌면서 한 차수 작은 노드부터 다시 포지셔닝
		curr = curr->pLink;
	}
	return (curr);
}