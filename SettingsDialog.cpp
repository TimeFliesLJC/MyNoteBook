#include "SettingsDialog.h"
#include "Settings.h"
#include "MyNoteBook.h"

SettingsDialog::SettingsDialog(QWidget *parent, int fontsize)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.spinBoxFontSize->setValue(fontsize);
	connect(ui.btnSaveSettings, SIGNAL(clicked()), this, SLOT(onBtnSaveSettings()));
}

SettingsDialog::~SettingsDialog()
{
}

int SettingsDialog::onBtnSaveSettings()
{
	Settings::SaveSettings(ui.spinBoxFontSize->value());
	MyNoteBook *mainPtr = (MyNoteBook *)parentWidget(); //��ø����ڵ�ָ��
	mainPtr->setPlainTextSize(); //���ø����ڵķ���
	return 0;
}
