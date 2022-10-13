/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:32:02 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/23 13:04:05 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"
#include <stdio.h>

int main()
{
	DoublyList *myArray;
	DoublyListNode *curr;
	DoublyListNode node0 = {0};
	int len = 0;
	int position = 0;
	char c;
	myArray = createDoublyList();
	while(1)
	{
		printf("put Add Remove Get Print Length Clear Delete: ");
		scanf(" %c", &c);
		switch (c)
		{
		case 'A':
			printf("data, position: ");
			scanf("%d %d", &(node0.data), &position);
			addDLElement(myArray, position, node0);
			break;
		case 'R':
			printf("position: ");
			scanf("%d", &position);
			removeDLElement(myArray, position);
			break;
		case 'G':
			printf("position: ");
			scanf("%d", &position);
			curr = getDLElement(myArray, position);
			if(curr)
				printf("%d\n", curr->data);
			break;
		case 'P':
			displayDoublyList(myArray);
			break;
		case 'L':
			len = getDoublyListLength(myArray);
			printf("%d\n", len);
		case 'C':
			clearDoublyList(myArray);
			break;
		case 'D':
			deleteDoublyList(myArray);
      return (0);
			break;
		default:
			break;
		}
	}
	if(myArray)
		deleteDoublyList(myArray);
	return (0);
}