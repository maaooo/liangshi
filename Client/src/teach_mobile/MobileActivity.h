#pragma once

#include "../common/Qt.h"
#include "TouchableScrollArea.h"

class MainWindow;

//����android��activity
class MobileActivity : public QWidget
{
	Q_OBJECT
public:
	MobileActivity(MainWindow* mainWindow, QWidget *parent = 0);
	virtual ~MobileActivity();

	//���ݵ�һ�μ��أ�Ӧ�������������Ƿ��һ�μ������ݣ���Ϊ���ܷ��ڹ��캯����
	virtual void OnBackKey() = 0;
	virtual void OnPause() = 0;
	virtual void OnInitialize();
	virtual void OnActive();
	virtual void OnDeactive();

protected:
	bool _hasInitialized;
	MainWindow* _mainWindow;

	//��������scroll, ���������Ҫ�����Ķ���
	TouchableScrollArea* _scroll;
};

