// Copyright (c) 2020 Jens Klimke.
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
#include <cmath>
#include "Complex.pb.h"
#include "proto/MyComplex.h"

typedef example::Complex Complex;

void MyComplex::save(const std::string &filename) const {

    // data instance
    Complex complex;

    // set parameters
    complex.set_real(this->real);
    complex.set_imag(this->imag);

    std::fstream fs(filename, std::ios::out);
    complex.SerializeToOstream(&fs);

}


void MyComplex::load(const std::string &filename) {

    // data instance
    Complex complex;

    // read stream
    std::fstream fs(filename, std::ios::in);
    complex.ParseFromIstream(&fs);

    // set parameters
    this->real = complex.real();
    this->imag = complex.imag();

}


double MyComplex::angle() const {

    return std::atan2(imag, real);

}

MyComplex::MyComplex(std::string &&filename) {

    load(filename);

}