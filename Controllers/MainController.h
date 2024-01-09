#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include "ModuloPedagogico/Controllers/TestController.h"
#include "Utils/RestAccessManager.h"

class MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = nullptr);

    Q_INVOKABLE void solicitarConsultaTurmas(QString ano);

    Q_INVOKABLE void autenticar(QString userName, QString password);
private:
    RestAccessManager* restAccessManager;
    TestController* testController;
signals:
    void getTurmasListModel(JsonListProxyModel* jsonListProxyModel);
private slots:
    void consultaTurmasFinalizada(JsonListProxyModel* jsonListProxyModel);
};

#endif // MAINCONTROLLER_H
