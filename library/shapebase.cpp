#include <library/shapebase.hpp>

ShapeBase::ShapeBase() : _pen(), _brush() {}
ShapeBase::~ShapeBase() {}

ShapeBase::ShapeBase(const ShapeBase &other) noexcept 
    : _pen(other._pen),
      _brush(other._brush)
{
}

ShapeBase::ShapeBase(ShapeBase &&other) noexcept
    : _pen(std::move(other._pen)),
      _brush(std::move(other._brush))
{
}

ShapeBase &ShapeBase::operator=(const ShapeBase &other) noexcept
{
    _pen = other._pen;
    _brush = other._brush;
    return *this;
}

ShapeBase &ShapeBase::operator=(ShapeBase &&other) noexcept
{
    _pen = std::move(other._pen);
    _brush = std::move(other._brush);
    return *this;
}