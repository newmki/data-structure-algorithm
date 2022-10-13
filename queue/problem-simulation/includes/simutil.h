#ifndef _SIM_UTIL_
#define _SIM_UTIL_

#include "simdef.h"
#include "linkedDeque.h"

// 고객 도착 큐에 고객 추가.
void insertCustomer(int arrivalTime, int processTime, LinkedDeque *pQueue);

// 고객 도착 처리.
void processArrival(int currentTime, LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue);

// 서비스 시작 처리.
DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue);

// 서비스 종료 처리.
DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode,
					  int *pServiceUserCount, int *pTotalWaitTime);

// 고객의 상태를 출력.
void printSimCustomer(int currentTime, SimCustomer customer);

// 대기 열의 상태를 출력.
void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue);

// 최종 시뮬레이션 결과(통계치) 출력.
void printReport(LinkedDeque *pWaitQueue,
				 int serviceUserCount,
				 int totalWaitTime);

#endif