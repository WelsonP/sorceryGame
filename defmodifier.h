#ifndef __DEFMODIFIER__
#define __DEFMODIFIER__
#include "effect.h"

class DefModifier final: public Effect {
 public:
  DefModifier(Board *b, int value);
}
#endif
