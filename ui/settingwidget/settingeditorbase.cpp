#include "settingeditorbase.h"
#include "ui_settingeditorbase.h"

SettingEditorBase::SettingEditorBase(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SettingEditorBase)
{
    ui->setupUi(this);
}

SettingEditorBase::~SettingEditorBase()
{
    delete ui;
}
