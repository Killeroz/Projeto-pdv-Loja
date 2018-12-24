#include "estoque.h"

Estoque::Estoque(QObject *parent) : QObject(parent)
{

}

void Estoque::inserirProduto(const Produto a)
{
    estoque.push_back(a);
}

float Estoque::mediaDoEstoque()
{
    return std::accumulate(estoque.begin(),estoque.end(),0.0, [](float acc, Produto a){return acc+=a.getPreco();})/estoque.size();
}

float Estoque::maiorPreco()
{
    Produto *maior = std::max_element(estoque.begin(),estoque.end(),[](Produto a, Produto b){ return a.getPreco() < b.getPreco();});
    return maior->getPreco();
}

float Estoque::menorPreco()
{
    Produto *menor = std::min_element(estoque.begin(),estoque.end(),[](Produto a, Produto b){return a.getPreco() < b.getPreco();});
    return menor->getPreco();
}

void Estoque::ordenarPorNome()
{
    std::sort(estoque.begin(), estoque.end(), [](Produto a, Produto b){return a.getNome()<b.getNome();});
}

void Estoque::ordenarPorCompra()
{
    ordenarPorNome();
    std::stable_sort(estoque.begin(),estoque.end(),[](Produto a, Produto b){return a.getPreco()<b.getPreco();});
}

void Estoque::ordenarPorVenda()
{
    //ordenarPorNome();
    ordenarPorCompra();
    std::stable_sort(estoque.begin(),estoque.end(),[](Produto a, Produto b){return a.getVenda()<b.getVenda();});
}

int Estoque::size()
{
    return estoque.size();
}

void Estoque::clear()
{
   estoque.clear();
}
Produto Estoque::operator[](int i)
{
    return estoque[i];
}
