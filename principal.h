#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QPainter>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();    

private slots:
    void on_cmdGraficar_clicked();

    void on_inNota1_valueChanged(const QString &arg1);
    void on_inNota2_valueChanged(const QString &arg1);
    void on_inNota3_valueChanged(const QString &arg1);

    void on_action_Guardar_triggered();

    void on_action_Salir_triggered();

private:
    Ui::Principal *ui;
    QPixmap lienzo;
    void dibujar();
};
#endif // PRINCIPAL_H
