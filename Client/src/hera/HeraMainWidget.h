#pragma once

#include "../common/Qt.h"
#include "../common/library.h"
#include "HeraDocument.h"
#include "../../../SharedCode/LokiBuffer.h"
#include "KeTime.h"

enum NewableDocType
{
	NewableDocType_Ban,
	NewableDocType_BanScript,
	NewableDocType_BanTest,
	NewableDocType_Ke,
	NewableDocType_KeEmbedded,
	NewableDocType_Player,
	NewableDocType_PlayerPreview,
	NewableDocType_PlayerInBrowser,
	NewableDocType_BanEmbedded,
	NewableDocType_TestEmbedded,
	NewableDocType_Live,
};

class TitleWidget;
class Element;
class BanElement;

//һ��doc���ܣ������治�ܶ��ĵ�������Ŀǰ��򵥵����
//���������Ҫ����һ��ģʽ������������ô��,�����棬ֻ���ڴ�ģʽ
class LIANGSHIEXPORT HeraMainWidget : public QDialog
{
	Q_OBJECT
	friend class PlayerTitleWidget;
public:
	HeraMainWidget(NewableDocType type, QWidget* docWidget = NULL);
	virtual ~HeraMainWidget();

	static HeraMainWidget* LoadScFile(QString filepath);
	static HeraMainWidget* LoadKeFile(QString filepath, bool embeddInBrowser = false, bool preview = false);
	static HeraMainWidget* BeginKeFromLokiBuffer(NewableDocType type, QPixmap& pixmap, QString taskBartitle);
	static HeraMainWidget* LoadFromLokiBuffer(NewableDocType type, LokiBuffer& buffer, QVariant& relatedData, QString title);
	static HeraMainWidget* LoadFromLokiBufferInLayer(NewableDocType type, LokiBuffer& buffer, QVariant& relatedData, int layer);
	void ShowModal();

//QWidget virtuals
private:
	virtual void dragEnterEvent(QDragEnterEvent *e);
//	virtual void dragMoveEvent(QDragMoveEvent *e);
//	virtual void dragLeaveEvent(QDragLeaveEvent *e);
	virtual void dropEvent(QDropEvent *e);
	virtual void resizeEvent(QResizeEvent *e);

Q_SIGNALS:
	void OnClosed();
	void OnGetScBuffer(LokiBuffer& buffer, QVariant& relatedData, bool canDelete);
	void OnHavenotSaveRelatedElement(QVariant& relatedData);
	void OnOpenKeFile(QString filepath);

public Q_SLOTS:
	void OnShowTriggered();
	void OnLiveCanApplyAndTakeTriggered(bool whole, bool student, bool apply);
	
private Q_SLOTS:
	void OnOpenFileTriggered();
	void OnSaveTriggered();
	void OnSaveAsTriggered();
	void OnPreviewTriggered();

private:
	virtual void closeEvent(QCloseEvent * event);
	virtual void keyPressEvent(QKeyEvent *e);
	void InitSlots();
	void InitKeTimeSlots();

private:
	//���˳����������ʵ����˳��ѽ
	KeTime* _keTime;
	TitleWidget* _title;
	HeraDocument* _mainDoc;
	QVBoxLayout* _centerLayout;
	NewableDocType _type;

	QVariant _relatedData;
};

