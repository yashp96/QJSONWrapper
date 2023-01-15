#ifndef QWRAPPERJSON_H
#define QWRAPPERJSON_H

#include <QObject>

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>

#include <QDebug>
#include <QMap>

class QWrapperJSON:public QObject
{
    Q_OBJECT
public:
    QWrapperJSON();

    void setJSONFileName(QString fName);
    QString getFileName();

    void readJSON(QString fileName, QMap<QString, QVariant> *jsonDictionary);
    void readJSON(QMap<QString, QVariant> *jsonDictionary);

    void writeJSON(QString fileName, QMap<QString, QVariant> srcMap);
    void writeJSON(QMap<QString, QVariant> srcMap);

private:
    QString fileName;

};

#endif // QWRAPPERJSON_H
