#include "shutdown_state.h"
#include "game.h"


ShutdownState::ShutdownState(Game* game) : GameState(SHUTDOWN, game) {}

GameStateId ShutdownState::conditions(void) const {
    return SHUTDOWN;
}