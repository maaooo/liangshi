#pragma once

#include "../common/Qt.h"
#include "../hera/HeraMainWidget.h"

class HiddenMainWidget : public QWidget
{
	Q_OBJECT
public:
	HiddenMainWidget(QWidget *parent = 0);
	~HiddenMainWidget();

Q_SIGNALS:

private Q_SLOTS:
	void OpenFileTriggered(QString filepath);
	void OnHeraCountChangeTriggered(int count);

private:
	void OpenPreview(QString filepath);
	void ResizeHera();

private:
	HeraMainWidget* _hera;
	bool _preview;

	//��Ϊ�������µĻ��ƣ�����������е�hera�رղ��ܹر�hidden,��������뷨
	vector<HeraMainWidget*> _heras;
};

