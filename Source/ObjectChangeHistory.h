#ifndef OBJECTCHANGEHISTORY_H
#define OBJECTCHANGEHISTORY_H

#include <map>
#include "Entityes.h"

typedef std::map<int, BaseEntity*> ChangeHistoryMap;

class ObjectChangeHistory
{
private:
    ChangeHistoryMap changeHistoryMap;
    int changeHistoryIndex = 0;

public:
    ObjectChangeHistory();
    int getChangeHistoryIndex() { return changeHistoryIndex; } ;
    void setChangeHistoryIndex(int index) { changeHistoryIndex += index; };
    ChangeHistoryMap getChangeHistoryMap() { return changeHistoryMap; };
};

#endif // OBJECTCHANGEHISTORY_H
