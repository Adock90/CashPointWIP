#define __MON_LOGIC__

#define _C_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <WinSock2.h>

typedef int NumID;
typedef char* NumString;

enum IDS
{
	MONEY_INVALID = 0,
	MONEY_VALID = 1
};

NumID CheckSum(NumID MonSub, NumID AccountNum);
int SendMoney(NumString UserName, NumID UserAccount, NumID MoneySend, NumString to);
int SendDataToServer(char Data[]);