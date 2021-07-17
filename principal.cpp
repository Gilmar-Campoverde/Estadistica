#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    //Crear lienzo
    lienzo = QPixmap(500,500);  //qpizmap Permite crear una imagen fuera de pantalla  y es valido pentar dentro de ella
    //Invocar al metodo dibujar
    this->dibujar();
}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar(){
    //Rellenar el lienzo
    lienzo.fill(Qt::white);

    //Crear el pintor
    QPainter painter(&lienzo);            //Le manda como referencia el objeto lienzo
    int x=50;
    int y=50;
    int ancho = 100;
    int alto_1 = ui->inNota1->value();
    int alto_2 = ui->inNota2->value();
    int alto_3 = ui->inNota3->value();

    //Crear un pincel para el borde
    QPen pin;
    pin.setWidth(5);                    //Es el grosor de la linea
    pin.setColor(Qt::red);
    pin.setJoinStyle(Qt::MiterJoin);

    //Establecer el pincel al pintor
    painter.setPen(pin);

    //Dibujar primera barra
    painter.drawRect(x,y+(400-alto_1), ancho, alto_1);

    //Crear un nuevo color
    QColor colorBorde2(78,3,48);
    QColor colorRelleno2(199,120,162);

    //Establecer el nuevo color al pincel
    pin.setColor(colorBorde2);

    //Volver a establecer el pincel al objeto painter
    painter.setPen(pin);

    //Establecer el color de la brocha del objeto painter
    painter.setBrush(colorRelleno2);

    //Dibujar la segunda barra
    painter.drawRect(x+150, y+(400-alto_2), ancho, alto_2);

    //Creando los colores de la tercera barra
    QColor colorBorde3(174,174,51);
    QColor colorRelleno3(253,253,115);

    pin.setColor(colorBorde3);

    painter.setPen(pin);
    painter.setBrush(colorRelleno3);

    painter.drawRect(x+300, y+(400-alto_3), ancho, alto_3);

    //mostrar el lienzo cuadro
    ui->cuadro->setPixmap(lienzo);
}

void Principal::on_cmdGraficar_clicked(){
    dibujar();
}
void Principal::on_inNota1_valueChanged(const QString &arg1){
    dibujar();
}
void Principal::on_inNota2_valueChanged(const QString &arg1){
    dibujar();
}
void Principal::on_inNota3_valueChanged(const QString &arg1){
    dibujar();
}

void Principal::on_action_Guardar_triggered()
{
    //Crear un objeto QDir a partir del directorio del usuario
    QDir directorio = QDir::home();

    //Agregar al path absoluto del objeto un nombre por defecto del archivo
    QString pathArchivo = directorio.absolutePath();

    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",pathArchivo,"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

void Principal::on_action_Salir_triggered()
{
    this->close();
}
