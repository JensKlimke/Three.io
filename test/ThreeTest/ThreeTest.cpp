//
// Copyright (c) 2019 Jens Klimke <jens.klimke@rwth-aachen.de>. All rights reserved.
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


#include <gtest/gtest.h>
#include <three/three.h>

TEST(ThreeTest, Add) {

    double a;

    // check adding zeros
    a = 0.0;
    EXPECT_EQ(0, three::add(&a, 0.0));
    EXPECT_DOUBLE_EQ(0.0, a);

    // check adding other number
    a = -2.0;
    EXPECT_EQ(0, three::add(&a, 1.0));
    EXPECT_DOUBLE_EQ(-1.0, a);

    // check nullptr given
    EXPECT_EQ(1, three::add(nullptr, 5.0));

}

TEST(ThreeTest, Constant) {

    EXPECT_DOUBLE_EQ(0.5, three::constant());

}