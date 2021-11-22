# three.io

[![CMake](https://github.com/JensKlimke/Three.io/actions/workflows/cmake.yml/badge.svg?branch=master)](https://github.com/JensKlimke/Three.io/actions/workflows/cmake.yml)

This is my almost empty base cmake project, which I use for starting a new project.

## Features

* ⭐️ Static library with professional folder structure
* ⭐️ GoogleTest enabled with CMake option and CMake macros
* ⭐️ Coverage enabled with CMake option (e.g. for use in CLion)
* ⭐ Sample application in test folder to link library against
* ⭐ GitHub Actions workflow for build and test
* ⭐ GitHub Pages deployment (https://jensklimke.github.io/Three.io/) 

## Instructions

### Use act to simulate GitHub Action

* Build Dockerfile in `.github/ubuntu-20.04/Dockerfile` with command `docker build -t ubuntu-github-20.04 .` (don't forget to change to folder or specify Dockerfile instead of `.`)
* You can replace `ubuntu-github-20.04` by any other image name you like better, but use your specified name in the `act` command.
* If not done, install act (https://github.com/nektos/act) e.g. by `brew install act`
* Use `act -P ubuntu-20.04=ubuntu-github-20.04`

## TODOs
* [x] Create travis or gitflow workflow
* [x] Add branch state to this README
* [ ] Install and link library to test application
* [ ] CMake Package
* [ ] Auto-add release tag
 