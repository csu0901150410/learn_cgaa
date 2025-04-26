#pragma once
#include <vector>
#include <memory>
#include <string>
#include "lsEntity.h"

class lsLayer
{
public:
    // 构造函数（可指定图层名称）
    explicit lsLayer(const std::string& name = "Unnamed Layer");

    // 图元管理
    void append_entity(std::unique_ptr<lsEntity> entity);
    bool remove_entity(lsObjectId id);  // 根据ID删除图元
    void clear_entitys();                       // 清空所有图元

    // 属性操作
    const std::string& get_name() const;
    void set_name(const std::string& name);
    bool is_visible() const;
    void set_visible(bool visible);
    bool is_locked() const;
    void set_locked(bool locked);

    // 获取图元集合（只读）
    const std::vector<std::unique_ptr<lsEntity>>& get_entitys() const;

private:
    std::string m_name;                // 图层名称
    bool m_visible = true;             // 是否可见
    bool m_locked = false;              // 是否锁定（不可编辑）
    std::vector<std::unique_ptr<lsEntity>> m_entitys; // 图元集合
};