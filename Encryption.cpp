#include "Encryption.h"
#include <QTextCodec>
#include <string>
#include "GBK.h"
#include <vector>
using std::string;
using std::vector;

QString Encryption::Encrypt(QString pwdKey, QString text)
{
	string keyStr = GBK::FromUnicode(pwdKey);
	vector<int> key;
	int keyLen = keyStr.size();
	for (int i = 0; i < keyLen; ++i)
	{
		key.push_back(keyStr[i] - '0');
	}

	//��Unicode����תΪ64���Ʊ���
	QByteArray base64text = text.toLocal8Bit().toBase64();

	//ʹ��������
	int textLen = base64text.size();
	char *base64CharArray = new char[textLen+1];
	strcpy(base64CharArray, base64text.data());
	base64CharArray[textLen] = 0;

	for (int i = 0; i < textLen; ++i)
	{
		char t = base64CharArray[i];
		base64CharArray[i] = base64CharArray[i] ^ key[i%keyLen];
		if (base64CharArray[i] == 0)
		{
			base64CharArray[i] = t;
		}
	}
	
	
	QString result(base64CharArray);
	free(base64CharArray);
	//��64���Ʊ�����ܺ��ٴ�תΪ64���Ʊ���,��ֹ���ܺ󱣴�ʱ��Ϣ��ʧ
	return result.toLocal8Bit().toBase64();
	
}

QString Encryption::Decrypt(QString pwdKey, QString entext)
{
	//��64���Ʊ���ת��Ϊunicode����
	QString text(QTextCodec::codecForName("GBK")->toUnicode(QByteArray::fromBase64(entext.toLocal8Bit())));

	//ʹ��������
	string keyStr = GBK::FromUnicode(pwdKey);
	vector<int> key;
	int keyLen = keyStr.size();
	for (int i = 0; i < keyLen; ++i)
	{
		key.push_back(keyStr[i] - '0');
	}

	int textLen = text.toLocal8Bit().size();
	char *base64CharArray = new char[textLen+1];
	strcpy(base64CharArray, text.toLocal8Bit().data());
	base64CharArray[textLen] = 0;

	for (int i = 0; i < textLen; ++i)
	{
		char t = base64CharArray[i];
		base64CharArray[i] = base64CharArray[i] ^ key[i%keyLen];
		if (base64CharArray[i] == 0)
		{
			base64CharArray[i] = t;
		}
	}

	QString result(base64CharArray);
	free(base64CharArray);
	//�ڶ��δ�64���Ʊ���ת��Ϊunicode����
	return QTextCodec::codecForName("GBK")->toUnicode(QByteArray::fromBase64(result.toLocal8Bit()));

}