#include <iostream>
#include <chrono>
#include <cstdlib>
#include <stdlib.h>
	
#include "tools/Random.h"
#include "tools/MatchBin.h"
#include "tools/matchbin_utils.h"

int main(int argc, char *argv[]) {
    // initialize MatchBin
    size_t iterations;
    size_t seed; 

    if (argc != 3) {
        // defaults
        iterations = 1000;
        seed = 2;
    } else {
        iterations = std::atoi(argv[1]);
        seed = std::atoi(argv[2]);
    }

    emp::Random random(seed);

    emp::MatchBin<
        int,
        emp::NextUpMetric<>,
        emp::RankedSelector<>,
        emp::NopRegulator
    > bin(random);

    // seed rand()
    std::srand(seed);

    // put elements into MatchBin

    std::cout << "Putting elements into MatchBin..." << std::endl;

    for (size_t tag = 0; tag < iterations; tag++) {
        int value = std::rand();
        bin.Put(value, tag);
    }

    /* ------ BENCHMARK! ------ */
    size_t result = 0;

    std::cout << "Benchmarking..." << std::endl;

    // start hig-res timer
    auto start_time = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < iterations; i++) {
        // get values
        emp::vector<int> matches = bin.GetVals(bin.Match(i));

        // do something with result, so that it is not optimized away
        result += matches.size();
    }

    // end timer
    auto end_time = std::chrono::high_resolution_clock::now();

    std::cout << "Results!\n" << std::endl;

    // print final result, just in case the compiler feels like optimizing it away
    std::cout << "result: " << result << std::endl;

    // calculate and print timing
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
    std::cout << duration << std::endl;

}