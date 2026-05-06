let
  nixpkgs = fetchTarball {
    url = "https://github.com/nixos/nixpkgs/archive/549bd84d6279f9852cae6225e372cc67fb91a4c1.tar.gz";
    sha256 = "0dchsfq8czjg8iwr60fxmqnglllchcy64wp60b8wx4wd9mwn0rw4";
  };

  pkgs = import nixpkgs { };
in
pkgs.mkShell {
  name = "c project";
  buildInputs = with pkgs; [
    bear
    clang-tools
    csfml_2
    sfml_2
    gcc
    gnumake
    lld
  ];
}
