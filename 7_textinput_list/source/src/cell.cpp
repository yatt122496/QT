#include "source/inc/cell.h"
#include <QtGui>
#include <QGridLayout>

Cell::Cell()
{

}

void Cell::setData(int role, const QVariant &value)
{
	QTableWidgetItem::setData(role, value);
}

QVariant Cell::data(int role)
{
	if (role == Qt::DisplayRole) {
		if (value().isValid()) {
			return value().toString();
		} else {
			return "####";
		}
	} else if (role == Qt::TextAlignmentRole) {
		if (value().type() == QVariant::String) {
			return int(Qt::AlignLeft | Qt::AlignVCenter);
		} else {
			return int(Qt::AlignRight | Qt::AlignVCenter);
		}
	} else {
		return QTableWidgetItem::data(role);
	}
}

void Cell::setcontentText(QString &formula)
{
	setData(Qt::EditRole, formula);
}

QString Cell::contentText()
{
	return data(Qt::EditRole).toString();
}

QVariant Cell::value()
{
	QString formulaStr = contentText();
	if (formulaStr.startsWith('\'')) {
		cachedValue = formulaStr.mid(1);
	} else if (formulaStr.startsWith('=')) {
		QString expr = formulaStr.mid(1);
		expr.replace(" ", "");
		expr.append(QChar::Null);

		int pos = 0;
		if (expr[pos] != QChar::Null) {
			cachedValue = expr;
		}
	} else {
		bool ok;
		double d = formulaStr.toDouble(&ok);
		if (ok) {
			cachedValue = d;
		} else {
			cachedValue = formulaStr;
		}
	}
	return cachedValue;
}
