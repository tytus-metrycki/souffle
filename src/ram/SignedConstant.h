/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2013, 2014, Oracle and/or its affiliates. All rights reserved
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/************************************************************************
 *
 * @file SignedConstant.h
 *
 * Defines a class for evaluating values in the Relational Algebra Machine
 *
 ************************************************************************/

#pragma once

#include "RamTypes.h"
#include "ram/Constant.h"
#include <ostream>

namespace souffle {

/**
 * @class RamSignedConstant
 * @brief Represents a signed constant
 *
 * For example:
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * number(5)
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
class RamSignedConstant : public RamConstant {
public:
    explicit RamSignedConstant(RamDomain val) : RamConstant(val) {}

    /** @brief Get value of the constant. */
    RamDomain getValue() const {
        return constant;
    }

    /** Create clone */
    RamSignedConstant* clone() const override {
        return new RamSignedConstant(getValue());
    }

protected:
    void print(std::ostream& os) const override {
        os << "number(" << constant << ")";
    }
};

}  // end of namespace souffle
