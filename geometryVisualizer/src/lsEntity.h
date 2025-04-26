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

    bool is_selected() const;

    virtual void draw(class IRenderContext& renderer) const = 0;
    virtual bool hit_test(const lsPoint& p) const = 0;

protected:
    // 图元状态由友元lsDocument访问，由doc统一管理选择集状态
    void set_selected(bool selected);

protected:
    lsObjectId id = 0;
    bool bSelected = false;

private:
    friend class lsDocument;
};
