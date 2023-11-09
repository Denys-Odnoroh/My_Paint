#ifndef OBJECTCHANGEHISTORY_H
#define OBJECTCHANGEHISTORY_H

#include <vector>
#include "Entityes.h"

typedef std::vector<BaseEntity*> ChangeHistoryArray;

class ObjectChangeHistory
{
private:
    ChangeHistoryArray m_changeHistoryArray;
    std::vector<QPointF> m_originalPoints;
    std::vector<QPointF> m_newPoints;
    bool m_isCreated;

public:
    ObjectChangeHistory(bool isCreatedFlag, std::vector<BaseEntity*> changedObject, std::vector<QPointF> originalPoints, std::vector<QPointF> newPoints);
    ObjectChangeHistory(bool isCreatedFlag, std::vector<BaseEntity*> changedObject, std::vector<QPointF> originalPoints);
    ObjectChangeHistory();
    ChangeHistoryArray getChangeHistoryArray() { return m_changeHistoryArray; };
    std::vector<QPointF> getOriginalPoints() { return m_originalPoints; };
    std::vector<QPointF> getNewPoints() { return m_newPoints; };
    bool getIsCreatedFlag() { return m_isCreated; };
    void setIsCreatedFlag(bool flag) { m_isCreated = flag; };
};

#endif // OBJECTCHANGEHISTORY_H
