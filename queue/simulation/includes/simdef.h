#ifndef _SIM_DEF_
#define _SIM_DEF_

typedef enum SimStatusType { arrival, start, end } SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;	// 도착 시각.
	int serviceTime;	// 서비스 시간.
	int startTime;		// 시작 시각.
	int endTime;		// 종료 시각: 시작 시각 + 서비스 시간.
} SimCustomer;

#endif