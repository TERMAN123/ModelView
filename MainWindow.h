#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "HumanTableModel.h"
#include "SortFilterProxyModel.h"
#include "SaveLoad.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = Q_NULLPTR);


public slots:
	void createAndAddHuman();
	void deleteHuman();
private slots:
	void serchFilterChanged(const QString& str);
	void sort();
	void filterHuman();
	void resetFilter();
	void loadFromFile();
	void saveToFile();

private:
	Ui::MainWindowClass ui;
	HumanTableModel* m_pHumanTableModel{ nullptr };
	SortFilterProxyModel* m_proxModel{ nullptr };
	SaveLoad* m_saveLoad{ nullptr };
};
