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
#include <proto/MyPointMass.h>

class ProtoPointMassTest : public testing::Test, public MyPointMass {

protected:

    std::string setup = R"({"input":{},"state":{"acceleration":-1,"velocity":9,"position":23.5},"parameters":{"mass":1,"drag":0.1}})";

};


TEST_F(ProtoPointMassTest, GenerateJSON) {

    // set parameters and calculate
    setParameters(1.0, 0.1);
    applyForceOverTime(10.0, 1.0);
    applyForceOverTime(0.0, 1.0);

    // check results
    EXPECT_NEAR(_force, 0.0, 1e-15);
    EXPECT_NEAR(_acceleration, -1.0, 1e-15);
    EXPECT_NEAR(_velocity, 9.0, 1e-15);
    EXPECT_NEAR(_position, 23.5, 1e-15);
    EXPECT_NEAR(_mass, 1.0, 1e-15);
    EXPECT_NEAR(_drag, 0.1, 1e-15);

    // export to json
    auto json = toJSON();

    // check json against setup string
    EXPECT_EQ(setup, json);

}


TEST_F(ProtoPointMassTest, LoadJSON) {

    // load setup from JSON
    fromJSON(setup);

    // check results
    EXPECT_NEAR(_force, 0.0, 1e-15);
    EXPECT_NEAR(_acceleration, -1.0, 1e-15);
    EXPECT_NEAR(_velocity, 9.0, 1e-15);
    EXPECT_NEAR(_position, 23.5, 1e-15);
    EXPECT_NEAR(_mass, 1.0, 1e-15);
    EXPECT_NEAR(_drag, 0.1, 1e-15);

}
