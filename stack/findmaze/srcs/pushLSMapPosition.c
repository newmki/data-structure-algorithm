#include "findmaze.h"

int pushLSMapPosition(LinkedStack* pStack, MapPosition data)
{
    StackNode element = {
        data,
        0
    };
    return (pushLS(pStack, element));
}
