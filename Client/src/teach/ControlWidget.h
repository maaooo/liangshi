#pragma once

#include "../common/config.h"
#include "../common/Qt.h"
#include "../common/TyrProtocol.h"
#include "../common/Menu.h"
#include "../common/SocketClient.h"

/*
class FourFingerTapGesture: public QGestureRecognizer
{ 
	virtual Result filterEvent(QGesture*, QObject*, QEvent*event) 
	{ 
		if(event->type() == QEvent::TouchUpdate) 
			if(static_cast<QTouchEvent *>(event)->touchPoints.size() == 4) 
				return GestureFinished;
		return Ignore;
	} 
};
*/

//�Ҹо���contorlwidgetҲ��Ҫdraw,�������ǣ���ô�̳�DocumentWidget?
//��һ����������ʹ�ã���Ϊcontrol����������ͼƬ�����Ի��ǲ�̫һ��

//ControlWidget��ControledWidget��Ҫһ����ƶϿ�

//controlҲ��Ҫ֧������
//1 pen 2. zoom 3 menu

class ControlWidget : public QWidget
{
	Q_OBJECT
public:
	ControlWidget(SocketClient* client, QWidget *parent = 0);
	~ControlWidget();

//qwidget virtuals
private:
	virtual void contextMenuEvent(QContextMenuEvent *event);
	virtual void paintEvent(QPaintEvent *e);
	virtual void resizeEvent(QResizeEvent *e);
	virtual void moveEvent(QMoveEvent *e);
	virtual void wheelEvent(QWheelEvent *e);
	//�˺�������QObject
	virtual bool event(QEvent *);

private Q_SLOTS:
	void OnKeSelectedTriggered(QString filepath);

private:
	void SetPainterStyle(QPainter& painter);
	void ResizePixmap(const QSize& size);
	void InitMenu();

private:
	TyrProtocol* _protocol;
	Menu* _menu;

	QPixmap* _backgroudPixmap;
};

