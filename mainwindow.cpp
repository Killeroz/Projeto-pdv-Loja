#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::atualizarEstatisticas()
{
    ui->lbl_mdia->setText(QString::number(loja.mediaDoEstoque(),'f',2));
    ui->lbl_maior->setText(QString::number(loja.maiorPreco(),'f',2));
    ui->lbl_menor->setText(QString::number(loja.menorPreco(),'f',2));

    QString color = loja.mediaDoEstoque() < 1000 ? "red" : "black";
    ui->lbl_mdia->setStyleSheet("color: "+color);

}

void MainWindow::inserirProdutoNaTabela(Produto produto, int row)
{

    ui->tbl_data->setItem(row,0,new QTableWidgetItem(produto.getNome()));
    ui->tbl_data->setItem(row,1,new QTableWidgetItem(QString::number(produto.getPreco())));
    ui->tbl_data->setItem(row,2,new QTableWidgetItem(QString::number(produto.getTaxa())));
    ui->tbl_data->setItem(row,3,new QTableWidgetItem(QString::number(produto.getVenda(),'f',2)));
}


void MainWindow::on_btn_inseri_clicked()
{

    if(ui->le_produto->text().size() !=0 && ui->le_preco->text().size()!=0){
        Produto produto;

        produto.setNome(ui->le_produto->text());
        produto.setPreco(ui->le_preco->text().toFloat());
        produto.setTaxa(ui->ln_mgl->text().toFloat());
        produto.setVenda();

        int qnt_row = ui->tbl_data->rowCount();
        ui->tbl_data->insertRow(qnt_row);

        inserirProdutoNaTabela(produto, qnt_row);

        ui->le_produto->clear();
        ui->le_preco->clear();
        ui->ln_mgl->clear();

        loja.inserirProduto(produto);
        atualizarEstatisticas();

     }
}


void MainWindow::on_btn_nome_clicked()
{
    ui->tbl_data->clearContents();

        loja.ordenarPorNome();
        for(int i = 0; i<loja.size(); i++){
            inserirProdutoNaTabela(loja[i], i);
        }
}


void MainWindow::on_btn_compra_clicked()
{
    ui->tbl_data->clearContents();
    loja.ordenarPorCompra();
    for(int i = 0; i<loja.size();i++){
        inserirProdutoNaTabela(loja[i],i);
    }
}

void MainWindow::on_btn_venda_clicked()
{
    ui->tbl_data->clearContents();
    loja.ordenarPorVenda();
    for(int i =0; i<loja.size(); i++){
        inserirProdutoNaTabela(loja[i], i);
    }
}



void MainWindow::on_actionSalva_triggered()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Lista de Produtos","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
        if( GerenciadorDeArquivos::salvarProdutos(nomeArquivo,loja) ){
            QMessageBox::information(this, "Salvar Produtos","Dados Salvos com Sucesso");
        }else{
            QMessageBox::information(this, "Salvar Produtos","Não foi possível salvar os dados");
        }
}

void MainWindow::on_actionCarregar_triggered()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Lista de Produtos","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");

       loja.clear();

       if(GerenciadorDeArquivos::carregarProdutos(nomeArquivo,loja)){

           ui->tbl_data->clearContents();
           for(int i=0;i<loja.size();i++){

               if(i >= ui->tbl_data->rowCount())
                   ui->tbl_data->insertRow(i);

               inserirProdutoNaTabela(loja[i],i);
           }

       }else{
           QMessageBox::information(this, "Carregar produtos","Não foi possível carregar os dados");
       }
}





