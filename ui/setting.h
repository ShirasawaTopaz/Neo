#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QString>
#include <QDebug>
#include <map>

#include "settingwidget/settingeditorbase.h"

namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

private slots:
    void getItem(QTreeWidgetItem *,int);

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();

private:
    Ui::Setting *ui;

    int *temp;

    // QTreeWidget Map
    enum SettingMapEnum{
        SETTING_EDITOR_BASE = 0,
        SETTING_EDITOR_COMPLETE = 1,
    };
    std::map<QString,int> SettingMap = {
        {"Base",SettingMapEnum::SETTING_EDITOR_BASE},

    };

    void callEditorBase();
};

#endif // SETTING_H
