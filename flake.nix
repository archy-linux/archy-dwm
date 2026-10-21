{
  description = "Archy WM";

  inputs = {
    nixpkgs.url = "nixpkgs/nixos-unstable";
    flake-utils = {
      url = "github:numtide/flake-utils";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem
      (system:
        let
          pkgs = import nixpkgs { inherit system; };
          libPath = with pkgs; lib.makeLibraryPath [ libX11 ];
          nativeBuildInputs = with pkgs; [ pkg-config gnumake ];
          buildInputs = with pkgs; [ libX11 libXft libXinerama ];
        in
        with pkgs; {
          packages = rec {
              archy-wm = pkgs.stdenv.mkDerivation {
                inherit buildInputs nativeBuildInputs;
                name = "archy-dwm";
                src = ./.;
                  
                buildPhase = ''
                  make
                '';

                installPhase = ''
                  mkdir -p $out/bin
                  cp ./build/archy-dwm $out/bin/
                '';
                };
                default = archy-wm;
            };

          devShell = mkShell {
            inherit buildInputs nativeBuildInputs;

            packages = with pkgs; [
              git
            ];
            shellHook = ''
              git status
            '';
            LD_LIBRARY_PATH = "${libPath}";
          };
        }
      ) // {
      overlay = final: prev: {
        inherit (self.packages.${final.system}) archy-wm;
      };
    };
}
