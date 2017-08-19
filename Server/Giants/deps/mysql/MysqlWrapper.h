#pragma once
#include "mysql.h"

class MysqlWrapper
{
public:
	MysqlWrapper();
	virtual ~MysqlWrapper();

	bool IsConnect();
	bool Connect(const char* HostName,const char* UserName,const char* Password,const char* DataBase);
	bool SQLExec(const char *SQL);
	//update,insert,delete��Ӱ������
	unsigned long AffectedRows();

	//�ر�һ��Result(��ѯ�������)
	bool SQLClose();
	//���ز�ѯselect����Ŀ
	unsigned long RecordCount();
	//ȡ��һ��
	MYSQL_ROW FetchRows();
	bool Close();

private:
	MYSQL _mysqlHandler;
	MYSQL_RES *_result;
	MYSQL_ROW _rows;
	bool _isConnected;
};

