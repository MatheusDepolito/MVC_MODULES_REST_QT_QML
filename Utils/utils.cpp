#include "utils.h"

std::optional<QJsonObject> byteArrayToJsonObject(const QByteArray &data)
{
    QJsonParseError err;
    const auto json = QJsonDocument::fromJson(data, &err);

    if(err.error)
        qDebug() << "Dados de uma resposta não Json:" << err.errorString() << "em" << err.offset << data;

                                                                                                    return json.isObject() ? json.object() : std::optional<QJsonObject>(std::nullopt);
}

std::optional<QJsonArray> byteArrayToJsonArray(const QByteArray &data)
{
    QJsonParseError err;
    const auto json = QJsonDocument::fromJson(data, &err);

    if(err.error)
        qDebug() << "Dados de uma resposta não Array Json:" << err.errorString() << "em" << err.offset << data;

                                                                                                          return json.isArray() ? json.array() : std::optional<QJsonArray>(std::nullopt);
}

std::optional<JsonListModel*> jsonArrayToJsonListModel(const QJsonArray &data)
{
    if (data.isEmpty())
        return std::nullopt;

    JsonListModel* jsonListModel = new JsonListModel;
    jsonListModel->setJsonArray(data);

    if(jsonListModel->rowCount() == 0) {
        delete jsonListModel;
        return nullptr;
    }

    return jsonListModel;
}

