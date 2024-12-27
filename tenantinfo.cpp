#include "tenantinfo.h"
#include "ui_tenantinfo.h"
#include <QString>
#include <QMessageBox>
#include "mainwindow.h"
#include <QSqlQueryModel>

TenantInfo::TenantInfo(QWidget *parent, QString id) :
    QWidget(parent),
    ui(new Ui::TenantInfo)
{
    ui->setupUi(this);

    if(!empDBUtils.connectToDB("payrolldb"))
    {
        QMessageBox::critical(this, "Error", "Failed to open the Tenant database, Check wheather your server is running or not.");
    }

    ui->label_7->setText("<html><head/><body><p align='center'>" + id + "</p></body></html>");

    QSqlQuery* info = new QSqlQuery();
    info = empDBUtils.getData(id);

    // Personal Info
    ui->showEmpName->setText(info->value(2).toString());
    ui->showEmpDOB->setText(info->value(3).toString());
    ui->showEmpFather->setText(info->value(5).toString());
    ui->showEmpEmail->setText(info->value(6).toString());
    ui->showEmpPhone->setText(info->value(7).toString());
    ui->showEmpAddress->setText(info->value(8).toString());

    // Room Designated Info
    ui->dept->setText(info->value(9).toString());
    ui->design->setText(info->value(10).toString());
    ui->doj->setText(info->value(11).toString());
    ui->salary->setText(info->value(12).toString());
    ui->type->setText(info->value(13).toString());


}

TenantInfo::~TenantInfo()
{
    delete ui;
}

void TenantInfo::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        isMouseDown = true;
        mousePoint = event->globalPos();
    }
}

void TenantInfo::mouseReleaseEvent(QMouseEvent *event)
{
    isMouseDown = false;
}

void TenantInfo::mouseMoveEvent(QMouseEvent *event)
{
    const QPoint delta = event->globalPos() - mousePoint;
    if(isMouseDown == true)
        move(x() + delta.x(), y() + delta.y());
    else
        move(x()+delta.x(), y()+delta.y());
        mousePoint = event->globalPos();
}

void TenantInfo::on_pushButton_clicked()
{
    empDBUtils.closeDBConnection();
    this->close();

    MainWindow* mainWin = new MainWindow();
    mainWin->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mainWin->show();
}
