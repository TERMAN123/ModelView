#pragma once

#include <QDialog>
#include "human.h"

class QLabel;
class QPushButton;
class QTextEdit;
class QLineEdit;

class Dialog : public QDialog
{
	Q_OBJECT

public:
	Dialog(QWidget* parent = 0);
	Human getHuman() const;

private:
	QLabel* nameLabel;
	QLabel* surnameLabel;
	QLabel* phoneLabel;

	QLineEdit* nameTextEdit;
	QLineEdit* surnameTextEdit;
	QLineEdit* phoneNumberEdit;

	QPushButton* okButton;
	QPushButton* cancelButton;
};
