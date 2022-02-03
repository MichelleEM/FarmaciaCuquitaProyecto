#include "farmaciascuquita.h"
#include "ui_farmaciascuquita.h"
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

FarmaciasCuquita::FarmaciasCuquita(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::FarmaciasCuquita)
{
    ui->setupUi(this);

    QStringList list=(QStringList() << "Sucursales" << "Compran" << "Proveedores" << "Productos"
                      << "Personal" << "Consultorio" << "Clientes" << "ClientesAntiguos" << "Productos Antiguos");
    ui->comboBox->addItems(list);
}

FarmaciasCuquita::~FarmaciasCuquita()
{
    delete ui;
}

void FarmaciasCuquita::on_conectarBDPB_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QPSQL");
        mydb.setHostName("127.0.0.1");
        mydb.setDatabaseName("FarmaciaCuquita");
        mydb.setUserName("postgres");
        mydb.setPassword("batman222000");
        bool is_open = mydb.open();

            if(!is_open)
            {
                QMessageBox text;
                text.setText(mydb.lastError().text());
                text.exec();
            }
            else
            {
                QMessageBox text;
                text.setText("Conexión realizada correctamente a la base de datos");
                text.exec();
            }
            mModel = new QSqlTableModel(this);
            mModel->setTable("sucursales");
            mModel->select();
            ui->sucursalesTableView->setModel(mModel);
}

void FarmaciasCuquita::on_comboBox_currentIndexChanged(int index)
{
    switch (index){
            case 0:
                ui->farmaciasCuquitaSW->setCurrentIndex(1);
                break;
            case 1:
                ui->farmaciasCuquitaSW->setCurrentIndex(2);
                break;
            case 2:
                ui->farmaciasCuquitaSW->setCurrentIndex(3);
                break;
            case 3:
                ui->farmaciasCuquitaSW->setCurrentIndex(4);
                break;
            case 4:
                ui->farmaciasCuquitaSW->setCurrentIndex(5);
                break;
            case 5:
                ui->farmaciasCuquitaSW->setCurrentIndex(6);
                break;
            case 6:
                ui->farmaciasCuquitaSW->setCurrentIndex(7);
                break;
            case 7:
                ui->farmaciasCuquitaSW->setCurrentIndex(8);
                break;
            case 8:
                ui->farmaciasCuquitaSW->setCurrentIndex(9);
                break;
                }
}

void FarmaciasCuquita::on_mostrarClientesPB_clicked()
{
    QMessageBox text;
    QSqlQueryModel *table = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT *FROM clientes");

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR EN LA CONSULTA");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("CONSULTA REALIZADA CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
    }

    table->setQuery(*query);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->setModel(table);
}

void FarmaciasCuquita::on_mostrarSucursalesPB_clicked()
{
    QMessageBox text;
    QSqlQueryModel *table = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT *FROM sucursales");

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR EN LA CONSULTA");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("CONSULTA REALIZADA CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
    }

    table->setQuery(*query);
    ui->sucursalesTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->sucursalesTableView->setModel(table);
}

void FarmaciasCuquita::on_mostrarVentasPB_clicked()
{
    QMessageBox text;
    QSqlQueryModel *table = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT *FROM compran");

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR EN LA CONSULTA");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("CONSULTA REALIZADA CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
    }

    table->setQuery(*query);
    ui->ventastableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->ventastableView->setModel(table);
}

void FarmaciasCuquita::on_mostrarProveedorPB_clicked()
{
    QMessageBox text;
    QSqlQueryModel *table = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT *FROM proveedores");

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR EN LA CONSULTA");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("CONSULTA REALIZADA CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
    }

    table->setQuery(*query);
    ui->proveedoresTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->proveedoresTableView->setModel(table);
}

void FarmaciasCuquita::on_mostrarProductoPB_clicked()
{
    QMessageBox text;
    QSqlQueryModel *table = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT *FROM productos");

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR EN LA CONSULTA");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("CONSULTA REALIZADA CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
    }

    table->setQuery(*query);
    ui->productosTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->productosTableView->setModel(table);
}

void FarmaciasCuquita::on_mostrarPersonalPB_2_clicked()
{
    QMessageBox text;
    QSqlQueryModel *table = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT *FROM personal");

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR EN LA CONSULTA");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("CONSULTA REALIZADA CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
    }

    table->setQuery(*query);
    ui->personalTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->personalTableView->setModel(table);
}

void FarmaciasCuquita::on_mostrarConsultorioPB_clicked()
{
    QMessageBox text;
    QSqlQueryModel *table = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT *FROM consultorio");

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR EN LA CONSULTA");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("CONSULTA REALIZADA CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
    }

    table->setQuery(*query);
    ui->consultorioTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->consultorioTableView->setModel(table);
}

