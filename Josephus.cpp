#include "test_runner.h"
#include "profile.h"

#include <cstdint>
#include <iterator>
#include <numeric>
#include <vector>
#include <list>

template <typename RandomIt>
void MakeJosephusPermutation(RandomIt first, RandomIt last, uint32_t step_size) {
  vector<typename RandomIt::value_type> pool;
  move(first,last,back_inserter(pool));
  size_t cur_pos = 0;
  while (!pool.empty()) {
    *(first++) = move(pool[cur_pos]);
    pool.erase(pool.begin() + cur_pos); // на больших данных узкое место тут
    if (pool.empty()) {
      break;
    }
    cur_pos = (cur_pos + step_size - 1) % pool.size();
  }
}

template<typename RandomIt>
void MakeJosephusPermutation_List(RandomIt first, RandomIt last,
		uint32_t step_size) {

	list<typename RandomIt::value_type> pool;
	move(first,last,back_inserter(pool));
	size_t to_move = 0;

	while (!pool.empty()) {
		auto it = pool.begin();
		advance(it,move(to_move)); // на больших данных узкое место тут
		(*first++) = move(*it);
		pool.erase(it);
		if (pool.empty()) {
					cout << to_move << endl;
					break;
		}
		to_move = (to_move + step_size - 1) % pool.size();
	}

}
