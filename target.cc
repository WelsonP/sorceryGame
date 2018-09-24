#include "target.h"

bool Target::isTargetable() const {
  return targetable;
}

void Target::makeTargetable() {
  targetable = true;
}

void Target::makeUntargetable() {
  targetable = false;
}

Target::~Target() {}
