#ifndef TENANTINFO_H
#define TENANTINFO_H

#include <QWidget>
#include <QString>
#include "tenantbutils.cpp"

namespace Ui
{
    class TenantInfo;
}

class TenantInfo : public QWidget
{
    Q_OBJECT

public:
    explicit TenantInfo(QWidget *parent = 0, QString id = "");
    ~TenantInfo();
    TenantDatabaseUtils empDBUtils;

protected:
   void mousePressEvent(QMouseEvent *event);
   void mouseReleaseEvent(QMouseEvent *event);
   void mouseMoveEvent(QMouseEvent *event);
   QPoint mousePoint;

private slots:
    void on_pushButton_clicked();

private:
    Ui::TenantInfo *ui;
    bool isMouseDown = false;
};

#endif // TENANTINFO_H
