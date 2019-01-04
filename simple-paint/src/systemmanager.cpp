#include "systemmanager.hpp"

namespace mlg {

namespace Core {

static Vec3d get_2d_ndc_coords(double const& x, double const& y) {
    return Vec3d(((x - (800 / 2)) / (800 / 2)), (-(y - (600 / 2)) / (600 / 2)), .0f);
}

SystemManager::SystemManager() noexcept {
    this->assign<GraphicSystem>();

    m_inputManager.setHandlerOnEvent(EventType::MOUSE_BUTTON_LEFT_PRESSED, [&](Event const* event) {
        auto pos = event->get<CursorPosition>();
        if (event->receiver()->getComponent()) {
            event->receiver()->getComponent()->vertices.emplace_back(get_2d_ndc_coords(pos->x, pos->y));
        }
    });

    m_inputManager.setHandlerOnEvent(EventType::MOUSE_BUTTON_LEFT_RELEASED, [&](Event const* event) {
        auto pos = event->get<CursorPosition>();
        if (event->receiver()->getComponent()) {
            event->receiver()->getComponent()->vertices.emplace_back(get_2d_ndc_coords(pos->x, pos->y));
            event->receiver()->onPaintEvent(*event, *this->get<GraphicSystem>());
        }
    });

    m_inputManager.setHandlerOnEvent(EventType::KEY_PRESSED, [&](Event const* event) {
        auto keyboard = event->get<KeyboardAction>();
        if (GLFW_KEY_L == keyboard->key) {
            if (!Application::getInstance()->entity()->getComponent()) {
                auto component = m_componentManager.create<Graphics::Line>();
                Application::getInstance()->entity()->attach(component);
            }
            std::cout << "Key 'L' was pressed!" << std::endl;
        }
    });
}

void SystemManager::processEvent() noexcept {
    Event* event = Application::getInstance()->getFrontEvent();
    m_inputManager.exec(event);

    Application::getInstance()->popFrontEvent();
    delete event;
}

} // namespace Core

} // namespace mlg
