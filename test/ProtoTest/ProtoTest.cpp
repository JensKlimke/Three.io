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

#include <cmath>
#include <gtest/gtest.h>
#include <proto/MyComplex.h>

class ModelProtoTest : public testing::Test, public MyComplex {

protected:

    void east() {
        real = 1.0;
        imag = 0.0;
    }

    void south() {
        real = 0.0;
        imag = -1.0;
    }

    void westPlus() {
        real = -1.0;
        imag = 1e-15;
    }

    void westMinus() {
        real = -1.0;
        imag = -1e-15;
    }

    void north() {
        real = 0.0;
        imag = 1.0;
    }

};


TEST_F(ModelProtoTest, CalculateAngle) {

    north();
    EXPECT_DOUBLE_EQ(0.0, real);
    EXPECT_DOUBLE_EQ(1.0, imag);
    EXPECT_NEAR(M_PI_2, angle(), 1e-9);

    east();
    EXPECT_DOUBLE_EQ(1.0, real);
    EXPECT_DOUBLE_EQ(0.0, imag);
    EXPECT_NEAR(0.0, angle(), 1e-9);

    south();
    EXPECT_DOUBLE_EQ( 0.0, real);
    EXPECT_DOUBLE_EQ(-1.0, imag);
    EXPECT_NEAR(-0.5 * M_PI, angle(), 1e-9);

    westPlus();
    EXPECT_DOUBLE_EQ(-1.0, real);
    EXPECT_NEAR(0.0, imag, 1e-9);
    EXPECT_NEAR(M_PI, angle(), 1e-9);

    westMinus();
    EXPECT_DOUBLE_EQ(-1.0, real);
    EXPECT_NEAR(0.0, imag, 1e-9);
    EXPECT_NEAR(-M_PI, angle(), 1e-9);

}

TEST_F(ModelProtoTest, SaveAndLoadModel) {


    north();
    save("north.bin");

    westPlus();
    save("west_plus.bin");

    westMinus();
    save("west_minus.bin");


    MyComplex cNorth("north.bin");
    EXPECT_NEAR(M_PI_2, cNorth.angle(), 1e-9);

    MyComplex cWestPlus("west_plus.bin");
    EXPECT_NEAR(M_PI, cWestPlus.angle(), 1e-9);

    MyComplex cWestMinus("west_minus.bin");
    EXPECT_NEAR(-M_PI, cWestMinus.angle(), 1e-9);

}

