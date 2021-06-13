#include "csmap.h"
#include "ui_csmap.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QPainter>

CsMap::CsMap(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CsMap)
{
    ui->setupUi(this);
    connect(ui->actionQuit, &QAction::triggered, this, &CsMap::exit);
    connect(ui->actionOpen, &QAction::triggered, this, &CsMap::load);
    connect(ui->actionSave, &QAction::triggered, this, &CsMap::save);
}

void CsMap::exit()
{
    QCoreApplication::quit();
}

void CsMap::load()
{
    QFileDialog dlg(this, tr("Open Report"), QDir::currentPath(), "*.cr");
    dlg.setAcceptMode(QFileDialog::AcceptOpen);
    dlg.setFileMode(QFileDialog::ExistingFile);
    if (dlg.exec()) {
        QStringList filenames = dlg.selectedFiles();
        if (!filenames.empty()) {
            QString filename = filenames.first();
            QMessageBox box(this);
            box.setText(QString("Loading %1").arg(filename));
            box.exec();
            ui->actionSave->setEnabled(true);
        }
    }
}

void CsMap::save()
{
    QMessageBox box(this);
    box.setText("Not implemented");
    box.exec();
}

CsMap::~CsMap()
{
    delete ui;
}

