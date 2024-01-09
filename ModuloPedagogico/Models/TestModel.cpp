#include "TestModel.h"

TestModel::TestModel(RestAccessManager *restAccessManager, QObject *parent)
    : QObject{parent}
    , restAccessManager(restAccessManager)
{
    connect(this, &TestModel::dataReceived, this, &TestModel::processResponseData);
}

void TestModel::getTurmas(QString url, QUrlQuery parameters)
{
    restAccessManager->GET(url, parameters, [this](QNetworkReply* reply, bool success){
        if (success)
            emit dataReceived(reply->readAll());
        else {
            emit dataReadReady(*jsonListProxyModelOpt);
        }
    });
}

QString TestModel::defineEscolaridade(const QString &nomeTurma)
{
    const std::vector<std::pair<QString, QString>> escolaridadeMap = {
        {"Série", "Ensino Médio"},
        {"SÉRIE", "Ensino Médio"},
        {"Ano", "Fundamental"   },
        {"ANO", "Fundamental"   },
        {"Infantil", "Infantil"}};

    for (const auto &entry : escolaridadeMap) {
        if (nomeTurma.contains(entry.first)) {
            return entry.second;
        }
    }

    return "Cursinho";
}

void TestModel::processResponseData(std::optional<QByteArray> data)
{
    auto jsonArrayOpt = byteArrayToJsonArray(*data);
    if(!jsonArrayOpt) {
        emit dataReadReady(*jsonListProxyModelOpt);
        return;
    }

    for(auto it = (*jsonArrayOpt).begin(); it != (*jsonArrayOpt).end(); ++it ){
        if(it->isObject()) {
            QJsonObject jsonObj = it->toObject();

            QString nome = jsonObj.value("NOME").toString();

            QString escolaridade = this->defineEscolaridade(nome);

            QJsonValue  escolaridadeValue(escolaridade);
            jsonObj["ESCOLARIDADE"] = escolaridadeValue;

            *it = jsonObj;
        }
    }

    if(!jsonModelOpt || !((*jsonModelOpt)->getJsonItems() == jsonArrayOpt)) {
        if(!jsonModelOpt) {
            jsonModelOpt = jsonArrayToJsonListModel(*jsonArrayOpt);
            (*jsonListProxyModelOpt) = new JsonListProxyModel(this);
            (*jsonListProxyModelOpt)->setSourceModel((*jsonModelOpt));
            (*jsonListProxyModelOpt)->setFilterField("ESCOLARIDADE");
        } else {
            (*jsonModelOpt)->setJsonArray(*jsonArrayOpt);
            (*jsonListProxyModelOpt)->setSourceModel((*jsonModelOpt));
        }

        emit dataReadReady(*jsonListProxyModelOpt);
    } else {
        qDebug() << "iguais";
    }
}
