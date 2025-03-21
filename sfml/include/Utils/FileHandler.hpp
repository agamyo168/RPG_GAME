#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include <string>
#include <vector>

class FileHandlers {
  std::vector<std::string> readLines(const std::string &filePath);
  void writeLines(const std::string &filePath,
                  const std::vector<std::string> &lines);
};

#endif // FILE_HANDLER_HPP