#ifndef __EFFECT__
#define __EFFECT__

class Effect {
 public:
  virtual void activate() = 0;
  virtual ~Effect() = 0;
};
#endif
