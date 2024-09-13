let
	pkgs = import <nixpkgs> {};
in pkgs.mkShell
{
	buildInputs = with pkgs; [
		cmake 
		gcc
		ninja
	];
	propagatedBuildInputs = with pkgs; [
		xorg.libX11 
		xorg.libX11.dev
		xorg.libXcursor
		xorg.libXcursor.dev
		xorg.libXext 
		xorg.libXext.dev
		xorg.libXinerama
		xorg.libXinerama.dev 
		xorg.libXrandr 
		xorg.libXrandr.dev
		xorg.libXrender
		xorg.libXrender.dev
		xorg.libxcb
		xorg.libxcb.dev
		xorg.libXi
		xorg.libXi.dev
		harfbuzz
		harfbuzz.dev
		zlib
		zlib.dev
		bzip2
		bzip2.dev
		pngpp
		brotli
		brotli.dev
		pulseaudio.dev
		git
		libGL
		libGL.dev
	];

}
