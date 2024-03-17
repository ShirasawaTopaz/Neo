#ifndef SETTINGEDITORBASE_H
#define SETTINGEDITORBASE_H

#include <QWidget>

namespace Ui {
class SettingEditorBase;
}

class SettingEditorBase : public QWidget
{
    Q_OBJECT

public:
    explicit SettingEditorBase(QWidget *parent = nullptr);
    ~SettingEditorBase();

private:
    Ui::SettingEditorBase *ui;
};

#endif // SETTINGEDITORBASE_H
