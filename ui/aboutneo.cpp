#include "aboutneo.h"
#include "ui_aboutneo.h"

AboutNeo::AboutNeo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AboutNeo)
{
    ui->setupUi(this);

    setWindowTitle(tr("About"));
}

AboutNeo::~AboutNeo()
{
    delete ui;
}
