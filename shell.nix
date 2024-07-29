with import <nixpkgs> {};

{
     testEnv = stdenv.mkDerivation {
       name = "ConwayGOL";
       buildInputs = [stdenv csfml sfml cmake gnumake];
     };
}