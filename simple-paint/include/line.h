#pragma once

#include "component.h"

namespace mlg {

namespace Graphics {

class Line : public Core::Component {
public:
    Line() noexcept;
    ~Line() noexcept override;

    void update() noexcept override;
};

} // namespace Graphics

} // namespace mlg
