#include "SortFilterProxyModel.h"

SortFilterProxyModel::SortFilterProxyModel(QObject *parent)
	: QSortFilterProxyModel(parent)
{
}

void SortFilterProxyModel::setFilterHuman(const Human& human)
{
	m_human = human;
}

bool SortFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex& source_parent) const
{
	QModelIndex index0 = sourceModel()->index(source_row, 0, source_parent);
	QModelIndex index1 = sourceModel()->index(source_row, 1, source_parent);
	QModelIndex index2 = sourceModel()->index(source_row, 2, source_parent);

	if (m_filterByserch)
	{
		return sourceModel()->data(index0).toString().toLower().contains(filterRegExp())
			|| sourceModel()->data(index1).toString().toLower().contains(filterRegExp())
			|| sourceModel()->data(index2).toString().toLower().contains(filterRegExp());
	}
	else
	{
		bool accept = true;
		if (!m_human.name.isEmpty())
		{
			accept &= sourceModel()->data(index0).toString() == m_human.name;
		}
		if (!m_human.surname.isEmpty())
		{
			accept &= sourceModel()->data(index1).toString() == m_human.surname;
		}
		if (!m_human.phone.isEmpty())
		{
			accept &= sourceModel()->data(index2).toString() == m_human.phone;
		}
		return accept;
	}
}

void SortFilterProxyModel::doInvalidateFilter()
{
	invalidateFilter();
}

bool SortFilterProxyModel::lessThan(const QModelIndex& source_left, const QModelIndex& source_right) const
{
	QVariant leftData = sourceModel()->data(source_left);
	QVariant rightData = sourceModel()->data(source_right);

	return leftData.toString() < rightData.toString();
}
