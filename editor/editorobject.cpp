#include "editorobject.h"

EditorObject::EditorObject(QString path, long long id)
{
    this->path = &path;
    this->file = new QFile(path);
    if (!file->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate))
    {
        // TODO:处理无法打开文件的错误
        return;
    }
    stream = new QTextStream(file);
    // 自动检测Unicode
    stream->setAutoDetectUnicode(true);
    *data = stream->readAll();
    editor = new EditorBase(path, id);

    // 默认设置
    setEditor();
}
EditorObject::EditorObject()
{

    editor = new EditorBase("untitled", 0);
    // 默认设置
    setEditor();
}

void EditorObject::save()
{
    file->write(data->toUtf8());
}

void EditorObject::getData()
{
}

EditorBase *EditorObject::getEditor()
{
    return editor;
}

/// 默认设置
void EditorObject::setEditor()
{
    QFont font("FiraCode", 14, QFont::Normal);

    editor->setMarginTypeN(1, SC_MARGIN_NUMBER);
    editor->setMarginTypeN(0, SC_MARGIN_SYMBOL);

    // 设置行号栏大小
    editor->setMarginWidthN(1, editor->textWidth(SC_MARGIN_NUMBER, (QString::number(editor->getTotalLine()) + "00000").toUtf8().constData()));
    editor->setMarginWidthN(0, editor->textWidth(SC_MARGIN_SYMBOL, "0"));
}

void EditorObject::resetNumberMargin()
{
    // 设置行号栏大小
    editor->setMarginWidthN(1, editor->textWidth(SC_MARGIN_NUMBER, (QString::number(editor->getTotalLine()) + "00000").toUtf8().constData()));
}

void EditorObject::keyPressEvent(QKeyEvent *event)
{
    editor->setMarginWidthN(1, editor->textWidth(SC_MARGIN_NUMBER, (QString::number(editor->getTotalLine()) + "00000").toUtf8().constData()));
    switch (event->key())
    {
    case Qt::Key_Enter || Qt::Key_Return:
        resetNumberMargin();
        break;
    default:
        break;
    }
}

void EditorObject::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Enter || Qt::Key_Return:
        resetNumberMargin();
        break;
    default:
        break;
    }
}

EditorObject::~EditorObject() {}