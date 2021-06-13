#ifndef CSMAP_H
#define CSMAP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CsMap; }
QT_END_NAMESPACE

class CsMap : public QMainWindow
{
    Q_OBJECT

public:
    CsMap(QWidget *parent = nullptr);
    ~CsMap();

private slots:
    void exit();
    void save();
    void load();

private:
    Ui::CsMap *ui;
};
#endif // CSMAP_H
