#include "RestAccessManager.h"

using namespace Qt::StringLiterals;

static constexpr auto contentTypeJson = "application/json"_L1;

static bool httpResponseSuccess(QNetworkReply* reply) {
    const int httpStatusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    const bool isReplyError = (reply->error() != QNetworkReply::NoError);

    qDebug() << "Solicitação para o caminho" << reply->request().url().path() << "finalizada";
    if (isReplyError)
        qDebug() << "Erro" << reply->error();
    else
        qDebug() << "HTTP:" << httpStatusCode;

    return (!isReplyError && (httpStatusCode >= 200 && httpStatusCode < 300));
}

RestAccessManager::RestAccessManager(QObject *parent)
    : QNetworkAccessManager{parent}
{
    connect(this, &QNetworkAccessManager::authenticationRequired, this, &RestAccessManager::onAuthenticationRequired);

    if (!isHostAvailable(localHost)) {
        qInfo() << "LocalHost não disponivel, alterando para o remote host";
        this->urlBase.replace(localHost, remoteHost);
    }
}

void RestAccessManager::setUsuario(QString userName, QString password)
{
    this->usuario.usuarioNome = userName;
    this->usuario.senha = password;
}

bool RestAccessManager::sslSupported() const
{
    #if QT_CONFIG(ssl)
        return QSslSocket::supportsSsl();
    #else
        return false;
    #endif
}

void RestAccessManager::POST(const QString &api, const QVariantMap &value, ResponseCallback callback)
{
    auto request = QNetworkRequest(QUrl(api));

    request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, contentTypeJson);

    QNetworkReply* reply = QNetworkAccessManager::post(request, QJsonDocument::fromVariant(value).toJson(QJsonDocument::Compact));

    QObject::connect(reply, &QNetworkReply::finished, reply, [reply, callback]() {
        callback(reply, httpResponseSuccess(reply));
    });
}

void RestAccessManager::GET(const QString &api, const QUrlQuery &parameters, ResponseCallback callback)
{
    auto request = QNetworkRequest(QUrl(api));
    request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, contentTypeJson);

    QNetworkReply* reply = QNetworkAccessManager::get(request);

    QObject::connect(reply, &QNetworkReply::finished, reply, [reply, callback]() {
        callback(reply, httpResponseSuccess(reply));
    });
}

void RestAccessManager::PUT(const QString &api, const QVariantMap &value, ResponseCallback callback)
{
    auto request = QNetworkRequest(QUrl(api));

    request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, contentTypeJson);

    QNetworkReply* reply = QNetworkAccessManager::put(request, QJsonDocument::fromVariant(value).toJson(QJsonDocument::Compact));

    QObject::connect(reply, &QNetworkReply::finished, reply, [reply, callback]() {
        callback(reply, httpResponseSuccess(reply));
    });
}

void RestAccessManager::DELETE(const QString &api, ResponseCallback callback)
{
    auto request = QNetworkRequest(QUrl(api));

    QNetworkReply* reply = QNetworkAccessManager::deleteResource(request);

    QObject::connect(reply, &QNetworkReply::finished, reply, [reply, callback]() {
        callback(reply, httpResponseSuccess(reply));
    });
}

void RestAccessManager::makeApiUrl(QString &consulta, QVector<QString> parametros, QVector<QString> valores)
{
    QString url = this->urlBase.arg(consulta);

    if(!parametros.isEmpty()) {
        QString param;
        url += "?parameters=";

        for(const auto& p : parametros)
            param += p + "=" + valores.at(&p - &parametros[0]) + ";";

        url += param;
    }

    this->apiUrl = url;
}

bool RestAccessManager::isHostAvailable(const QString &host)
{
    QHostAddress hostAdress(host);

    if(hostAdress.isNull())
        return false;

    QTcpSocket socket;
    socket.connectToHost(hostAdress, 8051);
    return socket.waitForConnected(1000);
}


void RestAccessManager::onAuthenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    auto user = this->usuario;
    authenticator->setUser(user.usuarioNome);
    authenticator->setPassword(user.senha);
}
