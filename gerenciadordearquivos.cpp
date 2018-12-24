#include "gerenciadordearquivos.h"

GerenciadorDeArquivos::GerenciadorDeArquivos()
{

}

bool GerenciadorDeArquivos::salvarProdutos(QString &arquivo, Estoque &estoque)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QTextStream out(&file);

    for(int i=0;i<estoque.size();i++){
        out << estoque[i].getNome()<<","<<estoque[i].getPreco()<<","<<estoque[i].getTaxa()<<","<<estoque[i].getVenda()<<"\n";
    }

    file.close();
    return true;
}

bool GerenciadorDeArquivos::carregarProdutos(QString &arquivo, Estoque &estoque)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QTextStream in(&file);

    QString linha;

    while(!in.atEnd()){
        linha = in.readLine();

        QStringList dados = linha.split(",");

        Produto a(dados[0],dados[1].toFloat(),dados[2].toFloat(),dados[3].toFloat());
        estoque.inserirProduto(a);

    }
    return true;
}
