#pragma once

#include "../common/Qt.h"
#include "../common/library.h"
#include "../common/QtSingleton.h"

class LIANGSHIEXPORT HackManager : public QtSingleton<HackManager>
{
public:
	HackManager();
	virtual ~HackManager();

	void EnterSuperMode();
	bool IsEnableKeSuperRevise();

private:
	bool _enteredPassword;
};

//�����dll��ȥ��singleton,�����⣬����ʵ��
//typedef CSingleton<HackManager> HackManagerSingleton;
