#include "produto.h"

QString Produto::getNome() const
{
    return nome;
}

void Produto::setNome(const QString &value)
{
    nome = value.toLower();
    nome[0]=nome[0].toUpper();
}

float Produto::getPreco() const
{
    return preco;
}

void Produto::setPreco(float value)
{
    preco = value;
}
float Produto::getTaxa() const
{
    return taxa;
}
void Produto::setTaxa(float value)
{
    taxa = value;
}
float Produto::getVenda() const
{
    return venda;
}
void Produto::setVenda()
{
     venda = ((preco * MARKUP)/(MARKUP - taxa));
}

Produto::Produto()
{

}

Produto::Produto(QString n, float p, float t, float v)
{
    nome = n;
    preco = p;
    taxa = t;
    venda = v;
}
