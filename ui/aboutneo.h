#ifndef ABOUTNEO_H
#define ABOUTNEO_H

#include <QWidget>

namespace Ui {
class AboutNeo;
}

class AboutNeo : public QWidget
{
    Q_OBJECT

public:
    explicit AboutNeo(QWidget *parent = nullptr);
    ~AboutNeo();

private:
    Ui::AboutNeo *ui;
};

#endif // ABOUTNEO_H
