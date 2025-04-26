#include "lsDocument.h"

// 添加图层（返回指针以便后续操作）
lsLayer* lsDocument::add_layer(std::shared_ptr<lsLayer> layer)
{
    m_layers.push_back(std::move(layer));
    return m_layers.back().get();
}

// 删除指定索引的图层
void lsDocument::del_layer(int index)
{
    if (index >= 0 && index < m_layers.size())
    {
        m_layers.erase(m_layers.begin() + index);
    }
}

// 获取所有图层
std::vector<std::shared_ptr<lsLayer>> lsDocument::get_layers() const
{
    return m_layers;
}

std::shared_ptr<lsLayer> lsDocument::get_work_layer() const
{
    if (m_layers.empty())
        return nullptr;
    return m_layers.back();
}

lsEntity *lsDocument::query_entity(lsObjectId id) const
{
    for (auto& layer : m_layers)
    {
        for (auto& entity : layer->get_entitys())
        {
            if (entity->get_id() == id)
            {
                return entity.get();
            }
        }
    }
    return nullptr;
}

// 选中图元
void lsDocument::sel_entity(lsObjectId id)
{
    m_selectedEntitys.insert(id);
    if (auto entity = query_entity(id))
    {
        entity->set_selected(true);
    }
}

// 取消选中
void lsDocument::unsel_entity(lsObjectId id)
{
    m_selectedEntitys.erase(id);
    if (auto entity = query_entity(id))
    {
        entity->set_selected(false);
    }
}

// 清空选中
void lsDocument::clear_selection()
{
    for (auto id : m_selectedEntitys)
    {
        if (auto entity = query_entity(id))
        {
            entity->set_selected(false);
        }
    }
    m_selectedEntitys.clear();
}

// 检查是否选中
bool lsDocument::is_selected(lsObjectId id) const
{
    return m_selectedEntitys.count(id) > 0;
}

bool lsDocument::is_selected() const
{
    return !m_selectedEntitys.empty();
}

const std::unordered_set<lsObjectId> &lsDocument::get_selected_entity() const
{
    return m_selectedEntitys;
}
