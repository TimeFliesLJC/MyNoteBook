#pragma once
#include <QString>

//���ܽ���ģ�飬֧����ĸ���ֻ�����룡
class Encryption
{
public:
	static QString Encrypt(QString pwdKey, QString text); //�����ı�
	static QString Decrypt(QString pwdKey, QString text); //�����ı�
};