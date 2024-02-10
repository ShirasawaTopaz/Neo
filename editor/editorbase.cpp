#include "editorbase.h"

EditorBase::EditorBase(QString title, long long id)
{
    // TODO: connect行修改的行为和发送行号变化行为的信号
    //connect(this, SIGNAL(modify_attempt()), this, SLOT(AutoChangeMarginWidth()));
}

void EditorBase::AutoChangeMarginWidth()
{
    sptr_t temp = send(SCI_GETLINECOUNT);
    if (temp != *line_count)
    {
        *line_count = temp;
        emit linesChanged();
    }
}

bool EditorBase::Neo_highlight()
{
    return false;
}

EditorBase::~EditorBase()
{
}