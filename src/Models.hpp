#include <utility>

#pragma once

namespace Model {


    enum model_names {
        polynomial,
        x,
    };

    enum regularization_type {
        empty,
        integer,
        real,
    };

    union regularization_term {
        int reg_int;
        double reg_double;
    };
    
    using regularization = std::pair<regularization_type, regularization_term>;
}