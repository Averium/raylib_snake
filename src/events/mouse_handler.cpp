#include "mouse_handler.h"


MouseHandler::MouseHandler(void) : EventHandler::EventHandler() {
    add_key(MOUSE_BUTTON_LEFT);
    add_key(MOUSE_BUTTON_MIDDLE);
    add_key(MOUSE_BUTTON_RIGHT);
}


void MouseHandler::add_key(int keycode) {
    Key* mouse_key = new MouseKey(keycode);
    keymap[keycode] = mouse_key;
}


void MouseHandler::update(void) {

    for (std::pair<const int, Key*> pair : keymap) {
        pair.second->update();
    }

    last_position = position;
    position = Vector(GetMousePosition());

    if (!check(MOUSE_BUTTON_LEFT, HOLD)) {
        anchor = position;
    }
    drag = position - anchor;
    
}