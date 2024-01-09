#ifndef TIPOS_H
#define TIPOS_H

#include <QString>
#include <QAbstractListModel>
#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QSortFilterProxyModel>

class Usuario
{
public:
    explicit Usuario(QString usuarioNome = QString(), QString senha = QString()) : usuarioNome(usuarioNome), senha(senha) {}

    QString usuarioNome;
    QString senha;
};

class Turma
{
public:
    explicit Turma(QString nome = QString(), QString codigoTurma = QString(), QString idPerLet = QString(), QString escolaridade = QString())
        : nome(nome), codigoTurma(codigoTurma), idPerLet(idPerLet), escolaridade(escolaridade)
    {}

    QString getCodTurma() const { return this->codigoTurma; }
    QString getNome() const { return this->nome; }
    QString getIdPerLet() const { return this->idPerLet; }
    QString getEscolaridade() const { return this->escolaridade; }

private:
    QString nome;
    QString codigoTurma;
    QString idPerLet;
    QString escolaridade;
};

class JsonListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    JsonListModel(QObject* parent = nullptr)
        : QAbstractListModel(parent) {}

    void setJsonArray(const QJsonArray& jsonArray) {
        beginResetModel();
        jsonItems = jsonArray;
        updateRolesFromJson(jsonArray);
        endResetModel();
    }

    Q_INVOKABLE int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return jsonItems.count();
    }

    Q_INVOKABLE QVariant data(const QModelIndex& index, int role) const override {
        if (!index.isValid() || index.row() >= jsonItems.count())
            return QVariant();

        const QJsonObject item = jsonItems.at(index.row()).toObject();

        if (m_roleNames.contains(role)) {
            auto test = item.value(m_roleNames[role]).toVariant();

            return item.value(m_roleNames[role]).toVariant();
        }

        return QVariant();
    }

    Q_INVOKABLE QHash<int, QByteArray> roleNames() const override {
        qDebug() << m_roleNames.keys();
        return m_roleNames;
    }

    void addRole(const QByteArray &name) {
        int maxRole = -1;
        for (QHash<int, QByteArray>::const_iterator it = m_roleNames.constBegin(); it != m_roleNames.constEnd(); ++it) {
            maxRole = qMax(maxRole, it.key());
        }
        int newRole = maxRole + 1;
        m_roleNames[newRole] = name;

    }


    void updateRolesFromJson(const QJsonArray& jsonArray) {
        if (jsonArray.isEmpty()) {
            m_roleNames.clear();
            return;
        }

        const QJsonObject firstItem = jsonArray.first().toObject();
        m_roleNames.clear();

        int role = Qt::UserRole + 1;
        for (const QString& key : firstItem.keys()) {
            m_roleNames[role] = key.toUtf8();
            ++role;
        }
    }

    Q_INVOKABLE QJsonArray getJsonItems() {
        return jsonItems;
    }



private:
    QJsonArray jsonItems;
    QHash<int, QByteArray> m_roleNames;
};

class JsonListProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

    // Propriedade para o campo de filtro
    Q_PROPERTY(QString filterField READ filterField WRITE setFilterField NOTIFY filterFieldChanged)

    // Propriedade para o valor de filtro
    Q_PROPERTY(QString filterValue READ filterValue WRITE setFilterValue NOTIFY filterValueChanged)

public:
    JsonListProxyModel(QObject* parent = nullptr)
        : QSortFilterProxyModel(parent) {}

    // Getter para a propriedade filterField
    Q_INVOKABLE QString filterField() const { return m_filterField; }

    // Setter para a propriedade filterField
    Q_INVOKABLE void setFilterField(const QString& field) {
        if (m_filterField != field) {
            m_filterField = field;
            invalidateFilter(); // Reavalia o filtro ao mudar o campo de filtro
            emit filterFieldChanged();
        }
    }

    // Getter para a propriedade filterValue
    Q_INVOKABLE QString filterValue() const { return m_filterValue; }

    // Setter para a propriedade filterValue
    Q_INVOKABLE void setFilterValue(const QString& value) {
        if (m_filterValue != value) {
            m_filterValue = value;
            invalidateFilter(); // Reavalia o filtro ao mudar o valor de filtro
            emit filterValueChanged();
        }
    }
    // Função para mapear o nome do campo (fieldName) para o número do papel (role) apropriado
    int roleFromFieldName(const QString& fieldName) const {

        auto rolesModel = sourceModel()->roleNames();


        for (auto it = rolesModel.constBegin(); it != rolesModel.constEnd(); ++it) {
            if (it.value() == fieldName) {
                return it.key(); // Retorna o número do papel associado ao nome do campo
            }
        }
        return int(); // Substitua com a implementação real
    }

protected:
    // Função que determina se uma linha no modelo de origem atende aos critérios de filtro
    bool filterAcceptsRow(int source_row, const QModelIndex& source_parent) const override {
        if(m_filterField == "Todos") {
            return true; // Sem filtro, todos os itens são aceitos
        }

        if (m_filterField.isEmpty() || m_filterValue.isEmpty()) {
            return true; // Sem filtro, todos os itens são aceitos
        }

        // Obtém o valor do campo especificado pelo filtro
        QModelIndex sourceIndex = sourceModel()->index(source_row, 0, source_parent);
        QVariant value = sourceIndex.data(roleFromFieldName(m_filterField));

        if (value.isValid() && value.toString() == m_filterValue)
            return true; // A linha atende aos critérios de filtro

        return false; // A linha não atende aos critérios de filtro
    };

signals:
    // Sinal emitido quando a propriedade filterField é alterada
    void filterFieldChanged();

    // Sinal emitido quando a propriedade filterValue é alterada
    void filterValueChanged();

private:
    QString m_filterField; // Armazena o campo de filtro
    QString m_filterValue; // Armazena o valor de filtro
};


class CustomResult : public QObject
{
    Q_OBJECT
public:
    explicit CustomResult(bool success = false, QVariant data = QVariant(), QString message = QString(), QObject *parent = nullptr)
        : QObject{parent}, m_success(success), m_data(data), m_message(message) {}

    Q_INVOKABLE bool success() {
        return m_success;
    }

    void setSucess(bool success) {

    }

    Q_INVOKABLE QVariant data() {
        return m_data;
    }

    Q_INVOKABLE QString message() {
        return m_message;
    }

private:
    bool m_success;
    QVariant m_data;
    QString m_message;
};




#endif // TIPOS_H