void FarmaciasCuquita::on_mostrarClientesAntiguosPB_clicked()
{
    QMessageBox text;
    QSqlQueryModel *table = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT *FROM clienteantiguos");

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR EN LA CONSULTA");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("CONSULTA REALIZADA CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
    }

    table->setQuery(*query);
    ui->ClientesAntiguosTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->ClientesAntiguosTableView->setModel(table);
}

void FarmaciasCuquita::on_mostrarProductosAntiguosPB_clicked()
{
    QMessageBox text;
    QSqlQueryModel *table = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT *FROM productosantiguos");

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR EN LA CONSULTA");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("CONSULTA REALIZADA CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
    }

    table->setQuery(*query);
    ui->ProductosAntiguosTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->ProductosAntiguosTableView->setModel(table);
}

void FarmaciasCuquita::on_insertarSucursalesPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();

    query->prepare("insert into sucursales values (:numerosucursal,:nombre,:telefono,:direccion,:noconsultorio)");
    query->bindValue(":numerosucursal", ui->numerosInsertarLE->text());
    query->bindValue(":nombre", ui->insertarNombreLE->text());
    query->bindValue(":telefono", ui->insertarTelefonoLE->text());
    query->bindValue(":direccion", ui->insertarDLE->text());
    query->bindValue(":noconsultorio", ui->noconsultorioInsertarLE->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->numerosInsertarLE->clear();
        ui->insertarNombreLE->clear();
        ui->insertarTelefonoLE->clear();
        ui->insertarDLE->clear();
        ui->noconsultorioInsertarLE->clear();
    }
}

void FarmaciasCuquita::on_eliminarSucursalesPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("DELETE FROM sucursales WHERE numerosucursal = :deleteNumeroSucursal");
    query->bindValue(":deleteNumeroSucursal", ui->nosucursalEliminarLE->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->nosucursalEliminarLE->clear();
    }
}

void FarmaciasCuquita::on_modificarSucursalesPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("UPDATE sucursales SET nombre = :modificarNombre WHERE nombre = :nombreSucursal");
    query->bindValue(":modificarNombre", ui->nombreNuevoSucursalLE->text());
    query->bindValue(":nombreSucursal", ui->insertarNombreLE_2->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->nombreNuevoSucursalLE->clear();
        ui->insertarNombreLE_2->clear();
    }
}

void FarmaciasCuquita::on_insertarVentasPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();

    query->prepare("insert into compran values (:codigoproductos,:nocliente,:noventa,:fecha,:total)");
    query->bindValue(":codigoproductos", ui->insertarCodigoPVentaLE->text());
    query->bindValue(":nocliente", ui->insertarNumeroClienteVLE->text());
    query->bindValue(":noventa", ui->insertarNumeroVVLE->text());
    query->bindValue(":fecha", ui->insertarFechaVLE->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->insertarCodigoPVentaLE->clear();
        ui->insertarNumeroClienteVLE->clear();
        ui->insertarNumeroVVLE->clear();
        ui->insertarFechaVLE->clear();
    }
}

void FarmaciasCuquita::on_modificarVentasPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("UPDATE compran SET codigoproductos = :modificarCodigoP WHERE codigoproductos = :CodigoP");
    query->bindValue(":modificarCodigoP", ui->insertarNuevoCodigoPCLE2->text());
    query->bindValue(":CodigoP", ui->insertarCodigoPCLEE->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->insertarNuevoCodigoPCLE2->clear();
        ui->insertarCodigoPCLEE->clear();
    }
}

void FarmaciasCuquita::on_eliminarVentasPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("DELETE FROM compran WHERE noventa = :deleteNumeroVenta");
    query->bindValue(":deleteNumeroVenta", ui->noventaEliminarLE->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->noventaEliminarLE->clear();
    }
}

void FarmaciasCuquita::on_insertarProveedorPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();

    query->prepare("insert into proveedores values (:numeroproveedor,:nombreempresa,:direccion,:telefono,:horario)");
    query->bindValue(":numeroproveedor", ui->insertarNumeroProveedorLE->text());
    query->bindValue(":nombreempresa", ui->insertarNombreProveedorLE->text());
    query->bindValue(":direccion", ui->insertarDireccionProveedorLE->text());
    query->bindValue(":telefono", ui->insertarTelefonoProveedorLE->text());
    query->bindValue(":horario", ui->insertarHorarioProveedorLE->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->insertarNumeroProveedorLE->clear();
        ui->insertarNombreProveedorLE->clear();
        ui->insertarDireccionProveedorLE->clear();
        ui->insertarTelefonoProveedorLE->clear();
        ui->insertarHorarioProveedorLE->clear();
    }
}

