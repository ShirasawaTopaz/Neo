#include "setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Setting)
{
    ui->setupUi(this);

    setWindowTitle(tr("Setting"));

    connect(this->ui->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(getItem(QTreeWidgetItem*,int)));
}

void Setting::getItem(QTreeWidgetItem *_item,int _int){
    qDebug()<<_item->text(0)<<Qt::endl;

    auto finder = SettingMap.find(_item->text(0));
    if (finder != SettingMap.end()) {
        finder->second();
    } else {
        qDebug()<<"SettingMap.end()"<<Qt::endl;
    }
}

Setting::~Setting()
{
    delete ui;
}
