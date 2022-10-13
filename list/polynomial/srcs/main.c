/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:52:25 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 17:31:40 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polylist.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char c;
	LinkedList *A;
	LinkedList *B;
	ListNode node0;

	A = createLinkedList();
	B = createLinkedList();
  addPolyNodeLast(B, 5, 5);
  addPolyNodeLast(B, 3, 3);
  addPolyNodeLast(B, 1, 1);

	while(1)
	{
		printf("put Add Remove Get Print Length Clear Delete rEverse: ");
		scanf(" %c", &c);
		switch (c)
		{
		case 'A':
			printf("coef, degree: ");
			scanf("%f %d", &(node0.coef), &(node0.degree));
			addPolyNodeLast(A, node0.coef, node0.degree);
			break;
		case 'P':
			displayPolynomial(A);
			break;
		case 'S':
			displayPolynomial(sumPolynomial(A, B));
			break;
		default:
			break;
		}
	}
}