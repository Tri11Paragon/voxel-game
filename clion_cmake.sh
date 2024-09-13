args="$@"
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
nix-shell --pure --run "cmake $args" $SCRIPT_DIR/default.nix
