#include "MainWindow.h"
#include <QtWidgets>
#include "Dialog.h"
#include "List.h"


MainWindow::MainWindow(QWidget* parent /* = 0 */)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	Human human1;
	human1.name = "Tereza";
	human1.surname = "Manukyan";
	human1.phone = "099-99-99-99";

	Human human2;
	human2.name = "Mko";
	human2.surname = "Marukyan";
	human2.phone = "044-44-44-44";

	Human human3;
	human3.name = "Tereza";
	human3.surname = "Mnacakanyan";
	human3.phone = "099-88-99-99";

	List<Human> humans;
	humans.push_back(human1);
	humans.push_back(human2);
	humans.push_back(human3);

	m_pHumanTableModel = new HumanTableModel(humans, this);

	ui.tableView->verticalHeader()->hide();
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);

	m_proxModel = new SortFilterProxyModel(this);
	m_proxModel->setSourceModel(m_pHumanTableModel);
	ui.tableView->setModel(m_proxModel);

	m_saveLoad = new SaveLoad(m_pHumanTableModel, this);

	QObject::connect(ui.lineEdit_serch, SIGNAL(textEdited(const QString&)),
					this, SLOT(serchFilterChanged(const QString&)));

	QObject::connect(ui.pushButtonAdd, SIGNAL(clicked()), this, SLOT(createAndAddHuman()));
	QObject::connect(ui.pushButtonDelete, SIGNAL(clicked()), this, SLOT(deleteHuman())); 

	QObject::connect(ui.groupBox_Sort, SIGNAL(clicked()), this, SLOT(sort()));

	QObject::connect(ui.radioButton_Ascending, SIGNAL(clicked()), this, SLOT(sort()));
	QObject::connect(ui.radioButton_Descending, SIGNAL(clicked()), this, SLOT(sort()));

	QObject::connect(ui.radioButton_ByName, SIGNAL(clicked()), this, SLOT(sort()));
	QObject::connect(ui.radioButton_BySurname, SIGNAL(clicked()), this, SLOT(sort()));
	QObject::connect(ui.radioButton_ByPhone, SIGNAL(clicked()), this, SLOT(sort()));
	
	QObject::connect(ui.pushButton_Apply, SIGNAL(clicked()), this, SLOT(filterHuman()));
	QObject::connect(ui.pushButton_Reset, SIGNAL(clicked()), this, SLOT(resetFilter()));

	QObject::connect(ui.pushButton_Load, SIGNAL(clicked()), this, SLOT(loadFromFile())); 
	QObject::connect(ui.pushButton_Save, SIGNAL(clicked()), this, SLOT(saveToFile())); 
	QObject::connect(ui.actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));

	this->resize(800, 600);
}

void MainWindow::saveToFile()
{
	m_saveLoad->save();
}

void MainWindow::loadFromFile()
{
	m_saveLoad->load();
}

void MainWindow::createAndAddHuman()
{
	Dialog dlg;
	dlg.exec();
	if (dlg.result() == QDialog::Accepted) 
	{
		m_pHumanTableModel->addRow(dlg.getHuman());
	}
}

void MainWindow::deleteHuman()
{
	QModelIndex indexOriginalModel = m_proxModel->mapToSource(ui.tableView->currentIndex());
	m_pHumanTableModel->remuveRow(indexOriginalModel);
}

void MainWindow::serchFilterChanged(const QString& str)
{
	m_proxModel->setFilterRegExp(str.toLower());
}

void MainWindow::filterHuman()
{
	ui.lineEdit_serch->clear();
	ui.lineEdit_serch->setDisabled(true);
	m_proxModel->setSerchMode(false);
	Human human;
	human.name = ui.lineEdit_Name->text();
	human.surname = ui.lineEdit_Surname->text();
	human.phone = ui.lineEdit_Phone->text();
	m_proxModel->setFilterHuman(human);
	m_proxModel->doInvalidateFilter();
}

void MainWindow::resetFilter()
{
	ui.lineEdit_Name->clear();
	ui.lineEdit_Surname->clear();
	ui.lineEdit_Phone->clear();
	ui.lineEdit_serch->clear();
	ui.lineEdit_serch->setEnabled(true);
	m_proxModel->setSerchMode(true);
	serchFilterChanged(QString());
}

void MainWindow::sort()
{
	if (ui.groupBox_Sort->isChecked())
	{
		Qt::SortOrder order = Qt::DescendingOrder;
		if (ui.radioButton_Ascending->isChecked())
		{
			order = Qt::AscendingOrder;
		}
		int column = 0;
		if (ui.radioButton_BySurname->isChecked())
		{
			column = 1;
		}
		else if (ui.radioButton_ByPhone->isChecked())
		{
			column = 2;
		}
		m_proxModel->sort(column, order);
	}
	else
	{
		m_proxModel->sort(-1);
		m_proxModel->setDynamicSortFilter(false);
	}
	m_proxModel->doInvalidateFilter();
}

