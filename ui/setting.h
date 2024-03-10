#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QString>
#include <QDebug>
#include <map>

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

    // QTreeWidget Map
    std::map<QString,std::function<void()>> SettingMap = {
        {"Base",[](){qDebug()<<"Success";}},
        {"Complete",[](){}},
        {"Font",[](){}},
        {"Clangd",[](){}},
        {"Complete",[](){}},
        {"Rust Analyzer",[](){}},
        {"Valgrind",[](){}},
        {"Installed",[](){}},
        {"Install Plugin",[](){}},
        {"Plugin Setting",[](){}},
    };
};

#endif // SETTING_H
