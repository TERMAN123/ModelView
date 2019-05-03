#include "HumanTableModel.h"
#include "Human.h"

HumanTableModel::HumanTableModel(QObject* parent /* =0 */)
	: QAbstractItemModel(parent)
{
}

HumanTableModel::HumanTableModel(const List<Human>& listHumans, QObject* parent)
	: QAbstractItemModel(parent),
	m_listHumans(listHumans)
{
}

const List<Human>& HumanTableModel::getHumans()
{
	return m_listHumans;
}

QModelIndex HumanTableModel::parent(const QModelIndex& index) const
{
	return QModelIndex();
}

QModelIndex HumanTableModel::index(int row, int column, const QModelIndex& parent) const
{
	return createIndex(row, column);
}

int HumanTableModel::rowCount(const QModelIndex& parent) const
{
	return m_listHumans.size();
}

int HumanTableModel::columnCount(const QModelIndex& parent) const
{
	return 3;
}

QVariant HumanTableModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
	{
		return QVariant();
	}
	if (index.row() >= m_listHumans.size() || index.row() < 0)
	{
		return QVariant();
	}
	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		Human human = m_listHumans.at(index.row());
		if (index.column() == 0)
			return human.name;
		else if (index.column() == 1)
			return human.surname;
		else if (index.column() == 2)
			return human.phone;
		else
			return QVariant();
	}
	return QVariant();
}

Qt::ItemFlags HumanTableModel::flags(const QModelIndex& index) const
{
	Qt::ItemFlags Itemflags = QAbstractItemModel::flags(index);
	return index.isValid() ? (Itemflags | Qt::ItemIsEditable) : Itemflags;
}

bool HumanTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (index.isValid() && role == Qt::EditRole)
	{
		Human& rHuman = m_listHumans[index.row()];
		if (index.column() == 0)
		{
			rHuman.name = value.toString();
		}
		else if (index.column() == 1)
		{
			rHuman.surname = value.toString();
		}
		else if (index.column() == 2)
		{
			rHuman.phone = value.toString();
		}
		else
		{
			return false;
		}
		emit dataChanged(index, index);
		return true;
	}
	return false;
}

void HumanTableModel::addRow(const Human& human)
{
	beginInsertRows(QModelIndex(), m_listHumans.size(), m_listHumans.size());
	m_listHumans.push_back(human);
	endInsertRows();
}

void HumanTableModel::remuveRow(const QModelIndex &index)
{
	if (index.isValid())
	{
		beginRemoveRows(QModelIndex(), index.row(), index.row());
		m_listHumans.remove(index.row());
		endRemoveRows();
	}
}

void HumanTableModel::removeRowsAndHumans()
{
	if (m_listHumans.size() > 0)
	{
		int size = m_listHumans.size() - 1;
		beginRemoveRows(QModelIndex(), 0, size);
		m_listHumans.clear();
		endRemoveRows();
	}
}


QVariant HumanTableModel::headerData(int nSection, Qt::Orientation orientation, int nRole) const 
{
	if (nRole != Qt::DisplayRole)
	{
		return QVariant();
	}
	if (orientation == Qt::Horizontal)
	{
		switch (nSection) 
		{
		case 0: 
			{ return QString("Name"); }
		case 1:
			{ return QString("Surname"); }
		case 2:
			{ return QString("Phone"); }
		default:
			{ return QVariant(); }
		}
	}
	return QVariant();
}




