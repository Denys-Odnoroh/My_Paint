#include "ObjectChangeHistory.h"

ObjectChangeHistory::ObjectChangeHistory(bool isCreatedFlag, std::vector<BaseEntity *> changedObject, std::vector<QPointF> originalPoints, std::vector<QPointF> newPoints)
{
    m_changeHistoryArray = changedObject;
    m_isCreated = isCreatedFlag;
    m_originalPoints = originalPoints;
    m_newPoints = newPoints;
}

ObjectChangeHistory::ObjectChangeHistory(bool isCreatedFlag, std::vector<BaseEntity *> changedObject, std::vector<QPointF> originalPoints)
{
    m_changeHistoryArray = changedObject;
    m_isCreated = isCreatedFlag;
    m_originalPoints = originalPoints;
}

ObjectChangeHistory::ObjectChangeHistory()
{

}
