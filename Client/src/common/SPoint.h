#pragma once

#include "Qt.h"
#include "library.h"


//���ڵ�
//QPoint����int
//QVector2D������float
//�������ļ��һ����int�ͣ����������ԭʼ�ļ����������

class LIANGSHIEXPORT SPoint
{
public:
	SPoint();
	SPoint(int x, int y);
	SPoint(const SPoint& p);
	explicit SPoint(const QPoint& p);
	explicit SPoint(const QVector2D& p);

	~SPoint();

	SPoint& operator= (const SPoint &another);
	SPoint& operator= (const QPoint &another);

	QPoint ToQPoint();

public:
	int _x;
	int _y;

public:
	MSGPACK_DEFINE(_x, _y);
};

