#ifndef GERENCIADORDEARQUIVOS_H
#define GERENCIADORDEARQUIVOS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>


#include "estoque.h"
#include "produto.h"


class GerenciadorDeArquivos
{
public:
    GerenciadorDeArquivos();
    static bool salvarProdutos(QString &arquivo, Estoque &estoque);
    static bool carregarProdutos(QString &arquivo, Estoque &estoque);
};

#endif // GERENCIADORDEARQUIVOS_H

