#ifndef ESTOQUE_H
#define ESTOQUE_H
#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>

#include "produto.h"

class Estoque : public QObject
{
    Q_OBJECT
private:
    QVector<Produto> estoque;
public:
    explicit Estoque(QObject *parent = nullptr);
    void inserirProduto(const Produto a);
    float mediaDoEstoque();
    float maiorPreco();
    float menorPreco();

    void ordenarPorNome();
    void ordenarPorCompra();
    void ordenarPorVenda();

    int size();
    void clear();

    Produto operator[](int i);


signals:

public slots:
};
#endif // ESTOQUE_H