void FarmaciasCuquita::on_modificarProveedorPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("UPDATE proveedores SET nombreempresa = :modificarNombrePro WHERE nombreempresa = :nombrePro");
    query->bindValue(":modificarNombrePro", ui->insertarNuevoNombreProveedorLE2_2->text());
    query->bindValue(":nombrePro", ui->insertarNombreProveedorLE2->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->insertarNuevoNombreProveedorLE2_2->clear();
        ui->insertarNombreProveedorLE2->clear();
    }

}

void FarmaciasCuquita::on_eliminarProveedorPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("DELETE FROM proveedores WHERE numeroproveedor = :deleteNumeroProveedor");
    query->bindValue(":deleteNumeroProveedor", ui->eliminarNumeroProveedorLE->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->eliminarNumeroProveedorLE->clear();
    }
}

void FarmaciasCuquita::on_insertarProductoPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();

    query->prepare("insert into productos values (:codigop,:nombreproducto,:preciounitario,:precioventa,:cantidadproductos)");
    query->bindValue(":codigop", ui->insertarNumeroProductoLE->text());
    query->bindValue(":nombreproducto", ui->insertarNombreProductoLE->text());
    query->bindValue(":preciounitario", ui->insertarPrecioUProductoLE->text());
    query->bindValue(":precioventa", ui->insertarPrecioVProductoLE->text());
    query->bindValue(":cantidadproductos", ui->insertarCantidadProductoLE->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->insertarNumeroProductoLE->clear();
        ui->insertarNombreProductoLE->clear();
        ui->insertarPrecioUProductoLE->clear();
        ui->insertarPrecioVProductoLE->clear();
        ui->insertarCantidadProductoLE->clear();
    }
}

void FarmaciasCuquita::on_modificarProductoPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("UPDATE productos SET nombreproducto = :modificarNombreProd WHERE nombreproducto = :nombreProd");
    query->bindValue(":modificarNombreProd", ui->insertarNuevoNombreProductoLE->text());
    query->bindValue(":nombreProd", ui->insertarNombreProductoLE2->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->insertarNuevoNombreProductoLE->clear();
        ui->insertarNombreProductoLE2->clear();
    }
}

void FarmaciasCuquita::on_eliminarProductoPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("DELETE FROM productos WHERE codigop = :deleteNumeroProducto");
    query->bindValue(":deleteNumeroProducto", ui->eliminarCodigoProductoLE->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->eliminarCodigoProductoLE->clear();
    }

}

void FarmaciasCuquita::on_insertarPersonalPB_2_clicked()
{
    QSqlQuery *query = new QSqlQuery();

    query->prepare("insert into personal values (:codigoper,:nombre,:puesto,:sexo,:sueldo,:fechanacimiento,:edad,:noconsultorio)");
    query->bindValue(":codigoper", ui->insertarNumeroPersonalLE->text());
    query->bindValue(":nombre", ui->insertarNombrePersonalPLE->text());
    query->bindValue(":puesto", ui->insertarPuestoPersonalPLE->text());
    query->bindValue(":sexo", ui->insertarSexoPersonalPLE->text());
    query->bindValue(":sueldo", ui->insertarSueldoPersonalPLE->text());
    query->bindValue(":fechanacimiento", ui->insertarFechaPersonalPLE->text());
    query->bindValue(":noconsultorio", ui->insertarNoConsultorioPersonalPLE->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->insertarNumeroPersonalLE->clear();
        ui->insertarNombrePersonalPLE->clear();
        ui->insertarPuestoPersonalPLE->clear();
        ui->insertarSexoPersonalPLE->clear();
        ui->insertarSueldoPersonalPLE->clear();
        ui->insertarFechaPersonalPLE->clear();
        ui->insertarNoConsultorioPersonalPLE->clear();
    }
}

void FarmaciasCuquita::on_edadActualizarPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("UPDATE personal SET edad=Extract(YEAR from AGE (CURRENT_DATE, fechanacimiento));");
    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
    }
}

void FarmaciasCuquita::on_modificarPersonalPB_2_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("UPDATE personal SET nombre = :modificarNombrePer WHERE nombre = :nombrePer");
    query->bindValue(":modificarNombrePer", ui->insertarNuevoNombrePersonalPLE->text());
    query->bindValue(":nombrePer", ui->insertarNombrePersonalPLE2->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->insertarNuevoNombrePersonalPLE->clear();
        ui->insertarNombrePersonalPLE2->clear();
    }
}

