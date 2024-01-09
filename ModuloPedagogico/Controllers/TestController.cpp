#include "TestController.h"

TestController::TestController(RestAccessManager *restAccessManager, QObject *parent)
    : QObject{parent}
    , restAccessManager(restAccessManager)
{
    testeModel = new TestModel{restAccessManager};
    connect(testeModel, &TestModel::dataReadReady, this, &TestController::onConsultaTurmasFinalizada);
}

void TestController::solicitarConsultaTurmas(QString ano)
{
    if(ano.isEmpty())
        qDebug() << "Ano Vazio";
    else {
        restAccessManager->makeApiUrl(consulta, parametro, {ano});
        testeModel->getTurmas(restAccessManager->apiUrl, QUrlQuery());
    }
}

void TestController::onConsultaTurmasFinalizada(JsonListProxyModel* jsonListProxyModel)
{
    //    qInfo() << customResult.message();
    emit consultaTurmasFinalizada(jsonListProxyModel);
}
