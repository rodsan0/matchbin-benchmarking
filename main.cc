#include <iostream>
#include <chrono>

#include "tools/MatchBin.h"
#include "tools/matchbin_utils.h"

int main() {
    // initialize MatchBin

    emp::Random random(1);
    emp::MatchBin<
        int,
        emp::NextUpMetric<>,
        emp::RankedSelector<>,
        emp::NopRegulator
    > bin(random);

    // put 10 things into MatchBin
    bin.Put(0, 0);
    bin.Put(1, 23);
    bin.Put(2, 44);
    bin.Put(3, 987);
    bin.Put(4, 990);
    bin.Put(5, 3423);
    bin.Put(6, 9878);
    bin.Put(7, 2213);
    bin.Put(8, 2);
    bin.Put(9, 653);

}