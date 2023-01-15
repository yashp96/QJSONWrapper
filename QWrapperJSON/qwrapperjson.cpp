#include "qwrapperjson.h"

QWrapperJSON::QWrapperJSON()
{

}

void QWrapperJSON::setJSONFileName(QString fName)
{
    fileName = fName;
}

QString QWrapperJSON::getFileName()
{
    return fileName;
}

void QWrapperJSON::readJSON(QString jsonFile, QMap<QString, QVariant> *jsonDictionary)
{
    QFile file;
    file.setFileName(jsonFile);

    if(file.exists())
    {
     file.open(QIODevice::ReadOnly|QIODevice::Text);
     QJsonParseError parseError;
     QJsonDocument jsonDocument = QJsonDocument::fromJson(file.readAll(),&parseError);
     if(parseError.error != QJsonParseError::NoError)
     {
         qDebug()<<"Error in parsing json file:" << parseError.errorString();
     }
     else
     {
         QVariant jsVar = jsonDocument.toVariant();
         QMap<QString, QVariant> jsVarMap = jsVar.toMap();
         *jsonDictionary = jsVarMap;
     }
     file.close();
    }
}

void QWrapperJSON::readJSON(QMap<QString, QVariant> *jsonDictionary)
{
    QFile file;
    file.setFileName(fileName);

    if(file.exists())
    {
     file.open(QIODevice::ReadOnly|QIODevice::Text);
     QJsonParseError parseError;
     QJsonDocument jsonDocument = QJsonDocument::fromJson(file.readAll(),&parseError);
     if(parseError.error != QJsonParseError::NoError)
     {
         qDebug()<<"Error in parsing json file:" << parseError.errorString();
         //*destnMap = NULL;
     }
     else
     {
         QVariant jsVar = jsonDocument.toVariant();
         QMap<QString, QVariant> jsVarMap = jsVar.toMap();
         *jsonDictionary = jsVarMap;
         qDebug() << "File parse OK.";
     }
     file.close();
    }
    else
    {
        qDebug() << "file not found.";
    }
}

void QWrapperJSON::writeJSON(QString jsonFile, QMap<QString, QVariant> srcMap)
{
    QVariantMap vmap;

    QMapIterator<QString, QVariant> i(srcMap);
    while (i.hasNext()) {
        i.next();
        vmap.insert(i.key(), i.value());
    }

    QJsonDocument json = QJsonDocument::fromVariant(vmap);

    QFile file;
    file.setFileName(jsonFile);
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    if(file.write(json.toJson()) != -1)
    {
        qDebug() << "json file saved successfully.";
    }
    else
    {
        qDebug() << "Error occured while saving the file.";
    }
    file.close();
}

void QWrapperJSON::writeJSON(QMap<QString, QVariant> srcMap)
{
    QVariantMap vmap;

    QMapIterator<QString, QVariant> i(srcMap);
    while (i.hasNext()) {
        i.next();
        vmap.insert(i.key(), i.value());
    }

    QJsonDocument json = QJsonDocument::fromVariant(vmap);

    QFile file;
    file.setFileName(fileName);
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    if(file.write(json.toJson()) != -1)
    {
        qDebug() << "json file saved successfully.";
    }
    else
    {
        qDebug() << "Error occured while saving the file.";
    }
    file.close();
}
