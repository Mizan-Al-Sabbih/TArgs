#pragma once

#include <functional>
#include <map>
#include <string>
#include <vector>

class TArgs {
  enum FMT {
    RUST,
  };

  struct Option {
    std::string desc;
    std::function<void(const std::string &)>;
    bool has_arg = false;
  };

public:
  TArgs(int argc, char **argv, const unsigned int min_argc, FMT fmt)
      : m_argc(argc), m_argv(argv), min_argc(std::move(min_argc)), fmt(fmt) {}
  ~TArgs() {}

  void add_opt(std::string, std::string,
               std::function<void(const std::string &)>, bool);

  int exec();

private:
  int m_argc;
  char **m_argv;
  std::map<std::string, Option> m_opts;
  const unsigned int min_argc;
  const FMT fmt;
};
