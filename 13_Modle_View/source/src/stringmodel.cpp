#include "source/inc/stringmodel.h"

StringListModel::StringListModel(const QStringList &strings, QObject *parent)
		: QAbstractListModel(parent)
{
	// stringlist(strings);
	stringlist.append(strings);
}

int StringListModel::rowCount(const QModelIndex &parent) const
{
	return stringlist.count();
}

QVariant StringListModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();
	if (index.row() >= stringlist.size())
		return QVariant();
	if (role == Qt::DisplayRole)
		return stringlist.at(index.row());
	else
		return QVariant();
}

QVariant StringListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole)
		return QVariant();
	if (orientation == Qt::Horizontal)
		return QString("Column %1").arg(section);
	else
		return QString("Row %1").arg(section);
}

Qt::ItemFlags StringListModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::ItemIsEnabled;
	return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}

bool StringListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (index.isValid() && role == Qt::EditRole) {
		stringlist.replace(index.row(), value.toString());
		emit dataChanged(index, index);
		return true;
	}
	return false;
}

bool StringListModel::insertRows(int position, int rows, const QModelIndex &parent)
{
	beginInsertRows(QModelIndex(), position, position + rows - 1);
	for (int i = 0; i < rows; ++i) {
		stringlist.insert(position, "");
	}
	endInsertRows();
	return true;
}

bool StringListModel::removeRows(int position, int rows, const QModelIndex &parent)
{
	beginRemoveRows(QModelIndex(), position, position + rows - 1);
	for (int i = 0; i < rows; ++i) {
		stringlist.removeAt(position);
	}
	endRemoveRows();
	return true;
}
