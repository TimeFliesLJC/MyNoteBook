#pragma once

#include <QtWidgets/QMainWindow>
#include <QLabel>
#include "ui_MyNoteBook.h"

class MyNoteBook : public QMainWindow
{
	Q_OBJECT

public:
	MyNoteBook(QWidget *parent = Q_NULLPTR);
	void setPlainTextSize(); //�����ı����������С

private slots:
	int OnMenuNew();
	int OnMenuSave();
	int OnMenuSaveAs();
	int OnMenuOpen();
	int OnMenuFontSizeUp();
	int OnMenuFontSizeDown();
	int OnMenuHelp();
	int OnMenuSettings();
	int OnMenuEncrypt();
	int OnMenuDecrypt();

private:
	Ui::MyNoteBookClass ui;
	QString m_filepath; //�ļ���
	QLabel *m_labelName; //״̬����ʾ
	int textFontSize; //�ı����������С
	QString encryptFlag; //���ܱ�־������ı���һ��Ϊ���ܱ�־����ʾ�Ѿ�����

	void closeEvent(QCloseEvent * event);
	bool isEncrypt(); //�ж��ı��Ƿ��Ѿ�����
};
