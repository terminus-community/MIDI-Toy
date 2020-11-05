# Examples

| Name                                          | Language    | Tested using     | Protocol |
| --------------------------------------------- | ----------- | ---------------- | -------- |
| [`tutorial.py`](/examples/HTTP/tutorial.py)   | Python      | CPython 3.6.9    | HTTP     |
| [`tutorial.lua`](/examples/HTTP/tutorial.lua) | Lua         | Lua 5.1.5        | HTTP     |
| [`tutorial.c`](/examples/HTTP/tutorial.c)     | C           | GCC 7.5.0        | HTTP     |
| [`tutorial.js`](/examples/HTTP/tutorial.js)   | JavaScript  | Node.js v12.13.1 | HTTP     |
| [`tutorial.hs`](/examples/HTTP/tutorial.hs)   | Haskell     | GHC 8.8.4 (Nix)  | HTTP     |
| [`tutorial.cl`](/examples/HTTP/tutorial.cl)   | Common Lisp | SBCL 1.4.5       | HTTP     |

# Notes

## Haskell installation; Nov 5, 2050

From now on I'm starting to use Nix package manager, since [Murat Kasimov](https://github.com/iokasimov) recommended it to me.
Nix GHC distro is updated more often and has more features. It took me some time to update and I did a ton of silly things,
so there are my steps to install GHC and requirements using Nix:

| Command                             | Explanation            |
| ----------------------------------- | ---------------------- |
| `nix-env -iA nixpkgs.ghc`           | install fresh GHC      |
| `nix-env -iA nixpkgs.cabal-install` | install Cabal with Nix |
| `cabal user-config update`          | configure Cabal        |
| `cabal update`                      | update package list to install stuff with Cabal |
| `cabal install network --lib`       | install Network *library* to perform HTTP requests |
