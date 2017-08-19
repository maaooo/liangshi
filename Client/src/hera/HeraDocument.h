#pragma once

#include "../common/Qt.h"
#include "../common/library.h"

//HeraMainWidget�����Ƕ����Ҫ��Ҫ֧���˳�����
//����Ժ�Ҫ�ģ�����������������ǽӿڹ���
class LIANGSHIEXPORT HeraDocument
{
protected:
	HeraDocument();
	virtual ~HeraDocument();

public:
	virtual bool CanQuit() = 0;
	virtual QString GetSaveFileDialongExtension() = 0;
	virtual void UpdateFilepath(QString filepath) = 0;
	virtual bool HasSavedPath() = 0;
	virtual bool SaveDocument(QString filepath = "") = 0;
	virtual bool SaveAsDocument(QString filepath) = 0;
	virtual QWidget* Convert2QWidget() = 0;
};

