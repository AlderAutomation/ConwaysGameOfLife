with import <nixpkgs> {};

{
    testEnv = stdenv.mkDerivation {
      name = "ConwayGOL";
      buildInputs = [stdenv gcc gdb sfml csfml gnumake ];

      shellHook = ''
        export CPLUS_INCLUDE_PATH="$CPLUS_INCLUDE_PATH:${sfml}/include"
        export LIBRARY_PATH="$LIBRARY_PATH:${sfml}/lib"       '';
    };
}