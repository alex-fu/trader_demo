#include<iostream>
#include "CtpTraderSpi.h"
#include "CSem.h"

using namespace std;

//请求编号
int requestId=0;

CSem sem(0);

int main(){
    // 前置地址
    char tradeFront[]="tcp://180.168.102.230:26205";

    TThostFtdcBrokerIDType brokerId = "1001";
    TThostFtdcUserIDType userId = "00000054";
    TThostFtdcPasswordType passwd = "123456";

	CThostFtdcTraderApi* pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();
	CtpTraderSpi* pUserSpi = new CtpTraderSpi(pUserApi);
	pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi);			// 注册事件类
	pUserApi->SubscribePublicTopic(THOST_TERT_RESTART);					// 注册公有流
	pUserApi->SubscribePrivateTopic(THOST_TERT_RESTART);			  // 注册私有流
	pUserApi->RegisterFront(tradeFront);							// 注册交易前置地址
	pUserApi->Init();
	//todo

    sleep(1);
    //login
    pUserSpi->ReqUserLogin(brokerId, userId, passwd);

    //Request for quering instrument
    TThostFtdcInstrumentIDType instrumentId = "";
    pUserSpi->ReqQryInstrument(instrumentId);

	
	pUserApi->Join();  
	//pUserApi->Release();
}
