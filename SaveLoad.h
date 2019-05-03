#pragma once
#include "HumanTableModel.h"
#include <QtWidgets>

class SaveLoad : public QWidget
{
	Q_OBJECT
public:
	SaveLoad(HumanTableModel* pHumanTableModel, QWidget* parent = 0);

	void load();
	void save();
private:
	HumanTableModel* m_pHumanTableModel;
};

