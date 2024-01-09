#include "MainController.h"


MainController::MainController(QObject *parent)
    : QObject{parent}
{
    restAccessManager = new RestAccessManager{this};
    testController = new TestController{restAccessManager, this};
    connect(testController, &TestController::consultaTurmasFinalizada, this, &MainController::consultaTurmasFinalizada);
}

void MainController::solicitarConsultaTurmas(QString ano)
{
    //    qDebug() << ano;
    testController->solicitarConsultaTurmas(ano);
}

void MainController::autenticar(QString userName, QString password)
{
    restAccessManager->setUsuario(userName, password);
}

void MainController::consultaTurmasFinalizada(JsonListProxyModel* jsonListProxyModel)
{
    // Criar uma instância do JsonListProxyModel e definir o modelo de origem
    emit getTurmasListModel(jsonListProxyModel);
}
