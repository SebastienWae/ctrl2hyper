{
  description = "Plugin for Interception Tools that remaps Left Ctrl to Hyper.";

  inputs.flake-utils.url = github:numtide/flake-utils;

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = nixpkgs.legacyPackages.${system}; in rec {
        packages.ctrl2hyper = pkgs.stdenv.mkDerivation rec {
          pname = "ctrl2hyper";
          version = "0.2.4";

          src = pkgs.fetchFromGitHub {
            owner = "sebastienwae";
            repo = "ctrl2hyper";
            rev = "v${version}";
            sha256 = "sha256-eLE9n2/0ANLuMxJf5DXaabJB2EAZfGJqEP+Ckwa5jiQ=";
          };

          nativeBuildInputs = [ pkgs.cmake ];
        }; 
        defaultPackage = packages.ctrl2hyper;
      }
    );
}
