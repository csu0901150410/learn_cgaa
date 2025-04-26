#pragma once
#include <string>

#include "lsCommon.h"
#include "lsPoint.h"

class lsEntity
{
public:
    lsEntity();
    virtual ~lsEntity() = default;

    virtual void init_id();
    lsObjectId get_id() const;

    virtual void draw(class IRenderContext& renderer, bool isSelected) const = 0;
    virtual bool hit_test(const lsPoint& p) const = 0;

protected:
    lsObjectId id = 0;
};
