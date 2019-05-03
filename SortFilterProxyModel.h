#pragma once

#include <QSortFilterProxyModel>
#include "human.h"

class SortFilterProxyModel : public QSortFilterProxyModel
{
	Q_OBJECT

public:
	SortFilterProxyModel(QObject* parent);
	void setFilterHuman(const Human& human);
	void doInvalidateFilter();

	inline void setSerchMode(bool serchMode)
	{
		m_filterByserch = serchMode;
	}

protected:
	virtual bool filterAcceptsRow(int source_row, const QModelIndex& source_parent) const override;
	virtual bool lessThan(const QModelIndex& source_left, const QModelIndex& source_right) const override;
private:
	bool m_filterByserch;
	Human m_human;
};
