#include <iostream>
#include <chrono>

#include "tools/MatchBin.h"
#include "tools/matchbin_utils.h"

int main() {

    emp::Random random(1);

    emp::MatchBin<
        int;
        emp::NextUpMetric<>,
        emp::RandomSelector<>,
        emp::NopRegulator<>
    > bin(random);

    
}