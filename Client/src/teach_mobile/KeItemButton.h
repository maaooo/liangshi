#pragma once

#include "../common/Qt.h"
#include "../common/YunHttp.h"

class KeItemButton : public QPushButton
{
	Q_OBJECT
public:
	KeItemButton(QString caption, QWidget *parent = 0);
	~KeItemButton();

public:
	void SetId(QString id){_id = id;}
	QString GetId(){return _id;}

	void SetClassDTO(ClassDTO dto){_classDTO = dto;}
	ClassDTO GetClassDTO(){return _classDTO;}

	void SetTeachingDTO(TeachingDTO dto){_teachingDTO = dto;}
	TeachingDTO GetTeachingDTO(){return _teachingDTO;}

	void SetKeDTO(KeDTO dto){_keDTO = dto;}
	KeDTO GetKeDTO(){return _keDTO;}

private:
	QString _id;
	ClassDTO _classDTO;
	TeachingDTO _teachingDTO;
	KeDTO _keDTO;
};

