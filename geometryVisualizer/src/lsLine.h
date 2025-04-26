#pragma once
#include "lsEntity.h"

class lsLine : public lsEntity
{
public:
    lsLine();
    lsLine(const lsPoint& s, const lsPoint& e);
    lsLine(const lsLine& other);
    ~lsLine() = default;
    
// 实现接口
public:
    void draw(IRenderContext& renderer, bool isSelected) const override;
    bool hit_test(const lsPoint& p) const override;

private:
    lsPoint s;
    lsPoint e;
};