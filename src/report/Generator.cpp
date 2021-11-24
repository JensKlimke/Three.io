// Copyright (c) 2021 Jens Klimke.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#include <fstream>
#include <functional>
#include <cmath>
#include "report/Generator.h"

void Generator::writeCSV(const std::string &filename) {

    // open file
    std::fstream fs(filename, std::ios::out);

    // write header
    fs << "time,acceleration,velocity,position" << std::endl;

    // time step size
    double dt = 0.01;

    // define velocity
    std::function<double (double)> acceleration = [] (double t) { return  std::sin(t); };
    std::function<double (double)> velocity     = [] (double t) { return -std::cos(t); };
    std::function<double (double)> position     = [] (double t) { return -std::sin(t); };

    // loop
    for(unsigned int i = 0; i < 1000; ++i) {

        double t = dt * (double) i;

        // write line
        fs << t
            << "," << acceleration(t)
            << "," << velocity(t)
            << "," << position(t)
            << std::endl;

    }

    // close file
    fs.close();

}