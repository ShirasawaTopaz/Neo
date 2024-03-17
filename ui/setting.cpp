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
    // 测试效果用的代码
    if(ui->stackedWidget->count() != 0){
        ui->stackedWidget->removeWidget(ui->stackedWidget->currentWidget());
    }
    if(finder != SettingMap.end()){
        // 正式版用下面这部分
        /*
        if(ui->stackedWidget->count() != 0){
            ui->stackedWidget->removeWidget(ui->stackedWidget->currentWidget());
        }*/

        switch (finder->second) {
        case SettingMapEnum::SETTING_EDITOR_BASE:
            auto *var = new SettingEditorBase;
            ui->stackedWidget->addWidget(var);
            break;
        }
    }
}

Setting::~Setting()
{
    delete ui;
}
