{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {
  buildInputs = [
    pkgs.clang-tools
    pkgs.clang
    pkgs.cmake
    pkgs.gcc
    pkgs.sfml
    # pkgs.llvmPackages.libcxxClang # Use libc++ (optional)
  ];

  shellHook = ''
    echo "Welcome to your C++ development environment!"
  '';
}
