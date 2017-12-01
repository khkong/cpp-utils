/*
 * Main.cpp
 *
 *  Created on: 2017. 11. 20.
 *      Author: khkong
 */
#include <vector>

#include "lib/smart_string.h"
#include "lib/viterbi.h"
#include "template_lib/test/priority_queue_test.h"

struct Lexicon {
    string word;
    double cost;
    Lexicon *prevLexicon;
};

int main(int argc, char **argv) {
    viterbi<Lexicon> test_viterbi;

}
