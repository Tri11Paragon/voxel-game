#echo "Running CMake!"
args="$@"
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
CLION=$(which clion)
CLION_DIR=$(nix-store -r $CLION 2>/dev/null)
CMAKE_DIR="$CLION_DIR/clion/bin/cmake/linux/x64/bin/cmake"
export NIXPKGS_ALLOW_UNFREE=1
nix-shell --pure --run "$CMAKE_DIR $args" $SCRIPT_DIR/default.nix
exit
