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
#include <google/protobuf/util/json_util.h>
#include "PointMass.pb.h"
#include "proto/MyPointMass.h"

typedef example::PointMass PointMass;


void MyPointMass::setParameters(double mass, double drag) {

    // set parameters
    _mass = mass;
    _drag = drag;

}

void MyPointMass::applyForceOverTime(double force, double deltaTime) {

    // set input
    _force = force;

    // dynamical state
    _acceleration = (force - _drag * _velocity) / _mass;
    _velocity += _acceleration * deltaTime;
    _position += 0.5 * _acceleration * deltaTime + _velocity * deltaTime;

}


std::string MyPointMass::toJSON() const {

    // create object
    PointMass pm{};

    // set inputs
    pm.mutable_input()->set_force(_force);

    // set parameters
    pm.mutable_parameters()->set_drag(_drag);
    pm.mutable_parameters()->set_mass(_mass);

    // set state
    pm.mutable_state()->set_acceleration(_acceleration);
    pm.mutable_state()->set_velocity(_velocity);
    pm.mutable_state()->set_position(_position);

    std::string json;
    google::protobuf::util::MessageToJsonString(pm, &json);

    return json;

}

void MyPointMass::fromJSON(const std::string &json) {

    // create object
    PointMass pm{};
    google::protobuf::util::JsonStringToMessage(json, &pm);

    // set inputs
    _force = pm.input().force();

    // set parameters
    _drag = pm.parameters().drag();
    _mass = pm.parameters().mass();

    // set state
    _acceleration = pm.state().acceleration();
    _velocity = pm.state().velocity();
    _position = pm.state().position();

}