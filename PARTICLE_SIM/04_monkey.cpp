#include<iostream>
#include<vector>


#define SPEED 1


using namespace std;

enum Direction {Left=0, Right=1};

struct Hit {
	float time = 0.0;
      	int count = 0;		
};

class Monkey {
	private:
		int monkey_id;
		float position;
		bool is_alive;
	public:
		Monkey() {}
		~Monkey() {}

		Monkey(int id, float position, int start, bool alive) : monkey_id{id}, position{position} , direction_start{start}, is_alive{alive} {}
		

};

class MonkeyBoard {

	private: 
		int size;
		int num_of_monkey;
		float start_pos;
		float end_pos;


};



int
main(int argc, char* argv[]) {
		
	return EXIT_SUCCESS;
}
