#pragma once

#include "../common/Qt.h"
#include "../../../SharedCode/LokiCommand.h"

//1 ����ͼ��
//2 �Ҽ��˵�
//3 Chat�߼�
//4 ״̬����

class FriendButton : public QTreeWidgetItem
{
	friend class ChatDialog;
public:
	FriendButton(QTreeWidgetItem *parent = 0);
	~FriendButton();

	void SetFriendInfo(Loki::LokiFriend info);
	Loki::LokiFriend GetFriendInfo(){return _info;}

private:
	Qt::ItemFlags _itemFlag;
	Loki::LokiFriend _info;
};

