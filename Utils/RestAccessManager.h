#ifndef RESTACCESSMANAGER_H
#define RESTACCESSMANAGER_H

#include "../Utils/Tipos.h"
#include <functional>
#include <QtCore>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QAuthenticator>
#include <QObject>

class RestAccessManager : public QNetworkAccessManager
{
    Q_OBJECT
    Q_PROPERTY(bool sslSupported READ sslSupported CONSTANT)
public:
    explicit RestAccessManager(QObject *parent = nullptr);

    void setUsuario(QString userName, QString password);

    bool sslSupported() const;

    using ResponseCallback = std::function<void(QNetworkReply*, bool)>;

    void POST(const QString& api, const QVariantMap& value, ResponseCallback callback);
    void GET(const QString& api, const QUrlQuery& parameters, ResponseCallback callback);
    void PUT(const QString& api, const QVariantMap& value, ResponseCallback callback);
    void DELETE(const QString& api, ResponseCallback callback);

    void makeApiUrl(QString &consulta, QVector<QString> parametros = QVector<QString>(), QVector<QString> valores = QVector<QString>());
    QString apiUrl;

private:
    Usuario usuario;
    QNetworkReply* currentReply = nullptr;
    QString urlBase = "http://122.11.111.110:3333/api/framework/v1/consultaSQLServer/RealizaConsulta/%1/1/S/";
    QString localHost = "111.11.111.111";
    QString remoteHost = "122.11.111.110";
    bool isHostAvailable(const QString &host);
    //186.194.232.102
private slots:
    void onAuthenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator);
};

#endif // RESTACCESSMANAGER.H
