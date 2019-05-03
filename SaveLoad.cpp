#include "SaveLoad.h"
#include <QtXml>


SaveLoad::SaveLoad(HumanTableModel* pHumanTableModel, QWidget* parent /* = 0 */)
	:QWidget(parent),
	m_pHumanTableModel(pHumanTableModel)
{
}

void SaveLoad::load()
{
	QString fileName = QFileDialog::getOpenFileName(this, ("Open People's Information"), "",
		("eXtensible MarkupLanguage fill (*.xml)"));
	if (fileName.isEmpty())
		return;
	else
	{
		QFile file(fileName);
		if (!file.open(QFile::ReadOnly | QFile::Text))
		{
			QMessageBox::information(this, "Unable to open file", file.errorString());
			return;
		}

		QXmlStreamReader reader(&file);

		if (reader.readNextStartElement())
		{
			if (reader.name() == "content")
			{
				Human human;
				m_pHumanTableModel->removeRowsAndHumans();
				while (reader.readNextStartElement())
				{
					if (reader.name() == "Human")
					{
						while (reader.readNextStartElement())
						{
							if (reader.name() == "Name")
							{
								human.name = reader.readElementText();
							}
							else if (reader.name() == "Surname")
							{
								human.surname = reader.readElementText();
							}
							else if (reader.name() == "Phone")
							{
								human.phone = reader.readElementText();
							}
						}
					}
					m_pHumanTableModel->addRow(human);
				}
			}
		}
	}
}

void SaveLoad::save()
{
	QString fileName = QFileDialog::getSaveFileName(this,
		"Save People's Information", "",
		"eXtensible MarkupLanguage fill (*.xml)");
	if (fileName.isEmpty())
		return;
	else
	{
		QFile file(fileName);
		if (!file.open(QIODevice::WriteOnly))
		{
			QMessageBox::information(this, "Unable to open file",
				file.errorString());
			return;
		}

		QXmlStreamWriter xmlWriter(&file);
		xmlWriter.setAutoFormatting(true);
		xmlWriter.writeStartDocument();

		xmlWriter.writeStartElement("content");
		const List<Human>& humansList = m_pHumanTableModel->getHumans();
		for (int i = 0; i < m_pHumanTableModel->rowCount(); i++)
		{
			xmlWriter.writeStartElement("Human");

			xmlWriter.writeTextElement("Name", humansList.at(i).name);
			xmlWriter.writeTextElement("Surname", humansList.at(i).surname);
			xmlWriter.writeTextElement("Phone", humansList.at(i).phone);

			xmlWriter.writeEndElement();
		}
		xmlWriter.writeEndElement();

		file.close();
	}
}


