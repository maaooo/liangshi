#pragma once

#include "Qt.h"
#include "stl.h"
#include "config.h"
#include "../../../SharedCode/LokiBuffer.h"
#include "../../../SharedCode/LokiCommand.h"
#include "LokiSocket.h"

class OdinClient : public QObject
{
	Q_OBJECT
private:
	OdinClient();
	~OdinClient();

public:
	void Init(QString ip, int port);
	void Disconnect();

//related net operation
public:
	void Login(QString& username, QString& password);
	void Chat(int from_id, int to_id, QString& message);
	void GetFriendList();
	void BoardLogin(QString& session_id);
	void HadesData(QString peer_id, LokiBuffer& buffer);
	void BoardData(LokiBuffer& buffer);
	void ApplyBoard();
	void AgreeBoard(QString student_id, bool agree);
	//��ʦ����ǿ���ջ�
	void TakeBoard();

Q_SIGNALS:
	void OnSocketError(QAbstractSocket::SocketError socketError);
	void OnConnected();
	void OnLogin(bool result, QString& message);
	void OnGetFriendList(vector<Loki::LokiFriend>& friends);
	void OnChat(int user_id, QString& message);
	void OnBoardLogin(bool result, bool peer, QString& peer_id, QString& nickname, bool is_teacher, bool allTeachers);
	void OnHadesData(QString peer_id, QString nickname, LokiBuffer& data);
	void OnBoardData(LokiBuffer& data);
	void OnTeacherAgreeBoard(bool another, bool agree);
	void OnApplyBoard(QString student_id, QString nickname);
	void OnTakeBoard();

private Q_SLOTS:
	void OnClientDisconnectTriggered(LokiSocket*);
	void OnDataReadTriggered(LokiBuffer& buffer);
	void OnCommandTriggered(Loki::LokiCommand* command);
	//void OnSocketErrorTriggered(QAbstractSocket::SocketError socketError);

private:
	void SendData(int type, LokiBuffer& buffer);
	void InitSocketSlot();

private:
	LokiSocket *_socket;

	//����һ��������Ϣ
public:
	QString _user_id;
	QString _class_id;
	//�����ֻ����Ǹ�
	QString _login_name;
	QString _nickname;
	bool _is_teacher;
	bool _all_teachers;
};


