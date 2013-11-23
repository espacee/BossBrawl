#ifndef TOOLS_HPP
#define TOOLS_HPP

enum class Tool {
    Pointer,
    Pen,
    RandomPen,
    PatternBrush,
    Eraser,
    FillShape,
    SelectArea,
    Arrow,
    Entity,
    Object,
    Hand,
    Zoom,
    Count
};

constexpr auto TOOL_COUNT = static_cast<size_t>(Tool::Count);

#endif // TOOLS_HPP
