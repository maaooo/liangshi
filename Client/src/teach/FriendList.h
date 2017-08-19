#pragma once

#include "../common/Qt.h"
#include "../../../SharedCode/LokiCommand.h"
#include "ChatDialog.h"

//chat dialog�Ĺ�������������

class FriendList : public QTreeWidget
{
	Q_OBJECT
public:
	FriendList(QWidget *parent = 0);
	~FriendList();

private Q_SLOTS:
	void OnGetFriendListTriggered(vector<Loki::LokiFriend>& friends);
	void OnItemDoubleClickTriggered(QTreeWidgetItem* item, int column);
	void OnReceiveChatTriggered(int user_id, QString& message);

private:
	ChatDialog* FindChatByUserID(int user_id);

private:
	Qt::ItemFlags _itemFlag;
	map<QString, QTreeWidgetItem*> _groups;

	//�������dialog,ֻhide,���ر�
	map<int, ChatDialog*> _chatDialogs;

	QString _defaultGroupName;
};

