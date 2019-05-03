#pragma once
#include <QAbstractListModel>
#include "List.h"
#include "human.h"
#include "SortFilterProxyModel.h"

class HumanTableModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	HumanTableModel(QObject* parent = 0);
	HumanTableModel(const List<Human>& listHumans, QObject* parent = 0);

	virtual QModelIndex parent(const QModelIndex& index) const override;
	virtual QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override;
	virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	virtual QVariant data(const QModelIndex& index, int role) const override;
	virtual Qt::ItemFlags flags(const QModelIndex& index) const override;
	virtual bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
	virtual QVariant headerData(int nSection, Qt::Orientation orientation, int nRole = Qt::DisplayPropertyRole) const override;

	void addRow(const Human& human);
	void remuveRow(const QModelIndex& index);

	void removeRowsAndHumans();

	const List<Human>& getHumans();

private:
	List<Human> m_listHumans;
};
