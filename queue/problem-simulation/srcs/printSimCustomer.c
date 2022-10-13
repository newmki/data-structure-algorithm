#include "simutil.h"

// 고객의 상태를 출력.
void printSimCustomer(int currentTime, SimCustomer customer)
{
  printf("%d시에 들어온 고객의 %d시의 고객 상태는 ", customer.arrivalTime, currentTime);
  switch (customer.status)
  {
    case arrival:
      printf("고객 도착\n");
      break;
    case start:
      printf("고객 서비스 시작\n");
      break;
    case end:
      printf("고객 서비스 종료\n");
      break;
    default:
      ;
  }
}
