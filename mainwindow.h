#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>

#include "gerenciadordearquivos.h"
#include "produto.h"
#include "estoque.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Estoque loja;
    Produto *produto;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void atualizarEstatisticas();

private slots:

    void on_btn_inseri_clicked();

    void on_btn_nome_clicked();

    void on_btn_compra_clicked();

    void on_btn_venda_clicked();



    void on_actionSalva_triggered();

    void on_actionCarregar_triggered();


private:
    Ui::MainWindow *ui;
     void inserirProdutoNaTabela(Produto produto, int row);
};

#endif // MAINWINDOW_H
