/// 负责提供编辑器控制函数

#ifndef EDITOROBJECT_H
#define EDITOROBJECT_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QEvent>
#include <QKeyEvent>

#include "editorbase.h"

class EditorObject : public QWidget
{
    Q_OBJECT
private:
    EditorBase *editor;
    QString *data;
    QString *path;
    QFile *file;
    QTextStream *stream;

private slots:
    inline void resetNumberMargin();

public:
    EditorObject(QString path, long long id);
    EditorObject();

    void save();
    void getData();
    EditorBase* getEditor();

    void setEditor();
    void setEditor(EditorSetting setting);

    ~EditorObject();
};

#endif
