#include "Dialog.h"
#include <QtWidgets>

Dialog::Dialog(QWidget* parent /* = 0*/)
	: QDialog(parent)
{
	nameLabel = new QLabel("Name: ", this);
	surnameLabel = new QLabel("Surname: ", this);
	phoneLabel = new QLabel("Phone: ", this);
	okButton = new QPushButton("OK", this);
	cancelButton = new QPushButton("Cancel", this);

	nameTextEdit = new QLineEdit(this);
	surnameTextEdit = new QLineEdit(this);
	phoneNumberEdit = new QLineEdit(this);

	QGridLayout* gLayout = new QGridLayout(this);
	gLayout->setColumnStretch(1, 2);
	gLayout->addWidget(nameLabel, 0, 0);
	gLayout->addWidget(nameTextEdit, 0, 1);
	gLayout->addWidget(surnameLabel, 1, 0);
	gLayout->addWidget(surnameTextEdit, 1, 1);
	gLayout->addWidget(phoneLabel, 2, 0);
	gLayout->addWidget(phoneNumberEdit, 2, 1);

	QHBoxLayout* buttonLayout = new QHBoxLayout(this);
	buttonLayout->addWidget(okButton);
	buttonLayout->addWidget(cancelButton);

	gLayout->addLayout(buttonLayout, 3, 1, Qt::AlignHCenter);

	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->addLayout(gLayout);
	setLayout(mainLayout);

	QObject::connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
	QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

	setWindowTitle("Add Person");
}

Human Dialog::getHuman() const
{
	Human human;
	QString name = nameTextEdit->text();
	human.name = name;;

	QString surname = surnameTextEdit->text();
	human.surname = surname;

	QString phone = phoneNumberEdit->text();
	human.phone = phone;

	return human;
}


