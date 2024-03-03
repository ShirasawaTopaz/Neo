#include "editormanager.h"

EditorManager::EditorManager(){
    //init
    editorVector.push_back(new EditorObject());
}

EditorObject* EditorManager::getEditor(long long index){
    return editorVector[index];
}

void EditorManager::newEditor(){
    editorVector.push_back(new EditorObject());
}

EditorManager::~EditorManager(){
    for (long long i = 0; i < editorVector.size(); i++)
    {
        free(editorVector[i]);
    }
}