void FarmaciasCuquita::on_eliminarPersonalPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("DELETE FROM personal WHERE codigoper = :deleteNumeroPersonal");
    query->bindValue(":deleteNumeroPersonal", ui->eliminarCodigoPersonalLE->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->eliminarCodigoPersonalLE->clear();
    }
}

void FarmaciasCuquita::on_insertarConsultorioPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();

    query->prepare("insert into consultorio values (:numeroconsultorio,:nombrepersonal,:horario)");
    query->bindValue(":numeroconsultorio", ui->insertarConsultorioLE->text());
    query->bindValue(":nombrepersonal", ui->insertarnNombrePerConsultorioLE->text());
    query->bindValue(":horario", ui->insertarHorarioConsultorioLE->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->insertarConsultorioLE->clear();
        ui->insertarnNombrePerConsultorioLE->clear();
        ui->insertarHorarioConsultorioLE->clear();
    }
}

void FarmaciasCuquita::on_modificarConsultorioPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("UPDATE consultorio SET nombrepersonal = :modificarNombrePer WHERE nombrepersonal = :nombrePer");
    query->bindValue(":modificarNombrePer", ui->insertarNuevoNombrePersonalConsultorioLE->text());
    query->bindValue(":nombrePer", ui->insertarNombrePerConsultorioLE2->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->insertarNuevoNombrePersonalConsultorioLE->clear();
        ui->insertarNombrePerConsultorioLE2->clear();
    }
}

void FarmaciasCuquita::on_eliminarConsultorioPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("DELETE FROM consultorio WHERE numeroconsultorio = :deleteNumeroConsultorio");
    query->bindValue(":deleteNumeroConsultorio", ui->eliminarConsultorioLE->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->eliminarConsultorioLE->clear();
    }
}

void FarmaciasCuquita::on_insertarClientesPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();

        query->prepare("insert into clientes values (:numerocliente,:nombre,:sexo,:fechacompra,:fechanacimiento,:edad)");
        query->bindValue(":numerocliente", ui->insertarNumeroClienteLE->text());
        query->bindValue(":nombre", ui->insertarNombreClienteLE->text());
        query->bindValue(":sexo", ui->insertarSexoClienteLE->text());
        query->bindValue(":fechacompra", ui->insertarFechaClienteLE->text());
        query->bindValue(":fechanacimiento", ui->insertarFechaNacimientoClienteLE->text());

        if(!query->exec())
        {
            QMessageBox error;
            error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
            error.setText(query->lastError().text());
            error.exec();
        }
        else
        {
            query->exec();
            QMessageBox isValid;
            isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
            isValid.setText(query->executedQuery());
            isValid.exec();
            ui->insertarNumeroClienteLE->clear();
            ui->insertarNombreClienteLE->clear();
            ui->insertarSexoClienteLE->clear();
            ui->insertarFechaClienteLE->clear();
            ui->insertarFechaNacimientoClienteLE->clear();
        }
}

void FarmaciasCuquita::on_modificarClientesPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("UPDATE clientes SET nombre = :modificarNombreCliente WHERE nombre = :nombreCliente");
    query->bindValue(":modificarNombreCliente", ui->modificarNuevoNombreClienteLE->text());
    query->bindValue(":nombreCliente", ui->modificarNombreClienteLE->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->modificarNuevoNombreClienteLE->clear();
        ui->modificarNombreClienteLE->clear();
    }
}

void FarmaciasCuquita::on_eliminarClientesPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("DELETE FROM clientes WHERE numerocliente = :deleteNumeroCliente");
    query->bindValue(":deleteNumeroCliente", ui->eliminarClienteLE->text());

    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
        ui->eliminarClienteLE->clear();
    }
}

void FarmaciasCuquita::on_calcularTotalVPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("UPDATE compran SET total=precioventa FROM productos WHERE codigoproductos = codigop;");
    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
    }
}

void FarmaciasCuquita::on_calcularEdadPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("UPDATE clientes SET edad=Extract(YEAR from AGE (CURRENT_DATE, fechanacimiento));");
    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
    }
}

void FarmaciasCuquita::on_productoCompraPB_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("UPDATE compran SET nombreproductos=nombreproducto FROM productos WHERE codigoproductos = codigop;");
    if(!query->exec())
    {
        QMessageBox error;
        error.setWindowTitle("ERROR AL EJECUTAR EL SCRIPT");
        error.setText(query->lastError().text());
        error.exec();
    }
    else
    {
        query->exec();
        QMessageBox isValid;
        isValid.setWindowTitle("SCRIPT EJECUTADO CORRECTAMENTE");
        isValid.setText(query->executedQuery());
        isValid.exec();
    }
}
