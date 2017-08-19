////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2016, All Rights Reserved
// Author:	FU YAN
// Created:2016/01/05
// Describe:UVSocket�ص��ӿ��࣬ʹ��ʱʵ�ֶ�Ӧ��Server/client�ӿ�
////////////////////////////////////////////////////////////////////////
#ifndef _UVSOCKETCALLBACK_H_
#define _UVSOCKETCALLBACK_H_

#include "UVSocketDef.h"

class CUVPeer;
class CUVServerSocket;
class CUVClientSocket;

class IUVServerCallback
{
public:
	//���ձ��ģ���Ҫ���д���ְ�ճ��
	virtual void OnSocketRecv(CUVPeer* pPeer, char* pMsg, ssize_t nMsgSize) = 0;
	// ���ͱ��ĳɹ�
	virtual void OnSocketSendSucc(CUVPeer* pPeer) = 0;
	//���ͱ���ʧ��
	virtual void OnSocketSendFailed(CUVPeer* pPeer) = 0;
	//����Socket�ر�
	virtual void OnSocketClose() = 0;
	//�Զ����ӳɹ�
	virtual void OnPeerConnectSucc(CUVPeer* pPeer) = 0;
	//�Զ����ӶϿ�
	virtual void OnPeerClose(CUVPeer* pPeer) = 0;

	CUVServerSocket* GetServerSocket() { return m_pServerSocket; }

	void SetServerSocket(CUVServerSocket* pServerSocket) { m_pServerSocket = pServerSocket; }
private:
	CUVServerSocket* m_pServerSocket;
};

class IUVClientCallback
{
public:
	//���ձ��ģ���Ҫ���д���ְ�ճ��
	virtual void OnSocketRecv(char* pMsg, ssize_t nMsgSize) = 0;
	// ���ͱ��ĳɹ�
	virtual void OnSocketSendSucc() = 0;
	//���ͱ���ʧ��
	virtual void OnSocketSendFailed() = 0;
	//����Socket�ر�
	virtual void OnSocketClose() = 0;
	//���Ϸ������ɹ�
	virtual void OnSocketConnectSucc() = 0;
	//���ӷ�����ʧ��
	virtual void OnSocketConnectFailed() = 0;

	CUVClientSocket* GetClientSocket() { return m_pClientSocket; }

	void SetClientSocket(CUVClientSocket* pClientSocket) { m_pClientSocket = pClientSocket; }
private:
	CUVClientSocket* m_pClientSocket;
};

#endif	//end of define _UVSOCKETCALLBACK_H_

