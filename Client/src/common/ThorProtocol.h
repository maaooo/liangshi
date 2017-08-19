#pragma once

#include "Qt.h"
#include "stl.h"
#include "library.h"
#include "ThorClient.h"
#include "ThorServer.h"

/*
���������͡���ӣ����Ů�񸥰���֮�ӡ�
�ж���Ŀ��࣬�������ˣ�������һ˫���ۡ���������ӡ�
�ж����ż�ª������������������һ��ħ��������ħ��ʹ���������ӱ���
�ж����������ף�ִ���װ¶������ Mjollner ��ħ����
�ж������ڶ���������˪���˺;�������Ϯ����������o�ļ�԰��
�ж��������������ڶ�ײ�¶����ж�Ƣ�����굫����������
����ĩ������ʱ�������ж����׵¼Ӷ��¾�����������ά�������ս�������ͬ���ھ���
*/

enum ThorProtocolType
{
	ThorProtocolType_Sync = 101,
	ThorProtocolType_Control = 102,
};

class ThorProtocol : public QObject
{
	Q_OBJECT
public:
	ThorProtocol(ThorClient* client, ThorServer* server, QObject *parent = 0);
	~ThorProtocol();

	//1 sync, 2 control
	int GetType(){return _type;}

	void SendServerInfo(ThorProtocolType type, QString ip, int port);
	void StartListen();
	void StopListen();

Q_SIGNALS:
	void OnGetServerInfo(ThorProtocolType type, QString ip, int port);

private Q_SLOTS:
	void OnDataReadTriggered(LokiBuffer& buffer);


private:
	string _ip;
	int _port;

private:
	int _type;
	ThorServer* _server;
	ThorClient* _client;

public:
	MSGPACK_DEFINE(_type, _ip, _port);
};

