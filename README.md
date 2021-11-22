# three.io

[![CMake](https://github.com/JensKlimke/Three.io/actions/workflows/cmake.yml/badge.svg?branch=master)](https://github.com/JensKlimke/Three.io/actions/workflows/cmake.yml)

This is my almost empty base cmake project, which I use for starting a new project.

## Instructions

### Use act to simulate GitHub Action

* Build Dockerfile in `.github/ubuntu-20.04/Dockerfile` with command `docker build -t ubuntu-github-20.04 .` (don't forget to change to folder or specify Dockerfile instead of `.`)
* You can replace `ubuntu-github-20.04` by any other image name you like better, but use your specified name in the `act` command.
* If not done, install act (https://github.com/nektos/act) e.g. by `brew install act`
* Use `act -P ubuntu-20.04=ubuntu-github-20.04`

## TODOs
* [ ] Create travis or gitflow workflow
* [ ] Add branch state to this README
* [ ] Auto-add release tag
 