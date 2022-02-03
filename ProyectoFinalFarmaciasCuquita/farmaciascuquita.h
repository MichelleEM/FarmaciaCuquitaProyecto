#ifndef FARMACIASCUQUITA_H
#define FARMACIASCUQUITA_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class FarmaciasCuquita; }
QT_END_NAMESPACE

class QSqlTableModel;

class FarmaciasCuquita : public QMainWindow
{
    Q_OBJECT

public:
    FarmaciasCuquita(QWidget *parent = nullptr);
    ~FarmaciasCuquita();
private slots:

    void on_conectarBDPB_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_insertarClientesPB_clicked();

    void on_mostrarClientesPB_clicked();

    void on_mostrarSucursalesPB_clicked();

    void on_mostrarVentasPB_clicked();

    void on_mostrarProveedorPB_clicked();

    void on_mostrarProductoPB_clicked();

    void on_mostrarPersonalPB_2_clicked();

    void on_mostrarConsultorioPB_clicked();

    void on_mostrarClientesAntiguosPB_clicked();

    void on_mostrarProductosAntiguosPB_clicked();

    void on_insertarSucursalesPB_clicked();

    void on_eliminarSucursalesPB_clicked();

    void on_modificarSucursalesPB_clicked();

    void on_insertarVentasPB_clicked();

    void on_modificarVentasPB_clicked();

    void on_eliminarVentasPB_clicked();

    void on_insertarProveedorPB_clicked();

    void on_modificarProveedorPB_clicked();

    void on_eliminarProveedorPB_clicked();

    void on_insertarProductoPB_clicked();

    void on_modificarProductoPB_clicked();

    void on_eliminarProductoPB_clicked();

    void on_insertarPersonalPB_2_clicked();

    void on_edadActualizarPB_clicked();

    void on_modificarPersonalPB_2_clicked();

    void on_eliminarPersonalPB_clicked();

    void on_insertarConsultorioPB_clicked();

    void on_modificarConsultorioPB_clicked();

    void on_eliminarConsultorioPB_clicked();

    void on_modificarClientesPB_clicked();

    void on_eliminarClientesPB_clicked();

    void on_calcularTotalVPB_clicked();

    void on_calcularEdadPB_clicked();

    void on_productoCompraPB_clicked();

private:
    Ui::FarmaciasCuquita *ui;
    QSqlTableModel *mModel;
};
#endif // FARMACIASCUQUITA_H
