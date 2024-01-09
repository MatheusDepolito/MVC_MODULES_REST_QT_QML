#ifndef TESTCONTROLLER_H
#define TESTCONTROLLER_H

#include <QObject>
#include "../../Utils/RestAccessManager.h"
#include "../Models/TestModel.h"


class TestController : public QObject
{
    Q_OBJECT
public:
    explicit TestController(RestAccessManager* restAccessManager, QObject *parent = nullptr);

    void solicitarConsultaTurmas(QString ano);

private:
    QString consulta = "NOme consulta";
    QVector<QString> parametro = {"ANO"};
    TestModel* testeModel;
    RestAccessManager* restAccessManager;

private slots:
    void onConsultaTurmasFinalizada(JsonListProxyModel* jsonListProxyModel);
signals:
    void consultaTurmasFinalizada(JsonListProxyModel* jsonListProxyModel);
};

#endif // TESTCONTROLLER_H
