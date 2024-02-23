/// 负责提供编辑器控制函数

#ifndef EDITOROBJECT_H
#define EDITOROBJECT_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QEvent>

#include "editorbase.h"

class EditorObject : public QWidget
{
private:
    EditorBase *editor;
    QString *data;
    QString *path;
    QFile *file;
    QTextStream *stream;

    inline void resetNumberMargin();

protected:
    /// 重写按下键盘事件
    void keyPressEvent(QKeyEvent *event);
    /// 重写释放键盘事件
    void keyReleaseEvent(QKeyEvent *event);

public:
    EditorObject(QString path, long long id);
    EditorObject();

    void save();
    void getData();
    EditorBase* getEditor();

    inline void setEditor();
    inline void setEditor(EditorSetting setting);

    ~EditorObject();
};

#endif