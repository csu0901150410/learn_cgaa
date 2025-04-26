#include "lsDocument.h"

// 添加图层（返回指针以便后续操作）
lsLayer* lsDocument::add_layer(std::unique_ptr<lsLayer> layer)
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

// 获取所有图层（只读）
const std::vector<std::unique_ptr<lsLayer>>& lsDocument::get_layers() const
{
    return m_layers;
}

// 选中图元
void lsDocument::sel_entity(lsObjectId id)
{
    m_selectedEntitys.insert(id);
}

// 取消选中
void lsDocument::unsel_entity(lsObjectId id)
{
    m_selectedEntitys.erase(id);
}

// 清空选中
void lsDocument::clear_selection()
{
    m_selectedEntitys.clear();
}

// 检查是否选中
bool lsDocument::is_selected(lsObjectId id) const
{
    return m_selectedEntitys.count(id) > 0;
}
