{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {
  buildInputs = [
    pkgs.clang-tools
    pkgs.cmake
    pkgs.gcc
  ];

  shellHook = ''
    echo "Welcome to your C++ development environment!"
  '';
}
