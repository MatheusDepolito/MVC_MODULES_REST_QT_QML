#ifndef UTILS_H
#define UTILS_H

#include "../Utils/Tipos.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <functional>

std::optional<QJsonObject> byteArrayToJsonObject(const QByteArray& data);

std::optional<QJsonArray> byteArrayToJsonArray(const QByteArray& data);

std::optional<JsonListModel*> jsonArrayToJsonListModel(const QJsonArray& data);


#endif // UTILS_H
