with import <nixpkgs> {};

{
     testEnv = stdenv.mkDerivation {
       name = "ConwayGOL";
       buildInputs = [stdenv gcc gdb sfml csfml cmake gnumake ];
     };
}