#include "MCell.h"

bool MCell::down() { return m_down; }

bool MCell::right() { return m_right; }

MCell::MCell() { m_down = false; m_right = false; }
