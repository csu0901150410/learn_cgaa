#include "lsLayer.h"
#include "lsEntity.h"
#include "lsLine.h"
#include <algorithm>

// 构造函数
lsLayer::lsLayer(const std::string& name)
    : m_name(name)
{
}

// 添加图元
void lsLayer::append_entity(std::unique_ptr<lsEntity> entity)
{
    if (entity)
        m_entitys.push_back(std::move(entity));
}

// 删除图元（返回是否成功）
bool lsLayer::remove_entity(lsObjectId id)
{
    auto it = std::remove_if(m_entitys.begin(), m_entitys.end(),
        [&id](const auto& p) { return p->get_id() == id; });
    bool removed = (it != m_entitys.end());
    m_entitys.erase(it, m_entitys.end());
    return removed;
}

// 清空所有图元
void lsLayer::clear_entitys()
{
    m_entitys.clear();
}

// 获取图层名称
const std::string& lsLayer::get_name() const
{
    return m_name;
}

// 设置图层名称
void lsLayer::set_name(const std::string& name)
{
    m_name = name;
}

// 图层是否可见
bool lsLayer::is_visible() const
{
    return m_visible;
}

// 设置可见性
void lsLayer::set_visible(bool visible)
{
    m_visible = visible;
}

// 图层是否锁定
bool lsLayer::is_locked() const
{
    return m_locked;
}

// 设置锁定状态
void lsLayer::set_locked(bool locked)
{
    m_locked = locked;
}

// 获取图元集合（只读）
const std::vector<std::unique_ptr<lsEntity>>& lsLayer::get_entitys() const
{
    return m_entitys;
}