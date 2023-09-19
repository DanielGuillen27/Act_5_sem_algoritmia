#include "mainwindow.h"
#include "./ui_mainwindow.h"

bool ok;
QString fileName;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString fileName;
}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Seleccione un archivo"), "C:\\Users\\Daniel\\Downloads", tr("Text File (*.txt)"));

    QMessageBox T;

    T.setText(fileName);

    T.exec();

}
void MainWindow::on_txtId_textChanged(const QString &arg1)
{

}
void MainWindow::vaciar(){
    ui->txtId->setText("");
    ui->txtVoltaje->setText("");
    ui->txtPosX->setText("");
    ui->txtPosY->setText("");
    ui->txtRed->setText("");
    ui->txtGreen->setText("");
    ui->txtBlue->setText("");
}

void MainWindow::on_btnGuardar_clicked()
{

    //primero obtenemos los datos de cada caja de texto
    id=ui->txtId->text();
    voltaje=ui->txtVoltaje->text();
    posX = ui->txtPosX->text();
    posY =ui->txtPosY->text();
    red = ui->txtRed->text();
    green = ui->txtGreen->text();
    blue = ui->txtBlue->text();
    //en el objeto que tenemos lo agregamos los datos a cada atributo del objeto
    n.setId(id.toInt(&ok));
    n.setVoltaje(voltaje.toFloat(&ok));
    n.setPosicionX(posX.toInt(&ok));
    n.setPosicionY(posY.toInt(&ok));
    n.setBlue(blue.toInt(&ok));
    n.setGreen(green.toInt(&ok));
    n.setRed(red.toInt(&ok));

    //creamos una neurona y agregamos datos, despues lo metemos en la lista

    lista.insertData(lista.getFirstPos(),n); // se inserta al principio

    vaciar();
}

void MainWindow::on_btnMostrar_clicked()
{

    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText(lista.toString());
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}


void MainWindow::on_txtRed_textChanged(const QString &arg1)
{

}


void MainWindow::on_txtBlue_textChanged(const QString &arg1)
{

}


void MainWindow::on_btnGuardarFinal_clicked()
{
    //primero obtenemos los datos de cada caja de texto
    id=ui->txtId->text();
    voltaje=ui->txtVoltaje->text();
    posX = ui->txtPosX->text();
    posY =ui->txtPosY->text();
    red = ui->txtRed->text();
    green = ui->txtGreen->text();
    blue = ui->txtBlue->text();
    //en el objeto que tenemos lo agregamos los datos a cada atributo del objeto
    n.setId(id.toInt(&ok));
    n.setVoltaje(voltaje.toFloat(&ok));
    n.setPosicionX(posX.toInt(&ok));
    n.setPosicionY(posY.toInt(&ok));
    n.setBlue(blue.toInt(&ok));
    n.setGreen(green.toInt(&ok));
    n.setRed(red.toInt(&ok));
    //creamos una neurona y agregamos datos, despues lo metemos en la lista

    lista.insertData(lista.getLastPos(),n); // se inserta al final
    vaciar();
}

void MainWindow::on_actionguardar_triggered()
{
    //aqui vamos a guardar en el archivo
}


void MainWindow::on_pushButton_clicked()
{
     fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Seleccione un archivo"), "C:\\Users\\usuario\\Downloads", tr("Text File (*.txt)"));

    QMessageBox T;

    T.setText(fileName);



    T.exec();
}


void MainWindow::on_btnLeer_clicked()
{
     lista.leer(fileName);
}


void MainWindow::on_btnEscribir_clicked()
{
    lista.escribir(fileName);
}


void MainWindow::on_btnUbicacion_clicked()
{

    fileName = QFileDialog::getOpenFileName(this,
                                            tr("Seleccione un archivo"), "C:\\Users\\usuario\\Downloads", tr("Text File (*.txt)"));

    QMessageBox T;

    T.setText(fileName);

    T.exec();

}


void MainWindow::on_txtUbicacion_textChanged(const QString &arg1)
{



}

