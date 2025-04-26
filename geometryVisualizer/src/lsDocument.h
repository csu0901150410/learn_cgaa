// DocumentModel.h
#pragma once
#include <vector>
#include <memory>
#include <unordered_set>
#include "lsLayer.h"

class lsDocument
{
public:
    // 图层管理
    lsLayer* add_layer(std::unique_ptr<lsLayer> layer);
    void del_layer(int index);
    const std::vector<std::unique_ptr<lsLayer>>& get_layers() const;

    // 图元选中状态
    void sel_entity(lsObjectId id);
    void unsel_entity(lsObjectId id);
    void clear_selection();
    bool is_selected(lsObjectId id) const;
    const std::unordered_set<lsObjectId>& get_selected_entity() const;

private:
    std::vector<std::unique_ptr<lsLayer>> m_layers;                     // 图层集合
    std::unordered_set<lsObjectId> m_selectedEntitys;             // 选中图元ID集合
};