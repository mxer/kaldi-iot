#include "iot/link.h"

namespace kaldi {
namespace iot {

Link::Link() :
  prev_(this),
  next_(this)
{ }

Link::~Link() {
  Unlink();
}

Link* Link::Prev() { 
  return prev_;
}

Link* Link::Next() { 
  return next_;
}
  
void Link::InsertBefore(Link* ref) {
  prev_ = ref->prev_;
  next_ = ref;

  prev_->next_ = this;
  ref->prev_  = this;
}

void Link::InsertAfter(Link* ref) {
  prev_ = ref;
  next_ = ref->next_;

  ref->next_  = this;
  next_->prev_ = this;
}

int Link::IsLinked() {
  return (prev_ != this || next_ != this);
} 

void Link::Unlink() {
  prev_->next_ = next_;
  next_->prev_ = prev_;

  prev_ = this;
  next_ = this;
}

} // namespace iot
} // namespace kaldi
