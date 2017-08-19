////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2016, All Rights Reserved
// Author:	FU YAN
// Created:2016/01/05
// Describe:
////////////////////////////////////////////////////////////////////////
#include "UVSocketCallBack.h"

class CTestClient : public IUVClientCallback
{
public:
	//���ձ��ģ���Ҫ���д���ְ�ճ��
	virtual void OnSocketRecv(char* pMsg, ssize_t nMsgSize);
	// ���ͱ��ĳɹ�
	virtual void OnSocketSendSucc();
	//���ͱ���ʧ��
	virtual void OnSocketSendFailed();
	//����Socket�ر�
	virtual void OnSocketClose();
	//���Ϸ������ɹ�
	virtual void OnSocketConnectSucc();
	//���ӷ�����ʧ��
	virtual void OnSocketConnectFailed();
};