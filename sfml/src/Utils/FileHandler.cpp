#include "Utils/FileHandler.hpp"
#include <fstream>
#include <stdexcept>

std::vector<std::string> FileHandlers::readLines(const std::string &filePath) {
  std::ifstream file(filePath);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + filePath);
  }

  std::vector<std::string> lines;
  std::string line;
  while (std::getline(file, line)) {
    lines.push_back(line);
  }

  return lines;
}

void FileHandlers::writeLines(const std::string &filePath,
                              const std::vector<std::string> &lines) {
  std::ofstream file(filePath);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + filePath);
  }

  for (const auto &line : lines) {
    file << line << "\n";
  }
}