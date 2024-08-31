#include "TArgs.h"
#include <functional>

void TArgs::add_opt(std::string name, std::string desc,
                    std::function<void(const std::string &)> func,
                    bool has_arg) {}

int TArgs::exec() {
  if (this->m_argc < min_argc) {
    switch (fmt) {
    case FMT::RUST:
      printf(
          "\e[0;31merror:\e[0m argument count is less than\e[0;93m%d\e[0m.\n",
          min_argc);
    }
  }
  for (int i = 0; i < this->m_argc; i++) {
  }
  return 0;
}
