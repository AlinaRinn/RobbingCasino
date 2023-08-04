#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRandomGenerator>
#include "dialog.h"
#include <QMessageBox>
#define PROGRESS_MAX 146

int progress = 0, received = 0;


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setWindowIcon(QIcon(":/icon-casino-game.png"));
    //setWindowTitle("Взлом Казино");
    //setWindowFlags(Qt::SplashScreen | Qt::WindowStaysOnTopHint);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    setWindowFlags(windowFlags() & ~Qt::WindowMinimizeButtonHint);
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
    ui->totalLabel->setText(QString::number(QRandomGenerator::global()->bounded(100000000)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    progress++;
    received += QRandomGenerator::global()->bounded(1000000);
    ui->progressBar->setValue(progress);
    ui->progressBar->update();
    ui->progressLabel->setText(QString::number(progress) + "%");
    ui->receivedLabel->setText(QString::number(received));
    _sleep(700);
    if(progress % 14 == 0){
        QMessageBox::information(this, "Внимание!", "Вы уверены?");
        QMessageBox::about(this, "Внимание!", "Вы уверены?");
        QMessageBox::question(this, "Внимание!", "Вы уверены?");
        QMessageBox::warning(this, "Внимание!", "Вы уверены?");
        QMessageBox::critical(this, "Внимание!", "Вы уверены?");
        Dialog k;
        k.setModal(true);
        k.exec();
    }
}

void MainWindow::on_NoRobButton_clicked()
{
    progress--;
    received -= QRandomGenerator::global()->bounded(1000000);
    ui->progressBar->setValue(progress);
    ui->progressLabel->setText(QString::number(progress) + "%");
    ui->receivedLabel->setText(QString::number(received));
}
