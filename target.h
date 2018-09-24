#ifndef __TARGET__
#define __TARGET__

class Killer;

class Target {
  bool targetable = false;
 public:
  bool isTargetable() const;
  void makeTargetable();
  void makeUntargetable();
  virtual void react(Killer &killerEffect) = 0;
  virtual ~Target() = 0;
};

#endif
