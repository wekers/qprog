/*	Filename:	centralwidget.h
	Primary Qt interface class for QProg
	Interface for DIY PIC programmer hardware
	
	Created December 17, 2005 by Brandon Fosdick
	
	Copyright 2005 Brandon Fosdick (BSD License)
*/

#ifndef	CENTRALWIDGET_H
#define	CENTRALWIDGET_H

#include <QCheckBox>
#include <QComboBox>
#include <QWidget>
#include <QPushButton>
#include <QProgressDialog>

class CentralWidget : public QWidget
{
	Q_OBJECT
public:
	CentralWidget();
	bool	FillTargetCombo();

private slots:
	void onTargetComboChange(const QString &);
	void browse();

	void program_all();
	void read();
	void bulk_erase();
	void verify();

private:
	QComboBox	*FileName;
	QComboBox	*ProgrammerDeviceNode;
	QComboBox	*TargetType;

	QCheckBox	*EraseCheckBox;
	QCheckBox	*VerifyCheckBox;
	QCheckBox	*NewWindowOnReadCheckBox;
	QCheckBox	*ProgramOnFileChangeCheckBox;
	QProgressDialog *progressDialog;

	bool FillPortCombo();
	
	QString currentPath()
	{
		return ProgrammerDeviceNode->itemData(ProgrammerDeviceNode->currentIndex()).toString();
	}
};

#endif	//CENTRALWIDGET_H
