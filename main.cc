#include <iostream>
#include <chrono>

#include "tools/MatchBin.h"
#include "tools/matchbin_utils.h"

size_t ITERATIONS = 10000;

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

    /* benchmark! */
    size_t result = 0;

    // start hig-res timer
    auto start_time = std::chrono::high_resolution_clock::now();

    for (size_t i; i < ITERATIONS; i++) {
        // get values
        emp::vector<int> matches = bin.GetVals(bin.Match(i));

        // do something with result, so that it is not optimized away
        result += matches.size();
    }

    // end timer
    auto end_time = std::chrono::high_resolution_clock::now();

    // print final result, just in case the compiler feels like optimizing it away
    std::cout << result << std::endl;


    // calculate and print timing
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
    std::cout << duration << std::endl;

}