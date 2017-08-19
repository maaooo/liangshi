#pragma once

#include "../common/library.h"
#include "../common/stl.h"
#include "User.h"

//��������1v1, setUserֻ��һ��
//������Ʋ�̫�ã�����Ҫpeer_id��������ƣ���һ��session��Ķ���̫��
//��̫�����ڹ���
class ClassSessionManager
{
public:
	ClassSessionManager();
	virtual ~ClassSessionManager();
	static ClassSessionManager& GetInstance();

public:
	void AddClassUser(string class_id, User* user, bool is_teacher);
	void RemoveUser(User* user);
	string GetClassForUser(User* user);
	set<User*> GetClassUsers(string class_id);
	User* GetClassTeacher(string class_id);

private:
	map<string, set<User*> > _classUsers;
	map<string, User*> _teachers;
};

