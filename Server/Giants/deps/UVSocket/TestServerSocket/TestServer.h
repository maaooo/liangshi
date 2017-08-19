////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2016, All Rights Reserved
// Author:	FU YAN
// Created:2016/01/05
// Describe:
////////////////////////////////////////////////////////////////////////
#ifndef _TESTSERVER_H_
#define _TESTSERVER_H_

#include "UVServerSocket.h"

class CTestServer : public IUVServerCallback
{
public:
	//���ձ��ģ���Ҫ���д���ְ�ճ��
	virtual void OnSocketRecv(CUVPeer* pPeer, char* pMsg, ssize_t nMsgSize);
	// ���ͱ��ĳɹ�
	virtual void OnSocketSendSucc(CUVPeer* pPeer);
	//���ͱ���ʧ��
	virtual void OnSocketSendFailed(CUVPeer* pPeer);
	//����Socket�ر�
	virtual void OnSocketClose();
	//�Զ����ӳɹ�
	virtual void OnPeerConnectSucc(CUVPeer* pPeer);
	//�Զ����ӶϿ�
	virtual void OnPeerClose(CUVPeer* pPeer);
};

#endif	//end of define _TESTSERVER_H_