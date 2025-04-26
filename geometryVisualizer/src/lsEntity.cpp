#include "lsEntity.h"

lsEntity::lsEntity()
{
    init_id();
}

void lsEntity::init_id()
{
    static lsObjectId idCounter = 0;
    id = idCounter++;
}

lsObjectId lsEntity::get_id() const
{
    return id;
}

bool lsEntity::is_selected() const
{
    return bSelected;
}

void lsEntity::set_selected(bool selected)
{
    bSelected = selected;
}
