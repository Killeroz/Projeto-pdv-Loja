#ifndef PRODUTO_H
#define PRODUTO_H


#include <QObject>

#define MARKUP 100

class Produto
{

private:
    QString nome;
    float preco;
    float venda;
    float taxa;

public:
    explicit Produto();
    Produto(QString n, float p, float t, float v);

    QString getNome() const;
    void setNome(const QString &value);

    float getPreco() const;
    void setPreco(float value);

    float getVenda() const;
    void setVenda ();

    float getTaxa () const;
    void setTaxa (float value);

signals:

public slots:
};

#endif // PRODUTO_H
