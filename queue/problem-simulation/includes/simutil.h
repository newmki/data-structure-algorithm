#ifndef _SIM_UTIL_
#define _SIM_UTIL_

#include "simdef.h"
#include "linkedDeque.h"

// �� ���� ť�� �� �߰�.
void insertCustomer(int arrivalTime, int processTime, LinkedDeque *pQueue);

// �� ���� ó��.
void processArrival(int currentTime, LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue);

// ���� ���� ó��.
DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue);

// ���� ���� ó��.
DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode,
					  int *pServiceUserCount, int *pTotalWaitTime);

// ���� ���¸� ���.
void printSimCustomer(int currentTime, SimCustomer customer);

// ��� ���� ���¸� ���.
void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue);

// ���� �ùķ��̼� ���(���ġ) ���.
void printReport(LinkedDeque *pWaitQueue,
				 int serviceUserCount,
				 int totalWaitTime);

#endif