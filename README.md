# three.io

[![CMake](https://github.com/JensKlimke/Three.io/actions/workflows/cmake.yml/badge.svg?branch=master)](https://github.com/JensKlimke/Three.io/actions/workflows/cmake.yml)

This is my almost empty base cmake project, which I use for starting a new project.

## Features

* ⭐️ Static library with professional folder structure
* ⭐️ GoogleTest enabled with CMake option and CMake macros
* ⭐️ Coverage enabled with CMake option (e.g. for use in CLion)
* ⭐ Sample application in test folder to link library against
* ⭐ GitHub Actions workflow for build, test, installation, integration and test report generation
* ⭐ Protobuf feature for serialization and deserialization of objects
* ⭐ Test report generation (e.g. showing test data) with jupyter notebooks
* ⭐ GitHub Pages deployment (https://jensklimke.github.io/Three.io/) 

## Instructions

### CMake Configuration

There are a few pre-defined CMake options in this project:

* `BUILD_TESTING=ON|OFF` (default `OFF`) - Sets or unsets the option to generate the test target (gtest must be installed on the system).
* `ENABLE_COVERAGE=ON|OFF` (default `OFF`) - Enable the coverage check of the module (not measured in workflow).
* `BUILD_LIBRARY=ON|OFF` (default `OFF`) - Enable the library to be build.
* `BUILD_APP=ON|OFF` (default `ON`) - Enables the example app (integrating the library) to be build.
* `BUILD_PROTOBUF_EXAMPLES=ON|OFF` (default `ON`) - The protobuf examples and tests are build when activated. 
* `BUILD_REPORT_EXAMPLES=ON|OFF` (default `ON`) - Enable the report feature.

### Use act to simulate GitHub Action

* Build Dockerfile in `.github/ubuntu-20.04/Dockerfile` with command `docker build -t ubuntu-github-20.04 .` (don't forget to change to folder or specify Dockerfile instead of `.`)
* You can replace `ubuntu-github-20.04` by any other image name you like better, but use your specified name in the `act` command.
* If not done, install act (https://github.com/nektos/act) e.g. by `brew install act`
* Use `act -P ubuntu-20.04=ubuntu-github-20.04`

## TODOs
* [x] Create travis or gitflow workflow
* [x] Add branch state to this README
* [x] Install and link library to test application
* [ ] CMake Package
* [ ] Auto-add release tag
 