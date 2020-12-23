#include "MCell.h"

bool MCell::right() { return m_right; }

bool MCell::down() { return m_down; }

MCell::MCell() { m_down = false; m_right = false; }
