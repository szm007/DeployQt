﻿#ifndef VERSIONMODE_H
#define VERSIONMODE_H

#include <QObject>
#include <QProcess>

class VersionMode : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList qtVersionList       READ qtVersionList                            NOTIFY listChanged)
    Q_PROPERTY(QStringList compilerVersionList READ compilerVersionList                      NOTIFY listChanged)
    Q_PROPERTY(QString     qtVersion           READ qtVersion       WRITE setQtVersion       NOTIFY statusChanged)
    Q_PROPERTY(QString     compilerVersion     READ compilerVersion WRITE setCompilerVersion NOTIFY statusChanged)
    Q_PROPERTY(QString     exeFile             READ exeFile         WRITE setExeFile         NOTIFY statusChanged)

public:
    VersionMode();

    Q_INVOKABLE bool create();
    Q_INVOKABLE bool test();

    QStringList qtVersionList();
    QStringList compilerVersionList();


    QString     qtVersion();
    void        setQtVersion(const QString &version);

    QString     compilerVersion();
    void        setCompilerVersion(const QString &version);

    QString     exeFile();
    void        setExeFile(const QString &file);

signals:
    void listChanged();
    void statusChanged();

private:
    QStringList m_qtVersionList;
    QStringList m_compilerVersionList;
    QString m_qtVersion;
    QString m_qtVersionDirName;
    QString m_compilerVersion;
    QString m_exeFile;
    QProcess m_testProcess;
};

#endif // VERSIONMODE_H
